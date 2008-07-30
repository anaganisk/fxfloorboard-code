/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
** Copyright (C) 2008 Colin Willcocks. All rights reserved.
** This file is part of "GT-10 Fx FloorBoard".
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

#include "stompbox_ch_b.h"

stompbox_ch_b::stompbox_ch_b(QWidget *parent)
    : stompBox(parent)
{
	/* PRE */
	setImage(":/images/ch_b.png");
	setLSB("01", "00");
	setSwitch("01", "00", "00");
	setEditPages();
};

void stompbox_ch_b::updateSignal()
{
	updateSwitch("01", "00", "00");
};

void stompbox_ch_b::setEditPages()
{
	//editDetails()->page()->newGroupBox("Effect");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00");   // off/on effect
	//editDetails()->page()->addGroupBox(0, 0, 1, 1);

	
	// CHANNEL B 
	
	editDetails()->page()->newGroupBox("Channel B");

	editDetails()->page()->newGroupBox("Pre Amp");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "30");  // pre type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "38", "bottom", Qt::AlignLeft); // gain sw	
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "31", "turbo");  //gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "32");            // bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "33");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "34");           // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "35");           //presence
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);                 // bright switch
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "36");  //effect level
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "40");   // direct level
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Speaker");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "3B");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "3C", "bottom", Qt::AlignRight);
	editDetails()->page()->addComboBox(1, 0, 1, 2, "01", "00", "3D");
	editDetails()->page()->addKnob(0, 2, 2, 1, "01", "00", "3E");
	editDetails()->page()->addKnob(0, 3, 2, 1, "01", "00", "3F");
	editDetails()->page()->addGroupBox(2, 0, 1, 1);

	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "39", "middle", Qt::AlignLeft | Qt::AlignTop);
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "3A");
	editDetails()->page()->addGroupBox(2, 1, 1, 1);
	
  editDetails()->page()->insertStackField(1, 0, 3, 3, 1);
  
  editDetails()->page()->newGroupBox("Custom PreAmp");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "41");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "42");
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "43");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "44");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "45");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "46");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "47");
	editDetails()->page()->addGroupBox(1, 0, 1, 2);

	editDetails()->page()->addGroupBox(0, 0, 1, 1);



	

	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Custom Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "49");
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "4A");
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "00", "48");
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "00", "4B", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "00", "4C", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(0, 3, 3, 1);
  editDetails()->page()->addStackField();


	editDetails()->addPage();	
};
