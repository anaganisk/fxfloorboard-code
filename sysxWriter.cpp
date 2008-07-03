/****************************************************************************
**
** Copyright (C) 2007, 2008 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-10 Fx FloorBoard".
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

		if(data.size() == patchSize){         // if GT-10B patch file size is correct- load file.
		SysxIO *sysxIO = SysxIO::Instance();
		sysxIO->setFileSource(data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
		}	else if (data.size() == 684){      // if the file size = gt-8 patch
		
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
	
	QByteArray gt8_data = data;
	QFile file(":default.syx");   // Read the default GT-10 sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	{	data = file.readAll(); };
	char r;
	QByteArray temp;                         // TRANSLATION of GT-8 PATCHES, data read from gt8 patch **************
	QByteArray Qhex;                            // and used to replace gt10 patch data*********************************
  QFile hexfile(":HexLookupTable.hex");   // use a QByteArray of hex numbers from a lookup table.
    if (hexfile.open(QIODevice::ReadOnly))
	{	Qhex = hexfile.readAll(); };
	 temp = gt8_data.mid(692, 16);           // copy gt8 name
	data.replace(11, 16, temp);              // replace gt10 name
	temp = gt8_data.mid(154, 1);             // copy gt8 compressor part1
	temp.append(gt8_data.mid(156,7));        // copy gt8 compressor part2
	data.replace(75, 8, temp);               // replace gt10 compressor
	temp = gt8_data.mid(212, 1);             // copy gt8 dist/od part1
	data.replace(123, 1, temp);              // replace gt10 distortion part1
	r = gt8_data.at(214);
	temp = Qhex.mid((180+r), 1);             // convert DISTORTION types from HexLookupTable 180->
	temp.append(gt8_data.mid(215,5));        // copy gt8 dist/od part2
	data.replace(124, 6, temp);              // replace gt10 distortion


  temp = gt8_data.mid(233, 1);             // copy gt8 preAmp control part1
	temp.append(gt8_data.mid(235,2));        // copy gt8 preAmp control part2
	temp.append(gt8_data.mid(238,1));        // copy gt8 preAmp control part3
	temp.append(gt8_data.mid(237,1));        // copy gt8 preAmp control part4
	data.replace(152, 5, temp);              // replace gt10 preAmp control
	r = gt8_data.at(239);
	temp = Qhex.mid((224+r), 1);             // convert PRE_AMP types from HexLookupTable 224->
	temp.append(gt8_data.mid(240, 16));      // copy gt8 preAmp channel A 
	data.replace(168, 17, temp);             // replace gt10 preAmp channel A
	r = gt8_data.at(256);
	temp = Qhex.mid((224+r), 1);             // convert PRE_AMP types from HexLookupTable 224->
	temp.append(gt8_data.mid(257, 16));      // copy gt8 preAmp channel B 
	data.replace(200, 17, temp);             // replace gt10 preAmp channel B
	temp = gt8_data.mid(286, 1);             // copy gt8 EQ part1
	temp.append(gt8_data.mid(288,11));       // copy gt8 EQ part2
	data.replace(264, 12, temp);             // replace gt10 EQ
	
	
	temp = gt8_data.mid(545, 1);            // copy gt8 delay part1
	temp.append(gt8_data.mid(547,16));      // copy gt8 delay part2
	temp.append(gt8_data.mid(565,4));       // copy gt8 delay part3
	temp.append(gt8_data.mid(563,2));       // copy gt8 delay part4
	temp.append(gt8_data.mid(569,2));       // copy gt8 delay part5
	if (temp.mid(2,1)=="11"){temp.replace(2, 1, "00"); }; // gt10 don't have hold function in delay
	data.replace(1351, 25, temp);           // replace gt10 delay
	temp = gt8_data.mid(584, 1);            // copy gt8 chorus part1
	temp.append(gt8_data.mid(586,7));       // copy gt8 chorus part2
	data.replace(1383, 8, temp);            // replace gt10 chorus
	temp = gt8_data.mid(606, 1);            // copy gt8 reverb part1
	temp.append(gt8_data.mid(608,3));       // copy gt8 reverb part2
	temp.append(gt8_data.mid(611,5));       // copy gt8 reverb part3
	data.replace(1399, 9, temp);            // replace gt10 reverb
	temp = (gt8_data.mid(610,1));           // copy gt8 reverb part4
	data.replace(1410, 1, temp);            // replace gt10 reverb
	
	
	temp.clear();                            // Convert GT8 Chain items to GT10 format 
			r = gt8_data.at(665);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(666);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(667);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(668);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(669);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(670);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(671);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(672);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(673);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(674);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(675);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(676);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(677);
    temp.append(Qhex.mid(r+164, 1)); 
    		r = gt8_data.at(678);
    temp.append(Qhex.mid(r+164, 1));          
	        
	unsigned int a = temp.indexOf(Qhex.mid(4,1)); // locate gt10_preamp 1 **** find "04"
	temp.insert(a-1, Qhex.mid(16, 1));       //insert gt10_split before preamp 1 "10"
	temp.insert(a+1, Qhex.mid(17, 1));       // insert gt10_merge after preamp 1  "11"
	temp.insert(a+1, Qhex.mid(13, 1));     // insert NS_2 "4D"  77
	temp.insert(a+1, Qhex.mid(3, 1));       // insert channel B "43" 67
	data.replace(1492, 18, temp);            // replace gt10 chain
	
	
	temp = gt8_data.mid(194, 1);             // copy gt8 Loop part1
	temp.append(gt8_data.mid(196,3));        // copy gt8 Loop part2
	data.replace(1472, 4, temp);             // replace gt10 Loop (Send/Return))
	
	temp = gt8_data.mid(629, 4);             // copy gt8 NS
	data.replace(1464, 4, temp);             // replace gt10 NS_1
	data.replace(1468, 4, temp);             // replace gt10 NS_2
	
	temp = gt8_data.mid(176, 1);             // copy gt8 wah on/off
	data.replace(1415, 1, temp);             // replace gt10 pedal fx on/off
	r = gt8_data.at(737);
	temp = Qhex.mid((r+1), 1);               // copy gt8 ExSw Func
	data.replace(1421, 1, temp);             // replace gt10 ExSw 1 Func + 1
	 r = gt8_data.at(722);
	temp = Qhex.mid((r+1), 1);               // copy gt8 CTL Func
	data.replace(1422, 1, temp);             // replace gt10 CTL 1 Func + 1
	temp = gt8_data.mid(178, 2);             // copy gt8 wah
	data.replace(1424, 2, temp);             // replace gt10 wah
	temp = gt8_data.mid(180, 1);             // copy gt8 wah level
	data.replace(1428, 1, temp);             // replace gt10 wah
	// todo replace direct level with effect inverted (optional).
	
	temp = gt8_data.mid(469, 5);             // copy gt8 pedal bend (fx2)
	data.replace(1435, 5, temp);             // replace gt10 pedal bend
	
	temp = gt8_data.mid(636, 1);             // copy gt8 FV level
	data.replace(1441, 1, temp);             // replace gt10 FV level
	temp = gt8_data.mid(637, 1);             // copy gt8 FV vol curve
	data.replace(1444, 1, temp);             // replace gt10 FV vol curve
	temp = gt8_data.mid(752, 2);             // copy gt8 FV vol min/max
	data.replace(1442, 2, temp);             // replace gt10 FV vol min/max
	
	temp = gt8_data.mid(651, 1);             // copy gt8 Amp control
	data.replace(1456, 1, temp);             // replace gt10 Amp control
	
	temp = gt8_data.mid(633, 1);             // copy gt8 Master patch level
	data.replace(1447, 1, temp);             // replace gt10 Master patch level
	temp = gt8_data.mid(634, 2);             // copy gt8 Master BPM
	data.replace(1454, 2, temp);             // replace gt10 Master BPM
	
	temp = gt8_data.mid(11, 1);              // copy gt8 FX1 on/off
	data.replace(293, 1, temp);              // replace gt10 FX1 on/off	
	 r = gt8_data.at(13);
	temp = Qhex.mid((128+r), 1);       // convert FX1 Type: selection items from lookup table Qhex (HexLookupTable.hex file) from 128 to 144
  temp.append(gt8_data.mid(14, 25));       // copy gt8 FX1 part2
	data.replace(294, 26, temp);             // replace gt10 FX1 part2
	temp = gt8_data.mid(49, 19);              // copy gt8 FX1 part3
	data.replace(320, 19, temp);             // replace gt10 FX1 part3
	temp = gt8_data.mid(68, 16);              // copy gt8 FX1 part4
	data.replace(341, 16, temp);             // replace gt10 FX1 part4
	temp = gt8_data.mid(98, 24);              // copy gt8 FX1 part5
	data.replace(357, 24, temp);             // replace gt10 FX1 part5
	temp = gt8_data.mid(130, 11);              // copy gt8 FX1 part6
	data.replace(381, 11, temp);              // replace gt10 FX1 part6
	temp = gt8_data.mid(84, 14);              // copy gt8 FX1 part7
	data.replace(479, 14, temp);             // replace gt10 FX1 part7
	temp = gt8_data.mid(122, 8);              // copy gt8 FX1 part8
	data.replace(493, 8, temp);              // replace gt10 FX1 part8
	temp = gt8_data.mid(39, 10);              // copy gt8 FX1 part9
	data.replace(747, 10, temp);               // replace gt10 FX1 part9
	
	
	temp = gt8_data.mid(312, 1);              // copy gt8 FX2 on/off
	data.replace(815, 1, temp);              // replace gt10 FX2 on/off	
	 r = gt8_data.at(314);
	temp = Qhex.mid((128+r), 1);       // convert FX2 Type: selection items from lookup table Qhex (HexLookupTable.hex file) from 128 to 144
  temp.append(gt8_data.mid(315, 25));       // copy gt8 FX2 part2
	data.replace(816, 26, temp);             // replace gt10 FX2 part2
	temp = gt8_data.mid(350, 19);              // copy gt8 FX2 part3
	data.replace(842, 19, temp);             // replace gt10 FX2 part3
	temp = gt8_data.mid(369, 16);              // copy gt8 FX2 part4
	data.replace(863, 16, temp);             // replace gt10 FX2 part4
	temp = gt8_data.mid(399, 24);              // copy gt8 FX2 part5
	data.replace(879, 24, temp);             // replace gt10 FX2 part5
	temp = gt8_data.mid(431, 11);              // copy gt8 FX2 part6
	data.replace(903, 11, temp);              // replace gt10 FX2 part6
	temp = gt8_data.mid(385, 14);              // copy gt8 FX2 part7
	data.replace(1001, 14, temp);             // replace gt10 FX2 part7
	temp = gt8_data.mid(423, 8);              // copy gt8 FX2 part8
	data.replace(1015, 8, temp);              // replace gt10 FX2 part8
	temp = gt8_data.mid(340, 10);              // copy gt8 FX2 part9
	data.replace(1269, 10, temp);               // replace gt10 FX2 part9
	temp = gt8_data.mid(442, 4);              // copy gt8 FX2 part10  HR
	temp.append(gt8_data.mid(447,5)); 
	temp.append(gt8_data.mid(446,1)); 
	temp.append(gt8_data.mid(453,1)); 
	data.replace(914, 11, temp);               // replace gt10 FX2 part10  HR
	temp = gt8_data.mid(454, 6);              // copy gt8 FX2 part11  PS
	temp.append(gt8_data.mid(461,7));
	temp.append(gt8_data.mid(460,1));
	temp.append(gt8_data.mid(468,1));
	data.replace(962, 15, temp);               // replace gt10 FX2 part11  PS
	temp = gt8_data.mid(474, 18);              // copy gt8 FX2 part12  OC, RT, 2CE
	data.replace(977, 18, temp);               // replace gt10 FX2 part12  OC, RT, 2CE
	temp = gt8_data.mid(492, 4);              // copy gt8 FX2 part13  AR
	temp.append(gt8_data.mid(497,4));
	data.replace(1040, 8, temp);               // replace gt10 FX2 part13  AR
	temp = gt8_data.mid(502, 1);              // copy gt8 FX2 part14  SYN
	temp.append(gt8_data.mid(501,1));
	temp.append(gt8_data.mid(503,15));
	data.replace(1023, 17, temp);               // replace gt10 FX2 part14 SYN
	temp = gt8_data.mid(518, 7);              // copy gt8 FX2 part15  AC
	data.replace(1279, 7, temp);               // replace gt10 FX2 part15 AC
	temp = gt8_data.mid(525, 3);              // copy gt8 FX2 part16  SH
	data.replace(1266, 3, temp);               // replace gt10 FX2 part16 SH
	temp = gt8_data.mid(528, 3);              // copy gt8 FX2 part17  SDD
	data.replace(995, 3, temp);               // replace gt10 FX2 part17 SDD
	temp = gt8_data.mid(531, 1);              // copy gt8 FX2 part18  SDD
	data.replace(999, 1, temp);               // replace gt10 FX2 part18 SDD
	
	
	/*
		 QString z;
		QString snork;
			snork.append("<font size='-1'>");
			snork.append(" { size=");
			snork.append(QString::number(temp.size(), 10));
			snork.append("}");	
			
			snork.append(" { size z=");
			snork.append(QString::number(z.size()/2, 10));
			snork.append("}");	
				snork.append("<br> midi data received  ");
			for(int i=0;i<temp.size();++i)
			{
			  r = temp.at(i);     
	      z = (Qhex.mid((65+r), 1));
				snork.append(z);
				snork.append(" ");
				//i++;
			};
			snork.append("<br> midi data received  ");
			for(int i=0;i<z.size();++i)
			{
			//QString hexStr = temp.at(i);
		  	//bool ok;
		    //snork.append( (char)(hexStr.toInt(&ok, 16)) );
				snork.append(z.mid(i*2, 2));
				snork.append(" ");
				//i++;
			};
			QMessageBox *msgBox2 = new QMessageBox();
			msgBox2->setWindowTitle("dBug Result");
			msgBox2->setIcon(QMessageBox::Information);
			msgBox2->setText(snork);
			msgBox2->setStandardButtons(QMessageBox::Ok);
			msgBox2->exec();
      
         

	 */
	
    SysxIO *sysxIO = SysxIO::Instance();
		sysxIO->setFileSource(data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
		
    }	else if (data.size() == 1839)
  {                                        // file size of a .mid type SMF patch file from Boss Librarian
   
	QByteArray smf_data = data;
	QFile file(":default.syx");              // Read the default GT-10B sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	{	data = file.readAll(); };
	QByteArray temp;                         // TRANSLATION of GT-10B SMF PATCHES, data read from smf patch **************
	temp = smf_data.mid(43, 128);            // copy SMF 128 bytes
	data.replace(11, 128, temp);             // replace gt10 address "00"...
	temp = smf_data.mid(171, 114);           // copy SMF part1...
	temp.append(smf_data.mid(301,14));       // copy SMF part2...
	data.replace(152, 128, temp);            // replace gt10 address "01"...
	temp = smf_data.mid(315, 128);           // copy SMF part1...
	data.replace(293, 128, temp);            // replace gt10 address "02"...
	temp = smf_data.mid(443, 100);           // copy SMF part1...
	data.replace(434, 100, temp);            // replace gt10 address "03"...
	temp = smf_data.mid(715, 86);            // copy SMF part1...
	temp.append(smf_data.mid(817,42));       // copy SMF part2...
	data.replace(547, 128, temp);             // replace gt10 address "05"...
	temp = smf_data.mid(859, 128);           // copy SMF part1...
	data.replace(688,128, temp);             // replace gt10 address "06"...
	temp = smf_data.mid(987, 72);            // copy SMF part1...
	temp.append(smf_data.mid(1075,28));      // copy SMF part2...
	data.replace(829, 100, temp);            // replace gt10 address "07"...
	temp = smf_data.mid(1259, 58);           // copy SMF part1...
	temp.append(smf_data.mid(1333,42));      // copy SMF part2...
	data.replace(942, 100, temp);           // replace gt10 address "09"...
	temp = smf_data.mid(1403, 128);          // copy SMF part1...
	data.replace(1083,128, temp);            // replace gt10 address "0A"...
	temp = smf_data.mid(1531, 44);           // copy SMF part1...
	temp.append(smf_data.mid(1591,84));      // copy SMF part2...
	data.replace(1224, 128, temp);           // replace gt10 address "0B"...
	temp = smf_data.mid(1675, 128);          // copy SMF part1...
	data.replace(1365,128, temp);            // replace gt10 address "0C"...
    
    SysxIO *sysxIO = SysxIO::Instance();
		sysxIO->setFileSource(data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;   
  } 
    else 
  {
	QMessageBox *msgBox = new QMessageBox();
	msgBox->setWindowTitle(QObject::tr("Patch size Error!"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+1'><b>");
	msgText.append(QObject::tr("This is not a ") + deviceType + (" patch!"));
	msgText.append("<b></font><br>");
	msgText.append(QObject::tr("Patch size is not ") + (QString::number(patchSize, 10)) + (" bytes, please try another file."));
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

SysxData sysxWriter::getFileSource()
{
	return fileSource;	
};

QString sysxWriter::getFileName()
{
	return fileName;	
};

