/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-8 Fx FloorBoard".
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
#include "statusBarSymbol.h"
#include "globalVariables.h"

statusBarSymbol::statusBarSymbol(QWidget *parent, QString imagePath)
    : QWidget(parent)
{
	this->imagePath = imagePath;
	QSize imageSize = QPixmap(imagePath).size();
	this->symbolSize =  QSize(imageSize.width()/4, imageSize.height());
	this->setFixedSize(symbolSize);

	setOffset(0);
};

void statusBarSymbol::paintEvent(QPaintEvent *)
{
	QRectF target(0.0 , 0.0, symbolSize.width(), symbolSize.height());
	QRectF source(xOffset, 0.0, symbolSize.width(), symbolSize.height());
	QPixmap image(imagePath);

	QPainter painter(this);
	painter.drawPixmap(target, image, source);
};

void statusBarSymbol::setOffset(int imageNr)
{
	this->xOffset = imageNr*symbolSize.width();
	this->update();
};

void statusBarSymbol::setValue(int value)
{
	setOffset(value);
};