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

#include "stompbox_fx1.h"

stompbox_fx1::stompbox_fx1(QWidget *parent)
    : stompBox(parent)
{
	/* FX1 */
	setImage(":/images/fx1.png");
        setLSB("01", "00");
        setComboBox("01", "00", "00", QRect(8, 31, 79, 13));
        setButton("00", "00", "00");
        editDetails()->patchPos(46, 9, "01", "00");
	setEditPages();
};

void stompbox_fx1::updateSignal()
{
        updateComboBox("01", "00", "00");
        updateButton("00", "00", "00");
};

void stompbox_fx1::setEditPages()
{
	
        editDetails()->page()->newGroupBox("Effect");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
        editDetails()->page()->newStackControl(0);
        editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "00");
        editDetails()->page()->addStackControl();
        editDetails()->page()->addGroupBox(0, 0, 1, 1);
        editDetails()->page()->insertStackField(0, 1, 0, 1, 1);
	

        editDetails()->page()->newStackField(0);
        editDetails()->page()->newGroupBox("FeedBacker");
        editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "01");      //fb rise time
        editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "02");      //fb rise time fine
        editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "03", "turbo"); //fb f.b.level
        editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "04", "turbo"); //fb f.b. level fine
        editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "05");      //fb vibe rate
        editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "06");      //fb vibe depth
        editDetails()->page()->addGroupBox(1, 0, 1, 1);
        editDetails()->page()->addStackField();


        editDetails()->page()->newStackField(0);
        editDetails()->page()->newGroupBox("Slow Gear");
        editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "07");
        editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "08");
        editDetails()->page()->addGroupBox(1, 0, 1, 1);
        editDetails()->page()->addStackField();  // PAGE 2 ABOVE

        editDetails()->addPage();
};

