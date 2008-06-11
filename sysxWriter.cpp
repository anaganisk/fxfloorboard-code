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

		if(data.size() == patchSize){
		SysxIO *sysxIO = SysxIO::Instance();
		sysxIO->setFileSource(data);
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
	msgText.append(QObject::tr("This is not a ") + deviceType + (" patch!"));
	msgText.append("<b></font><br>");
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

SysxData sysxWriter::getFileSource()
{
	return fileSource;	
};

QString sysxWriter::getFileName()
{
	return fileName;	
};

