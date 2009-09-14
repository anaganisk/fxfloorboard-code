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
	  QByteArray GTE_default;
	  QByteArray gt8_data;
	  QByteArray default_data;
	 
		QByteArray data = file.readAll();
		
		QFile file(":default.syx");   // Read the default GT-Pro sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	default_data = file.readAll(); };
	  
		QFile GTEfile(":default.gte");           // Read the default GT-Pro GTE file .
    if (GTEfile.open(QIODevice::ReadOnly))
	  {	GTE_default = GTEfile.readAll(); };
	   QByteArray GTE_header = GTE_default.mid(3, 20);
	   bool isGTE = false;
	  if (data.contains(GTE_header)){isGTE = true; }; 

		if(data.size() == patchSize){  // if the data is a syx GT-Pro patch ******************************
		SysxIO *sysxIO = SysxIO::Instance();
		QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
        }
     else if (data.size() == 1010) { // if a GT-8 patch file. *****************************************
		QByteArray gt8_data = data;
		QByteArray temp;   
	  QByteArray hex;
	  QFile fileHex(":HexLookupTable.hex");   // Read the HexLookupTable.hex file.
    if (fileHex.open(QIODevice::ReadOnly))
	  {	hex = fileHex.readAll(); };
    temp = gt8_data.mid(11, 130);     // copy gt8 address 00 data
    default_data.replace(11, 130, temp);      // replace  gtpro 00 data               
	  temp = gt8_data.mid(154, 9);     // copy gt8 address 02 data
    default_data.replace(154, 9, temp);      // replace  gtpro 02 data                   
	  temp = gt8_data.mid(176, 5);     // copy gt8 address 03 data
    default_data.replace(176, 5, temp);      // replace  gtpro 03 data  
    temp = gt8_data.mid(194, 5);     // copy gt8 address 04 data
    default_data.replace(194, 5, temp);      // replace  gtpro 04 data 
    temp = gt8_data.mid(212, 8);     // copy gt8 address 06 data
    default_data.replace(234, 8, temp);      // replace  gtpro 06 data   
    temp = gt8_data.mid(233, 40);     // copy gt8 address 07 data
    default_data.replace(255, 40, temp);      // replace  gtpro 07 data 
    temp = gt8_data.mid(286, 13);     // copy gt8 address 08 data
    default_data.replace(308, 13, temp);      // replace  gtpro 08 data   
    temp = gt8_data.mid(312, 220);     // copy gt8 address 09 data
    default_data.replace(334, 220, temp);      // replace  gtpro 09 data     
    temp = gt8_data.mid(545, 26);     // copy gt8 address 0B data
    default_data.replace(567, 26, temp);      // replace  gtpro 0B data   
    temp = gt8_data.mid(584, 9);     // copy gt8 address 0C data
    default_data.replace(606, 9, temp);      // replace  gtpro 0C data  
    temp = gt8_data.mid(606, 10);     // copy gt8 address 0D data
    default_data.replace(628, 10, temp);      // replace  gtpro 0D data   
    temp = gt8_data.mid(629, 9);     // copy gt8 address 0E data
    default_data.replace(651, 9, temp);      // replace  gtpro 0E data 
    temp = gt8_data.mid(651, 1);     // copy gt8 address 0F data
    default_data.replace(674, 1, temp);      // replace  gtpro 0F data   
    temp = gt8_data.mid(665, 14);     // copy gt8 address 11 data
    default_data.replace(702, 14, temp);      // replace  gtpro 11 data 
    temp = gt8_data.mid(692, 16);     // copy gt8 address 12 data
    default_data.replace(729, 16, temp);      // replace  gtpro 12 data  
    temp = gt8_data.mid(1007, 1);     // copy gt8 address 1E data
    default_data.replace(758, 1, temp);      // replace  gtpro 1E data 
    temp = gt8_data.mid(767, 17);     // copy gt8 address 16 data     Assign 1
    default_data.replace(772, 17, temp);      // replace  gtpro 20 data 
    temp = gt8_data.mid(797, 17);     // copy gt8 address 17 data     
    default_data.replace(802, 17, temp);      // replace  gtpro 21 data 
    temp = gt8_data.mid(827, 17);     // copy gt8 address 18 data
    default_data.replace(832, 17, temp);      // replace  gtpro 22 data 
    temp = gt8_data.mid(857, 17);     // copy gt8 address 19 data
    default_data.replace(862, 17, temp);      // replace  gtpro 23 data 
    temp = gt8_data.mid(887, 17);     // copy gt8 address 1A data
    default_data.replace(892, 17, temp);      // replace  gtpro 24 data 
    temp = gt8_data.mid(917, 17);     // copy gt8 address 1B data
    default_data.replace(922, 17, temp);      // replace  gtpro 25 data 
    temp = gt8_data.mid(947, 17);     // copy gt8 address 1C data
    default_data.replace(952, 17, temp);      // replace  gtpro 26 data 
    temp = gt8_data.mid(977, 17);     // copy gt8 address 1D data         Assign 8
    default_data.replace(982, 17, temp);      // replace  gtpro 27 data 
    temp = gt8_data.mid(751, 3);     // copy gt8 address 15 data
    default_data.replace(1132, 3, temp);      // replace  gtpro 2C data
    default_data.replace(1148, 3, temp);      // replace  gtpro 2D data 
    temp = hex.mid(32, 32);        // copy gt8 conversion text
    default_data.replace(1305, 32, temp);      // replace  gtpro user name text 
   
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "Structure";
		sysxIO->setFileSource(area, default_data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;	
		} if(data.size() == 1763  || data.size() == 2045 || data.size() == 1862)  {  // if a GT-10 patch file, with or without text  *****************
    QByteArray gt10_data = data;
		QByteArray temp;   
		QByteArray hex;
	  QFile fileHex(":HexLookupTable.hex");   // Read the HexLookupTable.hex file.
    if (fileHex.open(QIODevice::ReadOnly))
	  {	hex = fileHex.readAll(); };
    temp = gt10_data.mid(11, 16);        // copy gt10 patch name data
    default_data.replace(729, 16, temp);      // replace  gtpro name data    address 00 12 00 
    
    temp = gt10_data.mid(293, 1);        // copy gt10 patch fx1 sw
    default_data.replace(11, 1, temp);      // replace  gtpro fx1 sw    address 00 00 00 
    char r = gt10_data.at(294);            // copy gt10 patch fx1 type
    temp = hex.mid((76+r), 1);             // convert FX1 types from HexLookupTable
    default_data.replace(13, 1, temp);      // replace  gtpro fx1 type    address 00 00 00 
    
    temp = gt10_data.mid(75, 1);        // copy gt10 patch compressor sw
    default_data.replace(154, 1, temp);      // replace  gtpro compressor sw    address 00 02 00 
    temp = gt10_data.mid(76, 7);        // copy gt10 patch compressor data
    default_data.replace(156, 7, temp);      // replace  gtpro compressor data    address 00 02 00 
    temp = gt10_data.mid(1415, 1);        // copy gt10 patch wha sw
    default_data.replace(176, 1, temp);      // replace  gtpro wha sw    address 00 03 00 
    temp = gt10_data.mid(1424, 2);        // copy gt10 patch wha data
    default_data.replace(178, 2, temp);      // replace  gtpro wha data    address 00 03 00 
     temp = gt10_data.mid(1428, 1);        // copy gt10 patch wha data
    default_data.replace(180, 1, temp);      // replace  gtpro wha data    address 00 03 00 
    temp = gt10_data.mid(1472, 1);        // copy gt10 patch loop sw
    default_data.replace(194, 1, temp);      // replace  gtpro loop sw    address 00 04 00 
    temp = gt10_data.mid(1473, 3);        // copy gt10 patch loop data
    default_data.replace(196, 3, temp);      // replace  gtpro loop data    address 00 04 00 
    temp = gt10_data.mid(123, 1);        // copy gt10 patch od/ds sw
    default_data.replace(234, 1, temp);      // replace  gtpro od/ds sw    address 00 06 00 
    temp = gt10_data.mid(124, 6);        // copy gt10 patch od/ds data
    default_data.replace(236, 6, temp);      // replace  gtpro od/ds data    address 00 06 00 
    r = data.at(236);
    temp = hex.mid((125+r), 1);             // convert DISTORTION types from HexLookupTable
    default_data.replace(236, 1, temp);      // replace  gtpro od/ds type
    temp = gt10_data.mid(152, 1);        // copy gt10 patch preamp sw
    default_data.replace(255, 1, temp);      // replace  gtpro preamp sw    address 00 07 00 
    temp = gt10_data.mid(153, 2);        // copy gt10 patch preamp data
    default_data.replace(257, 2, temp);      // replace  gtpro preamp data    address 00 07 00 
    temp = gt10_data.mid(156, 1);        // copy gt10 patch preamp data
    default_data.replace(259, 1, temp);      // replace  gtpro preamp data    address 00 07 00 
    temp = gt10_data.mid(155, 1);        // copy gt10 patch preamp data
    default_data.replace(260, 1, temp);      // replace  gtpro preamp data    address 00 07 00 
    temp = gt10_data.mid(168, 17);        // copy gt10 patch preamp A data
    default_data.replace(261, 17, temp);      // replace  gtpro preamp A data    address 00 07 00 
    temp = gt10_data.mid(200, 17);        // copy gt10 patch preamp B data
    default_data.replace(278, 17, temp);      // replace  gtpro preamp B data    address 00 07 00 
    r = data.at(261);
    temp = hex.mid((172+r), 1);             // convert PREAMP  types from HexLookupTable
    default_data.replace(261, 1, temp);      // replace  gtpro preamp A type
    r = data.at(278);
    temp = hex.mid((172+r), 1);             // convert PREAMP  types from HexLookupTable
    default_data.replace(278, 1, temp);      // replace  gtpro preamp B type
    
    temp = gt10_data.mid(264, 1);        // copy gt10 patch eq sw
    default_data.replace(308, 1, temp);      // replace  gtpro eq sw    address 00 08 00 
    temp = gt10_data.mid(265, 11);        // copy gt10 patch eq data
    default_data.replace(310, 11, temp);      // replace  gtpro eq data    address 00 08 00 
    
    temp = gt10_data.mid(815, 1);        // copy gt10 patch fx2 sw
    default_data.replace(334, 1, temp);      // replace  gtpro fx2 sw    address 00 09 00 
    r = gt10_data.at(816);            // copy gt10 patch fx2 type
    temp = hex.mid((332+r), 1);             // convert FX2 types from HexLookupTable 
    default_data.replace(336, 1, temp);      // replace  gtpro fx2 type    address 00 09 00 
    
    temp = gt10_data.mid(1351, 1);        // copy gt10 patch delay sw
    default_data.replace(567, 1, temp);      // replace  gtpro delay sw    address 00 0B 00 
    temp = gt10_data.mid(1352, 24);        // copy gt10 patch delay data
    default_data.replace(569, 24, temp);      // replace  gtpro delay data    address 00 0B 00 
    temp = gt10_data.mid(1383, 1);        // copy gt10 patch chorus sw
    default_data.replace(606, 1, temp);      // replace  gtpro chorus sw    address 00 0C 00 
    temp = gt10_data.mid(1384, 7);        // copy gt10 patch chorus data
    default_data.replace(608, 7, temp);      // replace  gtpro chorus data    address 00 0C 00 
    temp = gt10_data.mid(1399, 1);        // copy gt10 patch reverb sw
    default_data.replace(628, 1, temp);      // replace  gtpro reverb sw    address 00 0D 00 
    temp = gt10_data.mid(1400, 8);        // copy gt10 patch reverb data
    default_data.replace(630, 8, temp);      // replace  gtpro reverb data    address 00 0D 00 
          
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
                default_data.replace(k, 1, temp);      // replace gtpro chain 
                k=k+1;  
              };
      }; 
    temp = gt10_data.mid(1524, 1);        // copy gt10 patch assign1 sw
    default_data.replace(772, 1, temp);      // replace  gtpro assign1 sw    address 00 20 00 
    temp = gt10_data.mid(1525, 2);        // copy gt10 patch assign1 target
    //default_data.replace(774, 2, temp);      // replace  gtpro assign1 target    address 00 20 00 
    temp = gt10_data.mid(1527, 13);        // copy gt10 patch assign1 data
    default_data.replace(776, 13, temp);      // replace  gtpro assign1 data    address 00 20 00 
    r = gt10_data.at(1531);            // copy gt10 patch source type
    temp = hex.mid((383+r), 1);             // convert source types from HexLookupTable 
    default_data.replace(780, 1, temp);      // replace  gtpro source type    
    
    temp = gt10_data.mid(1540, 1);        // copy gt10 patch assign2 sw
    default_data.replace(802, 1, temp);      // replace  gtpro assign2 sw    address 00 21 00 
    //temp = gt10_data.mid(1541, 2);        // copy gt10 patch assign2 target
    default_data.replace(804, 2, temp);      // replace  gtpro assign2 target    address 00 21 00 
    temp = gt10_data.mid(1543, 13);        // copy gt10 patch assign2 data
    default_data.replace(806, 13, temp);      // replace  gtpro assign2 data    address 00 21 00 
 
    temp = gt10_data.mid(1556, 1);        // copy gt10 patch assign3 sw
    default_data.replace(832, 1, temp);      // replace  gtpro assign1 sw    address 00 22 00 
    temp = gt10_data.mid(1557, 2);        // copy gt10 patch assign3 target
    //default_data.replace(834, 2, temp);      // replace  gtpro assign3 target    address 00 22 00 
    temp = gt10_data.mid(1559, 13);        // copy gt10 patch assign3 data
    default_data.replace(836, 13, temp);      // replace  gtpro assign3 data    address 00 22 00 
 
    temp = gt10_data.mid(1572, 1);        // copy gt10 patch assign4 sw
    default_data.replace(862, 1, temp);      // replace  gtpro assign4 sw    address 00 23 00 
    temp = gt10_data.mid(1573, 2);        // copy gt10 patch assign4 target
    //default_data.replace(864, 2, temp);      // replace  gtpro assign4 target    address 00 23 00 
    temp = gt10_data.mid(1575, 13);        // copy gt10 patch assign4 data
    default_data.replace(866, 13, temp);      // replace  gtpro assign1 data    address 00 23 00 
 
    temp = gt10_data.mid(1588, 1);        // copy gt10 patch assign1 sw
    default_data.replace(892, 1, temp);      // replace  gtpro assign5 sw    address 00 24 00 
    temp = gt10_data.mid(1589, 2);        // copy gt10 patch assign5 target
    //default_data.replace(894, 2, temp);      // replace  gtpro assign5 target    address 00 24 00 
    temp = gt10_data.mid(1591, 13);        // copy gt10 patch assign5 data
    default_data.replace(896, 13, temp);      // replace  gtpro assign1 data    address 00 24 00 
    
    temp = gt10_data.mid(1604, 1);        // copy gt10 patch assign1 sw
    default_data.replace(922, 1, temp);      // replace  gtpro assign6 sw    address 00 25 00 
    temp = gt10_data.mid(1605, 2);        // copy gt10 patch assign6 target
    //default_data.replace(924, 2, temp);      // replace  gtpro assign6 target    address 00 25 00 
    temp = gt10_data.mid(1607, 13);        // copy gt10 patch assign6 data
    default_data.replace(926, 13, temp);      // replace  gtpro assign1 data    address 00 25 00 
    
     temp = gt10_data.mid(1633, 1);        // copy gt10 patch assign1 sw
    default_data.replace(952, 1, temp);      // replace  gtpro assign7 sw    address 00 26 00 
    temp = gt10_data.mid(1634, 2);        // copy gt10 patch assign7 target
    //default_data.replace(954, 2, temp);      // replace  gtpro assign7 target    address 00 26 00 
    temp = gt10_data.mid(1636, 13);        // copy gt10 patch assign7 data
    default_data.replace(956, 13, temp);      // replace  gtpro assign7 data    address 00 26 00 
    
    temp = gt10_data.mid(1649, 1);        // copy gt10 patch assign8 sw
    default_data.replace(982, 1, temp);      // replace  gtpro assign8 sw    address 00 27 00 
    temp = gt10_data.mid(1650, 2);        // copy gt10 patch assign8 target
    //default_data.replace(984, 2, temp);      // replace  gtpro assign8 target    address 00 27 00 
    temp = gt10_data.mid(1652, 13);        // copy gt10 patch assign8 data
    default_data.replace(986, 13, temp);      // replace  gtpro assign1 data    address 00 27 00 
    
 
    temp = hex.mid(0, 32);        // copy "gt10 conversion" text
    default_data.replace(1305, 32, temp);      // replace  gtpro user name text
    if ( gt10_data.size() == 2045) 
           {
            temp = gt10_data.mid(1774, 128);        // copy user dialog text if file is an extended type.
            default_data.replace(1164, 128, temp);      // replace  gtpro user dialog text
           };
    
    SysxIO *sysxIO = SysxIO::Instance();
		QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
		} 
    else if (data.size() == systemDataSize)  {   //if GT-Pro system file size is correct- load file.***************** 
    SysxIO *sysxIO = SysxIO::Instance();
		QString area = "System";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);
		this->systemSource = sysxIO->getSystemSource();	
		return true; 
      }
	  else if (isGTE)      // if the read file is a Boss Librarian type. ***************************************
  {
  index=1;
  unsigned char r = (char)data[35];     // find patch count in GTE file at byte 35, 1~200
	bool ok;
  int patchCount;
  patchCount = QString::number(r, 16).toUpper().toInt(&ok, 16);
  if (patchCount>1)
  {
  QString msgText;
  QString patchText;
	QString patchNumber;
	this->patchList.clear();
	this->patchList.append("Select Patch");
  unsigned int a = 742; // locate patch start position from the start of the file                    
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
            a=a+1060;                      // offset is set in front of marker
        }; 
              
    fileDialog *dialog = new fileDialog(fileName, patchList); 
    dialog->exec();    
    patchIndex(this->index);                          
   };   
   
   int a=160;                             // offset is set in front of marker
   if (patchCount>1)
   {
    int q=index-1; 
    a = (q*1060) + 160; 
        };    
   QByteArray temp;
   temp = data.mid(a+8, 130);
   default_data.replace(11, 130, temp);      //address "00" ++
   
   temp = data.mid(a+142, 9);
   default_data.replace(154, 9, temp);     //address "02" ++ 
   
   temp = data.mid(a+155, 5);
   default_data.replace(176, 5, temp);     //address "03" ++
   
   temp = data.mid(a+164, 13);
   default_data.replace(194, 13, temp);     //address "04" ++
   
   temp = data.mid(a+180, 1);
   default_data.replace(220, 1, temp);     //address "05" ++ 
          
   temp = data.mid(a+186, 8);
   default_data.replace(234, 8, temp);     //address "06" ++ 
      
   temp = data.mid(a+198, 40);
   default_data.replace(255, 40, temp);     //address "07" ++ 
    
   temp = data.mid(a+242, 13);
   default_data.replace(308, 13, temp);     //address "08" ++
        
   temp = data.mid(a+259, 220);
   default_data.replace(334, 220, temp);     //address "09" ++
   
   temp = data.mid(a+483, 26);
   default_data.replace(567, 26, temp);    //address "0B" ++ 
       
   temp = data.mid(a+513, 9);
   default_data.replace(606, 9, temp);    //address "0C" ++    
   
   temp = data.mid(a+526, 10);
   default_data.replace(628, 10, temp);    //address "0D" ++    
   
   temp = data.mid(a+540, 10);
   default_data.replace(651, 10, temp);    //address "0E" ++    
   
   temp = data.mid(a+554, 1);
   default_data.replace(674, 1, temp);    //address "0F" ++    
   
   temp = data.mid(a+559, 1);
   default_data.replace(688, 1, temp);    //address "10" ++    
    
   temp = data.mid(a+564, 14);
   default_data.replace(702, 14, temp);    //address "11" ++    
   
   temp = data.mid(a+582, 16);
   default_data.replace(729, 16, temp);    //address "12" ++    
   
   temp = data.mid(a+598, 1);
   default_data.replace(758, 1, temp);    //address "1E" ++    
   
   temp = data.mid(a+794, 17);
   default_data.replace(772, 17, temp);    //address "20" ++    
   
   temp = data.mid(a+815, 17);
   default_data.replace(802, 17, temp);    //address "21" ++    
   
   temp = data.mid(a+836, 17);
   default_data.replace(832, 17, temp);    //address "22" ++    
   
   temp = data.mid(a+857, 17);
   default_data.replace(862, 17, temp);    //address "23" ++    
   
   temp = data.mid(a+878, 17);
   default_data.replace(892, 17, temp);    //address "24" ++    
   
   temp = data.mid(a+899, 17);
   default_data.replace(922, 17, temp);    //address "25" ++  
      
   temp = data.mid(a+920, 17);
   default_data.replace(952, 17, temp);    //address "26" ++    
   
   temp = data.mid(a+941, 17);
   default_data.replace(982, 17, temp);    //address "27" ++    
   
   temp = data.mid(a+962, 17);
   default_data.replace(1012, 17, temp);    //address "28" ++    
   
   temp = data.mid(a+983, 17);
   default_data.replace(1042, 17, temp);    //address "29" ++    
   
   temp = data.mid(a+1004, 17);
   default_data.replace(1072, 17, temp);    //address "2A" ++    
   
   temp = data.mid(a+1025, 17);
   default_data.replace(1102, 17, temp);    //address "2B" ++  
    
   temp = data.mid(a+1046, 3);
   default_data.replace(1132, 3, temp);    //address "2C" ++ 
     
   temp = data.mid(a+1053, 3);
   default_data.replace(1142, 3, temp);    //address "2D" ++              
           
    if (index>0)
    {  
    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource("Structure", default_data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true; 
    } else { return false; };
   } else  
   {
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
	msgText.append(QObject::tr("Patch size is ") + (QString::number(data.size(), 10)) + (" bytes, please try another file."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();
	return false;	
 } } else {return false; };
}

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

void sysxWriter::writeGTE(QString fileName)
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
	 QByteArray GTE_default;
   QByteArray temp;
   int a = 160;
    QFile GTEfile(":default.gte");           // Read the default GT-Pro GTE file .
    if (GTEfile.open(QIODevice::ReadOnly))
	  {	GTE_default = GTEfile.readAll(); };
   
    temp = out.mid(11, 130);
   GTE_default.replace(a+8, 130, temp);      //address "00" ++
   
   temp = out.mid(154, 9);
   GTE_default.replace(a+142, 9, temp);     //address "02" ++ 
   
   temp = out.mid(176, 5);
   GTE_default.replace(a+155, 5, temp);     //address "03" ++
   
   temp = out.mid(194, 13);
   GTE_default.replace(a+164, 13, temp);     //address "04" ++
   
   temp = out.mid(220, 1);
   GTE_default.replace(a+180, 1, temp);     //address "05" ++ 
          
   temp = out.mid(234, 8);
   GTE_default.replace(a+186, 8, temp);     //address "06" ++ 
      
   temp = out.mid(255, 40);
   GTE_default.replace(a+198, 40, temp);     //address "07" ++ 
    
   temp = out.mid(308, 13);
   GTE_default.replace(a+242, 13, temp);     //address "08" ++
        
   temp = out.mid(334, 220);
   GTE_default.replace(a+259, 220, temp);     //address "09" ++
   
   temp = out.mid(567, 26);
   GTE_default.replace(a+483, 26, temp);    //address "0B" ++ 
       
   temp = out.mid(606, 9);
   GTE_default.replace(a+513, 9, temp);    //address "0C" ++    
   
   temp = out.mid(628, 10);
   GTE_default.replace(a+526, 10, temp);    //address "0D" ++    
   
   temp = out.mid(651, 10);
   GTE_default.replace(a+540, 10, temp);    //address "0E" ++    
   
   temp = out.mid(674, 1);
   GTE_default.replace(a+554, 1, temp);    //address "0F" ++    
   
   temp = out.mid(688, 1);
   GTE_default.replace(a+559, 1, temp);    //address "10" ++    
    
   temp = out.mid(702, 14);
   GTE_default.replace(a+564, 14, temp);    //address "11" ++    
   
   temp = out.mid(729, 16);
   GTE_default.replace(a+582, 16, temp);    //address "12" ++    
   
   temp = out.mid(758, 1);
   GTE_default.replace(a+598, 1, temp);    //address "1E" ++    
   
   temp = out.mid(772, 17);
   GTE_default.replace(a+794, 17, temp);    //address "20" ++    
   
   temp = out.mid(802, 17);
   GTE_default.replace(a+815, 17, temp);    //address "21" ++    
   
   temp = out.mid(832, 17);
   GTE_default.replace(a+836, 17, temp);    //address "22" ++    
   
   temp = out.mid(862, 17);
   GTE_default.replace(a+857, 17, temp);    //address "23" ++    
   
   temp = out.mid(892, 17);
   GTE_default.replace(a+878, 17, temp);    //address "24" ++    
   
   temp = out.mid(922, 17);
   GTE_default.replace(a+899, 17, temp);    //address "25" ++  
      
   temp = out.mid(952, 17);
   GTE_default.replace(a+920, 17, temp);    //address "26" ++    
   
   temp = out.mid(982, 17);
   GTE_default.replace(a+941, 17, temp);    //address "27" ++    
   
   temp = out.mid(1012, 17);
   GTE_default.replace(a+962, 17, temp);    //address "28" ++    
   
   temp = out.mid(1042, 17);
   GTE_default.replace(a+983, 17, temp);    //address "29" ++    
   
   temp = out.mid(1072, 17);
   GTE_default.replace(a+1004, 17, temp);    //address "2A" ++    
   
   temp = out.mid(1102, 17);
   GTE_default.replace(a+1025, 17, temp);    //address "2B" ++  
    
   temp = out.mid(1132, 3);
   GTE_default.replace(a+1046, 3, temp);    //address "2C" ++ 
     
   temp = out.mid(1142, 3);
   GTE_default.replace(a+1053, 3, temp);    //address "2D" ++    
  
		file.write(GTE_default);
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

