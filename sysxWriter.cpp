/****************************************************************************
**
** Copyright (C) 2007, 2008 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-10B Fx FloorBoard".
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed data the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along
** with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**
****************************************************************************/

#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QMessageBox>
#include "sysxWriter.h"	
#include "fileDialog.h"
#include "globalVariables.h"

sysxWriter::sysxWriter() 
{
	
};

sysxWriter::~sysxWriter()
{

};

void sysxWriter::setFile(QString fileName)
{
	this->fileName = fileName;
	this->fileSource.address.clear();
	this->fileSource.hex.clear();
};

bool sysxWriter::readFile()
{	
	QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
	{
		QByteArray data = file.readAll();     // read the pre-selected file, copy to 'data'
		QByteArray default_data;
		QByteArray GXB_default;
		QByteArray hextable;
		QFile file(":default.syx");           // Read the default GT-10B sysx file .
    if (file.open(QIODevice::ReadOnly))
	  {	default_data = file.readAll(); };
	  QFile GXBfile(":default.gxb");           // Read the default GT-10B GXB file .
    if (GXBfile.open(QIODevice::ReadOnly))
	  {	GXB_default = GXBfile.readAll(); };
	  QFile hexfile(":HexLookupTable.hex");           // Read the HexLookupTable for the SMF header file .
    if (hexfile.open(QIODevice::ReadOnly))
	  {	hextable = hexfile.readAll(); };
	  
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
	  
		SysxIO *sysxIO = SysxIO::Instance();
    if(data.size() == 2366 && isHeader == true)  {         //if GT-10B SYSTEM file size is correct- load file. 
		QString area = "System";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->systemSource = sysxIO->getSystemSource();		
		return true;
		}                                                                                 //***************** SYX ******************
    else if(isPatch == true && /*data.size() == 1777 && */isHeader == true){         //1777 if GT-10B SYX PATCH file size is correct- load file >>>  currently at 1763 bytes.
	index = 1;
  int patchCount = data.size()/1777;
  if (patchCount>1)
  {
  QString msgText;
  QString patchText;
	QString patchNumber;
	unsigned char r;
	this->patchList.clear();
	this->patchList.append(QObject::tr("Select Patch"));
  unsigned int a = 11; // locate patch text start position from the start of the file
     for (int h=0;h<patchCount;h++)
       {       
        for (int b=0;b<16;b++)
           {
             r = (char)data[a+b];
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
              
    fileDialog *dialog = new fileDialog(fileName, patchList); 
    dialog->exec();    
    patchIndex(this->index);                          
   };   
     
   int a=0;                             // offset is set to first patch
   if (patchCount>1)
   {
    int q=index-1; 
    a = q*1777;  
   };
   if (index>0)
    { 
     QByteArray temp = data.mid(a, 1777);  
    SysxIO *sysxIO = SysxIO::Instance();
		QString area = "Structure";
		sysxIO->setFileSource(area, temp);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;}  else { return false; };
		}
		else if((data.size() == patchSize || data.size() == 1636) && isHeader == true){         // if GT-10B standard patch file size is correct- load file.
		QByteArray standard_data = data;
	  QFile file(":default.syx");   // Read the default GT-10 sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	  
	  QByteArray temp;                      
    temp = data.mid(1495, 282);           // copy patch description from default.syx  address 00 0D 00 00   
    standard_data.append(temp);  
    data = standard_data;
    SysxIO *sysxIO = SysxIO::Instance();
		QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
		}	else if (data.size() == 684){      // if the file size = gt-6b patch
		
	QMessageBox *msgBox = new QMessageBox();
	msgBox->setWindowTitle(QObject::tr("Patch file conversion"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+1'><b>");
	msgText.append(QObject::tr("This is a GT-6B patch!"));
	msgText.append("<b></font><br>");
	msgText.append(QObject::tr("*Note that conversions may not be consistant*."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();
	
	QByteArray gt6b_data = data;
	QFile file(":default.syx");   // Read the default GT-10B sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	{	data = file.readAll(); };
	char r;
	QByteArray temp;                         // TRANSLATION of GT-6B PATCHES, data read from gt6b patch **************
	QByteArray Qhex;                         // and used to replace gt10b patch data*********************************
  QFile hexfile(":HexLookupTable.hex");    // use a QByteArray of hex numbers from a lookup table.
    if (hexfile.open(QIODevice::ReadOnly))
	{	Qhex = hexfile.readAll(); };
	 temp = gt6b_data.mid(403, 14);          // copy gt6b name
	 temp.append(Qhex.mid(32, 1));
	 temp.append(Qhex.mid(32, 1));           // add 2 blank spaces as gt6b has only 14 characters
	data.replace(11, 16, temp);              // replace gt10b name
	temp = gt6b_data.mid(10,1);              // copy off/on
	data.replace(91, 1, temp);               // replace gt10b compressor
	r = gt6b_data.at(12);                    // copy cs type
	temp = Qhex.mid((128+r), 1);             // convert COMPRESSOR types from HexLookupTable 128->
	data.replace(92, 1, temp);               // replace gt10b compressor
	temp = gt6b_data.mid(19,2);              // copy gt6b compressor tone & level
	temp.append(gt6b_data.mid(15,1));        // copy gt6b compressor sustain
	temp.append(gt6b_data.mid(13,2));        // copy gt6b compressor attack & threshold
	temp.append(gt6b_data.mid(16,1));        // copy gt6b compressor ratio (big 1 only)
	temp.append(gt6b_data.mid(13,1));        // copy gt6b compressor attack again
  temp.append(gt6b_data.mid(18,1));        // copy gt6b compressor release
	data.replace(93, 8, temp);               // replace gt10b compressor...
	temp = gt6b_data.mid(100, 1);            // copy gt6b dist/od on/off
	data.replace(123, 1, temp);              // replace gt10 distortion
	r = gt6b_data.at(102);                   // copy gt6b dist type
	temp = Qhex.mid((133+r), 1);             // convert DISTORTION types from HexLookupTable 133->
	data.replace(124, 1, temp);              // replace gt10b distortion
	temp = gt6b_data.mid(103,5);             // copy gt6b dist/od part2
	data.replace(125, 5, temp);              // replace gt10b distortion

  temp = gt6b_data.mid(120, 1);            // copy gt6b preAmp off/on
  data.replace(232, 1, temp);              // replace gt10b preamp off/on
  r = gt6b_data.at(122);                   // copy gt6b preamp type
	temp = Qhex.mid((144+r), 1);             // convert PRE-AMP types from HexLookupTable 144->
	data.replace(233, 1, temp);              // replace gt10b preamp type
	temp = gt6b_data.mid(128,1);             // copy gt6b preAmp gain
	temp.append(gt6b_data.mid(133,1));        // copy gt6b preAmp bass
	temp.append(gt6b_data.mid(131,1));        // copy gt6b preAmp mid
	temp.append(gt6b_data.mid(129,1));        // copy gt6b preAmp treble
	temp.append(gt6b_data.mid(135,1));        // copy gt6b preAmp level
	temp.append(gt6b_data.mid(123,1));        // copy gt6b preAmp bright
	temp.append(gt6b_data.mid(132,1));        // copy gt6b preAmp mid freq
	temp.append(gt6b_data.mid(134,1));        // copy gt6b preAmp ultra low
	temp.append(gt6b_data.mid(130,1));        // copy gt6b preAmp ultra hi
	temp.append(gt6b_data.mid(125,1));        // copy gt6b preAmp response
	temp.append(gt6b_data.mid(124,1));        // copy gt6b preAmp deep
	temp.append(gt6b_data.mid(127,1));        // copy gt6b preAmp shape
	temp.append(gt6b_data.mid(126,1));        // copy gt6b preAmp enhancer
	data.replace(234, 13, temp);              // replace gt10b preamp
	r = gt6b_data.at(138);                   // copy gt6b spkr type
	temp = Qhex.mid((152+r), 1);             // convert SPEAKER types from HexLookupTable 152->
	data.replace(247, 1, temp);              // replace gt10b spkr type
	temp = gt6b_data.mid(136, 1);            // read gt6b spkr off/on
	if (temp == Qhex.mid((151), 1)){         // if spkr is off
  temp = Qhex.mid((151), 1);               // read 00 from HexLookupTable 151->
	data.replace(247, 1, temp);   };         // replace gt10b spkr type to OFF   
	temp = gt6b_data.mid(139,3);             // copy gt6b spkr settings
	data.replace(248, 3, temp);              // replace gt10b spkr settings
	
	
	
	temp = gt6b_data.mid(155, 1);             // copy gt6b EQ off/on
	//temp.append(gt6b_data.mid(288,11));                     // copy gt8 EQ part2 ...yet to do
	data.replace(264, 1, temp);               // replace gt10b EQ
	
	
	temp = gt6b_data.mid(322, 1);            // copy gt6b delay off/on
	temp.append(gt6b_data.mid(333,1));       // copy gt6b delay type
	data.replace(1083, 2, temp);             // replace gt10b delay
	r = gt6b_data.at(334);                   // copy gt6b delay time
	temp = Qhex.mid((r/6), 1);               // convert delay time to delay MSB
	data.replace(1085, 1, temp);             // replace gt10b delay
	r = gt6b_data.at(335);                   // copy gt6b delay time
	temp = Qhex.mid((r*5), 1);               // convert delay time to delay LSB
	data.replace(1086, 1, temp);             // replace gt10b delay
	temp = gt6b_data.mid(336, 3);            // copy gt6b delay stuff
	data.replace(1087, 3, temp);             // replace gt10b delay
	temp = gt6b_data.mid(339, 1);            // copy gt6b delay level
	data.replace(1106, 1, temp);             // replace gt10b delay
	temp = Qhex.mid(100, 1);                 // copy 0x64
	data.replace(1107, 1, temp);             // replace gt10b direct to %100
	
	temp = gt6b_data.mid(322, 1);            // copy gt6b reverb off/on
	temp.append(gt6b_data.mid(325,2));       // copy gt6b reverb type & time
	data.replace(1131, 3, temp);             // replace gt10b reverb type & time
	temp = gt6b_data.mid(328,4);             // copy gt6b reverb stuff
	temp.append(Qhex.mid(100, 1));           // copy 0x64 to set direct to %100
	data.replace(1135, 5, temp);             // replace gt10b reverb
	temp = Qhex.mid(151, 1);                 // set pre delay MSB to "00"
	temp.append(gt6b_data.mid(327,1));       // copy gt6b reverb pre-delay	
	data.replace(1141, 2, temp);             // replace gt10b reverb pre-delay LSB
	
	if ( gt6b_data.mid(322, 1) == Qhex.mid(1, 1) ){ // if the rev/dly/sos effect pedal is "ON"
      r = gt6b_data.at(324);               // copy gt6b delay/rev/sos select
      temp = Qhex.mid((160+r), 1);         // set delay off/on state from hexlookuptable->160
      data.replace(1083, 1, temp);         // replace gt10b delay off/on
      temp = Qhex.mid((164+r), 1);         // set reverb off/on state from hexlookuptable->164
      data.replace(1131, 1, temp);         // replace gt10b reverb off/on    
      };
  
	temp = gt6b_data.mid(302, 1);            // copy gt6b chorus off/on
	temp.append(gt6b_data.mid(304,5));       // copy gt6b chorus stuff
	data.replace(1115, 6, temp);             // replace gt10b chorus
	temp = gt6b_data.mid(309,1);             // copy gt6b chorus level
	data.replace(1122, 1, temp);             // replace gt10b chorus
	
	/*
	
	temp.clear();                            // Convert GT8 Chain items to GT10 format 
			r = gt6b_data.at(665);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(666);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(667);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(668);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(669);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(670);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(671);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(672);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(673);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(674);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(675);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(676);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(677);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt6b_data.at(678);
    temp.append(Qhex.mid(r+164, 1));          
	        
	unsigned int a = temp.indexOf(Qhex.mid(4,1)); // locate gt10_preamp 1 **** find "04"
	temp.insert(a-1, Qhex.mid(16, 1));       //insert gt10_split before preamp 1 "10"
	temp.insert(a+1, Qhex.mid(17, 1));       // insert gt10_merge after preamp 1  "11"
	temp.insert(a+1, Qhex.mid(13, 1));     // insert NS_2 "4D"  77
	temp.insert(a+1, Qhex.mid(3, 1));       // insert channel B "43" 67
	data.replace(1492, 18, temp);            // replace gt10 chain
	
	
	temp = gt6b_data.mid(194, 1);             // copy gt8 Loop part1
	temp.append(gt6b_data.mid(196,3));        // copy gt8 Loop part2
	data.replace(1472, 4, temp);             // replace gt10 Loop (Send/Return))
	*/   
	temp = gt6b_data.mid(359, 3);             // copy gt6b NS
	data.replace(1196, 3, temp);             // replace gt10b NS_1
	data.replace(1200, 3, temp);             // replace gt10b NS_2
	/*
	temp = gt6b_data.mid(176, 1);             // copy gt8 wah on/off
	data.replace(1415, 1, temp);             // replace gt10 pedal fx on/off
	r = gt6b_data.at(737);
	temp = Qhex.mid((r+1), 1);               // copy gt8 ExSw Func
	data.replace(1421, 1, temp);             // replace gt10 ExSw 1 Func + 1
	 r = gt6b_data.at(722);
	temp = Qhex.mid((r+1), 1);               // copy gt8 CTL Func
	data.replace(1422, 1, temp);             // replace gt10 CTL 1 Func + 1
	temp = gt6b_data.mid(178, 2);             // copy gt8 wah
	data.replace(1424, 2, temp);             // replace gt10 wah
	temp = gt6b_data.mid(180, 1);             // copy gt8 wah level
	data.replace(1428, 1, temp);             // replace gt10 wah
	// todo replace direct level with effect inverted (optional).
	
	temp = gt6b_data.mid(469, 5);             // copy gt8 pedal bend (fx2)
	data.replace(1435, 5, temp);             // replace gt10 pedal bend
	
	temp = gt6b_data.mid(636, 1);             // copy gt8 FV level
	data.replace(1441, 1, temp);             // replace gt10 FV level
	temp = gt6b_data.mid(637, 1);             // copy gt8 FV vol curve
	data.replace(1444, 1, temp);             // replace gt10 FV vol curve
	temp = gt6b_data.mid(752, 2);             // copy gt8 FV vol min/max
	data.replace(1442, 2, temp);             // replace gt10 FV vol min/max
	
	temp = gt6b_data.mid(651, 1);             // copy gt8 Amp control
	data.replace(1456, 1, temp);             // replace gt10 Amp control
	
	temp = gt6b_data.mid(633, 1);             // copy gt8 Master patch level
	data.replace(1447, 1, temp);             // replace gt10 Master patch level
	temp = gt6b_data.mid(634, 2);             // copy gt8 Master BPM
	data.replace(1454, 2, temp);             // replace gt10 Master BPM
	
	temp = gt6b_data.mid(11, 1);              // copy gt8 FX1 on/off
	data.replace(293, 1, temp);              // replace gt10 FX1 on/off	
	 r = gt6b_data.at(13);
	temp = Qhex.mid((128+r), 1);       // convert FX1 Type: selection items from lookup table Qhex (HexLookupTable.hex file) from 128 to 144
  temp.append(gt6b_data.mid(14, 25));       // copy gt8 FX1 part2
	data.replace(294, 26, temp);             // replace gt10 FX1 part2
	temp = gt6b_data.mid(49, 19);              // copy gt8 FX1 part3
	data.replace(320, 19, temp);             // replace gt10 FX1 part3
	temp = gt6b_data.mid(68, 16);              // copy gt8 FX1 part4
	data.replace(341, 16, temp);             // replace gt10 FX1 part4
	temp = gt6b_data.mid(98, 24);              // copy gt8 FX1 part5
	data.replace(357, 24, temp);             // replace gt10 FX1 part5
	temp = gt6b_data.mid(130, 11);              // copy gt8 FX1 part6
	data.replace(381, 11, temp);              // replace gt10 FX1 part6
	temp = gt6b_data.mid(84, 14);              // copy gt8 FX1 part7
	data.replace(479, 14, temp);             // replace gt10 FX1 part7
	temp = gt6b_data.mid(122, 8);              // copy gt8 FX1 part8
	data.replace(493, 8, temp);              // replace gt10 FX1 part8
	temp = gt6b_data.mid(39, 10);              // copy gt8 FX1 part9
	data.replace(747, 10, temp);               // replace gt10 FX1 part9
	
	
	temp = gt6b_data.mid(312, 1);              // copy gt8 FX2 on/off
	data.replace(815, 1, temp);              // replace gt10 FX2 on/off	
	 r = gt6b_data.at(314);
	temp = Qhex.mid((128+r), 1);       // convert FX2 Type: selection items from lookup table Qhex (HexLookupTable.hex file) from 128 to 144
  temp.append(gt6b_data.mid(315, 25));       // copy gt8 FX2 part2
	data.replace(816, 26, temp);             // replace gt10 FX2 part2
	temp = gt6b_data.mid(350, 19);              // copy gt8 FX2 part3
	data.replace(842, 19, temp);             // replace gt10 FX2 part3
	temp = gt6b_data.mid(369, 16);              // copy gt8 FX2 part4
	data.replace(863, 16, temp);             // replace gt10 FX2 part4
	temp = gt6b_data.mid(399, 24);              // copy gt8 FX2 part5
	data.replace(879, 24, temp);             // replace gt10 FX2 part5
	temp = gt6b_data.mid(431, 11);              // copy gt8 FX2 part6
	data.replace(903, 11, temp);              // replace gt10 FX2 part6
	temp = gt6b_data.mid(385, 14);              // copy gt8 FX2 part7
	data.replace(1001, 14, temp);             // replace gt10 FX2 part7
	temp = gt6b_data.mid(423, 8);              // copy gt8 FX2 part8
	data.replace(1015, 8, temp);              // replace gt10 FX2 part8
	temp = gt6b_data.mid(340, 10);              // copy gt8 FX2 part9
	data.replace(1269, 10, temp);               // replace gt10 FX2 part9
	temp = gt6b_data.mid(442, 4);              // copy gt8 FX2 part10  HR
	temp.append(gt6b_data.mid(447,5)); 
	temp.append(gt6b_data.mid(446,1)); 
	temp.append(gt6b_data.mid(453,1)); 
	data.replace(914, 11, temp);               // replace gt10 FX2 part10  HR
	temp = gt6b_data.mid(454, 6);              // copy gt8 FX2 part11  PS
	temp.append(gt6b_data.mid(461,7));
	temp.append(gt6b_data.mid(460,1));
	temp.append(gt6b_data.mid(468,1));
	data.replace(962, 15, temp);               // replace gt10 FX2 part11  PS
	temp = gt6b_data.mid(474, 18);              // copy gt8 FX2 part12  OC, RT, 2CE
	data.replace(977, 18, temp);               // replace gt10 FX2 part12  OC, RT, 2CE
	temp = gt6b_data.mid(492, 4);              // copy gt8 FX2 part13  AR
	temp.append(gt6b_data.mid(497,4));
	data.replace(1040, 8, temp);               // replace gt10 FX2 part13  AR
	temp = gt6b_data.mid(502, 1);              // copy gt8 FX2 part14  SYN
	temp.append(gt6b_data.mid(501,1));
	temp.append(gt6b_data.mid(503,15));
	data.replace(1023, 17, temp);               // replace gt10 FX2 part14 SYN
	temp = gt6b_data.mid(518, 7);              // copy gt8 FX2 part15  AC
	data.replace(1279, 7, temp);               // replace gt10 FX2 part15 AC
	temp = gt6b_data.mid(525, 3);              // copy gt8 FX2 part16  SH
	data.replace(1266, 3, temp);               // replace gt10 FX2 part16 SH
	temp = gt6b_data.mid(528, 3);              // copy gt8 FX2 part17  SDD
	data.replace(995, 3, temp);               // replace gt10 FX2 part17 SDD
	temp = gt6b_data.mid(531, 1);              // copy gt8 FX2 part18  SDD
	data.replace(999, 1, temp);               // replace gt10 FX2 part18 SDD*/
	
	
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
		                                        
    }	else if (isSMF)                      // SMF ******************************************************************
  {                                        // file contains a .mid type SMF patch file header from Boss Librarian
   
	QByteArray smf_data = data;
	QFile file(":default.syx");              // Read the default GT-10B sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	{	data = file.readAll(); };
	QByteArray temp;                         // TRANSLATION of GT-10B SMF PATCHES, data read from smf patch **************
	if ( smf_data.at(37) != data.at(5) ){    // check if a valid GT-10B file
  QMessageBox *msgBox = new QMessageBox();
	msgBox->setWindowTitle(QObject::tr("SMF file import"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+1'><b>");
	msgText.append(QObject::tr("This is not a GT-10B patch!"));
	msgText.append("<b></font><br>");
	msgText.append(QObject::tr("this file is a GT-10 Guitar version<br>"));
	msgText.append(QObject::tr("*Loading this file may have unpredictable results*."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();  
  };
  
  index = 1;
  int patchCount = (smf_data.size()-32)/1806;
  if (patchCount>1)
  {
  QString msgText;
  QString patchText;
	QString patchNumber;
	unsigned char r;
	this->patchList.clear();
	this->patchList.append(QObject::tr("Select Patch"));
  unsigned int a = 43; // locate patch text start position from the start of the file
     for (int h=0;h<patchCount;h++)
       {       
        for (int b=0;b<16;b++)
           {
             r = (char)smf_data[a+b];
             patchText.append(r);
           };
            patchNumber = QString::number(h+1, 10).toUpper();
            msgText.append(patchNumber + " : ");
            msgText.append(patchText + "   ");
            this->patchList.append(msgText);
            patchText.clear();
            msgText.clear();
            a=a+1806;                      // offset is set in front of marker
        }; 
              
    fileDialog *dialog = new fileDialog(fileName, patchList); 
    dialog->exec();    
    patchIndex(this->index);                          
   };   
     
   int a=0;                             // offset is set to first patch
   if (patchCount>1)
   {
    int q=index-1; 
    a = q*1806;  
   };    
  
	temp = smf_data.mid(a+43, 128);            // copy SMF 128 bytes
	data.replace(11, 128, temp);             // replace gt10 address "00"...
	temp = smf_data.mid(a+171, 114);           // copy SMF part1...
	temp.append(smf_data.mid(a+301,14));       // copy SMF part2...
	data.replace(152, 128, temp);            // replace gt10 address "01"...
	temp = smf_data.mid(a+315, 128);           // copy SMF part1...
	data.replace(293, 128, temp);            // replace gt10 address "02"...
	temp = smf_data.mid(a+443, 100);           // copy SMF part1...
	data.replace(434, 100, temp);            // replace gt10 address "03"...
	temp = smf_data.mid(a+715, 86);            // copy SMF part1...
	temp.append(smf_data.mid(a+817,42));       // copy SMF part2...
	data.replace(547, 128, temp);             // replace gt10 address "05"...
	temp = smf_data.mid(a+859, 128);           // copy SMF part1...
	data.replace(688,128, temp);             // replace gt10 address "06"...
	temp = smf_data.mid(a+987, 72);            // copy SMF part1...
	temp.append(smf_data.mid(a+1075,28));      // copy SMF part2...
	data.replace(829, 100, temp);            // replace gt10 address "07"...
	temp = smf_data.mid(a+1259, 58);           // copy SMF part1...
	temp.append(smf_data.mid(a+1333,42));      // copy SMF part2...
	data.replace(942, 100, temp);           // replace gt10 address "09"...
	temp = smf_data.mid(a+1403, 128);          // copy SMF part1...
	data.replace(1083,128, temp);            // replace gt10 address "0A"...
	temp = smf_data.mid(a+1531, 44);           // copy SMF part1...
	temp.append(smf_data.mid(a+1591,84));      // copy SMF part2...
	data.replace(1224, 128, temp);           // replace gt10 address "0B"...
	temp = smf_data.mid(a+1675, 128);          // copy SMF part1...
	data.replace(1365,128, temp);            // replace gt10 address "0C"...
	
    if (index>0)
    {
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;  
    } else { return false; }; 
  } 
  else if (isGXB)      // if the read file is a Boss Librarian type. ***************************************
  {
  index=1;
  unsigned char r = (char)data[35];     // find patch count in GXB file at byte 35, 1~200
	bool ok;
  int patchCount;
  patchCount = QString::number(r, 16).toUpper().toInt(&ok, 16);
  QByteArray marker;
  if (patchCount>1)
  {
  QString msgText;
  marker = data.mid(170, 2);      //copy marker key to find "06A5" which marks the start of each patch block
	QString patchText;
	QString patchNumber;
	this->patchList.clear();
	this->patchList.append(QObject::tr("Select Patch"));
  unsigned int a = data.indexOf(marker, 0); // locate patch start position from the start of the file
   a=a+2;                             // offset is set in front of marker  
     for (int h=0;h<patchCount;h++)
       {
        for (int b=0;b<16;b++)
           {
             r = (char)data[a+b];
             patchText.append(r);
           };
            patchNumber = QString::number(h+1, 10).toUpper();
            msgText.append(patchNumber + " : ");
            msgText.append(patchText + "   ");
            this->patchList.append(msgText);
            patchText.clear();
            msgText.clear();
        a = data.indexOf(marker, a); // locate patch start position from the start of the file
        a=a+2;                      // offset is set in front of marker
        }; 
              
    fileDialog *dialog = new fileDialog(fileName, patchList); 
    dialog->exec();    
    patchIndex(this->index);                          
   };   
   
   marker = data.mid(170, 2);      //copy marker key to find "06A5" which marks the start of each patch block
   unsigned int a = data.indexOf(marker, 0); // locate patch start position from the start of the file
   a=a+2;                             // offset is set in front of marker
   if (patchCount>1)
   {
    int q=index-1; 
     for (int h=0;h<q;h++)
       {
        a = data.indexOf(marker, a); // locate patch start position from the start of the file
        a=a+2;
       };                             // offset is set in front of marker          
   };    
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
   
   temp = data.mid(32, 1);
   int z = a+1701;
   int y = data.indexOf( temp, (a+1701));          // copy user text, first two sections only, section terminated by "00"
   int x = data.indexOf( temp, (a+1701)) + 1; 
   int w = data.indexOf( temp, (x+1));
   temp = data.mid(z, (y-z) );
   marker = data.mid(31, 1);    //"20"
   if (temp.size()>0 )
    {      
      for (int u = (32-(y-z));u>0; u--)
      { temp.append(marker); };
      if (temp.size()>32) {temp=temp.mid(0, 32); }
      default_data.replace(1647, (y-z), temp);       // paste text 1
    };   
    temp = data.mid(x, (w-x) );
    if (temp.size()>0 )
    {      
      for (int u = (128-(w-x));u>0; u--)
      { temp.append(marker); };
      if (temp.size()>128) {temp=temp.mid(0, 128); }
      default_data.replace(1506, (w-x), temp);            // paste text 2
    };
    
    if (index>0)
    {
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "Structure";
		sysxIO->setFileSource(area, default_data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true; 
    } else { return false; };    
  }
    else  // if nothing else matches, then the file can't be loaded
  {
	QMessageBox *msgBox = new QMessageBox();
	msgBox->setWindowTitle(QObject::tr("Patch can't be loaded"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+2'><b>");
	msgText.append(QObject::tr("This file is not known to the ") + deviceType);
	msgText.append("<b></font><br>");
	if (data.size() == 1763){
  msgText.append(QObject::tr("but appears to be a GT-10 patch<br>"));};
  if (data.size() == 1010){
  msgText.append(QObject::tr("but appears to be a GT-8 patch<br>"));};
  if (data.size() == 670){
  msgText.append(QObject::tr("but appears to be a GT-6 patch<br>"));};
  if (data.size() == 650){
  msgText.append(QObject::tr("but appears to be a GT-3 patch<br>"));};
 	msgText.append(QObject::tr("Patch size is ") + (QString::number(data.size(), 10)) + QObject::tr(" bytes, please try another file."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();
		return false;
	};
	}
	else
	{
		return false;
	};
};

void sysxWriter::patchIndex(int listIndex)
{
  SysxIO *sysxIO = SysxIO::Instance();     
   this->index=sysxIO->patchListValue;   
};

void sysxWriter::writeFile(QString fileName)
{	
	QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
	{
		SysxIO *sysxIO = SysxIO::Instance();
		this->fileSource = sysxIO->getFileSource();
		
		QByteArray out;
		unsigned int count=0;
		for (QList< QList<QString> >::iterator dev = fileSource.hex.begin(); dev != fileSource.hex.end(); ++dev)
		{
			QList<QString> data(*dev);
			for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
			{
				QString str(*code);
				bool ok;
				unsigned int n = str.toInt(&ok, 16);
				out[count] = (char)n;
				count++;
			};
		};
		file.write(out);
	};
};

void sysxWriter::writeSystemFile(QString fileName)
{	
	QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
	{
		SysxIO *sysxIO = SysxIO::Instance();
		this->systemSource = sysxIO->getSystemSource();
		
		QByteArray out;
		unsigned int count=0;
		for (QList< QList<QString> >::iterator dev = systemSource.hex.begin(); dev != systemSource.hex.end(); ++dev)
		{
			QList<QString> data(*dev);
			for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
			{
				QString str(*code);
				bool ok;
				unsigned int n = str.toInt(&ok, 16);
				out[count] = (char)n;
				count++;
			};
		};
		file.write(out);
	};

};

void sysxWriter::writeSMF(QString fileName)
{	
	QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
	{
		SysxIO *sysxIO = SysxIO::Instance();
		this->fileSource = sysxIO->getFileSource();
			
		QByteArray out;
		unsigned int count=0;
		for (QList< QList<QString> >::iterator dev = fileSource.hex.begin(); dev != fileSource.hex.end(); ++dev)
		{
			QList<QString> data(*dev);
			for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
			{
				QString str(*code);
				bool ok;
				unsigned int n = str.toInt(&ok, 16);
				out[count] = (char)n;
				count++;
			};
		};
	out.remove(1495, 282);	   // remove the user text portion at the end..
	QByteArray temp;                        // TRANSLATION of GT-10B PATCHES, data read from gt10B syx patch **************
	QByteArray Qhex;                        // and used to replace gt10B patch SMF data*********************************
  QFile hexfile(":HexLookupTable.hex");   // use a QByteArray of hex numbers from a lookup table.
    if (hexfile.open(QIODevice::ReadOnly))
	{	Qhex = hexfile.readAll(); };
	 
		temp = Qhex.mid((288), 30);
		out.prepend(temp);          // insert midi timing header...
		out.remove(30, 11);         // remove address "00 00" header...
		temp = Qhex.mid((320), 13);
		out.insert(30, temp);       // insert new address "00 00" header...
		out.remove(171, 13);        // remove address "01 00" header...
		temp = Qhex.mid((336), 16);
		out.insert(285, temp);      // insert new address "01 72" header...
		out.remove(315, 13);        // remove address "02 00" header...
		out.remove(443, 13);        // remove address "03 00" header...
		temp = Qhex.mid((352), 16);
		out.insert(543, temp);      // insert new address "03 64" header...
		out.remove(559, 13);        // remove address "05 00" header...
		temp = Qhex.mid((438), 78);
		temp.append(Qhex.mid((438), 78));
		out.insert(559, temp);      // insert 156 "0"'s to replace 04 00 00 00...
		temp = Qhex.mid((368), 16);
		out.insert(801, temp);      // insert new address "05 56" header...
		out.remove(859, 13);        // remove address "06 00" header...
		out.remove(987, 13);        // remove address "07 00" header...
		temp = Qhex.mid((384), 16);
		out.insert(1059, temp);      // insert new address "07 48" header...
		temp = Qhex.mid((438), 78);
		temp.append(Qhex.mid((438), 78));
		out.insert(1103, temp);      // insert 156 "0"'s to replace 08 00 00 00...
		out.remove(1259, 13);        // remove address "09 00" header...
		temp = Qhex.mid((400), 16);
		out.insert(1317, temp);      // insert new address "09 3A" header...
		out.remove(1403, 13);        // remove address "0A 00" header...
		out.remove(1531, 13);        // remove address "0B 00" header...
		out.remove(1659, 13);        // remove address "0C 00" header...
		temp = Qhex.mid((416), 16);
		out.insert(1575, temp);      // insert new address "0B 2C" header...
		out.remove(1803, 2);        // remove file footer...
		temp = Qhex.mid((438), 29);
		out.append(temp);            // insert 29 "0"'s...
		temp = Qhex.mid((432), 3);
		out.insert(1832, temp);      // insert new file footer (part of)...
		out.remove(0, 29);           // remove header-1 for checksum calcs
				
	this->fileSource.address.clear();
	this->fileSource.hex.clear();
	
	QList<QString> sysxBuffer; 
	int dataSize = 0; int offset = 0;
	for(int i=0;i<out.size();i++)
	{
		unsigned char byte = (char)out[i];
		unsigned int n = (int)byte;
		QString hex = QString::number(n, 16).toUpper();
		if (hex.length() < 2) hex.prepend("0");
		sysxBuffer.append(hex);

		unsigned char nextbyte = (char)out[i+1];
		unsigned int nextn = (int)nextbyte;
		QString nexthex = QString::number(nextn, 16).toUpper();
		if (nexthex.length() < 2) nexthex.prepend("0");
		if(offset >= checksumOffset+3 && nexthex != "F7")   // smf offset is 8 bytes + previous byte
		{		
			dataSize += n;
		};
		if(nexthex == "F7")
		{		
			QString checksum;
					bool ok;
					int dataSize = 0;
	        for(int i=checksumOffset+3;i<sysxBuffer.size()-1;++i)
	         { dataSize += sysxBuffer.at(i).toInt(&ok, 16); };
	     QString base = "80";
	     int sum = dataSize % base.toInt(&ok, 16);
	     if(sum!=0) sum = base.toInt(&ok, 16) - sum;
	     checksum = QString::number(sum, 16).toUpper();
	     if(checksum.length()<2) checksum.prepend("0");
	     sysxBuffer.replace(sysxBuffer.size() - 1, checksum);
	
		};
		offset++;

		if(hex == "F7") 
		{	
			this->fileSource.address.append( sysxBuffer.at(sysxAddressOffset + 5) + sysxBuffer.at(sysxAddressOffset + 6) );
			this->fileSource.hex.append(sysxBuffer);
			sysxBuffer.clear();
			dataSize = 0;
			offset = 0;
		};
	};
	
	
     out.clear();
		 count=0;
		for (QList< QList<QString> >::iterator dev = fileSource.hex.begin(); dev != fileSource.hex.end(); ++dev)
		{
			QList<QString> data(*dev);
			for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
			{
				QString str(*code);
				bool ok;
				unsigned int n = str.toInt(&ok, 16);
				out[count] = (char)n;
				count++;
			};
		};
		temp = Qhex.mid((288), 29);           // place smf header after checksum is added
	out.prepend(temp);
	temp = Qhex.mid((435), 4);             // place smf footer after "F7" EOF
	out.append(temp);
		file.write(out);
	};

};

void sysxWriter::writeGXB(QString fileName)
{	
	QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
	{
		SysxIO *sysxIO = SysxIO::Instance();
		this->fileSource = sysxIO->getFileSource();
			
		QByteArray out;
		unsigned int count=0;
		for (QList< QList<QString> >::iterator dev = fileSource.hex.begin(); dev != fileSource.hex.end(); ++dev)
		{
			QList<QString> data(*dev);
			for (QList<QString>::iterator code = data.begin(); code != data.end(); ++code)
			{
				QString str(*code);
				bool ok;
				unsigned int n = str.toInt(&ok, 16);
				out[count] = (char)n;
				count++;
			};
		};
	 QByteArray GXB_default;
   QByteArray temp;
   int a = 172;
    QFile GXBfile(":default.gxb");           // Read the default GT-10B GXB file .
    if (GXBfile.open(QIODevice::ReadOnly))
	  {	GXB_default = GXBfile.readAll(); };
   temp = out.mid(11, 128);
   GXB_default.replace(a, 128, temp);       //address "00" +   
   temp = out.mid(152, 128);
   GXB_default.replace(a+128, 128, temp);     //address "01" +      
   temp = out.mid(293, 128);
   GXB_default.replace(a+256, 128, temp);     //address "02" +    
   temp = out.mid(434, 100);
   GXB_default.replace(a+384, 100, temp);     //address "03" +      no "04"     
   temp = out.mid(547, 128);
   GXB_default.replace(a+640, 128, temp);     //address "05" +           
   temp = out.mid(688, 128);
   GXB_default.replace(a+768, 128, temp);     //address "06" +       
   temp = out.mid(829, 100);
   GXB_default.replace(a+896, 100, temp);     //address "07" +      no "08"   
   temp = out.mid(942, 128);
   GXB_default.replace(a+1152, 128, temp);     //address "09" +   
   temp = out.mid(1083, 128);
   GXB_default.replace(a+1280, 128, temp);    //address "0A" +        
   temp = out.mid(1224, 128);
   GXB_default.replace(a+1408, 128, temp);    //address "0B" +       
   temp = out.mid(1365, 128);
   GXB_default.replace(a+1536, 128, temp);    //address "0C" +  
   /*
   temp = GXB_default.mid(32, 1);
   int z = 1701;
   int y = data.indexOf( temp, (1701));          // copy user text, first two sections only, section terminated by "00"
   int x = data.indexOf( temp, (1701)) + 1; 
   int w = data.indexOf( temp, (x+1));
   temp = out.mid(z, (y-z) );
   marker = out.mid(31, 1);    //"20"
   if (temp.size()>0 )
    {      
      for (int u = (32-(y-z));u>0; u--)
      { temp.append(marker); };
      if (temp.size()>32) {temp=temp.mid(0, 32); }
      GXB_default.replace(1647, (y-z), temp);       // paste text 1
    };   
    temp = out.mid(x, (w-x) );
    if (temp.size()>0 )
    {      
      for (int u = (128-(w-x));u>0; u--)
      { temp.append(marker); };
      if (temp.size()>128) {temp=temp.mid(0, 128); }
      GXB_default.replace(1506, (w-x), temp);            // paste text 2
    };     */
		file.write(GXB_default);
	};

};

SysxData sysxWriter::getFileSource()
{
	return fileSource;	
};

SysxData sysxWriter::getSystemSource()
{
	return systemSource;	
};

QString sysxWriter::getFileName()
{
	return fileName;	
};

