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

#include "editPage.h"
#include <QLabel>
#include "customControlKnob.h"

editPage::editPage(QWidget *parent)
    : QWidget(parent)
{
	/*QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ),
                this, SIGNAL( dialogUpdateSignal() ));*/

	/*QObject::connect(this, SIGNAL( updateSignal() ),
                this->parent(), SIGNAL( updateSignal() ));*/
};

void editPage::paintEvent(QPaintEvent *)
{
	/*QPixmap image(":images/dragbar.png");
	
	QRectF target(0.0, 0.0, this->width(), this->height());
	QRectF source(0.0, 0.0, this->width(), this->height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);*/
};

void editPage::addKnob(QPoint pos, QString hex1, QString hex2, QString hex3, 
					   QString background, QString direction, int lenght)
{
	customControlKnob *knob = new customControlKnob(this, hex1, hex2, hex3, background, direction, lenght);
	knob->move(pos);
};

void editPage::addSwitch(QPoint pos)
{
	bool on = true;
	QString hex1 = "00";
	QString hex2 = "00";
	QString hex3 = "00";
	QString imagePath(":/images/switch.png");
	customSwitch *switchbutton = new customSwitch(on, pos, this, hex1, hex2, hex3, imagePath);	
};

void editPage::addComboBox(QPoint pos)
{
	
};

void editPage::addLabel(QString text, QPoint pos)
{
	QLabel *newLabel = new QLabel(this);

	QFont labelFont;
	labelFont.setFamily("Arial");
	labelFont.setBold(true);
	labelFont.setPixelSize(12);
	labelFont.setStretch(105);

	QPalette palette;
	palette.setColor(newLabel->foregroundRole(), Qt::white);

	newLabel->setPalette(palette);
	newLabel->setFont(labelFont);

	newLabel->setText(text);
	newLabel->move(pos);
};

void editPage::valueChanged(bool value, QString hex1, QString hex2, QString hex3)
{
	value;
	hex1;
	hex2;
	hex3;
}; 
