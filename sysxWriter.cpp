/****************************************************************************
**
** Copyright (C) 2007, 2008 Colin Willcocks.
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

		if(data.size() == patchSize){         // if patch file size is correct- load file.
		SysxIO *sysxIO = SysxIO::Instance();
		sysxIO->setFileSource(data);
		sysxIO->setFileName(this->fileName);

		this->fileSource = sysxIO->getFileSource();
		return true;
		}	else if (data.size() == 1010){
		
	QMessageBox *msgBox = new QMessageBox();
	msgBox->setWindowTitle(QObject::tr("Patch file conversion"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+1'><b>");
	msgText.append(QObject::tr("This is a GT-8 patch!"));
	msgText.append("<b></font><br>");
	msgText.append(QObject::tr("Be aware that conversions may not be consistant."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();
	
	QByteArray gt8_data = data;
	QFile file(":default.syx");   // Read the default GT-10 sysx file so whe don't start empty handed.
    if (file.open(QIODevice::ReadOnly))
	{	data = file.readAll(); };
	QByteArray temp;                           // TRANSLATION of GT-8 PATCHES **************
	QByteArray x = "00";
	 temp = gt8_data.mid(692, 16);            // copy gt8 name
	data.replace(11, 16, temp);              // replace gt10 name
	temp = gt8_data.mid(154, 1);             // copy gt8 compressor part1
	temp.append(gt8_data.mid(156,7));        // copy gt8 compressor part2
	data.replace(75, 8, temp);               // replace gt10 compressor
	temp = gt8_data.mid(212, 1);             // copy gt8 dist/od part1
	temp.append(gt8_data.mid(214,5));        // copy gt8 dist/od part2
	data.replace(123, 6, temp);               // replace gt10 distortion
	// adjust dist types here
	temp = gt8_data.mid(233, 1);             // copy gt8 preAmp control part1
	temp.append(gt8_data.mid(235,2));        // copy gt8 preAmp control part2
	temp.append(gt8_data.mid(238,1));        // copy gt8 preAmp control part3
	temp.append(gt8_data.mid(237,1));        // copy gt8 preAmp control part4
	data.replace(152, 5, temp);               // replace gt10 preAmp control
	temp = gt8_data.mid(239, 17);             // copy gt8 preAmp channel A 
	data.replace(168, 17, temp);               // replace gt10 preAmp channel A
	temp = gt8_data.mid(256, 17);             // copy gt8 preAmp channel B 
	data.replace(200, 17, temp);               // replace gt10 preAmp channel B
	temp = gt8_data.mid(286, 1);             // copy gt8 EQ part1
	temp.append(gt8_data.mid(288,11));       // copy gt8 EQ part2
	data.replace(264, 12, temp);               // replace gt10 EQ
	
	
	temp = gt8_data.mid(545, 1);             // copy gt8 delay part1
	temp.append(gt8_data.mid(547,16));       // copy gt8 delay part2
	temp.append(gt8_data.mid(565,4));       // copy gt8 delay part3
	temp.append(gt8_data.mid(563,2));       // copy gt8 delay part4
	temp.append(gt8_data.mid(569,2));       // copy gt8 delay part5
	if (temp.mid(2,1)=="11"){temp.replace(2, 1, "00");};
	data.replace(1351, 25, temp);               // replace gt10 delay
	temp = gt8_data.mid(584, 1);             // copy gt8 chorus part1
	temp.append(gt8_data.mid(586,7));       // copy gt8 chorus part2
	data.replace(1383, 8, temp);               // replace gt10 chorus
	temp = gt8_data.mid(606, 1);             // copy gt8 reverb part1
	temp.append(gt8_data.mid(608,3));       // copy gt8 reverb part2
	temp.append(gt8_data.mid(611,5));       // copy gt8 reverb part3
	data.replace(1399, 9, temp);               // replace gt10 reverb
	temp = (gt8_data.mid(610,1));              // copy gt8 reverb part4
	data.replace(1410, 1, temp);             // replace gt10 reverb
	
	
	
	
    SysxIO *sysxIO = SysxIO::Instance();
		sysxIO->setFileSource(data);
		sysxIO->setFileName(this->fileName);
		this->fileSource = sysxIO->getFileSource();
		return true;
		
    }	else {
	QMessageBox *msgBox = new QMessageBox();
	msgBox->setWindowTitle(QObject::tr("Patch size Error!"));
	msgBox->setIcon(QMessageBox::Warning);
	msgBox->setTextFormat(Qt::RichText);
	QString msgText;
	msgText.append("<font size='+1'><b>");
	msgText.append(QObject::tr("This is not a ") + deviceType + (" patch!"));
	msgText.append("<b></font><br>");
	msgText.append(QObject::tr("Patch size not ") + (QString::number(patchSize, 10)) + (" bytes, please try another file."));
	msgBox->setText(msgText);
	msgBox->setStandardButtons(QMessageBox::Ok);
	msgBox->exec();
			return false; };
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

SysxData sysxWriter::getFileSource()
{
	return fileSource;	
};

QString sysxWriter::getFileName()
{
	return fileName;	
};

