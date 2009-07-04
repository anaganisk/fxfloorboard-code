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
		QByteArray default_data;
		QFile file(":default.syx");           // Read the default GT-6 sysx file .
    if (file.open(QIODevice::ReadOnly))
	  {	default_data = file.readAll(); };
	  
	  QByteArray default_header = default_data.mid(0, 6);           // copy header from default.syx
	  QByteArray text_header = default_data.mid(684, 6);            // copy header from default.syx from text area
	  QByteArray file_header = data.mid(0, 6);                      // copy header from read file.syx
	  bool isHeader = false;
	  bool isOther = false;
	  bool isSystem = false;
	  if (default_header == file_header) { isHeader = true; };
	  if (text_header == file_header) { isOther = true; };
	  unsigned char byte = (char)data[6];
		unsigned int n = (int)byte;  
	  if (n < 6){ isSystem = true; };
    
		if(data.size() == 898 && isHeader && !isSystem){
		SysxIO *sysxIO = SysxIO::Instance();
		QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);

		this->fileSource = sysxIO->getFileSource();
		return true;
		}
		else if (data.size() == 684 && isHeader && !isSystem)
    {
    QByteArray standard_data = data;
	  QFile file(":default.syx");   // Read the default GT-6B sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	  
	  QByteArray temp;                      
    temp = data.mid(684, 228);           // copy patch description from default.syx  address 00 17 00 00
    
    standard_data.append(temp);  
    data = standard_data;
    
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);

		this->fileSource = sysxIO->getFileSource();
		return true;
		}
		else if (data.size() > 684 && isHeader && !isSystem)   // most likely a GT_Manager file
    {
    QByteArray patch_data = data;
	  QFile file(":default.syx");   // Read the default GT-6B sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	  
	  QByteArray temp; 
    temp = patch_data.mid(0, 684);                    
    temp.append(data.mid(684, 228));           // copy patch description from default.syx  address 00 17 00 00
     
    data = temp;
    
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);

		this->fileSource = sysxIO->getFileSource();
		return true;
    }
		else if (data.size() > 684 && data.size() < 684 && isSystem)   // most likely an other type file with system data at front
    {
    QByteArray patch_data = data;
	  QFile file(":default.syx");   // Read the default GT-6 sysx file so we don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	  {	data = file.readAll(); };
	  int x=1;
	  QByteArray temp; 
	  for(int b=0; b<2000; b++)
     {	  
	    x = patch_data.indexOf(default_header, b);  
	    byte = (char)patch_data[x+6];
		  n = (int)byte;  
	    if (n < 6){b=b+x;}else {b=2000;};
	     
    temp = patch_data.mid(4206, 684);                    
    temp.append(data.mid(684, 228));           // copy patch description from default.syx  address 00 17 00 00
     };
    data = temp;
    
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "Structure";
		sysxIO->setFileSource(area, data);
		sysxIO->setFileName(this->fileName);

		this->fileSource = sysxIO->getFileSource();
		return true;
		}	
		else if (data.size() == 2237 && isSystem)   // SYSytem File
    {  
    SysxIO *sysxIO = SysxIO::Instance();
    QString area = "System";
		sysxIO->setFileSource(area, data);
		
		this->systemSource = sysxIO->getSystemSource();
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
	msgText.append(QObject::tr("This is not a known ") + deviceType + (" patch!"));
	msgText.append("<b></font><br>");
	msgText.append(QObject::tr("Patch file not within allowable parameters or<br>"));
  msgText.append(QObject::tr("file format unknown, please try another file."));
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

