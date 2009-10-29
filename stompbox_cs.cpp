/****************************************************************************
**
** Copyright (C) 2005-2006 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-3 FX FloorBoard".
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

#include "stompbox_cs.h"

stompbox_cs::stompbox_cs(QWidget *parent)
    : stompBox(parent)
{
	/* COMP */
	setImage(":/images/cs.png");
	setLSB("01", "00");
	setKnob1("01", "00", "02");
	setKnob2("01", "00", "05");
	setComboBox("01", "00", "01");
	setButton("01", "00", "00");
	editDetails()->patchPos(96, 20, "01", "00");
	setEditPages();
};

void stompbox_cs::updateSignal()
{
	updateKnob1("01", "00", "02");
	updateKnob2("01", "00", "05");
	updateComboBox("01", "00", "01");
	updateButton("01", "00", "00");
};

void stompbox_cs::setEditPages()
{
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

  editDetails()->page()->newGroupBox("CS");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "02", "turbo");// sustain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "03");         //attack
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "04", "turbo");// tone
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "05");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("01", "00", "01", "00");  // PAGE 1 ABOVE


	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
    editDetails()->page()->newGroupBox("LM");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "06", "turbo");//threshold
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "07");         //release
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "08", "turbo");//tone
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "09");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("01", "00", "01", "01");  // PAGE 2 ABOVE



	
};
