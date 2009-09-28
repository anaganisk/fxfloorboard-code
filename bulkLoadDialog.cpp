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
#include "bulkLoadDialog.h"
#include "Preferences.h"
#include "globalVariables.h"


// Platform-dependent sleep routines.
#ifdef Q_OS_WIN
  #include <windows.h>
  #define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants & Mac
  #include <unistd.h>
  #define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

bulkLoadDialog::bulkLoadDialog()
{ 

  Qt::WindowStaysOnTopHint;
  QLabel *startListLabel = new QLabel(tr("Starting from"));
  this->startPatchCombo = new QComboBox(this);
  QLabel *finishListLabel = new QLabel(tr("Finishing at"));
	this->finishPatchCombo = new QComboBox(this);
  QObject::connect(startPatchCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(comboValueChanged(int)));
  QObject::connect(finishPatchCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(comboValueChanged(int)));	
	QVBoxLayout *comboBoxLayout = new QVBoxLayout;
	comboBoxLayout->addWidget(startListLabel);
	comboBoxLayout->addWidget(startPatchCombo);
  comboBoxLayout->addStretch(1);
	comboBoxLayout->addSpacing(12);
	comboBoxLayout->addWidget(finishListLabel);
  comboBoxLayout->addWidget(finishPatchCombo);
	
	QGroupBox *patchListGroup = new QGroupBox(tr("Set the Range of Patch data to restore"));
  patchListGroup->setLayout(comboBoxLayout);

  QLabel *startRangeLabel = new QLabel(tr("Start Bank."));
	QLabel *finishRangeLabel = new QLabel(tr("Finish Bank."));

	this->startRangeComboBox = new QComboBox(this);
	QObject::connect(startRangeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboValueChanged(int)));
	this->finishRange = new QLineEdit(this);
	this->finishRange->setReadOnly(true);
	
	QVBoxLayout *rangeLabelLayout = new QVBoxLayout;
	rangeLabelLayout->addSpacing(12);
	rangeLabelLayout->addWidget(startRangeLabel);
	rangeLabelLayout->addSpacing(12);
	rangeLabelLayout->addWidget(finishRangeLabel);

  QHBoxLayout *spinBoxLayout = new QHBoxLayout;
  spinBoxLayout->addWidget(startRangeComboBox);
    
	QVBoxLayout *rangeBoxLayout = new QVBoxLayout;
	rangeBoxLayout->addSpacing(12);
	rangeBoxLayout->addLayout(spinBoxLayout);
	rangeBoxLayout->addSpacing(12);
	rangeBoxLayout->addWidget(finishRange);

	QHBoxLayout *dataRangeLayout = new QHBoxLayout;
	dataRangeLayout->addSpacing(20);
	dataRangeLayout->addLayout(rangeLabelLayout);
	dataRangeLayout->addLayout(rangeBoxLayout);
	dataRangeLayout->addSpacing(20);

	QGroupBox *patchRangeGroup = new QGroupBox(tr("Set start location of Patch data to restore"));
  patchRangeGroup->setLayout(dataRangeLayout);

  this->startButton = new QPushButton(this);
  this->startButton->setText("Start");
  connect(startButton, SIGNAL(clicked()), this, SLOT(sendData()));
  
  this->completedButton = new QPushButton(this);
  this->completedButton->setText("DATA TRANSFER COMPLETED");
  this->completedButton->hide();
  connect(completedButton, SIGNAL(clicked()), this, SLOT(close()));
  
	this->cancelButton = new QPushButton(this);
	this->cancelButton->setText("Cancel");
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
  
  this->progressLabel = new QLabel(this);
  this->progressLabel->setText("Full Restoration may take up to 2 minutes");
  this->bytesLabel = new QLabel(this);
  this->bytesLabel->setText("");
  
  this->progressBar = new QProgressBar(this);
	this->progressBar->setTextVisible(false);
	this->progressBar->setRange(0, 100);
	this->progressBar->setValue(0);  
	 
	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addSpacing(40);
	buttonsLayout->addWidget(startButton);
	buttonsLayout->addStretch(1);
	buttonsLayout->addSpacing(20);
	buttonsLayout->addWidget(cancelButton);
	buttonsLayout->addSpacing(40);
	
	QHBoxLayout *progressBarLayout = new QHBoxLayout;	
	progressBarLayout->addWidget(progressBar);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(patchListGroup, Qt::AlignCenter);
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

	setWindowTitle(tr("Bulk File Restoration"));
	
	bulk.clear();
	
	
	SysxIO *sysxIO = SysxIO::Instance();
	QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
	QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
	QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString)));	
  
  Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getOpenFileName(
                this,
                "Choose a file",
                dir,
                "GT10B Bulk Data File (*.gxb *.syx *.mid)");
	if (!fileName.isEmpty())	
	{
	
	QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
	{
		this->data = file.readAll();     // read the pre-selected file, copy to 'data'
		QByteArray GXB_default;
		QFile file(":default.syx");           // Read the default GT-10B sysx file .
    if (file.open(QIODevice::ReadOnly))
	  {	default_data = file.readAll(); };
	  QFile GXBfile(":default.gxb");           // Read the default GT-10B GXB file .
    if (GXBfile.open(QIODevice::ReadOnly))
	  {	GXB_default = GXBfile.readAll(); };
	  QFile hexfile(":HexLookupTable.hex");           // Read the HexLookupTable for the SMF header file .
    if (hexfile.open(QIODevice::ReadOnly))
	  {	this->hextable = hexfile.readAll(); };
	  
	  QByteArray default_header = default_data.mid(0, 7);           // copy header from default.syx
	  QByteArray file_header = data.mid(0, 7);                      // copy header from read file.syx
	  QByteArray GXB_header = GXB_default.mid(3, 20);                // copy header from default.gxb
	  QByteArray SMF_header = hextable.mid(288,18);
	  QByteArray SMF_file = data.mid(0, 18);
	  unsigned char r = (char)data[7];     // find patch number in file (msb))
	  bool ok;
    int patchNum;
    patchNum = QString::number(r, 16).toUpper().toInt(&ok, 16);
	  bool isPatch = false;
	  if (patchNum >= 16) { isPatch = true; };    // check the sysx file is a valid patch & not system data.
	  
	  bool isHeader = false;
	  if (default_header == file_header) {isHeader = true;};
	  QByteArray GTM_bit =  default_data.mid(1765, 5);              // see if the file has a GT-Manager signature.
	  QByteArray GTM_file = data.mid(1764, 5);
	  bool isGTM = false;
	  if (GTM_bit == GTM_file) {isGTM = true;};
	  bool isGXB = false;
	  if (data.contains(GXB_header)){isGXB = true; };             // see if file is a GXB type and set isGXB flag.
	  bool isSMF = false;
	  if (data.contains(SMF_header)) {isSMF = true; };
	  
	  if (isHeader == true && isPatch == true) {loadSYX(); }
	  else if (isGXB == true) { loadGXB(); }
	  else if (isSMF == true) { loadSMF(); };
	  };
	};
};

void bulkLoadDialog::comboValueChanged(int value)
{
  this->bankStart = this->startRangeComboBox->currentIndex();
  this->startList = this->startPatchCombo->currentIndex();
  this->finishList = this->finishPatchCombo->currentIndex();
  if (startList > finishList) {this->startPatchCombo->setCurrentIndex(finishList); }
  else if (finishList < startList) {this->finishPatchCombo->setCurrentIndex(startList); }; 
  int x = (bankStart+(finishList-startList));
  if (x<0) {x=0; } else if (x>199) { x=199; bankStart=199-(finishList-startList);  startRangeComboBox->setCurrentIndex(199-(finishList-startList)); };
  QString text = "Finish at U";
  int y = x/4; y = y*4; y=x-y;
  text.append(QString::number((x/4)+1, 10).toUpper() );
  text.append("-");
  text.append(QString::number(y+1, 10).toUpper() );
  this->finishRange->setText(text); 
  this->startRangeComboBox->setMaxVisibleItems(200-(finishList-startList));
}; 

void bulkLoadDialog::valueChanged(int value)
{ 
  QApplication::beep(); 
  int x = (bankStart+(finishList-startList)/4);
  if (x<1) {x=1; };
  QString text = "Finish at U";
  text.append(QString::number(x, 10).toUpper() );
  text.append("-x");
  this->finishRange->setText(text); 
  
};

void bulkLoadDialog::sendData() 
{	
  bankStart = this->startRangeComboBox->currentIndex()+1;
  startList = this->startPatchCombo->currentIndex();
  finishList = this->finishPatchCombo->currentIndex();
  startButton->hide();
  cancelButton->hide();
  //progress = 0;
  //patch = 1;
  //range = 200/(patchRange-bankStart+1);
   
   int z = (this->bankStart);
   QString q;
   QString address;
   QString msg;
   QString v;
   QString addrMSB = "10";
   QString replyMsg;
   for (int a=startList;a<(finishList+1);a++)
   {
      if (z>128) {z=z-128; addrMSB = "11"; };          // next address range when > 10 7F.
      address = QString::number(z-1, 16).toUpper();
      if (address.size()<2){ address.prepend("0"); };
      int b = a*1777;                                // multiples of patch size.
       msg = this->bulk.mid(b*2, 1777*2);             // copy next patch from bulk patch list.
           for (int g=0;g<msg.size()/2;g++)
           {
             v = msg.mid(g*2, 2);
	           if (v == "F0") {msg.replace((g*2)+14, 2, addrMSB); msg.replace((g*2)+16, 2, address); };   // replace the message address
           };                            
        replyMsg.append(msg);
         ++z;          
   };
         
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
	              
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->sendSysx(replyMsg);

 	   /*    
	      ++patch; 
        if(patch>4) {patch=1; bank=bank+4;};	                      // increment patch.
        progress=progress+range;
        bulkStatusProgress(this->progress);                         // advance the progressbar.
        int bf = (patchRange+1)*4 -2;
  if (bank >= bf) 
      {                                                            // check if nearly finished.
        this->completedButton->show();        
        this->progressLabel->setText("Bulk data transfer completed!!");              
      };              
  if (bank<(patchRange+1)*4 )
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
  patchNumber.prepend( "User Patch U" );
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
  
  setStatusMessage("Bulk Upload");  
  requestPatch(bank/4, patch);                                   //request the next patch.
  } else {
  setStatusMessage("Ready");
    
  };      */
  
  
	close();
};

void bulkLoadDialog::updatePatch()
{
  patchCount = sysxPatches.size()/1777;
  QString msgText;
  QString patchText;
	QString patchNumber;
	unsigned char r;
	this->patchList.clear();
  unsigned int a = 11; // locate patch text start position from the start of the file
     for (int h=0;h<patchCount;h++)
       {       
        for (int b=0;b<16;b++)
           {
             r = (char)sysxPatches[a+b];
             patchText.append(r);
           };
            patchNumber = QString::number(h+1, 10).toUpper();
            msgText.append(patchNumber + " : ");
            msgText.append(patchText + "   ");
            this->patchList.append(msgText);
            patchText.clear();
            msgText.clear();
            a=a+1777;                      // offset is set in front of marker
        }; 
   this->startPatchCombo->addItems(patchList);            // add patch names to the combobox lists.
   this->finishPatchCombo->addItems(patchList);
   this->finishPatchCombo->setCurrentIndex(patchCount-1);     // set the finish combobox index to the end of the list.
   this->startPatchCombo->setCurrentIndex(0);
   QString text = "Finish at U";
   if (patchCount<4) {patchCount=4; };
   text.append(QString::number(patchCount/4, 10).toUpper() );
   text.append("-x");
   this->finishRange->setText(text);   
   
   	QString U = "U";
	for (int x=0; x<50; x++)
	{
    QString bnk = "U" + QString::number(x+1, 10).toUpper() + "-1";
    this->startRangeComboBox->addItem(bnk);
    bnk = "U" + QString::number(x+1, 10).toUpper() + "-2";
    this->startRangeComboBox->addItem(bnk);
    bnk = "U" + QString::number(x+1, 10).toUpper() + "-3";
    this->startRangeComboBox->addItem(bnk);
    bnk = "U" + QString::number(x+1, 10).toUpper() + "-4";
    this->startRangeComboBox->addItem(bnk);      
  }; 
    this->startRangeComboBox->setCurrentIndex(0);
        	
	QString sysxBuffer; 
	for(int i=0;i<sysxPatches.size();i++)
	{
		unsigned char byte = (char)sysxPatches[i];
		unsigned int n = (int)byte;
		QString hex = QString::number(n, 16).toUpper();     // convert QByteArray to QString
		if (hex.length() < 2) hex.prepend("0");
		sysxBuffer.append(hex);
  };
	bulk.append(sysxBuffer);                                // add patch to the bulk string.
};

void bulkLoadDialog::bulkStatusProgress(int value)
{
   value=value/8;
  if (value >100) {value = 100;};
  if (value<0) {value = 0; };
	this->progressBar->setValue(value);
};

void bulkLoadDialog::loadGXB()         // ************************************ GXB File Format***************************
{	
  unsigned char r = (char)data[35];     // find patch count in GXB file at byte 35, 1~200
	bool ok;
  int count;
  count = QString::number(r, 16).toUpper().toInt(&ok, 16);
  QByteArray marker;
  
  marker = data.mid(170, 2);      //copy marker key to find "06A5" which marks the start of each patch block
	unsigned int a = data.indexOf(marker, 0); // locate patch start position from the start of the file
   a=a+2;                             // offset is set in front of marker  
     for (int h=0;h<count;h++)
       {
           QByteArray temp;
           temp = data.mid(a, 128);
           default_data.replace(11, 128, temp);      //address "00" +
           temp = data.mid(a+128, 128);
           default_data.replace(152, 128, temp);     //address "01" + 
           temp = data.mid(a+256, 128);
           default_data.replace(293, 128, temp);     //address "02" + 
           temp = data.mid(a+384, 100);
           default_data.replace(434, 100, temp);     //address "03" +      no "04"   
           temp = data.mid(a+640, 128);
           default_data.replace(547, 128, temp);     //address "05" +        
           temp = data.mid(a+768, 128);
           default_data.replace(688, 128, temp);     //address "06" +    
           temp = data.mid(a+896, 100);
           default_data.replace(829, 100, temp);     //address "07" +      no "08"
           temp = data.mid(a+1152, 128);
           default_data.replace(942, 128, temp);     //address "09" +
           temp = data.mid(a+1280, 128);
           default_data.replace(1083, 128, temp);    //address "0A" +      
           temp = data.mid(a+1408, 128);
           default_data.replace(1224, 128, temp);    //address "0B" +     
           temp = data.mid(a+1536, 128);
           default_data.replace(1365, 128, temp);    //address "0C" +  
            a = data.indexOf(marker, a); // locate patch start position from the start of the file
            a=a+2;                      // offset is set in front of marker
            temp = default_data;
           this->sysxPatches.append(temp);
        };                               
   updatePatch();   
};

void bulkLoadDialog::loadSYX()        //********************************* SYX File Format *****************************
{	
    sysxPatches = data;
    updatePatch();  
};

void bulkLoadDialog::loadSMF()    // **************************** SMF FILE FORMAT ***************************
{	
  
	QByteArray temp;                         // TRANSLATION of GT-10B SMF PATCHES, data read from smf patch **************
	if ( data.at(37) != default_data.at(5) ){    // check if a valid GT-10B file
  QMessageBox *msgBox = new QMessageBox();
	msgBox->setWindowTitle(QObject::tr("SMF file import"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+1'><b>");
	msgText.append(QObject::tr("This is not a GT-10B file!"));
	msgText.append("<b></font><br>");
	msgText.append(QObject::tr("this file is a GT-10 Guitar version<br>"));
	msgText.append(QObject::tr("*Loading this file may have unpredictable results*."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();  
  };      
      int count = (data.size()-32)/1806;  
      int a=0;                             // offset is set to first patch  
     for (int h=0;h<count;h++)
       {       
          temp = data.mid(a+43, 128);            // copy SMF 128 bytes
	       default_data.replace(11, 128, temp);             // replace gt10 address "00"...
	       temp = data.mid(a+171, 114);           // copy SMF part1...
	       temp.append(data.mid(a+301,14));       // copy SMF part2...
          default_data.replace(152, 128, temp);            // replace gt10 address "01"...
	       temp = data.mid(a+315, 128);           // copy SMF part1...
        	default_data.replace(293, 128, temp);            // replace gt10 address "02"...
	       temp = data.mid(a+443, 100);           // copy SMF part1...
	       default_data.replace(434, 100, temp);            // replace gt10 address "03"...
	       temp = data.mid(a+715, 86);            // copy SMF part1...
        	temp.append(data.mid(a+817,42));       // copy SMF part2...
        	default_data.replace(547, 128, temp);             // replace gt10 address "05"...
        	temp = data.mid(a+859, 128);           // copy SMF part1...
        	default_data.replace(688,128, temp);             // replace gt10 address "06"...
        	temp = data.mid(a+987, 72);            // copy SMF part1...
        	temp.append(data.mid(a+1075,28));      // copy SMF part2...
        	default_data.replace(829, 100, temp);            // replace gt10 address "07"...
        	temp = data.mid(a+1259, 58);           // copy SMF part1...
        	temp.append(data.mid(a+1333,42));      // copy SMF part2...
        	default_data.replace(942, 100, temp);           // replace gt10 address "09"...
        	temp = data.mid(a+1403, 128);          // copy SMF part1...
        	default_data.replace(1083,128, temp);            // replace gt10 address "0A"...
        	temp = data.mid(a+1531, 44);           // copy SMF part1...
        	temp.append(data.mid(a+1591,84));      // copy SMF part2...
        	default_data.replace(1224, 128, temp);           // replace gt10 address "0B"...
        	temp = data.mid(a+1675, 128);          // copy SMF part1...
        	default_data.replace(1365,128, temp);            // replace gt10 address "0C"...           
          a=a+1806;                      // offset is set in front of marker
          temp = default_data;
          this->sysxPatches.append(temp);
        }; 
       updatePatch();                	
};
