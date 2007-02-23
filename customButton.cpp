/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT6B FX FloorBoard".
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
#include "customButton.h"

customButton::customButton(bool active, QPoint buttonPos, QWidget *parent, QString hex1, QString hex2, QString hex3, 
						   QString imagePath)
    : QWidget(parent)
{
	this->hex1 = hex1;
	this->hex2 = hex2;
	this->hex3 = hex3;
	this->active = active;
	this->imagePath = imagePath;
	QSize imageSize = QPixmap(imagePath).size();
	this->buttonSize =  QSize(imageSize.width(), imageSize.height()/4);
	this->buttonPos = buttonPos;
	setOffset(0);
    setGeometry(buttonPos.x(), buttonPos.y(), buttonSize.width(), buttonSize.height());

	QObject::connect(this, SIGNAL( valueChanged(bool, QString, QString, QString) ),
                this->parent(), SLOT( valueChanged(bool, QString, QString, QString) ));
};

void customButton::paintEvent(QPaintEvent *)
{
	QRectF target(0.0 , 0.0, buttonSize.width(), buttonSize.height());
	QRectF source(0.0, yOffset, buttonSize.width(), buttonSize.height());
	QPixmap image(imagePath);

	QPainter painter(this);
	painter.drawPixmap(target, image, source);
};

void customButton::setOffset(signed int imageNr)
{
	this->yOffset = imageNr*buttonSize.height();
	this->update();
};

void customButton::mousePressEvent(QMouseEvent *event)
{
	if ( event->button() == Qt::LeftButton )
	{	
		this->dragStartPosition = event->pos();
		if(active)
		{
			setOffset(3);
		}
		else
		{
			setOffset(1);
		};
		setFocus();
	};
};

void customButton::mouseReleaseEvent(QMouseEvent *event)
{
	if ( event->button() == Qt::LeftButton )
	{	
		if(active)
		{
			setOffset(0);
			emitValue(false);
		}
		else
		{
			setOffset(2);
			emitValue(true);
		};
		clearFocus();
	};
};

void customButton::emitValue(bool value)
{
    this->active = value;
	//if (value != m_value) {
    //    this->m_value = value;
        emit valueChanged((bool)value, this->hex1, this->hex2, this->hex3);
    //};
};

void customButton::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() == Qt::LeftButton) && (event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance())
	{
        return;
	};
	/*if(active)
	{
		setOffset(2);
	}
	else
	{
		setOffset(0);
	};*/
};

void customButton::setValue(bool value)
{
	this->active = value;
	if(active)
	{
		setOffset(2);
	}
	else
	{
		setOffset(0);
	};
	clearFocus();
};
