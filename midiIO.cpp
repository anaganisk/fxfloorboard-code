/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
** Copyright (C) 2006, 2007 colin Willcocks. All rights reserved.
**
** This file is part of "GT-6B Fx FloorBoard".
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
#include "SysxIO.h"
#include "globalVariables.h"
#include "RtMidi.h"
#include "Preferences.h"
#include <QSysInfo>

int midiIO::bytesTotal = 0;
int loopCount;
bool midiIO::dataReceive = false;
bool midiIO::multiple = false;
QString midiIO::sysxBuffer;

// Platform-dependent sleep routines.
#ifdef Q_OS_WIN
  #include <windows.h>
  #define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants & Mac
  #include <unistd.h>
  #define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

midiIO::midiIO()
{
	this->midi = false; // Set this to false until required;
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
	 std::string portName;
	 unsigned int outPorts;
  /* RtMidiOut constructor */
  try {
    midiout = new RtMidiOut();
  }
  catch (RtError &error) {
    error.printMessage();
    goto cleanup;
  }
  /* Check outputs. */ 
  outPorts = midiout->getPortCount();
  for ( unsigned int i=0; i<outPorts; i++ ) {
    try {
      portName = midiout->getPortName(i);
    }
    catch (RtError &error) {
      error.printMessage();
      goto cleanup;
    }
#ifdef Q_OS_WIN
	/* if we are running msdos based windows, use device numbers instead */
    if(QSysInfo::WindowsVersion <= QSysInfo::WV_Me) 
	{
		char dev = char(i+49); // point to character set numerals
		QString outstring = ("un-named midi device: ");
		outstring.append(dev);
		this->midiOutDevices.append(outstring);
	}
	else
	{
    this->midiOutDevices.append(QString::fromStdString(portName));
	}
#else
	this->midiOutDevices.append(QString::fromStdString(portName));
#endif
  } 
  if (outPorts == 0) {
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
	 std::string portName;
	 unsigned int inPorts;
  // RtMidiIn constructor
  try {
    midiin = new RtMidiIn();
  }
  catch (RtError &error) {
    error.printMessage();
    goto cleanup;
  }
  // Check inputs.
  inPorts = midiin->getPortCount();
  for ( unsigned int i=0; i<inPorts; i++ ) {
    try {
      portName = midiin->getPortName(i);
		}
    catch (RtError &error) 
	{
      error.printMessage();
      goto cleanup;
    }
#ifdef Q_OS_WIN
  if(QSysInfo::WindowsVersion <= QSysInfo::WV_Me) 
	{
		char dev = char(i+49); // point to character set numerals
		QString instring = ("un-named midi device: ");
		instring.append(dev);
		this->midiInDevices.append(instring);
	}
  else
	{
    this->midiInDevices.append(QString::fromStdString(portName));
	} 
#else
	this->midiInDevices.append(QString::fromStdString(portName));
#endif
  }
  if (inPorts == 0) 
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


/*********************** sendMsg() **********************************
 * Prepares the sysx message before sending on the MIDI Out device. It 
 * converts the message from a QString to a std::vector and opens, sends 
 * and closes the MIDI device.
 *************************************************************************/
void midiIO::sendMsg(QString sysxOutMsg, int midiOutPort)
{
	//emit setStatusProgress(100);
	RtMidiOut *midiMsgOut = new RtMidiOut(); 
    // Check available ports.
    unsigned int nPorts = midiMsgOut->getPortCount();
    if ( nPorts == 0 ) {
    // std::cout << "No ports available!\n";
    goto cleanup;
    }
    try {    
        midiMsgOut->openPort(midiOutPort);	// Open selected port.         
		std::vector<unsigned char> message;	
        //message.reserve(1024);
		int msgLength = sysxOutMsg.length()/2;
		char *ptr  = new char[msgLength];		// Convert QString to char* (hex value) 
		for(int i=0;i<msgLength*2;++i)
		{	
		    unsigned int n;
			QString hex = "0x";
			hex.append(sysxOutMsg.mid(i, 2));
			bool ok;
			n = hex.toInt(&ok, 16);
			*ptr = (char)n;
			message.push_back(*ptr);		// insert the char* string into a std::vector	
			ptr++; i++;	
		};
	midiMsgOut->sendMessage(&message);		// send the midi data as a std::vector
	goto cleanup;
	    }
 catch (RtError &error)
   {
	  error.printMessage();
	  goto cleanup;
    }   
   // Clean up
 cleanup:
	int msgLength = sysxOutMsg.length()/2;
	SLEEP(msgLength);						// wait as long as the message is sending.
	midiMsgOut->closePort();
    delete midiMsgOut;	
	};

/*********************** receiveMsg() **********************************
 * Prepares the sysx message after receiving on the MIDI In device. It 
 *  and opens, receives and closes the MIDI device then converts the 
 *  message from a std::vector to a QString.
 *************************************************************************/
void midicallback(double deltatime, std::vector<unsigned char> *message, void *userData)
{			
		QString rxData;
				unsigned int nBytes = message->size();
				if (nBytes <=  2) {rxData.append(nBytes);}
				for ( unsigned int i=0; i<nBytes; i++ )
				{
					 int n = ((int)message->at(i));					// convert std::vector to QString
					 QString hex = QString::number(n, 16).toUpper();
					 if (hex.length() < 2) hex.prepend("0");
					 rxData.append(hex);						
				}	
				midiIO *midi = new midiIO();
				midi->callbackMsg(rxData);
				//SysxIO *sysxIO = SysxIO::Instance();
			    //sysxIO->emitStatusdBugMessage(sysxBuffer);		
};
void midiIO::callbackMsg(QString rxData)
{
	sysxBuffer.append(rxData);
};

void midiIO::receiveMsg(QString sysxInMsg, int midiInPort)
{
	emit setStatusSymbol(3);
	Preferences *preferences = Preferences::Instance(); bool ok;// Load the preferences.
	const int maxWait = preferences->getPreferences("Midi", "Time", "set").toInt(&ok, 10);
	if(multiple){loopCount = maxWait*20;}
	  else {loopCount = maxWait*5;};
			int bytesReceived = 0;		
			RtMidiIn *midiin = new RtMidiIn();		   //RtMidi constructor
	unsigned int nPorts = midiin->getPortCount();	   // check we have a midiout port
    if ( nPorts == 0 ) {
    // std::cout << "No ports available!\n";
    goto cleanup;
    }
    try {
			midiin->ignoreTypes(false, true, true);  //don,t ignore sysex messages, but ignore other crap
			midiin->openPort(midiInPort);             // open the midi in port			
			midiin->setCallback(&midicallback);    // set the callback 
			sendMsg(sysxOutMsg, midiOutPort);      // send the data request message out	
			bytesReceived = sysxBuffer.size() / 2;
			emitProgress(bytesReceived);	
			SLEEP(loopCount);                    // time it takes to get all sysx messages in.		
		goto cleanup;
	    }
	 catch (RtError &error)
	 {
	  error.printMessage();
	  goto cleanup;
    }   
		
		/*Clean up */
cleanup:

		midiin->cancelCallback();
		this->sysxInMsg = sysxBuffer;		   //get the returning data string
		dataReceive = true;
		delete midiin;
};

/**************************** run() **************************************
 * New QThread that processes the sysex or midi message and handles if yes 
 * or no it has to start receiving a reply on the MIDI In device midiIn. If 
 * so midiCallback() will handle the receive of the incomming sysex message.
 *************************************************************************/
void midiIO::run()
{
	if(midi && midiMsg.size() > 1)	// Check if we are going to send sysx or midi data & have an actual midi message to send.
	{
		if (midiMsg.size() <= 6)		// if the midi message is <= 3 words
			{
			sysxOutMsg = midiMsg;   // use the same sending routine as sysx messages.
		    	sendMsg(sysxOutMsg, midiOutPort);
		  	}
	
		else
			{
		     	int z=0;
           	     	for(int i=0;i<midiMsg.size()/6;++i) // split the midi control message string into 3 word packages.
				{
			  	 sysxOutMsg = midiMsg.mid(z,2);
			 	 sysxOutMsg.append(midiMsg.mid(z+2,2));  // skip every second byte
			 	 sysxOutMsg.append(midiMsg.mid(z+4,2));  // skip every second byte
			 	 sendMsg(sysxOutMsg, midiOutPort);
			 	 z=(z+6);								// advance to the next midi message in the string
			 	 SLEEP(60);
			 	};
					
	 		 }; 

						
		emit setStatusSymbol(2);
		emit setStatusMessage("Sending");
		emit setStatusProgress(33); // time wasting sinusidal statusbar progress animation
		SLEEP(40);
		emit setStatusProgress(66);
		SLEEP(100);		
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
	else   // if not a midi message, then it must be a sysx message
	{
		this->dataReceive = false;
		this->sysxBuffer = "";
		this->sysxInMsg = "";
		/* Check if we are going to receive something on sending */
		bool receive;
		(this->sysxOutMsg.mid(sysxDataOffset, 2) != "12")? receive = true: receive = false;

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
			else if(sizeChunk == "00000001") // Patch Request data size.
			{
				bytesTotal = patchSize;     // progressbar scaled to patch size
			};
					dataReceive = true;
					receiveMsg(sysxInMsg, midiInPort);
		 }
		else 
		{
			emit setStatusSymbol(2);
			emit setStatusMessage("Sending");
			sendMsg(sysxOutMsg, midiOutPort);
			Preferences *preferences = Preferences::Instance(); bool ok;// Load the preferences.
			const int minWait = preferences->getPreferences("Midi", "Delay", "set").toInt(&ok, 10);
			emit setStatusProgress(50);  // do the statusbar progress thing
			SLEEP((100/minWait)*5);		// and wait predetermined time before being able to send more again.
			emit setStatusProgress(100);
			SLEEP((100/minWait)*5);
			emit midiFinished(); // We are finished so we send a signal to free the device.	
		};		
		this->sysxInMsg = sysxInMsg;
		emit replyMsg(sysxInMsg);
		emit setStatusSymbol(1);
		emit setStatusProgress(0);
		emit setStatusMessage(tr("Ready"));
	};
	//this->exec();    /* this was causing an overflow of new threads on each midi event */
};

/*********************** sendSysxMsg() ***********************************
 * Starts a new thread that handles the send and receive of sysex messages.
 *************************************************************************/
void midiIO::sendSysxMsg(QString sysxOutMsg, int midiOutPort, int midiInPort)
{	
	this->sysxOutMsg = sysxOutMsg.simplified().toUpper().remove("0X").remove(" ");
	
	if(sysxOutMsg.size() == (sysxDataOffset + 22) && sysxOutMsg.mid((sysxDataOffset + 2), 2) != "00")
	{this->multiple = true;}
	else {this->multiple = false;}
	this->midiOutPort = midiOutPort;
	this->midiInPort = midiInPort;
	start();
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


