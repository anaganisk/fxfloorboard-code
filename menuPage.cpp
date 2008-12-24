/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag.
** All rights reserved.
**
** This file is part of "GT-10 Fx FloorBoard".
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
#include "floorBoard.h"

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

	QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( updateSignal() ));

	QObject::connect(this, SIGNAL( dialogUpdateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));	

	QObject::connect(this->parent(), SIGNAL( updateSignal() ), this->editDialog, SIGNAL( dialogUpdateSignal() ));

	QObject::connect(this->editDialog, SIGNAL( updateSignal() ), this, SLOT( setDisplayToFxName() ));

	QObject::connect(this, SIGNAL( setEditDialog(editWindow*) ), this->parent(), SLOT( setEditDialog(editWindow*) ));
                
  QObject::connect(this->menuButton, SIGNAL(valueChanged(bool)), this, SLOT(menuButtonSignal(bool))); 
  
  QObject::connect(this->menuButton, SIGNAL(valueChanged(bool)), this->parent(), SLOT(menuButtonSignal()));
  
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


void menuPage::menuButtonSignal(bool value)	
	{
	  emitValueChanged(this->hex1, this->hex2, "00", "void");
	  this->editDialog->setWindow(this->fxName);
	  
	  if(this->id > 19)
    {
      emit setEditDialog(this->editDialog);
    };
	  if(this->id == 19 || this->id == 18)
	  {
    QString replyMsg;
	  SysxIO *sysxIO = SysxIO::Instance();
     if (sysxIO->isConnected())
	       {
	        emit setStatusSymbol(2);
		      emit setStatusMessage(tr("Request System data"));
	       	sysxIO->setDeviceReady(false); // Reserve the device for interaction.
		      QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)));
		      QObject::connect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(connectionResult(QString)));
		      sysxIO->sendSysx(systemRequest); // GT-10 System area data Request.      	        
         }else{
              QString snork = "Ensure connection is active and retry";
              QMessageBox *msgBox = new QMessageBox();
			        msgBox->setWindowTitle(deviceType + " not connected !!");
		        	msgBox->setIcon(QMessageBox::Information);
		        	msgBox->setText(snork);
		        	msgBox->setStandardButtons(QMessageBox::Ok);
		        	msgBox->exec(); 
              };  
              emit setEditDialog(this->editDialog);
    };
};

void menuPage::connectionResult(QString sysxMsg)
{
	SysxIO *sysxIO = SysxIO::Instance();
	QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(connectionResult(QString)));
	sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
   QApplication::beep();
		 /*DeBugGING OUTPUT */
	/*Preferences *preferences = Preferences::Instance(); // Load the preferences.
	if(preferences->getPreferences("Midi", "DBug", "bool")=="true")
	{ */
	if (sysxMsg.size() > 0){
		QString snork;
			snork.append("<font size='-1'>");
			snork.append("{ size=");
			snork.append(QString::number(sysxMsg.size()/2, 10));
			snork.append("}");	
			snork.append("<br> midi data received");
			for(int i=0;i<sysxMsg.size();++i)
			{
				snork.append(sysxMsg.mid(i, 2));
				snork.append(" ");
				i++;
			};
			snork.replace("F7", "F7 }<br>");
			snork.replace("F0", "{ F0");
					 
			QMessageBox *msgBox = new QMessageBox();
			msgBox->setWindowTitle("dBug Result for GT-10 System data request");
			msgBox->setIcon(QMessageBox::Information);
			msgBox->setText(snork);
			msgBox->setStandardButtons(QMessageBox::Ok);
			msgBox->exec();
			};	
			 emit setStatusMessage(tr("Ready"));
			 
	/*}

	else if(sysxIO->noError())
	{
		if(sysxMsg.size()==2261)
		{
			
		}
		else if(!sysxMsg.isEmpty())
		{		
			//notConnected();

			QMessageBox *msgBox = new QMessageBox();
			msgBox->setWindowTitle(deviceType + tr(" Fx FloorBoard connection Error !!"));
			msgBox->setIcon(QMessageBox::Warning);
			msgBox->setTextFormat(Qt::RichText);
			QString msgText;
			msgText.append("<font size='+1'><b>");
			msgText.append(tr("The device connected is not a Boss ") + deviceType + (" Effects Processor."));
			msgText.append("<b></font>");
			msgBox->setText(msgText);
			msgBox->setStandardButtons(QMessageBox::Ok);
			msgBox->exec();
		}
		else
		{
			//notConnected();

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
	}
	else
	{
		//notConnected();
		sysxIO->setNoError(true);		// Reset the error status (else we could never retry :) ).
	};  */
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
	
	QString valueHex = QString::number(value, 16).toUpper();
	if(valueHex.length() < 2) valueHex.prepend("0");

	SysxIO *sysxIO = SysxIO::Instance(); bool ok;
	if(midiTable->isData("Structure", hex1, hex2, hex3))
	{	
		int maxRange = QString("7F").toInt(&ok, 16) + 1;
		int value = valueHex.toInt(&ok, 16);
		int dif = value/maxRange;
		QString valueHex1 = QString::number(dif, 16).toUpper();
		if(valueHex1.length() < 2) valueHex1.prepend("0");
		QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
		if(valueHex2.length() < 2) valueHex2.prepend("0");
		
		sysxIO->setFileSource(hex1, hex2, hex3, valueHex1, valueHex2);
	}
	else
	{
		sysxIO->setFileSource(hex1, hex2, hex3, valueHex);
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
	sysxIO->setFileSource(hex1, hex2, hex3, valueHex);

	emitValueChanged(hex1, hex2, hex3, valueHex);
};


void menuPage::emitValueChanged(QString hex1, QString hex2, QString hex3, QString valueHex)
{
	QString valueName, valueStr;
	if(hex1 != "void" && hex2 != "void")
	{
		MidiTable *midiTable = MidiTable::Instance();
		if(valueHex != "void")
		{
			Midi items = midiTable->getMidiMap("Structure", hex1, hex2, hex3);
			valueName = items.desc;
			//this->fxName = midiTable->getMidiMap("Structure", hex1, hex2, hex3).name;
			valueStr = midiTable->getValue("Structure", hex1, hex2, hex3, valueHex);
			emit dialogUpdateSignal();
		}
		else
		{
		  if (this->id == 18)this->fxName = "System settings";
		  if (this->id == 19)this->fxName = "System Midi";
		  if (this->id == 20)this->fxName = "Assigns";
		  if (this->id == 21)this->fxName = "FX1 AutoRiff User Scales";  
      if (this->id == 22)this->fxName = "FX2 AutoRiff User Scales";  
      if (this->id == 23)this->fxName = "Master";  
		};
	};

	emit valueChanged(this->fxName, valueName, valueStr);
};

void menuPage::setDisplayToFxName()
{
	emit valueChanged(this->fxName, "", "");
};
