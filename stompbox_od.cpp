/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-10B Fx FloorBoard".
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

#include "stompbox_od.h"

stompbox_od::stompbox_od(QWidget *parent)
    : stompBox(parent)
{
	/* OD/DS */
	setImage(":/images/od.png");
	setLSB("00", "00");
	setKnob1("00", "00", "72");
	setKnob2("00", "00", "75");
	setComboBox("00", "00", "71");
	setButton("00", "00", "70");
	setEditPages();
};

void stompbox_od::updateSignal()
{
	updateKnob1("00", "00", "72");
	updateKnob2("00", "00", "75");
	updateComboBox("00", "00", "71");
	updateButton("00", "00", "70");
};

void stompbox_od::setEditPages()
{
  editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "70", "middle", Qt::AlignCenter);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "71");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Overdrive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "72", "turbo");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "74");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "73");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "75");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "76");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
 
	editDetails()->addPage();	

	editDetails()->patchPos(246, 14, "00", "70");    // sysx file offset and data length of chorus parameters x2,
                                                  // and hex1 & hex3 address start point.
};
