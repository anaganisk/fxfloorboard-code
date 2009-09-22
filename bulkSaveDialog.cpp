/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. 
** All rights reserved.
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

#include <QtGui>
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QMessageBox>
#include "bulkSaveDialog.h"
#include "globalVariables.h"


// Platform-dependent sleep routines.
#ifdef Q_OS_WIN
  #include <windows.h>
  #define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants & Mac
  #include <unistd.h>
  #define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

bulkSaveDialog::bulkSaveDialog()
{            
  QGroupBox *patchRangeGroup = new QGroupBox(tr("Set range of Patch data to save"));

	QLabel *startRangeLabel = new QLabel(tr("Start Bank."));
	QLabel *finishRangeLabel = new QLabel(tr("Finish Bank."));

	QCheckBox *systemCheckBox = new QCheckBox(tr("Save System Data"));
	QSpinBox *startRangeSpinBox = new QSpinBox;
	QSpinBox *finishRangeSpinBox = new QSpinBox;

	this->systemCheckBox = systemCheckBox;
		
	this->startRangeSpinBox = startRangeSpinBox;
	startRangeSpinBox->setValue(1);
	startRangeSpinBox->setRange(1, 50);
	startRangeSpinBox->setPrefix("Start at U");
	startRangeSpinBox->setSuffix("-1");

	this->finishRangeSpinBox = finishRangeSpinBox;
	finishRangeSpinBox->setValue(1);    // needs to be 50
	finishRangeSpinBox->setRange(1, 50);
	finishRangeSpinBox->setPrefix("Finish at U");
	finishRangeSpinBox->setSuffix("-4");

	QVBoxLayout *rangeLabelLayout = new QVBoxLayout;
	rangeLabelLayout->addSpacing(12);
	rangeLabelLayout->addWidget(startRangeLabel);
	rangeLabelLayout->addWidget(finishRangeLabel);

	QVBoxLayout *rangeBoxLayout = new QVBoxLayout;
	rangeBoxLayout->addWidget(systemCheckBox);
	rangeBoxLayout->addSpacing(12);
	rangeBoxLayout->addWidget(startRangeSpinBox);
	rangeBoxLayout->addSpacing(12);
	rangeBoxLayout->addWidget(finishRangeSpinBox);

	QHBoxLayout *dataRangeLayout = new QHBoxLayout;
	dataRangeLayout->addSpacing(20);
	dataRangeLayout->addLayout(rangeLabelLayout);
	//dataRangeLayout->addSpacing(12);
	dataRangeLayout->addLayout(rangeBoxLayout);
	dataRangeLayout->addSpacing(20);

	patchRangeGroup->setLayout(dataRangeLayout);

  this->startButton = new QPushButton(this);
  this->startButton->setText("Start");
  connect(startButton, SIGNAL(clicked()), this, SLOT(backup()));
  
  this->completedButton = new QPushButton(this);
  this->completedButton->setText("DATA TRANSFER COMPLETED");
  this->completedButton->hide();
  connect(completedButton, SIGNAL(clicked()), this, SLOT(close()));
  
	this->cancelButton = new QPushButton(this);
	this->cancelButton->setText("Cancel");
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(terminate()));
  
  this->progressLabel = new QLabel(this);
  this->progressLabel->setText("Full Backup may take up to 2 minutes");
  this->bytesLabel = new QLabel(this);
  this->bytesLabel->setText("");
  
  this->progressBar = new QProgressBar(this);
	this->progressBar->setTextVisible(false);
	this->progressBar->setRange(0, 100);
	this->progressBar->setValue(0);  
 
	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addSpacing(20);
	buttonsLayout->addWidget(startButton);
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(cancelButton);
	buttonsLayout->addSpacing(20);
	
	QHBoxLayout *progressBarLayout = new QHBoxLayout;	
	progressBarLayout->addWidget(progressBar);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addLayout(buttonsLayout, Qt::AlignCenter);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addWidget(patchRangeGroup, Qt::AlignCenter);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addWidget(progressLabel, Qt::AlignCenter);
	
	mainLayout->addWidget(bytesLabel, Qt::AlignCenter);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addWidget(completedButton);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addLayout(progressBarLayout, Qt::AlignCenter);
	setLayout(mainLayout);

	setWindowTitle(tr("Bulk File Backup"));
	
	QObject::connect(this, SIGNAL( startRangeSpinBox->valueChanged(int) ), this, SLOT( bankStart(int) ));
	QObject::connect(this, SIGNAL( finishRangeSpinBox->valueChanged(int) ), this, SLOT( bankFinish(int) ));
	SysxIO *sysxIO = SysxIO::Instance();
	QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
	QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
	QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString)));	 
};

void bulkSaveDialog::run()
{
  
  
  
  
  terminate(); 
};

void bulkSaveDialog::terminate()
{
  
  //close();
};
void bulkSaveDialog::backup()
{
  this->startButton->hide();
  this->cancelButton->hide();
  this->bankStart = this->startRangeSpinBox->value();
  this->bankFinish = this->finishRangeSpinBox->value();
  this->bank=bankStart*4;
	bulk.clear();
	this->progress = 0;
	this->patch = 1;
	range = 200/(bankFinish-bankStart+1);
	requestPatch(bank/4, patch);  
};

void bulkSaveDialog::requestPatch(int bank, int patch) 
{	
SysxIO *sysxIO = SysxIO::Instance();
	if(sysxIO->isConnected() && sysxIO->deviceReady() )
	{
	  SysxIO *sysxIO = SysxIO::Instance();
		QObject::connect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(updatePatch(QString)));					
		sysxIO->requestPatch(bank, patch);    		
	};
};

void bulkSaveDialog::updatePatch(QString replyMsg)
{
	SysxIO *sysxIO = SysxIO::Instance(); 
	QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(updatePatch(QString)));		
	sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
	
	replyMsg = replyMsg.remove(" ").toUpper();       // TRANSLATE SYSX MESSAGE FORMAT to 128 byte data blocks 
	if (replyMsg.size()/2 == 1530){              // size of patch sent from GT10B   GT-10=1784
	QString header = "F0410000003012";
	QString footer ="00F7";
	QString addressMsb = replyMsg.mid(14,4);
	QString part1 = replyMsg.mid(22, 256); 
  part1.prepend("0000").prepend(addressMsb).prepend(header).append(footer);    
	QString part2 = replyMsg.mid(278, 228);
	QString part2B = replyMsg.mid(532, 28);
	part2.prepend("0100").prepend(addressMsb).prepend(header).append(part2B).append(footer); 
	QString part3 = replyMsg.mid(560, 256);
	part3.prepend("0200").prepend(addressMsb).prepend(header).append(footer);
	QString part4 = replyMsg.mid(816, 200);
	QString part4B = replyMsg.mid(816, 200);
	part4.prepend("0300").prepend(addressMsb).prepend(header).append(footer); 
	QString part6 = replyMsg.mid(1042, 200);   //
	part6.prepend("00000000000000000000000000000000000000000000000000000000");
	part6.prepend("0500").prepend(addressMsb).prepend(header).append(footer);   
	QString part7 = replyMsg.mid(1242, 256);   // 
	part7.prepend("0600").prepend(addressMsb).prepend(header).append(footer);   
	QString part8 = replyMsg.mid(1498, 28);  // 
	QString part8B = replyMsg.mid(1552, 172);   // 
	part8.prepend("0700").prepend(addressMsb).prepend(header).append(part8B).append(footer); 
	QString part10 = replyMsg.mid(2062,200);    //
	part10.prepend("00000000000000000000000000000000000000000000000000000000");
	part10.prepend("0900").prepend(addressMsb).prepend(header).append(footer);
	QString part11 = replyMsg.mid(2262, 256);
	part11.prepend("0A00").prepend(addressMsb).prepend(header).append(footer);
	QString part12 = replyMsg.mid(2518, 28);   //
	QString part12B = replyMsg.mid(2572, 228);   //
	part12.prepend("0B00").prepend(addressMsb).prepend(header).append(part12B).append(footer);
	QString part13 = replyMsg.mid(2800, 256);
	part13.prepend("0C00").prepend(addressMsb).prepend(header).append(footer);
	
	replyMsg = "";
	replyMsg.append(part1).append(part2).append(part3).append(part4).append(part6)
  .append(part7).append(part8).append(part10).append(part11).append(part12).append(part13);
  QByteArray data;
  QFile file(":default.syx");   // Read the default GT-10 sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	  QByteArray temp;                      
    temp = data.mid(1495, 282);           // copy patch description from default.syx  address 00 0D 00 00   
	
	QString sysxBuffer; 
	for(int i=0;i<temp.size();i++)
	{
		unsigned char byte = (char)temp[i];
		unsigned int n = (int)byte;
		QString hex = QString::number(n, 16).toUpper();     // convert QByteArray to QString
		if (hex.length() < 2) hex.prepend("0");
		sysxBuffer.append(hex);
  };
	replyMsg.append(sysxBuffer);
	
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
	bulk.append(replyMsg); 	                                           // add patch to the bulk string.
	}; 	       
	      ++patch; 
        if(patch>4) {patch=1; bank=bank+4;};	                      // increment patch.
        progress=progress+range;
        bulkStatusProgress(this->progress);                         // advance the progressbar.
        int bf = (bankFinish+1)*4 -2;
  if (bank >= bf) 
      {                                                             // check if finished.
        this->completedButton->show();
        this->progressLabel->setText("Bulk data transfer completed!!");
      };              
  if (bank<(bankFinish+1)*4 )
  {      
        bool ok;
        QString patchText;
        QString name = replyMsg.mid(22, 32);                       // get name from loaded patch. 
        QList<QString> x;        
        for (int b=0;b<16;b++)
        {
          x.append(name.mid(b*2, 2));       
        };
        for (int b=0;b<16;b++)
        {
        	QString hexStr = x.at(b);			
		      patchText.append( (char)(hexStr.toInt(&ok, 16)) );      // convert name to readable text characters.
        };
        
  QString patchNumber = QString::number(bank/4, 10).toUpper();
  if (patchNumber.size()<2) { patchNumber.prepend("0"); };
  patchNumber.prepend( "Copying U:" );
  patchNumber.append("-");
  patchNumber.append( QString::number(patch, 10).toUpper() );
  patchNumber.append("     ");
  patchNumber.append(patchText);
  patchText=patchNumber;   
  this->progressLabel->setText(patchText);                        //display the patch number and name.
  
  patchNumber = "File build size = ";
  int size = (bulk.size()/2)+1777;
  patchNumber.append(QString::number(size, 10).toUpper() );
  patchNumber.append(" bytes");
  this->bytesLabel->setText(patchNumber);                         //display the bulk data size.
  
  setStatusMessage("Bulk Download");  
  requestPatch(bank/4, patch);                                   //request the next patch.
  } else {
  setStatusMessage("Ready");
  sysxIO->bulk = this->bulk;  
  };
   
};

void bulkSaveDialog::bulkStatusProgress(int value)
{
   value=value/8;
  if (value >100) {value = 100;};
  if (value<0) {value = 0; };
	this->progressBar->setValue(value);
};

void bulkSaveDialog::bulkStatusPatchName(QString name)
{
  	this->progressLabel->setText(name);
};

