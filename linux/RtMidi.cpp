/**********************************************************************/
/*! \class RtMidi
    \brief An abstract base class for realtime MIDI input/output.

    This class implements some common functionality for the realtime
    MIDI input/output subclasses RtMidiIn and RtMidiOut.

    RtMidi WWW site: http://music.mcgill.ca/~gary/rtmidi/

    RtMidi: realtime MIDI i/o C++ classes
    Copyright (c) 2003-2006 Gary P. Scavone

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation files
    (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    Any person wishing to distribute modifications to the Software is
    requested to send the modifications to the original developer so that
    they can be incorporated into the canonical version.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
    ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
    CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/**********************************************************************/

// RtMidi: Version 1.0.6

#include "RtMidi.h"
#include <sstream>

//*********************************************************************//
//  Common RtMidi Definitions
//*********************************************************************//

RtMidi :: RtMidi()
  : apiData_( 0 ), connected_( false )
{
}

void RtMidi :: error( RtError::Type type )
{
  if (type == RtError::WARNING) {
    std::cerr << '\n' << errorString_ << "\n\n";
  }
  else {
    std::cerr << '\n' << errorString_ << "\n\n";
    throw RtError( errorString_, type );
  }
}

//*********************************************************************//
//  Common RtMidiIn Definitions
//*********************************************************************//

RtMidiIn :: RtMidiIn() : RtMidi()
{
  this->initialize();
}

void RtMidiIn :: setCallback( RtMidiCallback callback, void *userData )
{
  if ( inputData_.usingCallback ) {
    errorString_ = "FxFloorBoard MidiIn::setCallback: a callback function is already set!";
    error( RtError::WARNING );
    return;
  }

  if ( !callback ) {
    errorString_ = "FxFloorBoard MidiIn::setCallback: callback function value is invalid!";
    error( RtError::WARNING );
    return;
  }

  inputData_.userCallback = (void *) callback;
  inputData_.userData = userData;
  inputData_.usingCallback = true;
}

void RtMidiIn :: cancelCallback()
{
  if ( !inputData_.usingCallback ) {
    errorString_ = "FxFloorBoard MidiIn::cancelCallback: no callback function was set!";
    error( RtError::WARNING );
    return;
  }

  inputData_.userCallback = 0;
  inputData_.userData = 0;
  inputData_.usingCallback = false;
}

void RtMidiIn :: setQueueSizeLimit( unsigned int queueSize )
{
  inputData_.queueLimit = queueSize;
}

void RtMidiIn :: ignoreTypes( bool midiSysex, bool midiTime, bool midiSense )
{
  inputData_.ignoreFlags = 0;
  if ( midiSysex ) inputData_.ignoreFlags = 0x01;
  if ( midiTime ) inputData_.ignoreFlags |= 0x02;
  if ( midiSense ) inputData_.ignoreFlags |= 0x04;
}

double RtMidiIn :: getMessage( std::vector<unsigned char> *message )
{
  message->clear();

  if ( inputData_.usingCallback ) {
    errorString_ = "FxFloorBoard MidiIn::getNextMessage: a user callback is currently set for this port.";
    error( RtError::WARNING );
    return 0.0;
  }

  if ( inputData_.queue.size() == 0 ) return 0.0;

  // Copy queued message to the vector pointer argument and then "pop" it.
  std::vector<unsigned char> *bytes = &(inputData_.queue.front().bytes);
  message->assign( bytes->begin(), bytes->end() );
  double deltaTime = inputData_.queue.front().timeStamp;
  inputData_.queue.pop();

  return deltaTime;
}

//*********************************************************************//
//  Common RtMidiOut Definitions
//*********************************************************************//

RtMidiOut :: RtMidiOut() : RtMidi()
{
  this->initialize();
}


//*********************************************************************//
//  API: LINUX ALSA SEQUENCER
//*********************************************************************//

// API information found at:
//   - http://www.alsa-project.org/documentation.php#Library

//#if defined(__LINUX_ALSASEQ__)

// The ALSA Sequencer API is based on the use of a callback function for
// MIDI input.
//
// Thanks to Pedro Lopez-Cabanillas for help with the ALSA sequencer
// time stamps and other assorted fixes!!!

#include <pthread.h>
#include <sys/time.h>

// ALSA header file.
#include <alsa/asoundlib.h>

// A structure to hold variables related to the ALSA API
// implementation.
struct AlsaMidiData {
  snd_seq_t *seq;
  int vport;
  snd_seq_port_subscribe_t *subscription;
  snd_midi_event_t *coder;
  unsigned int bufferSize;
  unsigned char *buffer;
  pthread_t thread;
  unsigned long long lastTime;
  int queue_id; // an input queue is needed to get timestamped events
};

#define PORT_TYPE( pinfo, bits ) ((snd_seq_port_info_get_capability(pinfo) & (bits)) == (bits))

//*********************************************************************//
//  API: LINUX ALSA
//  Class Definitions: RtMidiIn
//*********************************************************************//

extern "C" void *alsaMidiHandler( void *ptr )
{
  RtMidiIn::RtMidiInData *data = static_cast<RtMidiIn::RtMidiInData *> (ptr);
  AlsaMidiData *apiData = static_cast<AlsaMidiData *> (data->apiData);

  long nBytes;
  unsigned long long time, lastTime;
  bool continueSysex = false;
  RtMidiIn::MidiMessage message;

  snd_seq_event_t *ev;
  int result;
  apiData->bufferSize = 32;
  result = snd_midi_event_new( 0, &apiData->coder );
  if ( result < 0 ) {
    data->doInput = false;
    std::cerr << "\nFxFloorBoard MidiIn::alsaMidiHandler: error initializing MIDI event parser!\n\n";
    return 0;
  }
  unsigned char *buffer = (unsigned char *) malloc( apiData->bufferSize );
  if ( buffer == NULL ) {
    data->doInput = false;
    std::cerr << "\nFxFloorBoard MidiIn::alsaMidiHandler: error initializing buffer memory!\n\n";
    return 0;
  }
  snd_midi_event_init( apiData->coder );
  snd_midi_event_no_status( apiData->coder, 1 ); // suppress running status messages

  while ( data->doInput ) {

    if ( snd_seq_event_input_pending( apiData->seq, 1 ) == 0 ) {
      // No data pending ... sleep a bit.
      usleep( 1000 );
      continue;
    }

    // If here, there should be data.
    result = snd_seq_event_input( apiData->seq, &ev );
    if ( result == -ENOSPC ) {
      std::cerr << "\nFxFloorBoard MidiIn::alsaMidiHandler: MIDI input buffer overrun!\n\n";
      continue;
    }
    else if ( result <= 0 ) {
      std::cerr << "FxFloorBoard MidiIn::alsaMidiHandler: unknown MIDI input error!\n";
      continue;
    }

    // This is a bit weird, but we now have to decode an ALSA MIDI
    // event (back) into MIDI bytes.  We'll ignore non-MIDI types.
    message.bytes.clear();
    switch ( ev->type ) {

		case SND_SEQ_EVENT_PORT_SUBSCRIBED:
#if defined(__RTMIDI_DEBUG__)
      std::cout << "FxFloorBoard MidiIn::alsaMidiHandler: port connection made!\n";
#endif
      break;

		case SND_SEQ_EVENT_PORT_UNSUBSCRIBED:
      std::cerr << "FxFloorBoard MidiIn::alsaMidiHandler: port connection has closed!\n";
      data->doInput = false;
      break;

    case SND_SEQ_EVENT_QFRAME: // MIDI time code
      if ( data->ignoreFlags & 0x02 ) break;

    case SND_SEQ_EVENT_TICK: // MIDI timing tick
      if ( data->ignoreFlags & 0x02 ) break;

    case SND_SEQ_EVENT_SENSING: // Active sensing
      if ( data->ignoreFlags & 0x04 ) break;

		case SND_SEQ_EVENT_SYSEX:
      if ( (data->ignoreFlags & 0x01) ) break;
      if ( ev->data.ext.len > apiData->bufferSize ) {
        apiData->bufferSize = ev->data.ext.len;
        free( buffer );
        buffer = (unsigned char *) malloc( apiData->bufferSize );
        if ( buffer == NULL ) {
          data->doInput = false;
          std::cerr << "\nFxFloorBoard MidiIn::alsaMidiHandler: error resizing buffer memory!\n\n";
          break;
        }
      }

    default:
      nBytes = snd_midi_event_decode( apiData->coder, buffer, apiData->bufferSize, ev );
      if ( nBytes <= 0 ) {
#if defined(__RTMIDI_DEBUG__)
        std::cerr << "\nFxFloorBoard MidiIn::alsaMidiHandler: event parsing error or not a MIDI event!\n\n";
#endif
        break;
      }

      // The ALSA sequencer has a maximum buffer size for MIDI sysex
      // events of 256 bytes.  If a device sends sysex messages larger
      // than this, they are segmented into 256 byte chunks.  So,
      // we'll watch for this and concatenate sysex chunks into a
      // single sysex message if necessary.
      if ( !continueSysex )
        message.bytes.assign( buffer, &buffer[nBytes] );
      else
        message.bytes.insert( message.bytes.end(), buffer, &buffer[nBytes] );

      continueSysex = ( ev->type == SND_SEQ_EVENT_SYSEX && message.bytes.back() != 0xF7 );
      if ( continueSysex )
        break;

      // Calculate the time stamp:
      message.timeStamp = 0.0;

      // Method 1: Use the system time.
      //(void)gettimeofday(&tv, (struct timezone *)NULL);
      //time = (tv.tv_sec * 1000000) + tv.tv_usec;

      // Method 2: Use the ALSA sequencer event time data.
      // (thanks to Pedro Lopez-Cabanillas!).
      time = ( ev->time.time.tv_sec * 1000000 ) + ( ev->time.time.tv_nsec/1000 );
      lastTime = time;
      time -= apiData->lastTime;
      apiData->lastTime = lastTime;
      if ( data->firstMessage == true )
        data->firstMessage = false;
      else
        message.timeStamp = time * 0.000001;
    }

    snd_seq_free_event(ev);
    if ( message.bytes.size() == 0 ) continue;

    if ( data->usingCallback ) {
      RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
      callback( message.timeStamp, &message.bytes, data->userData );
    }
    else {
      // As long as we haven't reached our queue size limit, push the message.
      if ( data->queueLimit > data->queue.size() )
        data->queue.push( message );
      else
        std::cerr << "\nFxFloorBoard MidiIn: message queue limit reached!!\n\n";
    }
  }

  if ( buffer ) free( buffer );
  snd_midi_event_free( apiData->coder );
  apiData->coder = 0;
  return 0;
}

void RtMidiIn :: initialize( void )
{
  // Set up the ALSA sequencer client.
	snd_seq_t *seq;
  int result = snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, SND_SEQ_NONBLOCK);
  if ( result < 0 ) {
    errorString_ = "FxFloorBoard MidiIn::initialize: error creating ALSA sequencer input client object.";
    error( RtError::DRIVER_ERROR );
	}

  // Set client name.
  snd_seq_set_client_name(seq, "FxFloorBoard Midi Input Client");

  // Save our api-specific connection information.
  AlsaMidiData *data = (AlsaMidiData *) new AlsaMidiData;
  data->seq = seq;
  data->vport = -1;
  apiData_ = (void *) data;
  inputData_.apiData = (void *) data;

  // Create the input queue
  data->queue_id = snd_seq_alloc_named_queue(seq, "FxFloorBoard Midi Queue");
  // Set arbitrary tempo (mm=100) and resolution (240)
  snd_seq_queue_tempo_t *qtempo;
  snd_seq_queue_tempo_alloca(&qtempo);
  snd_seq_queue_tempo_set_tempo(qtempo, 600000);
  snd_seq_queue_tempo_set_ppq(qtempo, 240);
  snd_seq_set_queue_tempo(data->seq, data->queue_id, qtempo);
  snd_seq_drain_output(data->seq);
}

// This function is used to count or get the pinfo structure for a given port number.
unsigned int portInfo( snd_seq_t *seq, snd_seq_port_info_t *pinfo, unsigned int type, int portNumber )
{
	snd_seq_client_info_t *cinfo;
  int client;
  int count = 0;
	snd_seq_client_info_alloca( &cinfo );

	snd_seq_client_info_set_client( cinfo, -1 );
	while ( snd_seq_query_next_client( seq, cinfo ) >= 0 ) {
    client = snd_seq_client_info_get_client( cinfo );
    if ( client == 0 ) continue;
		// Reset query info
		snd_seq_port_info_set_client( pinfo, client );
		snd_seq_port_info_set_port( pinfo, -1 );
		while ( snd_seq_query_next_port( seq, pinfo ) >= 0 ) {
      if ( !PORT_TYPE( pinfo, type ) )  continue;
      if ( count == portNumber ) return 1;
      count++;
		}
	}

  // If a negative portNumber was used, return the port count.
  if ( portNumber < 0 ) return count;
  return 0;
}

void RtMidiIn :: openPort( unsigned int portNumber )
{
  if ( connected_ ) {
    errorString_ = "FxFloorBoard MidiIn::openPort: a valid connection already exists!";
    error( RtError::WARNING );
    return;
  }

  unsigned int nSrc = this->getPortCount();
  if (nSrc < 1) {
    errorString_ = "FxFloorBoard MidiIn::openPort: no MIDI input sources found!";
    error( RtError::NO_DEVICES_FOUND );
  }

	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );
  std::ostringstream ost;
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ, (int) portNumber ) == 0 ) {
    ost << "FxFloorBoard MidiIn::openPort: the listed device 'portNumber'(" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }


  snd_seq_addr_t sender, receiver;
  sender.client = snd_seq_port_info_get_client( pinfo );
  sender.port = snd_seq_port_info_get_port( pinfo );
  receiver.client = snd_seq_client_id( data->seq );
  if ( data->vport < 0 ) {
    snd_seq_port_info_set_client( pinfo, 0 );
    snd_seq_port_info_set_port( pinfo, 0 );
    snd_seq_port_info_set_capability( pinfo,
                                      SND_SEQ_PORT_CAP_WRITE |
                                      SND_SEQ_PORT_CAP_SUBS_WRITE );
    snd_seq_port_info_set_type( pinfo,
                                SND_SEQ_PORT_TYPE_MIDI_GENERIC |
                                SND_SEQ_PORT_TYPE_APPLICATION );
    snd_seq_port_info_set_midi_channels(pinfo, 16);
    snd_seq_port_info_set_timestamping(pinfo, 1);
    snd_seq_port_info_set_timestamp_real(pinfo, 1);    
    snd_seq_port_info_set_timestamp_queue(pinfo, data->queue_id);
    snd_seq_port_info_set_name(pinfo, "FxFloorBoard Midi Input");
    data->vport = snd_seq_create_port(data->seq, pinfo);
  
    if ( data->vport < 0 ) {
      errorString_ = "FxFloorBoard MidiIn::openPort: ALSA error creating input port.";
      error( RtError::DRIVER_ERROR );
    }
  }

  receiver.port = data->vport;

  // Make subscription
  snd_seq_port_subscribe_malloc( &data->subscription );
  snd_seq_port_subscribe_set_sender(data->subscription, &sender);
  snd_seq_port_subscribe_set_dest(data->subscription, &receiver);
  if ( snd_seq_subscribe_port(data->seq, data->subscription) ) {
    errorString_ = "FxFloorBoard MidiIn::openPort: ALSA error making port connection.";
    error( RtError::DRIVER_ERROR );
  }

  if ( inputData_.doInput == false ) {
    // Start the input queue
    snd_seq_start_queue( data->seq, data->queue_id, NULL );
    snd_seq_drain_output( data->seq );
    // Start our MIDI input thread.
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setschedpolicy(&attr, SCHED_OTHER);

    inputData_.doInput = true;
    int err = pthread_create(&data->thread, &attr, alsaMidiHandler, &inputData_);
    pthread_attr_destroy(&attr);
    if (err) {
      snd_seq_unsubscribe_port( data->seq, data->subscription );
      snd_seq_port_subscribe_free( data->subscription );
      inputData_.doInput = false;
      errorString_ = "FxFloorBoard MidiIn::openPort: error starting MIDI input thread!";
      error( RtError::THREAD_ERROR );
    }
  }

  connected_ = true;
}

void RtMidiIn :: openVirtualPort( std::string portName )
{
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( data->vport < 0 ) {
    snd_seq_port_info_t *pinfo;
    snd_seq_port_info_alloca( &pinfo );
    snd_seq_port_info_set_capability( pinfo,
				      SND_SEQ_PORT_CAP_WRITE |
				      SND_SEQ_PORT_CAP_SUBS_WRITE );
    snd_seq_port_info_set_type( pinfo,
				SND_SEQ_PORT_TYPE_MIDI_GENERIC |
				SND_SEQ_PORT_TYPE_APPLICATION );
    snd_seq_port_info_set_midi_channels(pinfo, 16);
    snd_seq_port_info_set_timestamping(pinfo, 1);
    snd_seq_port_info_set_timestamp_real(pinfo, 1);    
    snd_seq_port_info_set_timestamp_queue(pinfo, data->queue_id);
    snd_seq_port_info_set_name(pinfo, portName.c_str());
    data->vport = snd_seq_create_port(data->seq, pinfo);

    if ( data->vport < 0 ) {
      errorString_ = "FxFloorBoard MidiIn::openVirtualPort: ALSA error creating virtual port.";
      error( RtError::DRIVER_ERROR );
    }
  }

  if ( inputData_.doInput == false ) {
    // Start the input queue
    snd_seq_start_queue( data->seq, data->queue_id, NULL );
    snd_seq_drain_output( data->seq );
    // Start our MIDI input thread.
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setschedpolicy(&attr, SCHED_OTHER);

    inputData_.doInput = true;
    int err = pthread_create(&data->thread, &attr, alsaMidiHandler, &inputData_);
    pthread_attr_destroy(&attr);
    if (err) {
      snd_seq_unsubscribe_port( data->seq, data->subscription );
      snd_seq_port_subscribe_free( data->subscription );
      inputData_.doInput = false;
      errorString_ = "FxFloorBoard MidiIn::openPort: error starting MIDI input thread!";
      error( RtError::THREAD_ERROR );
    }
  }
}

void RtMidiIn :: closePort( void )
{
  if ( connected_ ) {
    AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
    snd_seq_unsubscribe_port( data->seq, data->subscription );
    snd_seq_port_subscribe_free( data->subscription );
    // Stop the input queue
    snd_seq_stop_queue( data->seq, data->queue_id, NULL );
    snd_seq_drain_output( data->seq );
    connected_ = false;
  }
}

RtMidiIn :: ~RtMidiIn()
{
  // Close a connection if it exists.
  closePort();

  // Shutdown the input thread.
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( inputData_.doInput ) {
    inputData_.doInput = false;
    pthread_join( data->thread, NULL );
  }

  // Cleanup.
  if ( data->vport >= 0 ) snd_seq_delete_port( data->seq, data->vport );
  snd_seq_free_queue( data->seq, data->queue_id );
  snd_seq_close( data->seq );
  delete data;
}

unsigned int RtMidiIn :: getPortCount()
{
	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );

  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  return portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ, -1 );
}

std::string RtMidiIn :: getPortName( unsigned int portNumber )
{
	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );

  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ, (int) portNumber ) ) {
    std::string stringName = std::string( snd_seq_port_info_get_name( pinfo ) );
    return stringName;
  }

  // If we get here, we didn't find a match.
  errorString_ = "FxFloorBoard MidiIn::getPortName: error looking for port name!";
  error( RtError::INVALID_PARAMETER );
  return 0;
}

//*********************************************************************//
//  API: LINUX ALSA
//  Class Definitions: RtMidiOut
//*********************************************************************//

unsigned int RtMidiOut :: getPortCount()
{
	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );

  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  return portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, -1 );
}

std::string RtMidiOut :: getPortName( unsigned int portNumber )
{
	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );

  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, (int) portNumber ) ) {
    std::string stringName = std::string( snd_seq_port_info_get_name( pinfo ) );
    return stringName;
  }

  // If we get here, we didn't find a match.
  errorString_ = "FxFloorBoard MidiOut::getPortName: error looking for port name!";
  error( RtError::INVALID_PARAMETER );
  return 0;
}

void RtMidiOut :: initialize( void )
{
  // Set up the ALSA sequencer client.
	snd_seq_t *seq;
  int result = snd_seq_open(&seq, "default", SND_SEQ_OPEN_OUTPUT, 0);
  if ( result < 0 ) {
    errorString_ = "FxFloorBoard MidiOut::initialize: error creating ALSA sequencer client object.";
    error( RtError::DRIVER_ERROR );
	}

  // Set client name.
  snd_seq_set_client_name(seq, "FxFloorBoard Midi Output Client");

  // Save our api-specific connection information.
  AlsaMidiData *data = (AlsaMidiData *) new AlsaMidiData;
  data->seq = seq;
  data->vport = -1;
  data->bufferSize = 32;
  data->coder = 0;
  data->buffer = 0;
  result = snd_midi_event_new( data->bufferSize, &data->coder );
  if ( result < 0 ) {
    delete data;
    errorString_ = "FxFloorBoard MidiOut::initialize: error initializing MIDI event parser!\n\n";
    error( RtError::DRIVER_ERROR );
  }
  data->buffer = (unsigned char *) malloc( data->bufferSize );
  if ( data->buffer == NULL ) {
    delete data;
    errorString_ = "FxFloorBoard MidiOut::initialize: error allocating buffer memory!\n\n";
    error( RtError::MEMORY_ERROR );
  }
  snd_midi_event_init( data->coder );
  apiData_ = (void *) data;
}

void RtMidiOut :: openPort( unsigned int portNumber )
{
  if ( connected_ ) {
    errorString_ = "FxFloorBoard MidiOut::openPort: a valid connection already exists!";
    error( RtError::WARNING );
    return;
  }

  unsigned int nSrc = this->getPortCount();
  if (nSrc < 1) {
    errorString_ = "FxFloorBoard MidiOut::openPort: no MIDI output sources found!";
    error( RtError::NO_DEVICES_FOUND );
  }

	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );
  std::ostringstream ost;
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, (int) portNumber ) == 0 ) {
    ost << "FxFloorBoard MidiOut::openPort: the listed device at 'portNumber'(" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }

  snd_seq_addr_t sender, receiver;
  receiver.client = snd_seq_port_info_get_client( pinfo );
  receiver.port = snd_seq_port_info_get_port( pinfo );
  sender.client = snd_seq_client_id( data->seq );

  if ( data->vport < 0 ) {
    data->vport = snd_seq_create_simple_port( data->seq, "FxFloorBoard Midi Output",
                                              SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
                                              SND_SEQ_PORT_TYPE_MIDI_GENERIC );
    if ( data->vport < 0 ) {
      errorString_ = "FxFloorBoard MidiOut::openPort: ALSA error creating output port.";
      error( RtError::DRIVER_ERROR );
    }
  }

  sender.port = data->vport;

  // Make subscription
  snd_seq_port_subscribe_malloc( &data->subscription );
  snd_seq_port_subscribe_set_sender(data->subscription, &sender);
  snd_seq_port_subscribe_set_dest(data->subscription, &receiver);
  snd_seq_port_subscribe_set_time_update(data->subscription, 1);
  snd_seq_port_subscribe_set_time_real(data->subscription, 1);
  if ( snd_seq_subscribe_port(data->seq, data->subscription) ) {
    errorString_ = "FxFloorBoard MidiOut::openPort: ALSA error making port connection.";
    error( RtError::DRIVER_ERROR );
  }

  connected_ = true;
}

void RtMidiOut :: closePort( void )
{
  if ( connected_ ) {
    AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
    snd_seq_unsubscribe_port( data->seq, data->subscription );
    snd_seq_port_subscribe_free( data->subscription );
    connected_ = false;
  }
}

void RtMidiOut :: openVirtualPort( std::string portName )
{
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( data->vport < 0 ) {
    data->vport = snd_seq_create_simple_port( data->seq, portName.c_str(),
                                              SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
                                              SND_SEQ_PORT_TYPE_MIDI_GENERIC );

    if ( data->vport < 0 ) {
      errorString_ = "FxFloorBoard MidiOut::openVirtualPort: ALSA error creating virtual port.";
      error( RtError::DRIVER_ERROR );
    }
  }
}

RtMidiOut :: ~RtMidiOut()
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( data->vport >= 0 ) snd_seq_delete_port( data->seq, data->vport );
  if ( data->coder ) snd_midi_event_free( data->coder );
  if ( data->buffer ) free( data->buffer );
  snd_seq_close( data->seq );
  delete data;
}

void RtMidiOut :: sendMessage( std::vector<unsigned char> *message )
{
  int result;
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  unsigned int nBytes = message->size();
  if ( nBytes > data->bufferSize ) {
    data->bufferSize = nBytes;
    result = snd_midi_event_resize_buffer ( data->coder, nBytes);
    if ( result != 0 ) {
      errorString_ = "FxFloorBoard MidiOut::sendMessage: ALSA error resizing MIDI event buffer.";
      error( RtError::DRIVER_ERROR );
    }
    free (data->buffer);
    data->buffer = (unsigned char *) malloc( data->bufferSize );
    if ( data->buffer == NULL ) {
    errorString_ = "FxFloorBoard MidiOut::initialize: error allocating buffer memory!\n\n";
    error( RtError::MEMORY_ERROR );
    }
  }

  snd_seq_event_t ev;
  snd_seq_ev_clear(&ev);
  snd_seq_ev_set_source(&ev, data->vport);
  snd_seq_ev_set_subs(&ev);
  snd_seq_ev_set_direct(&ev);
  for ( unsigned int i=0; i<nBytes; i++ ) data->buffer[i] = message->at(i);
  result = snd_midi_event_encode( data->coder, data->buffer, (long)nBytes, &ev );
  if ( result < (int)nBytes ) {
    errorString_ = "FxFloorBoard MidiOut::sendMessage: event parsing error!";
    error( RtError::WARNING );
    return;
  }

  // Send the event.
  result = snd_seq_event_output(data->seq, &ev);
  if ( result < 0 ) {
    errorString_ = "FxFloorBoard MidiOut::sendMessage: error sending MIDI message to port.";
    error( RtError::WARNING );
  }
  snd_seq_drain_output(data->seq);
}

//#endif // __LINUX_ALSA__


