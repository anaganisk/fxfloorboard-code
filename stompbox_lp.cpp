/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. 
** All rights reserved.
**
** This file is part of "GT-Pro Fx FloorBoard".
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

#include "stompbox_lp.h"

stompbox_lp::stompbox_lp(QWidget *parent)
    : stompBox(parent)
{
	/* LOOP */
	setImage(":/images/lp.png");
	setLSB("04", "00");
	setKnob1("04", "00", "09");
	setKnob2("04", "00", "0A");
	setComboBox("04", "00", "08");
	setButton("04", "00", "00");
	setEditPages();
};

void stompbox_lp::updateSignal()
{
	updateKnob1("04", "00", "09");
	updateKnob2("04", "00", "0A");
	updateComboBox("04", "00", "08");
	updateButton("04", "00", "00");
};

void stompbox_lp::setEditPages()
{
  editDetails()->page()->newGroupBox("Loop Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("S/R Loop 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "02");
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("S/R Loop 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "05");
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "06");
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "07");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	
	editDetails()->page()->newGroupBox("Pre Fx Loop");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

  editDetails()->page()->newGroupBox("Stereo Loop");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "08");
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "09");
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0A");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Type");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "0B");
	editDetails()->page()->addComboBox(0, 1, 1, 1, "04", "00", "0C");
	editDetails()->page()->addGroupBox(1, 2, 1, 1);

	editDetails()->addPage();	
};
