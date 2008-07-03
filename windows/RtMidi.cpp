/**********************************************************************
/! \class RtMidi

**********************************************************************/

// RtMidi: Version 1.0.6

#include "RtMidi.h"
#include "midiIO.h"
#include <sstream>
#include <windows.h> // Needed to acces midi and linking against winmm.lib is also needed!!!
#include <mmsystem.h>
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
  else if (type == RtError::DeBug_WARNING) {
#if defined(__RTMIDI_DeBug__)
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
    errorString_ = "FxFloorBoard Midi Input::setCallback: a callback function is already set!";
    error( RtError::WARNING );
    return;
  }

  if ( !callback ) {
    errorString_ = "FxFloorBoard Midi Input::setCallback: callback function value is invalid!";
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
    errorString_ = "FxFloorBoard Midi Input::cancelCallback: no callback function was set!";
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
    errorString_ = "FxFloorBoard Midi Input::getNextMessage: a user callback is currently set for this port.";
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
//  API: Windows Multimedia Library (MM)
//*********************************************************************//

// API information deciphered from:
//  - http://msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_midi_reference.asp

// Thanks to Jean-Baptiste Berruchon for the sysex code.

//#if defined(__WINDOWS_MM__)

// The Windows MM API is based on the use of a callback function for
// MIDI input.  We convert the system specific time stamps to delta
// time values.

// Windows MM MIDI header files.
#include <windows.h>
#include <mmsystem.h>

// A structure to hold variables related to the CoreMIDI API
// implementation.
struct WinMidiData {
  HMIDIIN inHandle;    // Handle to Midi Input Device
  HMIDIOUT outHandle;  // Handle to Midi Output Device
  DWORD lastTime;
  RtMidiIn::MidiMessage message;
  LPMIDIHDR sysexBuffer;
};

#define  RT_SYSEX_BUFFER_SIZE 1024

//*********************************************************************//
//  API: Windows MM
//  Class Definitions: RtMidiIn
//*********************************************************************//

static void CALLBACK midiInputCallback( HMIDIOUT hmin,
                                        UINT inputStatus, 
                                        DWORD instancePtr,
                                        DWORD midiMessage,
                                        DWORD timestamp )
{
  if ( inputStatus != MIM_DATA && inputStatus != MIM_LONGDATA ) return;

  //RtMidiIn::RtMidiInData *data = static_cast<RtMidiIn::RtMidiInData *> (instancePtr);
  RtMidiIn::RtMidiInData *data = (RtMidiIn::RtMidiInData *)instancePtr;
  WinMidiData *apiData = static_cast<WinMidiData *> (data->apiData);

  // Calculate time stamp.
  apiData->message.timeStamp = 0.0;
  if ( data->firstMessage == true ) data->firstMessage = false;
  else apiData->message.timeStamp = (double) ( timestamp - apiData->lastTime ) * 0.001;
  apiData->lastTime = timestamp;

  if ( inputStatus == MIM_DATA ) { // Channel or system message

    // Make sure the first byte is a status byte.
    unsigned char status = (unsigned char) (midiMessage & 0x000000FF);
    if ( !(status & 0x80) ) return;

    // Determine the number of bytes in the MIDI message.
    unsigned short nBytes = 1;
    if ( status < 0xC0 ) nBytes = 3;
    else if ( status < 0xE0 ) nBytes = 2;
    else if ( status < 0xF0 ) nBytes = 3;
    else if ( status < 0xF3 ) {
      // A MIDI time code message and we're ignoring it.
      if ( status == 0xF1 && (data->ignoreFlags & 0x02) ) return;
      nBytes = 3;
    }
    else if ( status == 0xF3 ) nBytes = 2;
    else if ( status == 0xF8 && (data->ignoreFlags & 0x02) ) {
      // A MIDI timing tick message and we're ignoring it.
      return;
    }
    else if ( status == 0xFE && (data->ignoreFlags & 0x04) ) {
      // A MIDI active sensing message and we're ignoring it.
      return;
    }

    // Copy bytes to our MIDI message.
    unsigned char *ptr = (unsigned char *) &midiMessage;
    for ( int i=0; i<nBytes; i++ ) apiData->message.bytes.push_back( *ptr++ );
  }
  else if ( !(data->ignoreFlags & 0x01) ) {
    // Sysex message and we're not ignoring it
    MIDIHDR *sysex = ( MIDIHDR *) midiMessage;
    for ( int i=0; i<(int)sysex->dwBytesRecorded; i++ )
      apiData->message.bytes.push_back( sysex->lpData[i] );

    // When the callback has to be unaffected (application closes), 
    // it seems WinMM calls it with an empty sysex to de-queue the buffer
    // If the buffer is requeued afer that message, the PC suddenly reboots
    // after one or two minutes (JB).
    if ( apiData->sysexBuffer->dwBytesRecorded > 0 ) {
      MMRESULT result = midiInAddBuffer( apiData->inHandle, apiData->sysexBuffer, sizeof(MIDIHDR) );
      if ( result != MMSYSERR_NOERROR )
        std::cerr << "\nFxFloorBoard Midi Input::midiInputCallback: error sending sysex to Midi device!!\n\n";
    }
  }

  if ( data->usingCallback ) {
    RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
    callback( apiData->message.timeStamp, &apiData->message.bytes, data->userData );
  }
  else {
    // As long as we haven't reached our queue size limit, push the message.
    if ( data->queueLimit > data->queue.size() )
      data->queue.push( apiData->message );
    else
      std::cerr << "\nFxFloorBoard Midi Input: message queue limit reached!!\n\n";
  }

  // Clear the vector for the next input message.  Note that doing
  // this here allows our code to work for sysex messages which are
  // segmented across multiple buffers.
  apiData->message.bytes.clear();
}

void RtMidiIn :: initialize( void )
{
  // We'll issue a warning here if no devices are available but not
  // throw an error since the user can plugin something later.
  unsigned int nDevices = midiInGetNumDevs();
  if ( nDevices == 0 ) {
    errorString_ = "FxFloorBoard Midi Input::initialize: no MIDI input devices currently available.";
    error( RtError::WARNING );
  }

  // Save our api-specific connection information.
  WinMidiData *data = (WinMidiData *) new WinMidiData;
  apiData_ = (void *) data;
  inputData_.apiData = (void *) data;
  data->message.bytes.clear();  // needs to be empty for first input message
}

void RtMidiIn :: openPort( unsigned int portNumber )
{
  if ( connected_ ) {
    errorString_ = "FxFloorBoard Midi Input::openPort: a valid connection already exists!";
    error( RtError::WARNING );
    return;
  }

  unsigned int nDevices = midiInGetNumDevs();
  if (nDevices == 0) {
    errorString_ = "FxFloorBoard Midi Input::openPort: no MIDI input sources found!";
    error( RtError::NO_DEVICES_FOUND );
  }

  std::ostringstream ost;
  if ( portNumber >= nDevices ) {
    ost << "FxFloorBoard Midi Input::openPort: the midi device listed at 'portNumber'(" << portNumber << ") is missing.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }

  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  MMRESULT result = midiInOpen( &data->inHandle,
                                portNumber,
                                (DWORD)&midiInputCallback,
                                (DWORD)&inputData_,
                                CALLBACK_FUNCTION );
  if ( result != MMSYSERR_NOERROR ) {
    errorString_ = "FxFloorBoard Midi Input::openPort: error creating Windows MM MIDI input port.";
    error( RtError::DRIVER_ERROR );
  }

  // Allocate and init the sysex buffer.
  data->sysexBuffer = (MIDIHDR*) new char[ sizeof(MIDIHDR) ];
  data->sysexBuffer->lpData = new char[1024];
  data->sysexBuffer->dwBufferLength = 1024;
  data->sysexBuffer->dwFlags = 0;

  result = midiInPrepareHeader( data->inHandle, data->sysexBuffer, sizeof(MIDIHDR) );
  if ( result != MMSYSERR_NOERROR ) {
    midiInClose( data->inHandle );
    errorString_ = "FxFloorBoard Midi Input::openPort: error starting Windows MM MIDI input port (PrepareHeader).";
    error( RtError::DRIVER_ERROR );
  }

  // Register the buffer.
  result = midiInAddBuffer( data->inHandle, data->sysexBuffer, sizeof(MIDIHDR) );
  if ( result != MMSYSERR_NOERROR ) {
    midiInClose( data->inHandle );
    errorString_ = "FxFloorBoard Midi Input::openPort: error starting Windows MM MIDI input port (AddBuffer).";
    error( RtError::DRIVER_ERROR );
  }

  result = midiInStart( data->inHandle );
  if ( result != MMSYSERR_NOERROR ) {
    midiInClose( data->inHandle );
    errorString_ = "FxFloorBoard Midi Input::openPort: error starting Windows MM MIDI input port.";
    error( RtError::DRIVER_ERROR );
  }

  connected_ = true;
}

void RtMidiIn :: openVirtualPort( std::string portName )
{
  // This function cannot be implemented for the Windows MM MIDI API.
  errorString_ = "FxFloorBoard Midi Input::openVirtualPort: cannot be implemented in Windows MM MIDI API!";
  error( RtError::WARNING );
}

void RtMidiIn :: closePort( void )
{
  if ( connected_ ) {
    WinMidiData *data = static_cast<WinMidiData *> (apiData_);
    midiInReset( data->inHandle );
    midiInStop( data->inHandle );

    int result = midiInUnprepareHeader(data->inHandle, data->sysexBuffer, sizeof(MIDIHDR));
    delete [] data->sysexBuffer->lpData;
    delete [] data->sysexBuffer;
    if ( result != MMSYSERR_NOERROR ) {
      midiInClose( data->inHandle );
      errorString_ = "FxFloorBoard Midi Input::openPort: error closing Windows MM MIDI input port (midiInUnprepareHeader).";
      error( RtError::DRIVER_ERROR );
    }

    midiInClose( data->inHandle );
    connected_ = false;
  }
}

RtMidiIn :: ~RtMidiIn()
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  delete data;
}

unsigned int RtMidiIn :: getPortCount()
{
   return midiInGetNumDevs();
}

std::string RtMidiIn :: getPortName( unsigned int portNumber )
{
  unsigned int nDevices = midiInGetNumDevs();
  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "FxFloorBoard Midi Input::getPortName: the midi device listed at 'portNumber'(" << portNumber << ") is missing.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }

  MIDIINCAPS deviceCaps;
  MMRESULT result = midiInGetDevCaps( portNumber, &deviceCaps, sizeof(MIDIINCAPS));

  // For some reason, we need to copy character by character with
  // UNICODE (thanks to Eduardo Coutinho!).
  //std::string stringName = std::string( deviceCaps.szPname );
  char nameString[MAXPNAMELEN];
  for( int i=0; i<MAXPNAMELEN; i++ )
    nameString[i] = (char)( deviceCaps.szPname[i] );

  std::string stringName( nameString );
  return stringName;
}

//*********************************************************************//
//  API: Windows MM
//  Class Definitions: RtMidiOut
//*********************************************************************//

unsigned int RtMidiOut :: getPortCount()
{
  return midiOutGetNumDevs();
}

std::string RtMidiOut :: getPortName( unsigned int portNumber )
{
  unsigned int nDevices = midiOutGetNumDevs();
  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "FxFloorBoard Midi Output: the midi device listed at 'portNumber'(" << portNumber << ") is missing.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }

  MIDIOUTCAPS deviceCaps;
  MMRESULT result = midiOutGetDevCaps( portNumber, &deviceCaps, sizeof(MIDIOUTCAPS));

  // For some reason, we need to copy character by character with
  // UNICODE (thanks to Eduardo Coutinho!).
  //std::string stringName = std::string( deviceCaps.szPname );
  char nameString[MAXPNAMELEN];
  for( int i=0; i<MAXPNAMELEN; i++ )
    nameString[i] = (char)( deviceCaps.szPname[i] );

  std::string stringName( nameString );
  return stringName;
}

void RtMidiOut :: initialize( void )
{
  // We'll issue a warning here if no devices are available but not
  // throw an error since the user can plug something in later.
  unsigned int nDevices = midiOutGetNumDevs();
  if ( nDevices == 0 ) {
    errorString_ = "FxFloorBoard Midi Output::initialize: no MIDI output devices currently available.";
    error( RtError::WARNING );
  }

  // Save our api-specific connection information.
  WinMidiData *data = (WinMidiData *) new WinMidiData;
  apiData_ = (void *) data;
}

void RtMidiOut :: openPort( unsigned int portNumber )
{
  if ( connected_ ) {
    errorString_ = "FxFloorBoard Midi Output::openPort: a valid connection already exists!";
    error( RtError::WARNING );
    return;
  }

  unsigned int nDevices = midiOutGetNumDevs();
  if (nDevices < 1) {
    errorString_ = "FxFloorBoard Midi Output::openPort: no MIDI output destinations found!";
    error( RtError::NO_DEVICES_FOUND );
  }

  std::ostringstream ost;
  if ( portNumber >= nDevices ) {
    ost << "FxFloorBoard Midi Output::openPort: the midi device listed at 'portNumber'(" << portNumber << ") is missing.";
    errorString_ = ost.str();
    error( RtError::INVALID_PARAMETER );
  }

  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  MMRESULT result = midiOutOpen( &data->outHandle,
                                 portNumber,
                                 (DWORD)NULL,
                                 (DWORD)NULL,
                                 CALLBACK_NULL );
  if ( result != MMSYSERR_NOERROR ) {
    errorString_ = "FxFloorBoard Midi Output::openPort: error creating Windows MM MIDI output port.";
    error( RtError::DRIVER_ERROR );
  }

  connected_ = true;
}

void RtMidiOut :: closePort( void )
{
  if ( connected_ ) {
    WinMidiData *data = static_cast<WinMidiData *> (apiData_);
    midiOutReset( data->outHandle );
    midiOutClose( data->outHandle );
    connected_ = false;
  }
}

void RtMidiOut :: openVirtualPort( std::string portName )
{
  // This function cannot be implemented for the Windows MM MIDI API.
  errorString_ = "FxFloorBoard Midi Output::openVirtualPort: cannot be implemented in Windows MM MIDI API!";
  error( RtError::WARNING );
}

RtMidiOut :: ~RtMidiOut()
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  delete data;
}

void RtMidiOut :: sendMessage( std::vector<unsigned char> *message )
{
  unsigned int nBytes = message->size();
  if ( nBytes == 0 ) {
    errorString_ = "FxFloorBoard Midi Output::sendMessage: message argument is empty!";
    error( RtError::WARNING );
    return;
  }

  MMRESULT result;
  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  if ( message->at(0) == 0xF0 ) { // Sysex message

    // Allocate buffer for sysex data.
    char *buffer = (char *) malloc( nBytes );
    if ( buffer == NULL ) {
      errorString_ = "FxFloorBoard Midi Output::sendMessage: error allocating sysex message memory!";
      error( RtError::MEMORY_ERROR );
    }

    // Copy data to buffer.
    for ( unsigned int i=0; i<nBytes; i++ ) buffer[i] = message->at(i);

    // Create and prepare MIDIHDR structure.
    MIDIHDR sysex;
    sysex.lpData = (LPSTR) buffer;
    sysex.dwBufferLength = nBytes;
    sysex.dwFlags = 0;
    result = midiOutPrepareHeader( data->outHandle,  &sysex, sizeof(MIDIHDR) ); 
    if ( result != MMSYSERR_NOERROR ) {
      free( buffer );
      errorString_ = "FxFloorBoard Midi Output::sendMessage: error preparing sysex header.";
      error( RtError::DRIVER_ERROR );
    }

    // Send the message.
    result = midiOutLongMsg( data->outHandle, &sysex, sizeof(MIDIHDR) );
    if ( result != MMSYSERR_NOERROR ) {
      free( buffer );
      errorString_ = "FxFloorBoard Midi Output::sendMessage: error sending sysex message.";
      error( RtError::DRIVER_ERROR );
    }

    // Unprepare the buffer and MIDIHDR.
    while ( MIDIERR_STILLPLAYING == midiOutUnprepareHeader( data->outHandle, &sysex, sizeof (MIDIHDR) ) ) Sleep( 1 );
    free( buffer );

  }
  else { // Channel or system message.

    // Make sure the message size isn't too big.
    if ( nBytes > 3 ) {
      errorString_ = "FxFloorBoard Midi Output::sendMessage: message size is greater than 3 bytes (and not sysex)!";
      error( RtError::WARNING );
      return;
    } 

    // Pack MIDI bytes into double word.
    DWORD packet;
    unsigned char *ptr = (unsigned char *) &packet;
    for ( unsigned int i=0; i<nBytes; i++ ) {
      *ptr = message->at(i);
      ptr++;
    }

    // Send the message immediately.
    result = midiOutShortMsg( data->outHandle, packet );
    if ( result != MMSYSERR_NOERROR ) {
      errorString_ = "FxFloorBoard Midi Output::sendMessage: error sending MIDI message.";
      error( RtError::DRIVER_ERROR );
    }
  }
}

//#endif  // __WINDOWS_MM__
