/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-x Fx FloorBoard".
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
		QByteArray data = file.readAll();

		if(data.size() == patchSize){
		SysxIO *sysxIO = SysxIO::Instance();
		QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
		}
		 else if (data.size() == 1010) { // if an original basic GT-8 patch file.
		QByteArray gt8_data = data;
		QByteArray temp;   
		QFile file(":default.syx");   // Read the default GT-8 sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	   temp = data.mid(1010, 231);
	   gt8_data.append(temp);
	   data = gt8_data;
	   SysxIO *sysxIO = SysxIO::Instance();
		QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;   }
		else if(data.size() == 1763  || data.size() == 2045 || data.size() == 1862)  {       // if a GT-10 patch file, with or without text
    QByteArray gt10_data = data;
		QByteArray temp;   
		QFile file(":default.syx");   // Read the default GT-8 sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	  QByteArray hex;
	  QFile fileHex(":HexLookupTable.hex");   // Read the HexLookupTable.hex file.
    if (fileHex.open(QIODevice::ReadOnly))
	  {	hex = fileHex.readAll(); };
    temp = gt10_data.mid(11, 16);        // copy gt10 patch name data
    data.replace(692, 16, temp);      // replace  gt8 name data    address 00 12 00 
    
    temp = gt10_data.mid(293, 1);        // copy gt10 patch fx1 sw
    data.replace(11, 1, temp);      // replace  gt8 fx1 sw    address 00 00 00 
    char r = gt10_data.at(294);            // copy gt10 patch fx1 type
    temp = hex.mid((76+r), 1);             // convert FX1 types from HexLookupTable
    data.replace(13, 1, temp);      // replace  gt8 fx1 type    address 00 00 00 
     
    temp = gt10_data.mid(75, 1);        // copy gt10 patch compressor sw
    data.replace(154, 1, temp);      // replace  gt8 compressor sw    address 00 02 00 
    temp = gt10_data.mid(76, 7);        // copy gt10 patch compressor data
    data.replace(156, 7, temp);      // replace  gt8 compressor data    address 00 02 00 
    temp = gt10_data.mid(1415, 1);        // copy gt10 patch wha sw
    data.replace(176, 1, temp);      // replace  gt8 wha sw    address 00 03 00 
    temp = gt10_data.mid(1424, 2);        // copy gt10 patch wha data
    data.replace(178, 2, temp);      // replace  gt8 wha data    address 00 03 00 
    temp = gt10_data.mid(1428, 1);        // copy gt10 patch wha data
    data.replace(180, 1, temp);      // replace  gt8 wha data    address 00 03 00 
    temp = gt10_data.mid(1472, 1);        // copy gt10 patch loop sw
    data.replace(194, 1, temp);      // replace  gt8 loop sw    address 00 04 00 
    temp = gt10_data.mid(1473, 3);        // copy gt10 patch loop data
    data.replace(196, 3, temp);      // replace  gt8 loop data    address 00 04 00 
    temp = gt10_data.mid(123, 1);        // copy gt10 patch od/ds sw
    data.replace(212, 1, temp);      // replace  gt8 od/ds sw    address 00 06 00 
    temp = gt10_data.mid(124, 6);        // copy gt10 patch od/ds data
    data.replace(214, 6, temp);      // replace  gt8 od/ds data    address 00 06 00 
    r = data.at(214);
    temp = hex.mid((125+r), 1);             // convert DISTORTION types from HexLookupTable
    data.replace(214, 1, temp);      // replace  gt8 od/ds type
    
    temp = gt10_data.mid(152, 1);        // copy gt10 patch preamp sw
    data.replace(233, 1, temp);      // replace  gt8 preamp sw    address 00 07 00 
    temp = gt10_data.mid(153, 2);        // copy gt10 patch preamp data
    data.replace(235, 2, temp);      // replace  gt8 preamp data    address 00 07 00 
    temp = gt10_data.mid(156, 1);        // copy gt10 patch preamp data
    data.replace(237, 1, temp);      // replace  gt8 preamp data    address 00 07 00 
    temp = gt10_data.mid(155, 1);        // copy gt10 patch preamp data
    data.replace(238, 1, temp);      // replace  gt8 preamp data    address 00 07 00 
    temp = gt10_data.mid(168, 17);        // copy gt10 patch preamp A data
    data.replace(239, 17, temp);      // replace  gt8 preamp A data    address 00 07 00 
    temp = gt10_data.mid(200, 17);        // copy gt10 patch preamp B data
    data.replace(256, 17, temp);      // replace  gt8 preamp B data    address 00 07 00 
    r = data.at(239);
    temp = hex.mid((172+r), 1);             // convert PREAMP  types from HexLookupTable
    data.replace(239, 1, temp);      // replace  gt8 preamp A type
    r = data.at(256);
    temp = hex.mid((172+r), 1);             // convert PREAMP  types from HexLookupTable
    data.replace(256, 1, temp);      // replace  gt8 preamp B type
     
    temp = gt10_data.mid(264, 1);        // copy gt10 patch eq sw
    data.replace(286, 1, temp);      // replace  gt8 eq sw    address 00 08 00 
    temp = gt10_data.mid(265, 11);        // copy gt10 patch eq data
    data.replace(288, 11, temp);      // replace  gt8 eq data    address 00 08 00 
    
    temp = gt10_data.mid(815, 1);        // copy gt10 patch fx2 sw
    data.replace(312, 1, temp);      // replace  gt8 fx2 sw    address 00 09 00 
    r = gt10_data.at(816);            // copy gt10 patch fx2 type
    temp = hex.mid((332+r), 1);             // convert FX2 types from HexLookupTable 
    data.replace(314, 1, temp);      // replace  gt8 fx2 type    address 00 09 00 
      
    temp = gt10_data.mid(1351, 1);        // copy gt10 patch delay sw
    data.replace(545, 1, temp);      // replace  gt8 delay sw    address 00 0B 00 
    temp = gt10_data.mid(1352, 24);        // copy gt10 patch delay data
    data.replace(547, 24, temp);      // replace  gt8 delay data    address 00 0B 00 
    temp = gt10_data.mid(1383, 1);        // copy gt10 patch chorus sw
    data.replace(584, 1, temp);      // replace  gt8 chorus sw    address 00 0C 00 
    temp = gt10_data.mid(1384, 7);        // copy gt10 patch chorus data
    data.replace(586, 7, temp);      // replace  gt8 chorus data    address 00 0C 00   
    temp = gt10_data.mid(1399, 1);        // copy gt10 patch reverb sw
    data.replace(606, 1, temp);      // replace  gt8 reverb sw    address 00 0D 00  
    temp = gt10_data.mid(1400, 8);        // copy gt10 patch reverb data
    data.replace(608, 8, temp);      // replace  gt8 reverb data    address 00 0D 00 
       
           
            
       
    QString chain;
    int k = 665;    // gt-8 chain data start location offset.
    for(int i=0;i<18;i++)
     {
          r = gt10_data.at(1492+i);                // read gt-10 chain data
          temp = hex.mid((233+r), 1);             // convert chain from HexLookupTable      
          unsigned char byte = (char)temp[0];
		      unsigned int n = (int)byte;
	        QString z = QString::number(n, 16).toUpper();
		      if (z.length() < 2) z.prepend("0");                                  
            if (n < 15)
              {
                data.replace(k, 1, temp);      // replace gt8 chain 
                k=k+1;  
              };
      };
 
       
    temp = gt10_data.mid(1524, 1);        // copy gt10 patch assign1 sw
    data.replace(767, 1, temp);      // replace  gt8 assign1 sw    address 00 16 00 
    temp = gt10_data.mid(1525, 2);        // copy gt10 patch assign1 target
    data.replace(769, 2, temp);      // replace  gt8 assign1 target    address 00 16 00 
    temp = gt10_data.mid(1527, 13);        // copy gt10 patch assign1 data
    data.replace(771, 13, temp);      // replace  gt8 assign1 data    address 00 16 00 
    r = gt10_data.at(1531);            // copy gt10 patch source type
    temp = hex.mid((383+r), 1);             // convert source types from HexLookupTable 
    data.replace(775, 1, temp);      // replace  gt8 source type    
      
    temp = gt10_data.mid(1540, 1);        // copy gt10 patch assign2 sw
    data.replace(797, 1, temp);      // replace  gt8 assign2 sw    address 00 17 00 
    temp = gt10_data.mid(1541, 2);        // copy gt10 patch assign2 target
    data.replace(799, 2, temp);      // replace  gt8 assign2 target    address 00 17 00 
    temp = gt10_data.mid(1543, 13);        // copy gt10 patch assign2 data
    data.replace(801, 13, temp);      // replace  gt8 assign2 data    address 00 17 00 
       
    temp = gt10_data.mid(1556, 1);        // copy gt10 patch assign3 sw
    data.replace(827, 1, temp);      // replace  gt8 assign1 sw    address 00 18 00 
    temp = gt10_data.mid(1557, 2);        // copy gt10 patch assign3 target
    data.replace(829, 2, temp);      // replace  gt8 assign3 target    address 00 18 00 
    temp = gt10_data.mid(1559, 13);        // copy gt10 patch assign3 data
    data.replace(831, 13, temp);      // replace  gt8 assign3 data    address 00 18 00 
 
    temp = gt10_data.mid(1572, 1);        // copy gt10 patch assign4 sw
    data.replace(857, 1, temp);      // replace  gt8 assign4 sw    address 00 19 00 
    temp = gt10_data.mid(1573, 2);        // copy gt10 patch assign4 target
    data.replace(859, 2, temp);      // replace  gt8 assign1 target    address 00 19 00 
    temp = gt10_data.mid(1575, 13);        // copy gt10 patch assign4 data
    data.replace(861, 13, temp);      // replace  gt8 assign1 data    address 00 19 00 
        
    temp = gt10_data.mid(1588, 1);        // copy gt10 patch assign1 sw
    data.replace(887, 1, temp);      // replace  gt8 assign5 sw    address 00 1A 00 
    temp = gt10_data.mid(1589, 2);        // copy gt10 patch assign5 target
    data.replace(889, 2, temp);      // replace  gt8 assign5 target    address 00 1A 00 
    temp = gt10_data.mid(1591, 13);        // copy gt10 patch assign5 data
    data.replace(891, 13, temp);      // replace  gt8 assign1 data    address 00 1A 00 
    
    temp = gt10_data.mid(1604, 1);        // copy gt10 patch assign1 sw
    data.replace(917, 1, temp);      // replace  gt8 assign6 sw    address 00 1B 00 
    temp = gt10_data.mid(1605, 2);        // copy gt10 patch assign6 target
    data.replace(919, 2, temp);      // replace  gt8 assign6 target    address 00 1B 00 
    temp = gt10_data.mid(1607, 13);        // copy gt10 patch assign6 data
    data.replace(921, 13, temp);      // replace  gt8 assign1 data    address 00 1B 00 
    
     temp = gt10_data.mid(1633, 1);        // copy gt10 patch assign1 sw
    data.replace(947, 1, temp);      // replace  gt8 assign7 sw    address 00 1C 00 
    temp = gt10_data.mid(1634, 2);        // copy gt10 patch assign7 target
    data.replace(949, 2, temp);      // replace  gt8 assign7 target    address 00 1C 00 
    temp = gt10_data.mid(1636, 13);        // copy gt10 patch assign7 data
    data.replace(951, 13, temp);      // replace  gt8 assign7 data    address 00 1C 00 
    
    temp = gt10_data.mid(1649, 1);        // copy gt10 patch assign8 sw
    data.replace(977, 1, temp);      // replace  gt8 assign8 sw    address 00 1D 00 
    temp = gt10_data.mid(1650, 2);        // copy gt10 patch assign8 target
    data.replace(979, 2, temp);      // replace  gt8 assign8 target    address 00 1D 00 
    temp = gt10_data.mid(1652, 13);        // copy gt10 patch assign8 data
    data.replace(981, 13, temp);      // replace  gt8 assign1 data    address 00 1D 00 
       
               
    temp = hex.mid(0, 32);        // copy "gt10 conversion" text
    data.replace(1162, 32, temp);      // replace  gt8 user name text
    if ( gt10_data.size() == 2045) 
           {
            temp = gt10_data.mid(1774, 128);        // copy user dialog text if file is an extended type.
            data.replace(1021, 128, temp);      // replace  gt8 user dialog text
           };
     
    SysxIO *sysxIO = SysxIO::Instance();
		QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
		} 
		else if (data.size() == systemDataSize)  {         //if GT-8 system file size is correct- load file. 
    SysxIO *sysxIO = SysxIO::Instance();
		QString area = "System";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->systemSource = sysxIO->getSystemSource();	
		return true;   }
		else {
	QMessageBox *msgBox = new QMessageBox();
	msgBox->setWindowTitle(QObject::tr("Patch size Error!"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+1'><b>");
	msgText.append(QObject::tr("This is not a ") + deviceType + (" patch!"));
	msgText.append("<b></font><br>");
	if (data.size() == 670){
  msgText.append("but appears to be a GT-6 patch<br>");};
  if (data.size() == 650){
  msgText.append("but appears to be a GT-3 patch<br>");};
	msgText.append(QObject::tr("Patch size not ") + (QString::number(patchSize, 10)) + (" bytes, please try another file."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();
			return false;};
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

