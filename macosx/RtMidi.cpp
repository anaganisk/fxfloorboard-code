// RtMidi: Version 1.0.6

#include "FxFloorBoard Midi.h"
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
  else if (type == RtError::DEBUG_WARNING) {
#if defined(__RTMIDI_DEBUG__)
    std::cerr << '\n' << errorString_ << "\n\n";
#endif
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
//  API: Macintosh OS-X
//*********************************************************************//

// API information found at:
//   - http://developer.apple.com/audio/pdf/coreaudio.pdf 

//#if defined(__MACOSX_CORE__)

// The CoreMIDI API is based on the use of a callback function for
// MIDI input.  We convert the system specific time stamps to delta
// time values.

// OS-X CoreMIDI header files.
#include <CoreMIDI/CoreMIDI.h>
#include <CoreAudio/HostTime.h>

// A structure to hold variables related to the CoreMIDI API
// implementation.
struct CoreMidiData {
  MIDIClientRef client;
  MIDIPortRef port;
  MIDIEndpointRef endpoint;
  MIDIEndpointRef destinationId;
  unsigned long long lastTime;
};

//*********************************************************************//
//  API: OS-X
//  Class Definitions: RtMidiIn
//*********************************************************************//

void midiInputCallback( const MIDIPacketList *list, void *procRef, void *srcRef )
{
  RtMidiIn::RtMidiInData *data = static_cast<RtMidiIn::RtMidiInData *> (procRef);
  CoreMidiData *apiData = static_cast<CoreMidiData *> (data->apiData);

  bool continueSysex = false;
  unsigned char status;
  unsigned short nBytes, iByte, size;
  unsigned long long time;
  RtMidiIn::MidiMessage message;
  const MIDIPacket *packet = &list->packet[0];
  for ( unsigned int i=0; i<list->numPackets; ++i ) {

    // My interpretation of the CoreMIDI documentation: all message
    // types, except sysex, are complete within a packet and there may
    // be several of them in a single packet.  Sysex messages can be
    // broken across multiple packets but are bundled alone within a
    // packet.  I'm assuming that sysex messages, if segmented, must
    // be complete within the same MIDIPacketList.

    nBytes = packet->length;
    if ( nBytes == 0 ) continue;

    // Calculate time stamp.
    message.timeStamp = 0.0;
    if ( data->firstMessage )
      data->firstMessage = false;
    else {
      time = packet->timeStamp;
      time -= apiData->lastTime;
      time = AudioConvertHostTimeToNanos( time );
      message.timeStamp = time * 0.000000001;
    }
    apiData->lastTime = packet->timeStamp;

    iByte = 0;
    if ( continueSysex ) {
      // We have a continuing, segmented sysex message.
      if ( !(data->ignoreFlags & 0x01) ) {
        // If we're not ignoring sysex messages, copy the entire packet.
        for ( unsigned int j=0; j<nBytes; j++ )
          message.bytes.push_back( packet->data[j] );
      }
      if ( packet->data[nBytes] == 0xF7 ) continueSysex = false;
      if ( !continueSysex ) {
        // If not a continuing sysex message, invoke the user callback function or queue the message.
        if ( data->usingCallback && message.bytes.size() > 0 ) {
          RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
          callback( message.timeStamp, &message.bytes, data->userData );
        }
        else {
          // As long as we haven't reached our queue size limit, push the message.
          if ( data->queueLimit > data->queue.size() )
            data->queue.push( message );
          else
            std::cerr << "\nRtMidiIn: message queue limit reached!!\n\n";
        }
        message.bytes.clear();
      }
    }
    else {
      while ( iByte < nBytes ) {
        size = 0;
        // We are expecting that the next byte in the packet is a status byte.
        status = packet->data[iByte];
        if ( !(status & 0x80) ) break;
        // Determine the number of bytes in the MIDI message.
        if ( status < 0xC0 ) size = 3;
        else if ( status < 0xE0 ) size = 2;
        else if ( status < 0xF0 ) size = 3;
        else if ( status == 0xF0 ) {
          // A MIDI sysex
          if ( data->ignoreFlags & 0x01 ) {
            size = 0;
            iByte = nBytes;
          }
          else size = nBytes - iByte;
          if ( packet->data[nBytes] == 0xF7 ) continueSysex = false;
        }
        else if ( status < 0xF3 ) {
          if ( status == 0xF1 && (data->ignoreFlags & 0x02) ) {
            // A MIDI time code message and we're ignoring it.
            size = 0;
            iByte += 3;
          }
          else size = 3;
        }
        else if ( status == 0xF3 ) size = 2;
        else if ( status == 0xF8 ) {
          size = 1;
          if ( data->ignoreFlags & 0x02 ) {
            // A MIDI timing tick message and we're ignoring it.
            size = 0;
            iByte += 3;
          }
        }
        else if ( status == 0xFE && (data->ignoreFlags & 0x04) ) {
          // A MIDI active sensing message and we're ignoring it.
          size = 0;
          iByte += 1;
        }
        else size = 1;

        // Copy the MIDI data to our vector.
        if ( size ) {
          message.bytes.assign( &packet->data[iByte], &packet->data[iByte+size] );
          if ( !continueSysex ) {
            // If not a continuing sysex message, invoke the user callback function or queue the message.
            if ( data->usingCallback ) {
              RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
              callback( message.timeStamp, &message.bytes, data->userData );
            }
            else {
              // As long as we haven't reached our queue size limit, push the message.
              if ( data->queueLimit > data->queue.size() )
                data->queue.push( message );
              else
                std::cerr << "\nRtMidiIn: message queue limit reached!!\n\n";
            }
            message.bytes.clear();
          }
          iByte += size;
        }
      }
    }
    packet = MIDIPacketNext(packet);
  }
}

void RtMidiIn :: initialize( void )
{
  // Set up our client.
  MIDIClientRef client;
  OSStatus result = MIDIClientCreate( CFSTR("FxFloorBoard Midi Input Client"), NULL, NULL, &client );
  if ( result != noErr ) {
    errorString_ = "FxFloorBoard MidiIn::initialize: error creating OS-X MIDI client object.";
    error( RtError::DRIVER_ERROR );
  }

  // Save our api-specific connection information.
  CoreMidiData *data = (CoreMidiData *) new CoreMidiData;
  data->client = client;
  data->endpoint = 0;
  apiData_ = (void *) data;
  inputData_.apiData = (void *) data;
}

void RtMidiIn :: openPort( unsigned int portNumber )
{
  if ( connected_ ) {
    errorString_ = "FxFloorBoard MidiIn::openPort: a valid connection already exists!";
    error( RtError::WARNING );
    return;
  }

  unsigned int nSrc = MIDIGetNumberOfSources();
  if (nSrc < 1) {
    errorString_ = "FxFloorBoard MidiIn::openPort: no MIDI input sources found!";
    error( RtError::NO_DEVICES_FOUND );
  }

  std::ostringstream ost;
  if ( portNumber >= nSrc ) {
    ost << "FxFloorBoard MidiIn::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }

  MIDIPortRef port;
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  OSStatus result = MIDIInputPortCreate( data->client, CFSTR("FxFloorBoard Midi MIDI Input Port"), midiInputCallback, (void *)&inputData_, &port );
  if ( result != noErr ) {
    MIDIClientDispose( data->client );
    errorString_ = "FxFloorBoard MidiIn::openPort: error creating OS-X MIDI input port.";
    error( RtError::DRIVER_ERROR );
  }

  // Get the desired input source identifier.
  MIDIEndpointRef endpoint = MIDIGetSource( portNumber );
  if ( endpoint == NULL ) {
    MIDIPortDispose( port );
    MIDIClientDispose( data->client );
    errorString_ = "FxFloorBoard MidiIn::openPort: error getting MIDI input source reference.";
    error( RtError::DRIVER_ERROR );
  }

  // Make the connection.
  result = MIDIPortConnectSource( port, endpoint, NULL );
  if ( result != noErr ) {
    MIDIPortDispose( port );
    MIDIClientDispose( data->client );
    errorString_ = "FxFloorBoard MidiIn::openPort: error connecting OS-X MIDI input port.";
    error( RtError::DRIVER_ERROR );
  }

  // Save our api-specific port information.
  data->port = port;

  connected_ = true;
}

void RtMidiIn :: openVirtualPort( const std::string portName )
{
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);

  // Create a virtual MIDI input destination.
  MIDIEndpointRef endpoint;
  OSStatus result = MIDIDestinationCreate( data->client,
                                           CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII ),
                                           midiInputCallback, (void *)&inputData_, &endpoint );
  if ( result != noErr ) {
    errorString_ = "FxFloorBoard MidiIn::openVirtualPort: error creating virtual OS-X MIDI destination.";
    error( RtError::DRIVER_ERROR );
  }

  // Save our api-specific connection information.
  data->endpoint = endpoint;
}

void RtMidiIn :: closePort( void )
{
  if ( connected_ ) {
    CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
    MIDIPortDispose( data->port );
    connected_ = false;
  }
}

RtMidiIn :: ~RtMidiIn()
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  MIDIClientDispose( data->client );
  if ( data->endpoint ) MIDIEndpointDispose( data->endpoint );
  delete data;
}

unsigned int RtMidiIn :: getPortCount()
{
  return MIDIGetNumberOfSources();
}

std::string RtMidiIn :: getPortName( unsigned int portNumber )
{
  CFStringRef nameRef;
  MIDIEndpointRef portRef;
  std::ostringstream ost;
  char name[128];

  if ( portNumber >= MIDIGetNumberOfSources() ) {
    ost << "FxFloorBoard MidiIn::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }
  portRef = MIDIGetSource( portNumber );

  MIDIObjectGetStringProperty( portRef, kMIDIPropertyName, &nameRef );
  CFStringGetCString( nameRef, name, sizeof(name), 0);
  CFRelease( nameRef );
  std::string stringName = name;
  return stringName;
}

//*********************************************************************//
//  API: OS-X
//  Class Definitions: RtMidiOut
//*********************************************************************//

unsigned int RtMidiOut :: getPortCount()
{
  return MIDIGetNumberOfDestinations();
}

std::string RtMidiOut :: getPortName( unsigned int portNumber )
{
  CFStringRef nameRef;
  MIDIEndpointRef portRef;
  std::ostringstream ost;
  char name[128];

  if ( portNumber >= MIDIGetNumberOfDestinations() ) {
    ost << "FxFloorBoard MidiOut::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }
  portRef = MIDIGetDestination( portNumber );

  MIDIObjectGetStringProperty( portRef, kMIDIPropertyName, &nameRef );
  CFStringGetCString( nameRef, name, sizeof(name), 0);
  CFRelease( nameRef );
  std::string stringName = name;
  return stringName;
}

void RtMidiOut :: initialize( void )
{
  // Set up our client.
  MIDIClientRef client;
  OSStatus result = MIDIClientCreate( CFSTR("FxFloorBoard Midi Output Client"), NULL, NULL, &client );
  if ( result != noErr ) {
    errorString_ = "FxFloorBoard MidiOut::initialize: error creating OS-X MIDI client object.";
    error( RtError::DRIVER_ERROR );
  }

  // Save our api-specific connection information.
  CoreMidiData *data = (CoreMidiData *) new CoreMidiData;
  data->client = client;
  data->endpoint = 0;
  apiData_ = (void *) data;
}

void RtMidiOut :: openPort( unsigned int portNumber )
{
  if ( connected_ ) {
    errorString_ = "FxFloorBoard MidiOut::openPort: a valid connection already exists!";
    error( RtError::WARNING );
    return;
  }

  unsigned int nDest = MIDIGetNumberOfDestinations();
  if (nDest < 1) {
    errorString_ = "FxFloorBoard MidiOut::openPort: no MIDI output destinations found!";
    error( RtError::NO_DEVICES_FOUND );
  }

  std::ostringstream ost;
  if ( portNumber >= nDest ) {
    ost << "FxFloorBoard MidiOut::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }

  MIDIPortRef port;
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  OSStatus result = MIDIOutputPortCreate( data->client, CFSTR("FxFloorBoard Midi Virtual MIDI Output Port"), &port );
  if ( result != noErr ) {
    MIDIClientDispose( data->client );
    errorString_ = "FxFloorBoard MidiOut::openPort: error creating OS-X MIDI output port.";
    error( RtError::DRIVER_ERROR );
  }

  // Get the desired output port identifier.
  MIDIEndpointRef destination = MIDIGetDestination( portNumber );
  if ( destination == NULL ) {
    MIDIPortDispose( port );
    MIDIClientDispose( data->client );
    errorString_ = "FxFloorBoard MidiOut::openPort: error getting MIDI output destination reference.";
    error( RtError::DRIVER_ERROR );
  }

  // Save our api-specific connection information.
  data->port = port;
  data->destinationId = destination;
  connected_ = true;
}

void RtMidiOut :: closePort( void )
{
  if ( connected_ ) {
    CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
    MIDIPortDispose( data->port );
    connected_ = false;
  }
}

void RtMidiOut :: openVirtualPort( std::string portName )
{
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);

  if ( data->endpoint ) {
    errorString_ = "FxFloorBoard MidiOut::openVirtualPort: a virtual output port already exists!";
    error( RtError::WARNING );
    return;
  }

  // Create a virtual MIDI output source.
  MIDIEndpointRef endpoint;
  OSStatus result = MIDISourceCreate( data->client,
                                      CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII ),
                                      &endpoint );
  if ( result != noErr ) {
    errorString_ = "FxFloorBoard MidiOut::initialize: error creating OS-X virtual MIDI source.";
    error( RtError::DRIVER_ERROR );
  }

  // Save our api-specific connection information.
  data->endpoint = endpoint;
}

RtMidiOut :: ~RtMidiOut()
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  MIDIClientDispose( data->client );
  if ( data->endpoint ) MIDIEndpointDispose( data->endpoint );
  delete data;
}

void RtMidiOut :: sendMessage( std::vector<unsigned char> *message )
{
  unsigned int nBytes = message->size();
  // Pad the buffer for extra (unknown) structure data.
  Byte buffer[nBytes+32];
  MIDIPacketList *pktlist = (MIDIPacketList *) buffer;
  MIDIPacket *curPacket = MIDIPacketListInit( pktlist );

  MIDITimeStamp timeStamp = 0;
  curPacket = MIDIPacketListAdd( pktlist, sizeof(buffer), curPacket, timeStamp, nBytes, &message->at(0) );

  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);

  // Send to any destinations that may have connected to us.
  OSStatus result;
  if ( data->endpoint ) {
    result = MIDIReceived( data->endpoint, pktlist );
    if ( result != noErr ) {
      errorString_ = "FxFloorBoard MidiOut::sendMessage: error sending MIDI to virtual destinations.";
      error( RtError::WARNING );
    }
  }

  // And send to an explicit destination port if we're connected.
  if ( connected_ ) {
    result = MIDISend( data->port, data->destinationId, pktlist );
    if ( result != noErr ) {
      errorString_ = "FxFloorBoard MidiOut::sendMessage: error sending MIDI message to port.";
      error( RtError::WARNING );
    }
  }
}

//#endif  // __MACOSX_CORE__
