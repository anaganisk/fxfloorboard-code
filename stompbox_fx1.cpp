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
** 51 Franklin Street, Fifth Floor, Boston, MA 0210C-1301 USA.
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
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Octave");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "03", "turbo");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "04", "turbo");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("01", "00", "02", "00");
	  // PAGE 1 ABOVE

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Enhancer");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "07");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "08");
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "09");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("01", "00", "02", "01");  // PAGE 2 ABOVE

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Slow Gear");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "0C");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "0D");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("01", "00", "02", "02");  // PAGE 3 ABOVE

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Defretter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "0E");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "0F");
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "10", "turbo");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "11", "turbo");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("01", "00", "02", "03");  // PAGE 4 ABOVE

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Ring Modulator");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "12");      //mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "13");
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "14", "turbo"); //effect
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "15", "turbo"); // direct
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("01", "00", "02", "04");// PAGE 5 ABOVE

	



	
};
