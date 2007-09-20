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

#include "midiIO.h"
#include "../SysxIO.h"
#include "../globalVariables.h"
#include "RtMidi.h"
#include <QMessageBox>
#include <signal.h>
#include <QSysInfo>
#include <QTextCodec>

unsigned char midiIO::SysXBuffer[256];
unsigned char midiIO::SysXFlag = 0;
int midiIO::bytesTotal = 0;
int midiIO::count = 0;
int loopCount;
bool midiIO::dataReceive = false;
QString midiIO::sysxBuffer;
bool done;
static void finish (int ignore) { done = true; }

// Platform-dependent sleep routines.
#ifdef Q_OS_WIN
  #include <windows.h>
  #define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants
  #include <unistd.h>
  #define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

midiIO::midiIO()
{
	this->midi = false; // Set this to false;

	/* Connect signals */
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
	// if we are running msdos based windows, names convert to unicode
    if(QSysInfo::WindowsVersion <= QSysInfo::WV_Me) 
	{
		char dev = char(i+49);
		QString outstring = ("un-named midi device: ");
		outstring.append(dev);
		this->midiOutDevices.append(outstring);
	}
	else
	{
    this->midiOutDevices.append(QString::fromStdString(portName));
	}
  } 
  if (nPorts == 0) {
	  this->midiOutDevices.push_back("no midi device available");
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
    catch (RtError &error) 
	{
      error.printMessage();
      goto cleanup;
    }
  if(QSysInfo::WindowsVersion <= QSysInfo::WV_Me) 
	{
		char dev = char(i+49);
		QString instring = ("un-named midi device: ");
		instring.append(dev);
		this->midiInDevices.append(instring);
	}
  else
	{
    this->midiInDevices.append(QString::fromStdString(portName));
	} 
  }
  if (nPorts == 0) 
	{
	  this->midiInDevices.push_back("no midi device available");
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
{/*
	#define BUFFERSIZE 200
	WCHAR	errMsg[BUFFERSIZE];
	QString errorMsg;
	
	if (!(err = midiOutGetErrorText(err, &errMsg[0], BUFFERSIZE)))
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
	return 0;
};

/************************* getMidiInErrorMsg() ***************************
 * Retrieves and displays an error message for the passed MIDI In error
 * number. It does this using midiInGetErrorText().
 *************************************************************************/
QString midiIO::getMidiInErrorMsg(unsigned long err)
{/*
	#define BUFFERSIZE 200
	WCHAR	errMsg[BUFFERSIZE];
	QString errorMsg;
	
	if (!(err = midiOutGetErrorText(err, &errMsg[0], BUFFERSIZE)))
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
	};
*/
	return 0;
};

/*********************** sendMsg() **********************************
 * Prepares the sysx message before sending on the MIDI Out device. It 
 * converts the message from a QString to a std::vector and opens, sends 
 * and closes the MIDI device.
 *************************************************************************/
void midiIO::sendMsg(QString sysxOutMsg, int midiOutPort)
{
		emit setStatusProgress(100);
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
        message.reserve(1024);
		int msgLength = sysxOutMsg.length()/2;
		char *ptr  = new char[msgLength];
		
		for(int i=0;i<msgLength*2;++i)
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
catch (RtError &error)
   {
	  error.printMessage();
	  goto cleanup;
    }   
   // Clean up
 cleanup:
	//emit setStatusProgress(100);
	int msgLength = sysxOutMsg.length()/2;
		SLEEP(msgLength);
	midiMsgOut->closePort();
    delete midiMsgOut;	
	emit midiFinished();
};

/*********************** receiveMsg() **********************************
 * Prepares the sysx message after receiving on the MIDI In device. It 
 *  and opens, receives and closes the MIDI device then converts the 
 *  message from a std::vector to a QString.
 *************************************************************************/
void midiIO::receiveMsg(QString sysxInMsg, int midiInPort)
{
	QString tmp = ""; 
	int n;
	int bytesReceived = 0;
		RtMidiIn *midiin = 0;
		std::vector<unsigned char> message;
		message.reserve(1024);
		int nBytes, i;
		double stamp;
		//RtMidi constructor
		try {
			midiin = new RtMidiIn();
		}
		catch (RtError &error) {
			//error.printMessage();
			exit (EXIT_FAILURE);
		}
		try {
			midiin->openPort(midiInPort);
		}
		catch (RtError &error) {
			//error.printMessage();
			goto cleanup;
		}
		if(this->multiple = true){loopCount = maxWait;}
		else {loopCount = minWait;};
		//don,t ignore sysex messages, but ignore other crap
		midiin->ignoreTypes(false, true, true);
		//install interupt handler
		done = false;
		(void) signal(SIGINT, finish);
		//send sysx data request here, after midi in port is open.
		sendMsg(sysxOutMsg, midiOutPort);
		//periodically check the input queue
		while ( !done ) {
			for (int loop = 0; loop<loopCount; loop++)
			{
					stamp = midiin->getMessage( &message );  //get message from RtMidiIn
					nBytes = message.size();
					if ( nBytes <= 1 ) {goto wait;}          // if message buffer is empty, wait for a bit and try again
				for ( i=0; i<nBytes; i++ )
				{
					 n = ((int)message[i]);					// convert vector to qstring
					 QString hex = QString::number(n, 16).toUpper();
					 if (hex.length() < 2) hex.prepend("0");
					 tmp.append(hex);						// join all recieved messages into one string
					 bytesReceived = tmp.size() / 2;
					 emitProgress(bytesReceived);
				}
			wait:
				SLEEP(receiveTimeout);						// wait for the next sysx in the queue					
				if(loop >= loopCount) done = true;					// when loops are completed, we are done :)
			}
				done = true;
				bytesReceived = sysxBuffer.size() / 2;
				emitProgress(bytesReceived);
		};
			// Clean up
			cleanup:
			delete midiin;
		sysxInMsg = tmp;
		this->sysxInMsg = sysxInMsg;		
		dataReceive = true;
};


/**************************** run() **************************************
 * New QThread that processes the sysex or midi message and handles if yes 
 * or no it has to start receiving a reply on the MIDI In device midiIn. If 
 * so midiCallback() will handle the receive of the incomming sysex message.
 *************************************************************************/
void midiIO::run()
{
	if(midi) // Check if we are going to send syssex or midi data.
	{
		//emit setStatusProgress(0); // Reset the progress bar.
			QStringList msgList = midiMsg.split("0x", QString::SkipEmptyParts);
				for(int i=0;i<msgList.size();++i)
				{
					/* Calculate the percentage and update the progress bar */
					int percentage = (100/(double)msgList.size()) * (double)(i + 1);
					emit setStatusProgress(percentage);
					//send the midi message
					sysxOutMsg = midiMsg;
					sendMsg(sysxOutMsg, midiOutPort);
				};
		emit setStatusSymbol(2);
		emit setStatusMessage("Sending");
		emit setStatusProgress(33); // time wasting sinusidal statusbar progress animation
		SLEEP(30);
		emit setStatusProgress(66);
		SLEEP(60);		
		emit setStatusProgress(100);
		SLEEP(100);		
		emit setStatusProgress(75);
		SLEEP(100);		
		emit setStatusProgress(42);
		SLEEP(150);
		emit setStatusSymbol(1);
		emit setStatusProgress(0);
		emit setStatusMessage(tr("Ready"));

		emit midiFinished(); // We are finished so we send a signal to free the device.		
	}
	else
	{
		this->SysXFlag = 0;
		this->count = 0;
		this->dataReceive = false;
		this->sysxBuffer = "";
		this->sysxInMsg = "";

		/* Check if we are going to receive something on sending */
		bool receive;
		(this->sysxOutMsg.mid(10, 2) != "12")? receive = true: receive = false;

		if(receive==true)
		{
			emit setStatusSymbol(3);
		emit setStatusMessage(tr("Receiving Data"));
			/* Get the size of data bytes returned to calculate the progress percentage */
			bool ok;
			QString sizeChunk = sysxOutMsg.mid(sysxDataOffset * 2, 4 * 2);
			int dataLenght = sizeChunk.toInt(&ok, 16);
			bytesTotal = (sysxDataOffset + 2) + dataLenght;
			if(dataLenght == 0) // Id request>
			{
				bytesTotal += 2;
			}
			else if(sizeChunk == "00000001") // Patch Request
			{
				bytesTotal = 684;
			};
					dataReceive = true;
					receiveMsg(sysxInMsg, midiInPort);

			 }
		else
		{
			emit setStatusSymbol(2);
			emit setStatusMessage("Sending");
			sendMsg(sysxOutMsg, midiOutPort);
			
			
		
		//emit setStatusProgress(33); // Finished so we can set the progress bar to 100
		//SLEEP(10);
		//emit setStatusProgress(66);
		//SLEEP(20);		
		emit setStatusProgress(100);
		//SLEEP(30);		
		//emit setStatusProgress(75);
		//SLEEP(30);		
		//emit setStatusProgress(42);
		//SLEEP(50);
		};
		
		this->sysxInMsg = sysxInMsg;
		emit replyMsg(sysxInMsg);
		emit setStatusSymbol(1);
		emit setStatusProgress(0);
		emit setStatusMessage(tr("Ready"));
	};
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

	start();
};

/*********************** showErrorMsg() **********************************
 * Formats the error message received by the midi-in or midi-out device 
 * and outputs a warning text box to the user.
 *************************************************************************/
void midiIO::showErrorMsg(QString errorMsg, QString type)
{
	QString windowTitle;
	
	windowTitle = tr("GT-6B Fx FloorBoard");

	emit errorSignal(windowTitle, errorMsg);
};

/*********************** sendMidi() **********************************
 * Starts a new thread that handles the sending of the midi messages.
 **********************************************************************/
void midiIO::sendMidi(QString midiMsg, int midiOutPort)
{	
	this->midiOutPort = midiOutPort;
	this->midiMsg = midiMsg;
	this->midi = true;

	start();
};

/*********************** emitProgress() **********************************
 * This is a static function to make it it possible to update the progress 
 * bar from the CALLBACK function which is a static member.
 * It calculates the percenage and emits the signal.
 **********************************************************************/
void midiIO::emitProgress(int bytesReceived)
{
	if(bytesReceived != 0) // This is to prevent flickering of the progress bar.
	{
		int percentage;
		percentage = (100 / (double)bytesTotal) * (double)bytesReceived;

		SysxIO *sysxIO = SysxIO::Instance();
		sysxIO->emitStatusProgress(percentage);
	};
};
void midiIO::progressFlash()
{
	emit setStatusProgress(33); // time wasting sinusidal statusbar progress
		SLEEP(30);
		emit setStatusProgress(66);
		SLEEP(60);		
		emit setStatusProgress(100);
		SLEEP(100);		
		emit setStatusProgress(75);
		SLEEP(100);		
		emit setStatusProgress(42);
		SLEEP(150);
};

