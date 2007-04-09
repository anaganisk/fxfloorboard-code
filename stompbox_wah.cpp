/****************************************************************************
**
** Copyright (C) 2005-2006 Uco Mesdag. All rights reserved.
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

#include "stompbox_wah.h"

stompbox_wah::stompbox_wah(QWidget *parent)
    : stompBox(parent)
{
	/* WAH */
	setImage(":/images/wah.png");
	setLSB("02", "00");
	setButton("02", "00", "00", QPoint::QPoint(0, 109), ":/images/pedal.png");
	setComboBox("02", "00", "02");
	setEditPages();
};

void stompbox_wah::updateSignal()
{
	updateButton("02", "00", "00");
	updateComboBox("02", "00", "02");
};

void stompbox_wah::setEditPages()
{
 	/*editDetails()->page()->addLabel("WH - Pedal Wah", QPoint(0,0));
	editDetails()->page()->addKnob(QPoint(0,20), "02", "00", "03");
	editDetails()->page()->addKnob(QPoint(45,20), "02", "00", "04");
	editDetails()->page()->addKnob(QPoint(90,20), "02", "00", "05");
	//editDetails()->page()->addSwitch(QPoint(230,25));
	editDetails()->addPage();

	editDetails()->page()->addLabel("TW - Touch Wah", QPoint(0,0));
	editDetails()->page()->addKnob(QPoint(0,20), "02", "00", "06");
	editDetails()->page()->addKnob(QPoint(45,20), "02", "00", "07");
	editDetails()->page()->addKnob(QPoint(90,20), "02", "00", "08");
	editDetails()->page()->addKnob(QPoint(135,20), "02", "00", "09");
	editDetails()->page()->addKnob(QPoint(180,20), "02", "00", "0A");
	editDetails()->page()->addKnob(QPoint(225,20), "02", "00", "0B");
	editDetails()->page()->addKnob(QPoint(270,20), "02", "00", "0C");
    //editDetails()->page()->addSwitch(QPoint(230,25));
	editDetails()->addPage();

		editDetails()->page()->addLabel("AW - Auto Wah", QPoint(0,0));
	editDetails()->page()->addKnob(QPoint(0,20), "01", "00", "07");
	editDetails()->page()->addKnob(QPoint(45,20), "01", "00", "08");
	editDetails()->page()->addKnob(QPoint(90,20), "01", "00", "09");
    //editDetails()->page()->addSwitch(QPoint(230,25));
	editDetails()->addPage();*/
};
