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

#include "stompbox_od.h"

stompbox_od::stompbox_od(QWidget *parent)
    : stompBox(parent)
{
	/* OD/DS */
	setImage(":/images/od.png");
	setLSB("02", "00");
	setKnob1("02", "00", "03");
	setKnob2("02", "00", "06");
	setComboBox("02", "00", "02");
	setButton("02", "00", "00");
	setEditPages();
};

void stompbox_od::updateSignal()
{
	updateKnob1("02", "00", "03");
	updateKnob2("02", "00", "06");
	updateComboBox("02", "00", "02");
	updateButton("02", "00", "00");
};

void stompbox_od::setEditPages()
{
    editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "02"); 
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "03", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "04");         //bass
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "05");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "06", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage();  // PAGE 1 ABOVE 

  
	};
