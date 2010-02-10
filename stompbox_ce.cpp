/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-3 Fx FloorBoard".
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
	setLSB("02", "00");
	setKnob1("02", "00", "1A");
	setKnob2("02", "00", "1B");
	setComboBox("02", "00", "19");
        setButton("00", "00", "00");
	editDetails()->patchPos(211, 6, "02", "00");
	setEditPages();
};

void stompbox_ce::updateSignal()
{
	updateKnob1("02", "00", "1A");
	updateKnob2("02", "00", "1B");
	updateComboBox("02", "00", "19");
        updateButton("00", "00", "00");
};

void stompbox_ce::setEditPages()
{
        editDetails()->page()->newGroupBox("Effect");
        editDetails()->page()->addSwitch(0, 0, 2, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addComboBox(0, 1, 2, 1, "02", "00", "19");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

        editDetails()->page()->newGroupBox("Chorus");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "1A", "normal","right", 105);          //rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "1B", "turbo"); //depth
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "1C");          //predelay
        editDetails()->page()->addGroupBox(1, 1, 1, 1);

        editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 4, 1, 1, "02", "00", "1D", "turbo"); //high cut
	editDetails()->page()->addGroupBox(1, 2, 1, 1);

        editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 5, 1, 1, "02", "00", "1E");          //effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage();  // PAGE 1 ABOVE 
	
};
