/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. 
** All rights reserved.
**
** This file is part of "GT-Pro Fx FloorBoard".
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
	QByteArray gt8_data;
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
     else if (data.size() == 1010) { // if a GT-8 patch file.
		QByteArray gt8_data = data;
		QByteArray temp;   
		QFile file(":default.syx");   // Read the default GT-Pro sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	  QByteArray hex;
	  QFile fileHex(":HexLookupTable.hex");   // Read the HexLookupTable.hex file.
    if (fileHex.open(QIODevice::ReadOnly))
	  {	hex = fileHex.readAll(); };
    temp = gt8_data.mid(11, 130);     // copy gt8 address 00 data
    data.replace(11, 130, temp);      // replace  gtpro 00 data               
	  temp = gt8_data.mid(154, 9);     // copy gt8 address 02 data
    data.replace(154, 9, temp);      // replace  gtpro 02 data                   
	  temp = gt8_data.mid(176, 5);     // copy gt8 address 03 data
    data.replace(176, 5, temp);      // replace  gtpro 03 data  
    temp = gt8_data.mid(194, 5);     // copy gt8 address 04 data
    data.replace(194, 5, temp);      // replace  gtpro 04 data 
    temp = gt8_data.mid(212, 8);     // copy gt8 address 06 data
    data.replace(234, 8, temp);      // replace  gtpro 06 data   
    temp = gt8_data.mid(233, 40);     // copy gt8 address 07 data
    data.replace(255, 40, temp);      // replace  gtpro 07 data 
    temp = gt8_data.mid(286, 13);     // copy gt8 address 08 data
    data.replace(308, 13, temp);      // replace  gtpro 08 data   
    temp = gt8_data.mid(312, 220);     // copy gt8 address 09 data
    data.replace(334, 220, temp);      // replace  gtpro 09 data     
    temp = gt8_data.mid(545, 26);     // copy gt8 address 0B data
    data.replace(567, 26, temp);      // replace  gtpro 0B data   
    temp = gt8_data.mid(584, 9);     // copy gt8 address 0C data
    data.replace(606, 9, temp);      // replace  gtpro 0C data  
    temp = gt8_data.mid(606, 10);     // copy gt8 address 0D data
    data.replace(628, 10, temp);      // replace  gtpro 0D data   
    temp = gt8_data.mid(629, 9);     // copy gt8 address 0E data
    data.replace(651, 9, temp);      // replace  gtpro 0E data 
    temp = gt8_data.mid(651, 1);     // copy gt8 address 0F data
    data.replace(674, 1, temp);      // replace  gtpro 0F data   
    temp = gt8_data.mid(665, 14);     // copy gt8 address 11 data
    data.replace(702, 14, temp);      // replace  gtpro 11 data 
    temp = gt8_data.mid(692, 16);     // copy gt8 address 12 data
    data.replace(729, 16, temp);      // replace  gtpro 12 data  
    temp = gt8_data.mid(1007, 1);     // copy gt8 address 1E data
    data.replace(758, 1, temp);      // replace  gtpro 1E data 
    temp = gt8_data.mid(767, 17);     // copy gt8 address 16 data     Assign 1
    data.replace(772, 17, temp);      // replace  gtpro 20 data 
    temp = gt8_data.mid(797, 17);     // copy gt8 address 17 data     
    data.replace(802, 17, temp);      // replace  gtpro 21 data 
    temp = gt8_data.mid(827, 17);     // copy gt8 address 18 data
    data.replace(832, 17, temp);      // replace  gtpro 22 data 
    temp = gt8_data.mid(857, 17);     // copy gt8 address 19 data
    data.replace(862, 17, temp);      // replace  gtpro 23 data 
    temp = gt8_data.mid(887, 17);     // copy gt8 address 1A data
    data.replace(892, 17, temp);      // replace  gtpro 24 data 
    temp = gt8_data.mid(917, 17);     // copy gt8 address 1B data
    data.replace(922, 17, temp);      // replace  gtpro 25 data 
    temp = gt8_data.mid(947, 17);     // copy gt8 address 1C data
    data.replace(952, 17, temp);      // replace  gtpro 26 data 
    temp = gt8_data.mid(977, 17);     // copy gt8 address 1D data         Assign 8
    data.replace(982, 17, temp);      // replace  gtpro 27 data 
    temp = gt8_data.mid(751, 3);     // copy gt8 address 15 data
    data.replace(1132, 3, temp);      // replace  gtpro 2C data
    data.replace(1148, 3, temp);      // replace  gtpro 2D data 
    temp = hex.mid(32, 32);        // copy gt8 conversion text
    data.replace(1305, 32, temp);      // replace  gtpro user name text 
   
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;	
		} if(data.size() == 1763  || data.size() == 2045 || data.size() == 1862)  {       // if a GT-10 patch file, with or without text
    QByteArray gt10_data = data;
		QByteArray temp;   
		QFile file(":default.syx");   // Read the default GT-Pro sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	  QByteArray hex;
	  QFile fileHex(":HexLookupTable.hex");   // Read the HexLookupTable.hex file.
    if (fileHex.open(QIODevice::ReadOnly))
	  {	hex = fileHex.readAll(); };
    temp = gt10_data.mid(11, 16);        // copy gt10 patch name data
    data.replace(729, 16, temp);      // replace  gtpro name data    address 00 12 00 
    
    temp = gt10_data.mid(293, 1);        // copy gt10 patch fx1 sw
    data.replace(11, 1, temp);      // replace  gtpro fx1 sw    address 00 00 00 
    char r = gt10_data.at(294);            // copy gt10 patch fx1 type
    temp = hex.mid((76+r), 1);             // convert FX1 types from HexLookupTable
    data.replace(13, 1, temp);      // replace  gtpro fx1 type    address 00 00 00 
    
    temp = gt10_data.mid(75, 1);        // copy gt10 patch compressor sw
    data.replace(154, 1, temp);      // replace  gtpro compressor sw    address 00 02 00 
    temp = gt10_data.mid(76, 7);        // copy gt10 patch compressor data
    data.replace(156, 7, temp);      // replace  gtpro compressor data    address 00 02 00 
    temp = gt10_data.mid(1415, 1);        // copy gt10 patch wha sw
    data.replace(176, 1, temp);      // replace  gtpro wha sw    address 00 03 00 
    temp = gt10_data.mid(1424, 2);        // copy gt10 patch wha data
    data.replace(178, 2, temp);      // replace  gtpro wha data    address 00 03 00 
     temp = gt10_data.mid(1428, 1);        // copy gt10 patch wha data
    data.replace(180, 1, temp);      // replace  gtpro wha data    address 00 03 00 
    temp = gt10_data.mid(1472, 1);        // copy gt10 patch loop sw
    data.replace(194, 1, temp);      // replace  gtpro loop sw    address 00 04 00 
    temp = gt10_data.mid(1473, 3);        // copy gt10 patch loop data
    data.replace(196, 3, temp);      // replace  gtpro loop data    address 00 04 00 
    temp = gt10_data.mid(123, 1);        // copy gt10 patch od/ds sw
    data.replace(234, 1, temp);      // replace  gtpro od/ds sw    address 00 06 00 
    temp = gt10_data.mid(124, 6);        // copy gt10 patch od/ds data
    data.replace(236, 6, temp);      // replace  gtpro od/ds data    address 00 06 00 
    r = data.at(236);
    temp = hex.mid((125+r), 1);             // convert DISTORTION types from HexLookupTable
    data.replace(236, 1, temp);      // replace  gtpro od/ds type
    temp = gt10_data.mid(152, 1);        // copy gt10 patch preamp sw
    data.replace(255, 1, temp);      // replace  gtpro preamp sw    address 00 07 00 
    temp = gt10_data.mid(153, 2);        // copy gt10 patch preamp data
    data.replace(257, 2, temp);      // replace  gtpro preamp data    address 00 07 00 
    temp = gt10_data.mid(156, 1);        // copy gt10 patch preamp data
    data.replace(259, 1, temp);      // replace  gtpro preamp data    address 00 07 00 
    temp = gt10_data.mid(155, 1);        // copy gt10 patch preamp data
    data.replace(260, 1, temp);      // replace  gtpro preamp data    address 00 07 00 
    temp = gt10_data.mid(168, 17);        // copy gt10 patch preamp A data
    data.replace(261, 17, temp);      // replace  gtpro preamp A data    address 00 07 00 
    temp = gt10_data.mid(200, 17);        // copy gt10 patch preamp B data
    data.replace(278, 17, temp);      // replace  gtpro preamp B data    address 00 07 00 
    r = data.at(261);
    temp = hex.mid((172+r), 1);             // convert PREAMP  types from HexLookupTable
    data.replace(261, 1, temp);      // replace  gtpro preamp A type
    r = data.at(278);
    temp = hex.mid((172+r), 1);             // convert PREAMP  types from HexLookupTable
    data.replace(278, 1, temp);      // replace  gtpro preamp B type
    
    temp = gt10_data.mid(264, 1);        // copy gt10 patch eq sw
    data.replace(308, 1, temp);      // replace  gtpro eq sw    address 00 08 00 
    temp = gt10_data.mid(265, 11);        // copy gt10 patch eq data
    data.replace(310, 11, temp);      // replace  gtpro eq data    address 00 08 00 
    
    temp = gt10_data.mid(815, 1);        // copy gt10 patch fx2 sw
    data.replace(334, 1, temp);      // replace  gtpro fx2 sw    address 00 09 00 
    r = gt10_data.at(816);            // copy gt10 patch fx2 type
    temp = hex.mid((332+r), 1);             // convert FX2 types from HexLookupTable 
    data.replace(336, 1, temp);      // replace  gtpro fx2 type    address 00 09 00 
    
    temp = gt10_data.mid(1351, 1);        // copy gt10 patch delay sw
    data.replace(567, 1, temp);      // replace  gtpro delay sw    address 00 0B 00 
    temp = gt10_data.mid(1352, 24);        // copy gt10 patch delay data
    data.replace(569, 24, temp);      // replace  gtpro delay data    address 00 0B 00 
    temp = gt10_data.mid(1383, 1);        // copy gt10 patch chorus sw
    data.replace(606, 1, temp);      // replace  gtpro chorus sw    address 00 0C 00 
    temp = gt10_data.mid(1384, 7);        // copy gt10 patch chorus data
    data.replace(608, 7, temp);      // replace  gtpro chorus data    address 00 0C 00 
    temp = gt10_data.mid(1399, 1);        // copy gt10 patch reverb sw
    data.replace(628, 1, temp);      // replace  gtpro reverb sw    address 00 0D 00 
    temp = gt10_data.mid(1400, 8);        // copy gt10 patch reverb data
    data.replace(630, 8, temp);      // replace  gtpro reverb data    address 00 0D 00 
    
    
    
       
    QString chain;
    int k = 702;    // gt-pro chain data start location offset.
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
                data.replace(k, 1, temp);      // replace gtpro chain 
                k=k+1;  
              };
      };
 
 
    temp = gt10_data.mid(1524, 1);        // copy gt10 patch assign1 sw
    data.replace(772, 1, temp);      // replace  gtpro assign1 sw    address 00 20 00 
    temp = gt10_data.mid(1525, 2);        // copy gt10 patch assign1 target
    //data.replace(774, 2, temp);      // replace  gtpro assign1 target    address 00 20 00 
    temp = gt10_data.mid(1527, 13);        // copy gt10 patch assign1 data
    data.replace(776, 13, temp);      // replace  gtpro assign1 data    address 00 20 00 
    r = gt10_data.at(1531);            // copy gt10 patch source type
    temp = hex.mid((383+r), 1);             // convert source types from HexLookupTable 
    data.replace(780, 1, temp);      // replace  gtpro source type    
    
    temp = gt10_data.mid(1540, 1);        // copy gt10 patch assign2 sw
    data.replace(802, 1, temp);      // replace  gtpro assign2 sw    address 00 21 00 
    //temp = gt10_data.mid(1541, 2);        // copy gt10 patch assign2 target
    data.replace(804, 2, temp);      // replace  gtpro assign2 target    address 00 21 00 
    temp = gt10_data.mid(1543, 13);        // copy gt10 patch assign2 data
    data.replace(806, 13, temp);      // replace  gtpro assign2 data    address 00 21 00 
 
    temp = gt10_data.mid(1556, 1);        // copy gt10 patch assign3 sw
    data.replace(832, 1, temp);      // replace  gtpro assign1 sw    address 00 22 00 
    temp = gt10_data.mid(1557, 2);        // copy gt10 patch assign3 target
    //data.replace(834, 2, temp);      // replace  gtpro assign3 target    address 00 22 00 
    temp = gt10_data.mid(1559, 13);        // copy gt10 patch assign3 data
    data.replace(836, 13, temp);      // replace  gtpro assign3 data    address 00 22 00 
 
    temp = gt10_data.mid(1572, 1);        // copy gt10 patch assign4 sw
    data.replace(862, 1, temp);      // replace  gtpro assign4 sw    address 00 23 00 
    temp = gt10_data.mid(1573, 2);        // copy gt10 patch assign4 target
    //data.replace(864, 2, temp);      // replace  gtpro assign4 target    address 00 23 00 
    temp = gt10_data.mid(1575, 13);        // copy gt10 patch assign4 data
    data.replace(866, 13, temp);      // replace  gtpro assign1 data    address 00 23 00 
 
    temp = gt10_data.mid(1588, 1);        // copy gt10 patch assign1 sw
    data.replace(892, 1, temp);      // replace  gtpro assign5 sw    address 00 24 00 
    temp = gt10_data.mid(1589, 2);        // copy gt10 patch assign5 target
    //data.replace(894, 2, temp);      // replace  gtpro assign5 target    address 00 24 00 
    temp = gt10_data.mid(1591, 13);        // copy gt10 patch assign5 data
    data.replace(896, 13, temp);      // replace  gtpro assign1 data    address 00 24 00 
    
    temp = gt10_data.mid(1604, 1);        // copy gt10 patch assign1 sw
    data.replace(922, 1, temp);      // replace  gtpro assign6 sw    address 00 25 00 
    temp = gt10_data.mid(1605, 2);        // copy gt10 patch assign6 target
    //data.replace(924, 2, temp);      // replace  gtpro assign6 target    address 00 25 00 
    temp = gt10_data.mid(1607, 13);        // copy gt10 patch assign6 data
    data.replace(926, 13, temp);      // replace  gtpro assign1 data    address 00 25 00 
    
     temp = gt10_data.mid(1633, 1);        // copy gt10 patch assign1 sw
    data.replace(952, 1, temp);      // replace  gtpro assign7 sw    address 00 26 00 
    temp = gt10_data.mid(1634, 2);        // copy gt10 patch assign7 target
    //data.replace(954, 2, temp);      // replace  gtpro assign7 target    address 00 26 00 
    temp = gt10_data.mid(1636, 13);        // copy gt10 patch assign7 data
    data.replace(956, 13, temp);      // replace  gtpro assign7 data    address 00 26 00 
    
    temp = gt10_data.mid(1649, 1);        // copy gt10 patch assign8 sw
    data.replace(982, 1, temp);      // replace  gtpro assign8 sw    address 00 27 00 
    temp = gt10_data.mid(1650, 2);        // copy gt10 patch assign8 target
    //data.replace(984, 2, temp);      // replace  gtpro assign8 target    address 00 27 00 
    temp = gt10_data.mid(1652, 13);        // copy gt10 patch assign8 data
    data.replace(986, 13, temp);      // replace  gtpro assign1 data    address 00 27 00 
    
 
    temp = hex.mid(0, 32);        // copy "gt10 conversion" text
    data.replace(1305, 32, temp);      // replace  gtpro user name text
    if ( gt10_data.size() == 2045) 
           {
            temp = gt10_data.mid(1774, 128);        // copy user dialog text if file is an extended type.
            data.replace(1164, 128, temp);      // replace  gtpro user dialog text
           };
    
    SysxIO *sysxIO = SysxIO::Instance();
		QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
		} 
    else if (data.size() == systemDataSize)  {         //if GT-Pro system file size is correct- load file. 
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
	msgText.append(QObject::tr("This is not a known ") + deviceType + (" patch!"));
	msgText.append("<b></font><br>");
	if (data.size() == 670){
  msgText.append("but appears to be a GT-6 patch<br>");};
  if (data.size() == 650){
  msgText.append("but appears to be a GT-3 patch<br>");};
	msgText.append(QObject::tr("Patch size not ") + (QString::number(patchSize, 10)) + (" bytes, please try another file."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();
			return false;
	
	};
 } else {return false;};
}

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

