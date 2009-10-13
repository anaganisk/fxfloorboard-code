/****************************************************************************
**  
** Copyright (C) 2007, 2008, 2009 Colin Willcocks. 
** Copyright (C) 2005, 2006, 2007 Uco Mesdag.
** All rights reserved.
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

#include <QSysInfo>
#include "midiIO.h"
#include "SysxIO.h"
#include "globalVariables.h"
#include "RtMidi.h"
#include "Preferences.h"
#include "MidiTable.h"

int midiIO::bytesTotal = 1;
int midiIO::bytesReceived = 0;
int loopCount;
bool midiIO::dataReceive = false;
QString midiIO::sysxBuffer;
QString midiIO::msgType = "name";

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
	QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
	QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
	QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString)));
	QObject::connect(this, SIGNAL(errorSignal(QString, QString)), sysxIO, SLOT(errorSignal(QString, QString)));

	QObject::connect(this, SIGNAL(replyMsg(QString)), sysxIO, SLOT(receiveSysx(QString)));
	QObject::connect(this, SIGNAL(midiFinished()), sysxIO, SLOT(finishedSending()));
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
  const std::string clientName = "FxFloorBoard";
  try { midiout = new RtMidiOut(clientName); }   /* RtMidiOut constructor */
  catch (RtError &error) {
    error.printMessage();
    emit errorSignal("Midi Output Error", "port error");
    goto cleanup; };
  outPorts = midiout->getPortCount();      /* Check outputs. */ 
  for ( unsigned int i=0; i<outPorts; i++ ) {
    try {
      portName = midiout->getPortName(i);
        }
    catch (RtError &error) {
      error.printMessage();
      emit errorSignal("Midi Output Error", "data error");
      goto cleanup; };
#ifdef Q_OS_WIN
	/* if we are running msdos based windows, use device numbers instead, UNICODE not supported*/
    if(QSysInfo::WindowsVersion <= QSysInfo::WV_Me) 
	{
		char dev = char(i+49); // point to character set numerals
		QString outstring = ("un-named midi device: ");
		outstring.append(dev);
		this->midiOutDevices.append(outstring);
	}
	else { this->midiOutDevices.append(QString::fromStdString(portName)); };
#else
	this->midiOutDevices.append(QString::fromStdString(portName));
#endif
  }; 
  if (outPorts < 1) { this->midiOutDevices.push_back("no midi device available"); };
 /* Clean up */
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
   const std::string clientName = "FxFloorBoard";
  try { midiin = new RtMidiIn(clientName); }    /* RtMidiIn constructor */
  catch (RtError &error) {
    error.printMessage();
    emit errorSignal("Midi Input Error", "port error");
    goto cleanup; };
  inPorts = midiin->getPortCount();   /* Check inputs. */
  for ( unsigned int i=0; i<inPorts; i++ ) {
     try { portName = midiin->getPortName(i); }
     catch (RtError &error) {
        error.printMessage();
        emit errorSignal("Midi Input Error", "data error");
        goto cleanup; };
#ifdef Q_OS_WIN
  if(QSysInfo::WindowsVersion <= QSysInfo::WV_Me) 
	{
		char dev = char(i+49); // point to character set numerals
		QString instring = ("un-named midi device: ");
		instring.append(dev);
		this->midiInDevices.append(instring);
	}
  else { this->midiInDevices.append(QString::fromStdString(portName)); }; 
#else
	this->midiInDevices.append(QString::fromStdString(portName));
#endif
  };
  if (inPorts < 1) 
	{ this->midiInDevices.push_back("no midi device available"); };
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
void midiIO::sendSyxMsg(QString sysxOutMsg, int midiOutPort)
{
  RtMidiOut *midiMsgOut = 0;
	const std::string clientName = "FxFloorBoard";
	midiMsgOut = new RtMidiOut(clientName); 
     int nPorts = midiMsgOut->getPortCount();   // Check available ports.
    if ( nPorts < 1 ) { goto cleanup; }
    try {    
        midiMsgOut->openPort(midiOutPort, clientName);	// Open selected port.         
		    std::vector<unsigned char> message;	
        message.reserve(256);
		int msgLength = sysxOutMsg.length()/2;
		char *ptr  = new char[msgLength];		// Convert QString to char* (hex value) 
		for(int i=0;i<msgLength*2;++i)
		 if (!midi) {
     unsigned int n;
			QString hex = "0x";
			hex.append(sysxOutMsg.mid(i, 2));
			bool ok;
			n = hex.toInt(&ok, 16);
			*ptr = (char)n;
			message.push_back(*ptr);		// insert the char* string into a std::vector	
			if(hex.contains ("F7"))
           {	
#ifdef Q_OS_WIN
                                  message.push_back(32);
                                  message.push_back(32);
#endif
            midiMsgOut->sendMessage(&message);  // send the midi data as a std::vector
            SLEEP(20);
            message.clear();    
            hex = "0x"; 
            };
        ptr++; i++; 	
      };
	goto cleanup;
	    }
 catch (RtError &error)
   {
	  error.printMessage();
	  emit errorSignal("Midi Output Error", "data error");
	  goto cleanup;
    };   
   /* Clean up */
 cleanup:
        SLEEP(20);						// wait as long as the message is sending.
        //midiMsgOut->closePort();
  delete midiMsgOut;	
};
/*********** send midi messages *******************************/
void midiIO::sendMidiMsg(QString sysxOutMsg, int midiOutPort)
{
    RtMidiOut *midiMsgOut = 0;
		const std::string clientName = "FxFloorBoard";
		midiMsgOut = new RtMidiOut(clientName);  
    unsigned int nPorts = midiMsgOut->getPortCount();   // Check available ports.
    if ( nPorts < 1 ){ goto cleanup; };
    try {    
    midiMsgOut->openPort(midiOutPort, clientName);	// Open selected port.         
		std::vector<unsigned char> message;	
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
  midiMsgOut->sendMessage(&message);  // send the midi data as a std::vector
	goto cleanup;
	    }
 catch (RtError &error)
   {
	  error.printMessage();
	  emit errorSignal("Midi Output Error", "data error");
	  goto cleanup;
    };   
   /* Clean up*/
 cleanup:
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
		QString rxData = "";
		  midiIO *midi = new midiIO();
				unsigned int nBytes = message->size();
				for ( unsigned int i=0; i<nBytes; i++ )
				{
					 int n = ((int)message->at(i));					// convert std::vector to QString
					 QString hex = QString::number(n, 16).toUpper();
					 if (hex.length() < 2) hex.prepend("0");
					 rxData.append(hex);	
        };	
		if (rxData.contains("F0") || rxData.contains("F7"))
		{ midi->callbackMsg(rxData); };
};
void midiIO::callbackMsg(QString rxData)
{
	this->sysxBuffer.append(rxData);
};

void midiIO::receiveMsg(QString sysxInMsg, int midiInPort)
{
  int count = 0;
	emit setStatusSymbol(3);
#ifdef Q_OS_WIN
        int x = 1;
#else
        int x = 3;
#endif
	if (msgType == "patch"){
  loopCount = x*600;
  count = 1010;
  } else if(msgType == "system"){
  loopCount = x*900;
  count = 4326; // native gt-pro system size, then trimmed to 4313 later.
  }
  else if (msgType == "name"){
  loopCount = x*80;
  count = 29; }
  else {
  loopCount = x*120;
  count = 15; };
		RtMidiIn *midiin = 0;
    const std::string clientName = "FxFloorBoard";	
	  midiin = new RtMidiIn(clientName);		   //RtMidi constructor
	unsigned int nPorts = midiin->getPortCount();	   // check we have a midiout port
    if ( nPorts < 1 ) { goto cleanup; };
    try {
			midiin->ignoreTypes(false, true, true);  //don,t ignore sysex messages, but ignore other crap like active-sensing
			midiin->openPort(midiInPort, clientName);             // open the midi in port			
			midiin->setCallback(&midicallback);    // set the callback 
			SLEEP(5);
			sendSyxMsg(sysxOutMsg, midiOutPort);      // send the data request message out	
			int x = 0;
			unsigned int t = 1;
      while (x<loopCount && sysxBuffer.size()/2 < count)  // wait until exact bytes received or timeout
      {
      SLEEP(5);
      t = (x*100)/loopCount;
      emit setStatusProgress(t);    
       x++;
      };                   // time it takes to get all sysx messages in.			
      
		goto cleanup;
	    }
	 catch (RtError &error)
	 {
	  error.printMessage();
	  emit errorSignal("Midi Input Error", "data error");
	  goto cleanup;
     };   		
		/*Clean up */
cleanup:
    emit setStatusProgress(100);
		midiin->cancelCallback();
		this->sysxInMsg = this->sysxBuffer;		   //get the returning data string
		dataReceive = true;
		midiin->closePort();             // close the midi in port	
		delete midiin;
};

/**************************** run() **************************************
 * New QThread that processes the sysex or midi message and handles if yes 
 * or no it has to start receiving a reply on the MIDI In device midiIn. If 
 * so midiCallback() will handle the receive of the incomming sysx message.
 *************************************************************************/
void midiIO::run()
{
	if(midi && midiMsg.size() > 1)	// Check if we are going to send sysx or midi data & have an actual midi message to send.
	{
	 
		if (midiMsg.size() <= 6)		// if the midi message is <= 3 words
			{
			  sysxOutMsg = midiMsg;   // use the same sending routine as sysx messages.
		    sendMidiMsg(sysxOutMsg, midiOutPort);
		  }
		else
			{
		     	int z=0; 
			   sysxOutMsg = midiMsg.mid(z,2);
			 	 sysxOutMsg.append(midiMsg.mid(z+2,2));  // skip every second byte
			 	 sysxOutMsg.append(midiMsg.mid(z+4,2));  // skip every second byte
			 	 sendMidiMsg(sysxOutMsg, midiOutPort);
			 	 z=(z+6);								// advance to the next midi message in the string
			 	 sysxOutMsg = midiMsg.mid(z,2);
			 	 sysxOutMsg.append(midiMsg.mid(z+2,2));  // skip every second byte
			 	 sysxOutMsg.append(midiMsg.mid(z+4,2));  // skip every second byte
			 	 sendMidiMsg(sysxOutMsg, midiOutPort);
			 	 z=(z+6);								// advance to the next midi message in the string
			 	 sysxOutMsg = midiMsg.mid(z,2);
			 	 sysxOutMsg.append(midiMsg.mid(z+2,2));  // skip every second byte
			 	 sysxOutMsg.append(midiMsg.mid(z+4,2));  // skip every second byte
			 	 sendMidiMsg(sysxOutMsg, midiOutPort);			
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
		emit setStatusProgress(0);
		emit midiFinished(); // We are finished so we send a signal to free the device.		
	}
	else   // if not a midi message, then it must be a sysx message
	{
		this->dataReceive = false;
		this->sysxBuffer.clear();
		this->sysxInMsg.clear();
		/* Check if we are going to receive something on sending */
		bool receive;
		(this->sysxOutMsg.mid(sysxAddressOffset*2-2, 2) != "12")? receive = true: receive = false;
    if(receive==true)
		{
			emit setStatusSymbol(3);
			//emit setStatusMessage(tr("Receiving Data"));
			/* Get the size of data bytes returned to calculate the progress percentage */
			bool ok;
			QString sizeChunk = sysxOutMsg.mid(sysxDataOffset * 2, 4 * 2);
			int dataLenght = sizeChunk.toInt(&ok, 16);
			bytesTotal = (sysxDataOffset + 2) + dataLenght;
			if(dataLenght == 0) // Id request>
			{
				bytesTotal = 1;
			}
			else if(sizeChunk == patchRequestSize) // Patch Request data size.
			{
				bytesTotal = patchSize;     // progressbar scaled to patch size
			};
					dataReceive = true;
					receiveMsg(sysxInMsg, midiInPort);
		 }
		else 
		{
			emit setStatusSymbol(2);
			sendSyxMsg(sysxOutMsg, midiOutPort);
			Preferences *preferences = Preferences::Instance(); bool ok;// Load the preferences.
			const int minWait = preferences->getPreferences("Midi", "Delay", "set").toInt(&ok, 10);
			emit setStatusProgress(33);  // do the statusbar progress thing
			SLEEP((100/minWait)*2);		// and wait predetermined time before being able to send more again.
			emit setStatusProgress(75);
			SLEEP((100/minWait)*3);
			emit setStatusProgress(100);
			SLEEP((100/minWait)*3);
			emit setStatusProgress(66);
			SLEEP((100/minWait)*2);
			emit midiFinished(); // We are finished so we send a signal to free the device.	
		};		
		this->sysxInMsg = sysxInMsg;
		emit replyMsg(sysxInMsg);
		emit setStatusSymbol(1);
		emit setStatusProgress(0);
	};
};

/*********************** sendSysxMsg() ***********************************
 * Starts a new thread that handles the send and receive of sysex messages.
 *************************************************************************/
void midiIO::sendSysxMsg(QString sysxOutMsg, int midiOutPort, int midiInPort)
{	
  QString reBuild;
  QString sysxEOF;	
  QString hex;
  int msgLength = sysxOutMsg.length()/2;
  for(int i=0;i<msgLength*2;++i) 
  {
	hex.append(sysxOutMsg.mid(i*2, 2));
	sysxEOF = sysxOutMsg.mid((i*2)+4, 2);
  if (sysxEOF == "F7")
    {    
  	int dataSize = 0; bool ok;
	  for(int h=checksumOffset;h<hex.size()-1;++h)
	  { dataSize += hex.mid(h*2, 2).toInt(&ok, 16); };
	 	QString base = "80";                       // checksum calculate.
	  unsigned int sum = dataSize % base.toInt(&ok, 16);
  	if(sum!=0) { sum = base.toInt(&ok, 16) - sum; };
	  QString checksum = QString::number(sum, 16).toUpper();
	   if(checksum.length()<2) {checksum.prepend("0");};
      	hex.append(checksum);
        hex.append("F7");
        if (!hex.contains("F0000000001B12") ) {reBuild.append(hex); };   
		hex.clear();
		sysxEOF.clear();
		i=i+2;
    }; 
  };    
  if (sysxOutMsg == idRequestString){reBuild = sysxOutMsg;  msgType = "";};  // identity request not require checksum
	this->sysxOutMsg = reBuild.simplified().toUpper().remove("0X").remove(" ");

  if((sysxOutMsg.size() == 34) && (sysxOutMsg.contains(patchRequestSize)) && (sysxOutMsg.mid((sysxAddressOffset*2-2), 2) == "11")) { msgType = "patch"; };
    
  if((sysxOutMsg.size() == 34) && (sysxOutMsg.contains("00000010")) && (sysxOutMsg.mid((sysxAddressOffset*2-2), 2) == "11")) { msgType = "name"; };
   
  if (sysxOutMsg != idRequestString && sysxOutMsg.contains("F0410000000611000000000")) {msgType = "system"; };
  
 	this->midiOutPort = midiOutPort;
	this->midiInPort = midiInPort;
	this->midi = false;
	Preferences *preferences = Preferences::Instance();// Load the preferences.
	QString midiOut = preferences->getPreferences("Midi", "MidiOut", "device");
	QString check = sysxOutMsg.mid(0, 14);
   if (check == "F0000000001B12")
   { 
      emit setStatusSymbol(1);
    	emit setStatusProgress(0);
    	emit setStatusMessage(tr("Ready"));
    	emit replyMsg("");
   }
   else if (midiOut!="" ) 
    {
      start(); 
    } 
    else
    {
        emit setStatusSymbol(1);
        emit setStatusMessage(tr("no midi device set"));
        emit replyMsg("");
    };  
};

/*********************** sendMidi() **********************************
 * Starts a new thread that handles the sending of the midi messages.
 **********************************************************************/
void midiIO::sendMidi(QString midiMsg, int midiOutPort)
{	
	this->midiOutPort = midiOutPort;
	this->midiMsg = midiMsg;
	this->midi = true;
	Preferences *preferences = Preferences::Instance();// Load the preferences.
	QString midiOut = preferences->getPreferences("Midi", "MidiOut", "device");
  if(midiOut!="") {start();} else { 
  emit setStatusSymbol(0);
  emit setStatusMessage(tr("no midi device set"));
  };
};

