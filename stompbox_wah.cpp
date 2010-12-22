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

#include "stompbox_wah.h"

stompbox_wah::stompbox_wah(QWidget *parent)
    : stompBox(parent)
{
	/* WAH */
	setImage(":/images/wah.png");
        setLSB("01", "00");
        setButton("00", "00", "00", QPoint(0, 109), ":/images/pedal.png");
        setComboBox("01", "00", "12");
        editDetails()->patchPos(64, 11, "01", "00");
	setEditPages();
};

void stompbox_wah::updateSignal()
{
        updateButton("00", "00", "00");
        updateComboBox("01", "00", "12");
};

void stompbox_wah::setEditPages()
{
        editDetails()->page()->newGroupBox("Effect");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
        editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "12");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->insertStackField(0, 1, 0, 1, 1);
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pedal Wah");
        editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "13");           //pedal pos
        editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "14");           //level
	editDetails()->page()->addGroupBox(1, 0, 1, 3);
	editDetails()->page()->addStackField();   // PAGE 1 ABOVE

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Auto Wah");
        editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "15");       //mode
        editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "16");       //polarity
        editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "17");           //sensitivity
        editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "18", "turbo");  //freq
        editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "19");           //peak
        editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "1A");           //rate
        editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "1B");           //depth
        editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "1C");           //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();   // PAGE 2 ABOVE

	editDetails()->addPage();	
};
