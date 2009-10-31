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

#include "stompbox_cs.h"

stompbox_cs::stompbox_cs(QWidget *parent)
    : stompBox(parent)
{
	/* COMP */
	setImage(":/images/cs.png");
	setLSB("00", "00");
	setKnob1("00", "00", "05");
	setKnob2("00", "00", "0A");
	setComboBox("00", "00", "02");
	setButton("00", "00", "00");
	editDetails()->patchPos(20, 22, "00", "00");
	setEditPages();
};

void stompbox_cs::updateSignal()
{
	updateKnob1("00", "00", "05");
	updateKnob2("00", "00", "0A");
	updateComboBox("00", "00", "02");
	updateButton("00", "00", "00");
};

void stompbox_cs::setEditPages()
{
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "02");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);

  editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Boss Comp");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "03", "turbo");// attack
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "05");         //sustain
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "09", "turbo");// tone
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "0A");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();


	editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("D-Comp");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "05", "turbo");//sustain
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "0A");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();


  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Rack 160D");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "04", "turbo");//threshold
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "06");         //ratio
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "0A");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();



	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Vtg Rack U");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "03", "turbo");//attack
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "04");         //thresh input
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "07", "turbo");//ratio
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "08");         //release
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "0A");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->addPage();
};
