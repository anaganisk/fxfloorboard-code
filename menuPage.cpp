/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-10B Fx FloorBoard".
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

#include "menuPage.h"
#include "MidiTable.h"
#include "SysxIO.h"
#include "globalVariables.h"
#include "floorBoardDisplay.h"
#include "sysxWriter.h"

menuPage::menuPage(QWidget *parent, unsigned int id, QString imagePath, QPoint stompPos)
    : QWidget(parent)
{
	this->id = id;
	this->imagePath = imagePath;
	this->stompSize = QPixmap(imagePath).size();
	this->stompPos = stompPos;	

	this->setFixedSize(stompSize);

	this->editDialog = new editWindow();
	
  this->menuButton = new customButton(tr(""), false, QPoint(0, 0), this, ":/images/menu_pushbutton.png");

	QObject::connect(this, SIGNAL( valueChanged(QString, QString, QString) ), this->parent(), SIGNAL( valueChanged(QString, QString, QString) ));
	
	QObject::connect(this->parent(), SIGNAL( updateStompOffset(signed int) ), this, SLOT( updatePos(signed int) ));

	QObject::connect(this->parent(), SIGNAL( updateSignal() ), this, SLOT( updateSignal() ));
	
	QObject::connect(this, SIGNAL( systemUpdateSignal() ), this->parent()->parent(), SIGNAL( updateSignal() ));

	QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( updateSignal() ));

	QObject::connect(this, SIGNAL( dialogUpdateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));	

	QObject::connect(this->parent(), SIGNAL( updateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));

	QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( setDisplayToFxName() ));

	QObject::connect(this, SIGNAL( setEditDialog(editWindow*) ), this->parent(), SLOT( setEditDialog(editWindow*) ));
	
	QObject::connect(this->menuButton, SIGNAL(valueChanged(bool)), this, SLOT(menuButtonSignal(bool))); 
  
  QObject::connect(this->menuButton, SIGNAL(valueChanged(bool)), this->parent(), SLOT(menuButtonSignal()));
  
  QObject::connect(this->parent(), SIGNAL(master_buttonSignal(bool)), this, SLOT(master_ButtonSignal(bool) )); 
  QObject::connect(this->parent(), SIGNAL(master_buttonSignal(bool)), this->parent(), SLOT(menuButtonSignal()));
                
  QObject::connect(this->parent(), SIGNAL(assignSignal(bool)), this, SLOT(assignSignal(bool)));  //cw  
  
  SysxIO *sysxIO = SysxIO::Instance();
	QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
	QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
	QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString))); 
};

void menuPage::paintEvent(QPaintEvent *)
{
	QRectF target(0.0, 0.0, stompSize.width(), stompSize.height());
	QRectF source(0.0, 0.0, stompSize.width(), stompSize.height());
	QPixmap image(imagePath);

	this->image = image;

	QPainter painter(this);
	painter.drawPixmap(target, image, source);
};

editWindow* menuPage::editDetails()
{
	return this->editDialog;
};

/*void menuPage::master_ButtonSignal(bool value)	
{  
    if (this->id == 23)
    { 
      emitValueChanged(this->hex1, this->hex2, "00", "void");
	    this->editDialog->setWindow("Master");
      emit setEditDialog(this->editDialog);
    };
};
*/
void menuPage::menuButtonSignal(bool value)	
{
	  if(this->id > 19)
    {
      emitValueChanged(this->hex1, this->hex2, "00", "void");
	    this->editDialog->setWindow(this->fxName);

      emit setEditDialog(this->editDialog);
    };
    SysxIO *sysxIO = SysxIO::Instance();
	  if((this->id == 19 || this->id == 18) && sysxIO->deviceReady())
	  {
    QString replyMsg;
	   if (!sysxIO->isConnected())
	       {
	        emit setStatusSymbol(2);
		      emit setStatusMessage(tr("Request System data"));
	       	sysxIO->setDeviceReady(false); // Reserve the device for interaction.
		      QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)));
		      QObject::connect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(systemReply(QString)));
		      sysxIO->sendSysx(systemRequest); // GT-6 System area data Request.    
          
          emitValueChanged(this->hex1, this->hex2, "00", "void");
	        this->editDialog->setWindow(this->fxName);
		      emit setEditDialog(this->editDialog);  	        
         }
         else
            {
              QString snork = "Ensure Bulk Mode is set and retry";
              QMessageBox *msgBox = new QMessageBox();
			        msgBox->setWindowTitle(deviceType + " not connected !!");
		        	msgBox->setIcon(QMessageBox::Information);
		        	msgBox->setText(snork);
		        	msgBox->setStandardButtons(QMessageBox::Ok);
		        	msgBox->exec(); 
             };  
    };
};

void menuPage::systemReply(QString replyMsg)
{
	SysxIO *sysxIO = SysxIO::Instance();
	QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(systemReply(QString)));
	sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
	
	   sysxWriter file;
		 file.setFile(":system.syx");  // Read the default sysex file so whe don't start empty handed.
		 if(file.readFile())
	   {	
			sysxIO->setFileSource("System", file.getSystemSource());
		 };
  /*
	if(sysxIO->noError())
	{ 
	if(replyMsg.size()/2 == 2236)
		{
		// TRANSLATE SYSX MESSAGE FORMAT to 128 byte data blocks 
	QString header = "F0410000002F12";
	QString footer ="00F7";
	QString addressMsb = replyMsg.mid(14,4); // read  MSb word at bits 7 & 8 from sysxReply (which is "0000")
	QString part1 = replyMsg.mid(22, 256); //from 11, copy 128 bits (values are doubled for QString)
  part1.prepend("0000").prepend(addressMsb).prepend(header).append(footer);    
	QString part2 = replyMsg.mid(278, 226);
	QString part2B = replyMsg.mid(530, 30);
	part2.prepend("0100").prepend(addressMsb).prepend(header).append(part2B).append(footer); 
	QString part3 = replyMsg.mid(560, 256);
	part3.prepend("0200").prepend(addressMsb).prepend(header).append(footer);
	QString part4 = replyMsg.mid(816, 198);	
	part4.prepend("0300").prepend(addressMsb).prepend(header).append(footer); 
	addressMsb = "0001"; // new address range "00 01 00 00"
	QString part5 = replyMsg.mid(1040, 256);   
	part5.prepend("0000").prepend(addressMsb).prepend(header).append(footer);   
	QString part6 = replyMsg.mid(1296, 228);   // 
	part6.prepend("0100").prepend(addressMsb).prepend(header).append(footer);   
  QString part7 = replyMsg.mid(1550, 256);  // 
  part7.prepend("0200").prepend(addressMsb).prepend(header).append(footer); 
	QString part8 = replyMsg.mid(1806,228);    // spare 
	part8.prepend("0300").prepend(addressMsb).prepend(header).append(footer);
	addressMsb = "0002"; // new address range "00 02 00 00"  midi area
	QString part10 = replyMsg.mid(2060, 256);   //
	part10.prepend("0000").prepend(addressMsb).prepend(header).append(footer);
	QString part11 = replyMsg.mid(2316, 228);
	QString part11B = replyMsg.mid(2570, 28);
	part11.prepend("0100").prepend(addressMsb).prepend(header).append(part11B).append(footer); 
	QString part12 = replyMsg.mid(2598, 256);   //
	part12.prepend("0200").prepend(addressMsb).prepend(header).append(footer);
	QString part13 = replyMsg.mid(2854, 200);
	QString part13B = replyMsg.mid(3080, 56);
	part13.prepend("0300").prepend(addressMsb).prepend(header).append(part13B).append(footer);  
	QString part14 = replyMsg.mid(3136, 256);   //
	part14.prepend("0400").prepend(addressMsb).prepend(header).append(footer);
	QString part15 = replyMsg.mid(3392, 172);
	QString part15B = replyMsg.mid(3590, 84);
	part15.prepend("0500").prepend(addressMsb).prepend(header).append(part15B).append(footer);  
	QString part16 = replyMsg.mid(3674, 256);   //
	part16.prepend("0600").prepend(addressMsb).prepend(header).append(footer);
	QString part17 = replyMsg.mid(3930, 144);
	QString part17B = replyMsg.mid(4100, 112);
	part17.prepend("0700").prepend(addressMsb).prepend(header).append(part17B).append(footer);  
	QString part18 = replyMsg.mid(4212, 256);   //
	part18.prepend("0800").prepend(addressMsb).prepend(header).append(footer);
	
	replyMsg = "";
	replyMsg.append(part1).append(part2).append(part3).append(part4).append(part5)
  .append(part6).append(part7).append(part8).append(part10).append(part11)
  .append(part12).append(part13).append(part14).append(part15).append(part16).append(part17).append(part18);
	
	QString reBuild = "";       // Add correct checksum to patch strings 
  QString sysxEOF = "";	
  QString hex = "";
  int msgLength = replyMsg.length()/2;
  for(int i=0;i<msgLength*2;++i) 
  {
	hex.append(replyMsg.mid(i*2, 2));
	sysxEOF = (replyMsg.mid((i*2)+4, 2));
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
        reBuild.append(hex);   
    
		hex = "";
		sysxEOF = "";
		i=i+2;
    }; 
  };    
	replyMsg = reBuild.simplified().toUpper().remove("0X").remove(" ");
		
		QString area = "System";
		sysxIO->setFileSource(area, replyMsg);		// Set the source to the data received.
		sysxIO->setFileName(tr("System Data from ") + deviceType);	// Set the file name to GT-10B system for the display.
		sysxIO->setDevice(true);				// Patch received from the device so this is set to true.
		sysxIO->setSyncStatus(true);			// We can't be more in sync than right now! :)
		emit systemUpdateSignal();
		}
		else
		{
			QMessageBox *msgBox = new QMessageBox();
			msgBox->setWindowTitle(deviceType + tr(" Fx FloorBoard connection Error !!"));
			msgBox->setIcon(QMessageBox::Warning);
			msgBox->setTextFormat(Qt::RichText);
			QString msgText;
			msgText.append("<font size='+1'><b>");
			msgText.append(tr("The Boss ") + deviceType + (" Effects Processor was not found."));
			msgText.append("<b></font><br>");
			msgBox->setText(msgText);
			msgBox->setStandardButtons(QMessageBox::Ok);
			msgBox->exec();
		}; 
   };  */
		emit setStatusMessage(tr("Ready"));   
};

void menuPage::setPos(QPoint newPos)
{
	this->move(newPos);
	//this->stompPos = newPos;
};

void menuPage::updatePos(signed int offsetDif)
{ 
	this->stompPos = this->pos();
	QPoint newPos = stompPos + QPoint::QPoint(offsetDif, 0);
	this->move(newPos);
	//this->stompPos = newPos;
};
	
void menuPage::setImage(QString imagePath)
{
	this->imagePath = imagePath;
	this->update();
};

void menuPage::setSize(QSize newSize)
{
	this->stompSize = newSize;
	this->setFixedSize(stompSize);
};

void menuPage::setId(unsigned int id)
{
	this->id = id;
};

unsigned int menuPage::getId()
{
	return this->id;
};

void menuPage::setLSB(QString hex1, QString hex2)
{
	this->hex1 = hex1;
	this->hex2 = hex2;
	this->editDialog->setLSB(hex1, hex2);
};

void menuPage::valueChanged(int value, QString hex1, QString hex2, QString hex3)
{
	MidiTable *midiTable = MidiTable::Instance();
	QString area; 
	if(this->id == 18 || this->id == 19) {area = "System";} else {area = "Structure";};
	QString valueHex = QString::number(value, 16).toUpper();
	if(valueHex.length() < 2) valueHex.prepend("0");

	SysxIO *sysxIO = SysxIO::Instance(); bool ok;
	if(midiTable->isData(area, hex1, hex2, hex3))
	{	
		int maxRange = QString("7F").toInt(&ok, 16) + 1;
		int value = valueHex.toInt(&ok, 16);
		int dif = value/maxRange;
		QString valueHex1 = QString::number(dif, 16).toUpper();
		if(valueHex1.length() < 2) valueHex1.prepend("0");
		QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
		if(valueHex2.length() < 2) valueHex2.prepend("0");
		
		sysxIO->setFileSource(area, hex1, hex2, hex3, valueHex1, valueHex2);
	}
	else
	{
		sysxIO->setFileSource(area, hex1, hex2, hex3, valueHex);
	};

	emitValueChanged(hex1, hex2, hex3, valueHex);
};

void menuPage::valueChanged(bool value, QString hex1, QString hex2, QString hex3)
{
	int valueInt;
	(value)? valueInt=1: valueInt=0;
	QString valueHex = QString::number(valueInt, 16).toUpper();
	if(valueHex.length() < 2) valueHex.prepend("0");
	
	SysxIO *sysxIO = SysxIO::Instance();
	QString area; 
	if(this->id == 18 || this->id == 19) {area = "System";} else {area = "Structure";};
	sysxIO->setFileSource(area, hex1, hex2, hex3, valueHex);


	emitValueChanged(hex1, hex2, hex3, valueHex);
};

void menuPage::emitValueChanged(QString hex1, QString hex2, QString hex3, QString valueHex)
{
  QString area; 
	if(this->id == 18 || this->id == 19) {area = "System";} else {area = "Structure";};
	QString valueName, valueStr;
	if(hex1 != "void" && hex2 != "void")
	{
		MidiTable *midiTable = MidiTable::Instance();
		if(valueHex != "void")
		{
			Midi items = midiTable->getMidiMap("Structure", hex1, hex2, hex3);
			valueName = items.desc;
			this->fxName = midiTable->getMidiMap("Structure", hex1, hex2, hex3).name;
			valueStr = midiTable->getValue("Structure", hex1, hex2, hex3, valueHex);
			emit dialogUpdateSignal();
		}
		else
		{
		 
		  if (this->id == 18)this->fxName = "System settings";
		  if (this->id == 19)this->fxName = "Custom Settings";
		  if (this->id == 20)this->fxName = "Assigns";
		  //if (this->id == 23)this->fxName = "Pedal"; 
				 //midiTable->getMidiMap("Structure", hex1, hex2, hex3).name;//hex1).customdesc;
		};
	};

	emit valueChanged(this->fxName, valueName, valueStr);
};

void menuPage::setDisplayToFxName()
{
	emit valueChanged(this->fxName, "", "");
};
