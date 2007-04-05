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

#include "stompbox_fx1.h"

stompbox_fx1::stompbox_fx1(QWidget *parent)
    : stompBox(parent)
{
	/* FX1 */
	setImage(":/images/fx1.png");
	setLSB("01", "00");
	setComboBox("01", "00", "02", QRect(8, 31, 79, 13));
	setButton("01", "00", "00");
	setEditPages();
};

void stompbox_fx1::updateSignal()
{
	updateComboBox("01", "00", "02");
	updateButton("01", "00", "00");
};

void stompbox_fx1::setEditPages()
{
 	editDetails()->page()->addLabel("Octave", QPoint(0,0));
	editDetails()->page()->addKnob(QPoint(0,20), "01", "00", "03");
	editDetails()->page()->addKnob(QPoint(45,20), "01", "00", "04");
	//editDetails()->page()->addSwitch(QPoint(230,25));
	editDetails()->addPage();

	editDetails()->page()->addLabel("Enhancer", QPoint(0,0));
	editDetails()->page()->addKnob(QPoint(0,20), "01", "00", "07");
	editDetails()->page()->addKnob(QPoint(45,20), "01", "00", "08");
	editDetails()->page()->addKnob(QPoint(90,20), "01", "00", "09");
    //editDetails()->page()->addSwitch(QPoint(230,25));
	editDetails()->addPage();

	editDetails()->page()->addLabel("Slow Gear", QPoint(0,0));
	editDetails()->page()->addKnob(QPoint(0,20), "01", "00", "0C");
	editDetails()->page()->addKnob(QPoint(80,20), "01", "00", "0D");
	editDetails()->addPage();

	editDetails()->page()->addLabel("Defretter", QPoint(0,0));
	editDetails()->page()->addKnob(QPoint(0,20), "01", "00", "0E");
	editDetails()->page()->addKnob(QPoint(45,20), "01", "00", "0F");
	editDetails()->page()->addKnob(QPoint(90,20), "01", "00", "10");
	editDetails()->page()->addKnob(QPoint(135,20), "01", "00", "11");
	editDetails()->addPage();

	editDetails()->page()->addLabel("Ring Modulator", QPoint(0,0));
	editDetails()->page()->addKnob(QPoint(0,20), "01", "00", "12");
	editDetails()->page()->addKnob(QPoint(45,20), "01", "00", "13");
	editDetails()->page()->addKnob(QPoint(90,20), "01", "00", "14");
	editDetails()->page()->addKnob(QPoint(135,20), "01", "00", "15");
    editDetails()->addPage(); 
};
