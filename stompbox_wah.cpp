/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-6 Fx FloorBoard".
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
	setButton("01", "00", "00", QPoint::QPoint(0, 109), ":/images/pedal.png");
	setComboBox("01", "00", "02");
	editDetails()->patchPos(128, 34, "01", "00");
	setEditPages();
};

void stompbox_wah::updateSignal()
{
	updateButton("01", "00", "00");
	updateComboBox("01", "00", "02");
};

void stompbox_wah::setEditPages()
{
 	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "02");	
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->insertStackField(0, 1, 0, 1, 1);
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Wah");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "03");       //wah type
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "04");           //pedal pos
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "05");           //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 1 ABOVE
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Auto Wah");
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "06");       //mode
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "07");       //polarity
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "08");           //sensitivity
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "09", "turbo");  //freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "0A");           //peak
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "0B", "normal", "right", 60); //rate
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "0C");           //depth
  editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "0D");           //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 2 ABOVE

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Footpedal Wah");
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "0E");       //type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "0F", "turbo");  //pdl pos
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "10");           //level	
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 3 ABOVE
	
	editDetails()->addPage();
};
