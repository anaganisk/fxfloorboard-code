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
	QByteArray gt8_data;
    if (file.open(QIODevice::ReadOnly))
	{
		QByteArray data = file.readAll();

		if(data.size() == patchSize){
		SysxIO *sysxIO = SysxIO::Instance();
		sysxIO->setFileSource(data);
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
	  
	                   
    temp = gt8_data.mid(0, 199);     // copy patch description from gt8_data.syx  to 00 04 00 byte 5, all same as gtpro
    temp.append(data.mid(199, 24));  // loop insert from gtpro. 04 & 05
    temp.append(gt8_data.mid(201, 453));  // copy gt8 file to amp ctrl. 06 - 0F
    
    temp.append(data.mid(677, 14));  //  copy gtpro amp ctrl 2. 10
    temp.append(gt8_data.mid(654, 56));  // copy gt8 file 11 & 12. 
    temp.append(gt8_data.mid(996, 14));  // copy gt8 file 1E.
    temp.append(data.mid(761, 392));  //  copy gtpro assigns.*/
        
      
    SysxIO *sysxIO = SysxIO::Instance();
    //QString area = "Structure";
		sysxIO->setFileSource(temp);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;	
		}
		else {
	QMessageBox *msgBox = new QMessageBox();
	msgBox->setWindowTitle(QObject::tr("Patch size Error!"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+1'><b>");
	msgText.append(QObject::tr("This is not a known ") + deviceType + (" patch!"));
	msgText.append("<b></font><br>");
	msgText.append(QObject::tr("Patch size not ") + (QString::number(patchSize, 10)) + (" bytes, please try another file."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();
			return false;
	
	};
 };
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

SysxData sysxWriter::getFileSource()
{
	return fileSource;	
};

QString sysxWriter::getFileName()
{
	return fileName;	
};

