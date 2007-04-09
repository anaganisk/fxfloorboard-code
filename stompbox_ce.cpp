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

#include "stompbox_ce.h"

stompbox_ce::stompbox_ce(QWidget *parent)
    : stompBox(parent)
{
	/* Chorus */
	setImage(":/images/ce.png");
	setLSB("07", "00");
	setKnob1("07", "00", "03");
	setKnob2("07", "00", "04");
	setComboBox("07", "00", "02");
	setButton("07", "00", "00");
	setEditPages();
};

void stompbox_ce::updateSignal()
{
	updateKnob1("07", "00", "03");
	updateKnob2("07", "00", "04");
	updateComboBox("07", "00", "02");
	updateButton("07", "00", "00");
};

void stompbox_ce::setEditPages()
{
    editDetails()->page()->newGroupBox("Chorus");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "02", "turbo"); //mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "03");          //rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "04", "turbo"); //depth
	editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "05");          //predelay
	editDetails()->page()->addKnob(0, 4, 1, 1, "07", "00", "06", "turbo"); //low cut
	editDetails()->page()->addKnob(0, 5, 1, 1, "07", "00", "07");          //effect level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage();  // PAGE 1 ABOVE 
	
};
