/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-5 Fx FloorBoard".
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
        setKnob1("01", "00", "0A");
        setKnob2("01", "00", "0D");
        setComboBox("01", "00", "09");
        setButton("00", "00", "00");
        editDetails()->patchPos(55, 9, "01", "00");
	setEditPages();
};

void stompbox_cs::updateSignal()
{
        updateKnob1("01", "00", "0A");
        updateKnob2("01", "00", "0D");
        updateComboBox("01", "00", "09");
        updateButton("00", "00", "00");
};

void stompbox_cs::setEditPages()
{
        editDetails()->page()->newGroupBox("Effect");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
        editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "09");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);

        editDetails()->page()->newStackField(0);
        editDetails()->page()->newGroupBox("Compressor");
        editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "0A", "turbo");// sustain
        editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "0B");         //attack
        editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "0C", "turbo");// tone
        editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "0D");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 1 ABOVE

	editDetails()->page()->newStackField(0);
        editDetails()->page()->newGroupBox("Limiter");
        editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "0E", "turbo");//threshold
        editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "0F");         //release
        editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "10", "turbo");//tone
        editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "11");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 2 ABOVE

        editDetails()->addPage();
};
