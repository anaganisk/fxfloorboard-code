/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-8 Fx FloorBoard".
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along
** with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**
****************************************************************************/
#include <QMessageBox>
#include "midiIO.h"
#include "RtMidi.h"
#include "../SysxIO.h"
#include "../globalVariables.h"

unsigned char midiIO::SysXBuffer[256];
unsigned char midiIO::SysXFlag = 0;
int midiIO::count = 0;
bool midiIO::dataReceive = false;
QString midiIO::sysxBuffer;

midiIO::midiIO()
{
	SysxIO *sysxIO = SysxIO::Instance();
	QObject::connect(this, SIGNAL(setStatusSymbol(int)),
                sysxIO, SIGNAL(setStatusSymbol(int)));
	QObject::connect(this, SIGNAL(setStatusProgress(int)),
                sysxIO, SIGNAL(setStatusProgress(int)));
	QObject::connect(this, SIGNAL(setStatusMessage(QString)),
                sysxIO, SIGNAL(setStatusMessage(QString)));
	QObject::connect(this, SIGNAL(errorSignal(QString, QString)),
                sysxIO, SLOT(errorSignal(QString, QString)));

	QObject::connect(this, SIGNAL(replyMsg(QString)),
		sysxIO, SLOT(receiveSysx(QString)));
	QObject::connect(this, SIGNAL(midiFinished()),	
			sysxIO, SLOT(finishedSending()));
};

/*********************** queryMidiOutDevices() *****************************
 * Retrieves all MIDI Out devices installed on your system and stores them 
 * as a QList of QStrings and device id's. 
 *************************************************************************/
void midiIO::queryMidiOutDevices()
{
    RtMidiOut *midiout = 0;
  // RtMidiOut constructor
  try {
    midiout = new RtMidiOut();
  }
  catch (RtError &error) {
    error.printMessage();
    exit(EXIT_FAILURE);
  }

  // Check outputs.
  std::string portName;
  unsigned int nPorts = midiout->getPortCount();
  for ( unsigned int i=0; i<nPorts; i++ ) {
    try {
      portName = midiout->getPortName(i);
    }
    catch (RtError &error) {
      error.printMessage();
      goto cleanup;
    }
    this->midiOutDevices.append(QString::fromStdString(portName));
  } 
 // Clean up
 cleanup:
  delete midiout;
};

QList<QString> midiIO::getMidiOutDevices()
{
	queryMidiOutDevices();
	return this->midiOutDevices;
};

/*********************** queryMidiInDevices() ******************************
 * Retrieves all MIDI In devices installed on your system and stores them 
 * as a QList of QStrings and device id's. 
 *************************************************************************/
void midiIO::queryMidiInDevices()
{
	 RtMidiIn *midiin = 0;
  // RtMidiIn constructor
  try {
    midiin = new RtMidiIn();
  }
  catch (RtError &error) {
    error.printMessage();
    exit(EXIT_FAILURE);
  }
  // Check inputs.
  std::string portName;
  unsigned int nPorts = midiin->getPortCount();
  for ( unsigned int i=0; i<nPorts; i++ ) {
    try {
      portName = midiin->getPortName(i);
    }
    catch (RtError &error) {
      error.printMessage();
      goto cleanup;
    }
    this->midiInDevices.append(QString::fromStdString(portName));
  } 
 // Clean up
 cleanup:
  delete midiin;
};

QList<QString> midiIO::getMidiInDevices()
{
	queryMidiInDevices();
	return this->midiInDevices;
};

/************************* getMidiOutErrorMsg() **************************
 * Retrieves and displays an error message for the passed MIDI Out error
 * number. It does this using midiOutGetErrorText().
 *************************************************************************/
QString midiIO::getMidiOutErrorMsg(unsigned long err)
{
	/*#define BUFFERSIZE 200
	WCHAR	errMsg[BUFFERSIZE];*/
	QString errorMsg;
	
	/*if (!(err = midiOutGetErrorText(err, &errMsg[0], BUFFERSIZE)))
	{
		errorMsg = QString::fromWCharArray(errMsg);
	}
	else if (err == MMSYSERR_BADERRNUM)
	{
		errorMsg = tr("Strange error number returned!");
	}
	else 
	{
		errorMsg = tr("Specified pointer is invalid!");
	};

	this->dataReceive = false;*/
	return errorMsg;
};

/************************* getMidiInErrorMsg() ***************************
 * Retrieves and displays an error message for the passed MIDI In error
 * number. It does this using midiInGetErrorText().
 *************************************************************************/
QString midiIO::getMidiInErrorMsg(unsigned long err)
{
	/*#define BUFFERSIZE 200
	WCHAR	errMsg[BUFFERSIZE];*/
	QString errorMsg;
	
	/*if (!(err = midiOutGetErrorText(err, &errMsg[0], BUFFERSIZE)))
	{
		errorMsg = QString::fromWCharArray(errMsg);
	}
	else if (err == MMSYSERR_BADERRNUM)
	{
		errorMsg = tr("Strange error number returned!");
	}
	else if (err == MMSYSERR_INVALPARAM) 
	{
		errorMsg = tr("Specified pointer is invalid!");
	}
	else 
	{
		errorMsg = tr("Unable to allocate/lock memory!");
	};*/

	return errorMsg;
};

/*********************** sendMsg() **********************************
 * Prepares the sysx message before sending on the MIDI Out device. It 
 * converts the message from a QString to a char* and opens, sends 
 * and closes the MIDI device.
 *************************************************************************/
void midiIO::sendMsg(QString sysxOutMsg, int midiOutPort)
{	
	emit setStatusProgress(80);
	 RtMidiOut *midiMsgOut = new RtMidiOut(); 
  // Check available ports.
  unsigned int nPorts = midiMsgOut->getPortCount();
  if ( nPorts == 0 ) {
   // std::cout << "No ports available!\n";
    goto cleanup;
 }
  try {
        // Open selected port.
        midiMsgOut->openPort(midiOutPort);
	    // Convert QString to char* (hex value) 
 
		std::vector<unsigned char> message;	
        message.reserve(256);
		int msgLength = sysxOutMsg.length()/2;
		char *ptr  = new char[msgLength];
		
		for(int i=0;i<sysxOutMsg.length();++i)
		{	
		    unsigned int n;
			QString hex = "0x";
			hex.append(sysxOutMsg.mid(i, 2));
			bool ok;
			n = hex.toInt(&ok, 16);
			*ptr = (char)n;
			message.push_back(*ptr);			
			ptr++; i++;	
		};
	midiMsgOut->sendMessage(&message);
	
	goto cleanup;
     }
catch (RtError &error) {
	  //error.printMessage();
	  goto cleanup;
    }
    
   // Clean up
 cleanup:
	//midiMsgOut->closePort();
	Sleep(midiTimeout); 
    delete midiMsgOut;
	emit setStatusProgress(100);
	emit midiFinished();
};

/*********************** midiCallback() **********************************
 * Processes the sysex message and handles if yes or no it has to start  
 * receiving a reply on the MIDI In device midiIn. If so it will begin
 * receiving the incoming sysex message.
 *************************************************************************/
//void CALLBACK midiIO::midiCallback()//HMIDIIN handle, UINT wMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
//{
	
void usage(void) {
  // Error function in case of incorrect command-line
  // argument specifications.
  std::cout << "\nuseage: cmidiin <port>\n";
  std::cout << "    where port = the device to use (default = 0).\n\n";
  exit(0);
}

void mycallback( double deltatime, std::vector< unsigned char > *message, void *userData )
{
  unsigned int nBytes = message->size();
  for ( unsigned int i=0; i<nBytes; i++ )
    std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  if ( nBytes > 0 )
    std::cout << "stamp = " << deltatime << '\n';
}

void midiindata(std::vector< unsigned char > *message, int midiInPort)
{
  RtMidiIn *midiin = new RtMidiIn(); 
  // Check available ports.
  unsigned int nPorts = midiin->getPortCount();
  if ( nPorts == 0 ) {
   // std::cout << "No ports available!\n";
    goto cleanup;
 }
  try {
        // Open selected port.
        midiin->openPort(midiInPort);
  }
  catch (RtError &error) {
    error.printMessage();
    goto cleanup;
  }

  // Set our callback function.  This should be done immediately after
  // opening the port to avoid having incoming messages written to the
  // queue instead of sent to the callback function.
  midiin->setCallback( &mycallback );

  // Don't ignore sysex, timing, or active sensing messages.
  midiin->ignoreTypes( true, false, false );

  std::cout << "\nReading MIDI input ... press <enter> to quit.\n";
  char input;
  std::cin.get(input);

  // Clean up
 cleanup:
  delete midiin;


//LPMIDIHDR		lpMIDIHeader;
//	unsigned char *	ptr;
//
//	/* Determine why Windows called me */
//	switch (wMsg)
//	{
//		/* Received all or part of some System Exclusive message */	
//		case MIM_LONGDATA:
//		{
//			/* If this application is ready to close down, then don't midiInAddBuffer() again */
//			if (!(SysXFlag & 0x80))
//			{
//				/*	Assign address of MIDIHDR to a LPMIDIHDR variable. Makes it easier to access the
//					field that contains the pointer to our block of MIDI events */
//				lpMIDIHeader = (LPMIDIHDR)dwParam1;
//
//				/* Get address of the MIDI event that caused this call */
//				ptr = (unsigned char *)(lpMIDIHeader->lpData);
//
//				/* Is this the first block of System Exclusive bytes? */
//				if (!SysXFlag)
//				{
//					dataReceive = true;
//					count = 0;
//
//					/* Print out a noticeable heading as well as the timestamp of the first block.
//						(But note that other, subsequent blocks will have their own time stamps). */
//					//printf("*************** System Exclusive ************** 0x%08X\r\n", dwParam2);
//
//					/* Indicate we've begun handling a particular System Exclusive message */
//					SysXFlag |= 0x01;
//				};
//
//				/* Is this the last block (ie, the end of System Exclusive byte is here in the buffer)? */
//				if (*(ptr + (lpMIDIHeader->dwBytesRecorded - 1)) == 0xF7)
//				{
//					/* Indicate we're done handling this particular System Exclusive message */
//					SysXFlag &= (~0x01);
//				};
//				QString tmp;
//				while((lpMIDIHeader->dwBytesRecorded--))
//				{
//					//printf("%x ", *ptr);
//					unsigned int n = (int)*ptr;
//					QString hex = QString::number(n, 16).toUpper();
//					if (hex.length() < 2) hex.prepend("0");
//					sysxBuffer.append(hex);
//					tmp.append(hex);
//					tmp.append(" ");
//					ptr++;
//				}
//
//				/* Was this the last block of System Exclusive bytes? */
//				if (!SysXFlag)
//				{
//					//					dataReceive = false;
//				};
//
//				/* Queue the MIDIHDR for more input */
//				midiInAddBuffer(handle, lpMIDIHeader, sizeof(MIDIHDR));
//			};
//			break;
//		};
 // }
};

/**************************** run() **************************************
 * New QThread that processes the sysex message and handles if yes or no 
 * it has to start receiving a reply on the MIDI In device midiIn. If so 
 * midiCallback() will handle the receive of the incomming sysex message.
 *************************************************************************/
void midiIO::run()
{
	this->SysXFlag = 0;
    this->count = 0;
    this->dataReceive = false;
    this->sysxBuffer = "";
	this->sysxInMsg = "";

	// Check if we are going to receive something or are sending 
	bool receive;
	(this->sysxOutMsg.mid(12, 2) != "12")? receive = true: receive = false;

	if(receive==true)
	{
	//	HMIDIIN			inHandle;
	//	MIDIHDR			midiHdr;
	//	unsigned long	err;

		/* Open default MIDI In device */
	//	if (!(err = midiInOpen(&inHandle, midiIn, (DWORD)midiCallback, 0, CALLBACK_FUNCTION)))
	//	{
			/* Store pointer to our input buffer for System Exclusive messages in MIDIHDR */
	//		midiHdr.lpData = (LPSTR)&SysXBuffer[0];

			/* Store its size in the MIDIHDR */
	//		midiHdr.dwBufferLength = sizeof(SysXBuffer);

			/* Flags must be set to 0 */
	//		midiHdr.dwFlags = 0;
	//		
			/* Prepare the buffer and MIDIHDR */
	//		err = midiInPrepareHeader(inHandle, &midiHdr, sizeof(MIDIHDR));
	//		if (!err)
	//		{
				/* Queue MIDI input buffer */
	//			err = midiInAddBuffer(inHandle, &midiHdr, sizeof(MIDIHDR));
	//			if (!err)
	//			{
					/* Start recording Midi */
	//				err = midiInStart(inHandle);
	//				if (!err)
	//				{
	//					//printf("Recording started...\r\n");
	//					dataReceive = true;
	//					sendMsg(sysxOutMsg, midiOut);
	//					count=0;
	//					if(multiple)
	//					{
	//						/* Make the loop wait a bit more for the rest
	//						due to the crapy midi api of windows */
	//						while(dataReceive || count < maxWait)
	//						{
	//							//printf("Waiting for data.... \r\n");
	//							Sleep(receiveTimeout);
	//							count++;
	//						};
	//					}
	//					else
	//					{
	//						while(dataReceive && count < minWait) // count is in case we get stuck
	//						{
	//							//printf("Waiting for data.... \r\n");
	//							Sleep(receiveTimeout);
	//							count++;
	//						};
	//					};

	//					/* We need to set a flag to tell our callback midiCallback()
	//					   not to do any more midiInAddBuffer(), because when we
	//					   call midiInReset() below, Windows will send a final
	//					   MIM_LONGDATA message to that callback. If we were to
	//					   allow midiCallback() to midiInAddBuffer() again, we'd
	//					   never get the driver to finish with our midiHdr
	//					*/
	//					SysXFlag |= 0x80;
	//					//printf("Recording stopped!\r\n\r\n");
	//					sysxInMsg = sysxBuffer.toUpper();
	//				};

	//				/* Stop recording */
	//				midiInReset(inHandle);
	//			};
	//		};

			/* If there was an error above, then print a message */
	//		if (err) 
	//		{
	//			QString errorMsg;
	//			errorMsg.append("<font size='+1'><b>");
	//			errorMsg.append(tr("Midi Input Error!"));
	//			errorMsg.append("<b></font><br>");
	//			errorMsg.append(getMidiInErrorMsg(err));
	//			showErrorMsg(errorMsg, "in");
	//		};
	//		
			/* Close the MIDI In device */
	//		while ((err = midiInClose(inHandle)) == MIDIERR_STILLPLAYING) 
	//		{
	//			Sleep(0);
	//		};

	//		if (err) 
	//		{
	//			QString errorMsg;
	//			errorMsg.append("<font size='+1'><b>");
	//			errorMsg.append(tr("Midi Input Error!"));
	//			errorMsg.append("<b></font><br>");
	//			errorMsg.append(getMidiInErrorMsg(err));
	//			showErrorMsg(errorMsg, "in");
	//		};
	//		
			/* Unprepare the buffer and MIDIHDR. Unpreparing a buffer that has not been prepared is ok */
	//		midiInUnprepareHeader(inHandle, &midiHdr, sizeof(MIDIHDR));
	//	}
	//	else
	//	{
	//		QString errorMsg;
	//		errorMsg.append("<font size='+1'><b>");
	//		errorMsg.append(tr("Error opening default MIDI In device!"));
	//		errorMsg.append("<b></font><br>");
	//		errorMsg.append(getMidiInErrorMsg(err));
	//		showErrorMsg(errorMsg, "in");
	//	};
	}
	else
	{
		sendMsg(sysxOutMsg, midiOutPort);
	};
	
	this->sysxInMsg = sysxInMsg;
	emit replyMsg(sysxInMsg);

	this->exec();
};

/*********************** sendSysxMsg() ***********************************
 * Starts a new thread that handles the send and receive of sysex messages.
 *************************************************************************/
void midiIO::sendSysxMsg(QString sysxOutMsg, int midiOutPort, int midiInPort)
{	
	this->sysxOutMsg = sysxOutMsg.simplified().toUpper().remove("0X").remove(" ");
	this->multiple = false;
	if(sysxOutMsg.size() == 32 && sysxOutMsg.mid(sysxOutMsg.size()-6, 2) != "00")
	{
		this->multiple = true;
	};
	this->midiOutPort = midiOutPort;
	this->midiInPort = midiInPort;
     sendMsg(sysxOutMsg, midiOutPort);
	start();
};

/*********************** showErrorMsg() **********************************
 * Formats the error message received by the midi-in or midi-out device 
 * and outputs a warning text box to the user.
 *************************************************************************/
void midiIO::showErrorMsg(QString errorMsg, QString type)
{
	QString windowTitle;
	if(type == "out")
	{
		windowTitle = tr("GT-8 Fx FloorBoard - Midi Output Error");
	}
	else if(type == "in")
	{
		windowTitle = tr("GT-8 Fx FloorBoard - Midi Input Error");
	};
	windowTitle = tr("GT-8 Fx FloorBoard");

	emit errorSignal(windowTitle, errorMsg);
};

/*********************** sendMidi() **********************************
 * Send a midi command to the midi-out device. This is used to change 
 * the current patch displayed.
 *************************************************************************/
void midiIO::sendMidi(QString midiMsg, int midiOutPort)
{	
	emit setStatusProgress(100);
	 RtMidiOut *midiMsgout = new RtMidiOut(); 
  // Check available ports.
  unsigned int nPorts = midiMsgout->getPortCount();
  if ( nPorts == 0 ) {
   // std::cout << "No ports available!\n";
    goto cleanup;
 }
  try {
        // Open selected port.
        midiMsgout->openPort(midiOutPort);
	    // Convert QString to char* (hex value) 
		int msgLength = midiMsg.length()/2;
		std::vector<unsigned char> message;	
        message.reserve(256);
		char *ptr = new char[msgLength];
		for(int i=0;i<midiMsg.length();i++)
		{	
			unsigned int n;
			QString hex = "0x";
			hex.append(midiMsg.mid(i, 2));
			bool ok;
			n = hex.toInt(&ok, 16);
			*ptr = (char)n;
			message.push_back(*ptr);			
			i++; ptr++;		
		};
		
	midiMsgout->sendMessage(&message);
	Sleep(midiTimeout); 
	//midiMsgout->closePort();
    }
    catch (RtError &error) {
      error.printMessage();
      goto cleanup;
    }
   // Clean up
 cleanup:
	midiMsgout->closePort();
    delete midiMsgout;
	emit setStatusProgress(100);
	emit midiFinished();
};


