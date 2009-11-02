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
** 51 Franklin Street, Fifth Floor, Boston, MA 0210C-1301 USA.
**
****************************************************************************/

#include "stompbox_fx1.h"

stompbox_fx1::stompbox_fx1(QWidget *parent)
    : stompBox(parent)
{
	/* FX1 */
	setImage(":/images/fx1.png");
	setLSB("00", "00");
	setComboBox("00", "00", "02", QRect(8, 31, 79, 13));
	setButton("00", "00", "00");
	editDetails()->patchPos(20, 84, "00", "00");
	setEditPages();
};

void stompbox_fx1::updateSignal()
{
	updateComboBox("00", "00", "02");
	updateButton("00", "00", "00");
};

void stompbox_fx1::setEditPages()
{
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Compressor");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "03", "turbo");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "04", "turbo");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "05", "turbo");
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "06", "turbo");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "02", "00");
	  // PAGE 1 ABOVE

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Limiter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "07");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "08");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "09");
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "0A");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "02", "01");  // PAGE 2 ABOVE

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Acoustic Simulator");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "0B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "0C");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "0D");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "02", "02");  // PAGE 3 ABOVE

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Pickup Simulator");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "0E");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "0F");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "10", "turbo");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "02", "03");  // PAGE 4 ABOVE

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Tremolo");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "11");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "12", "normal", "right", 60);
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "13");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "02", "04");// PAGE 5 ABOVE
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Slow gear");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "14");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "15");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "02", "05");// PAGE 6 ABOVE
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "16");      //mode
	editDetails()->page()->addStackControl();	
	editDetails()->page()->insertStackField(0, 1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Feedbacker");	
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "17");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "18");
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "19");
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "1A");
	editDetails()->page()->addKnob(0, 5, 1, 1, "00", "00", "1B");
	editDetails()->page()->addKnob(0, 6, 1, 1, "00", "00", "1C");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Feedbacker");	
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "19");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	
	editDetails()->addPage("00", "00", "02", "06");  // PAGE 7 ABOVE
	
		editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Anti-Feedback");
  editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "1D");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "1E");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "1F");
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "20");
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "21");
	editDetails()->page()->addKnob(0, 5, 1, 1, "00", "00", "22");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "02", "07");  // PAGE 8 ABOVE
	
		editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "02");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("De-fretter");
  editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "23");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "24");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "25");
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "26");
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "27");
	editDetails()->page()->addKnob(0, 5, 1, 1, "00", "00", "28");
	editDetails()->page()->addKnob(0, 6, 1, 1, "00", "00", "29");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "02", "08");  // PAGE 9 ABOVE

	



	
};
