/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag.
** All rights reserved.
**
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

#include "stompbox_ch_a.h"

stompbox_ch_a::stompbox_ch_a(QWidget *parent)
    : stompBox(parent)
{
	/* CHANNEL_A */
	setImage(":/images/ch_a.png");
	setLSB("01", "00");
	setSwitch("01", "00", "00");
	setEditPages();
};

void stompbox_ch_a::updateSignal()
{
	updateSwitch("01", "00", "00");
};

void stompbox_pre::setEditPages()
{
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00");   // off/on effect

	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "01"); // channel select
	editDetails()->page()->addStackControl();

	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(2, 0, 1, 1, "01", "00", "02");   //mode
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	// TYPE SETTINGS 
	editDetails()->page()->insertStackField(1, 1, 0, 1, 1);

	editDetails()->page()->newStackField(1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(1, Qt::AlignCenter);
	editDetails()->page()->newGroupBox("Ch.Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "03");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(1, Qt::AlignCenter);
	editDetails()->page()->newGroupBox("Ch.Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "03");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(1, Qt::AlignCenter);
	editDetails()->page()->newGroupBox("Dynamic");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "04");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	// CHANNEL A 
	editDetails()->page()->insertStackField(0, 0, 1, 2, 1);
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Channel A");

	editDetails()->page()->newGroupBox("Pre Amp");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 5, "01", "00", "10");  //pre type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "00", "18", "bottom", Qt::AlignHCenter); //gain sw
	
	editDetails()->page()->addKnob(2, 0, 1, 1, "01", "00", "11", "turbo"); // gain
	editDetails()->page()->addKnob(2, 1, 1, 1, "01", "00", "12");            //bass
	editDetails()->page()->addKnob(2, 2, 1, 1, "01", "00", "13");            // mid
	editDetails()->page()->addKnob(2, 3, 1, 1, "01", "00", "14");           // treble
	editDetails()->page()->addKnob(2, 4, 1, 1, "01", "00", "15");            // presence

	editDetails()->page()->insertStackField(2, 2, 5, 1, 1);                  // bright button

	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "16");     // effect level
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");    // direct level
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Speaker");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "1B");
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "1C", "bottom", Qt::AlignRight);
	editDetails()->page()->addComboBox(1, 0, 1, 2, "01", "00", "1D");
	editDetails()->page()->addKnob(0, 2, 2, 1, "01", "00", "1E");
	editDetails()->page()->addKnob(0, 3, 2, 1, "01", "00", "1F");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "19", "middle", Qt::AlignLeft | Qt::AlignTop);
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "1A");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	// CHANNEL B 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Channel B");

	editDetails()->page()->newGroupBox("Pre Amp");
	editDetails()->page()->newStackControl(3);
	editDetails()->page()->addComboBox(0, 0, 1, 5, "01", "00", "30");  // pre type
	editDetails()->page()->addStackControl();

	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "00", "38", "bottom", Qt::AlignHCenter); // gain sw
	
	editDetails()->page()->addKnob(2, 0, 1, 1, "01", "00", "31", "turbo");  //gain
	editDetails()->page()->addKnob(2, 1, 1, 1, "01", "00", "32");            // bass
	editDetails()->page()->addKnob(2, 2, 1, 1, "01", "00", "33");           // mid
	editDetails()->page()->addKnob(2, 3, 1, 1, "01", "00", "34");           // treble
	editDetails()->page()->addKnob(2, 4, 1, 1, "01", "00", "35");           //presence

	editDetails()->page()->insertStackField(3, 2, 5, 1, 1);

	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "36");  //effect level
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "40");   // direct level
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Speaker");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "3B");
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "3C", "bottom", Qt::AlignRight);
	editDetails()->page()->addComboBox(1, 0, 1, 2, "01", "00", "3D");
	editDetails()->page()->addKnob(0, 2, 2, 1, "01", "00", "3E");
	editDetails()->page()->addKnob(0, 3, 2, 1, "01", "00", "3F");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "39", "middle", Qt::AlignLeft | Qt::AlignTop);
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "3A");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();

	editDetails()->addPage();	
};
