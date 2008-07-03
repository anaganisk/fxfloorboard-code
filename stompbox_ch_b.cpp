/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
** Copyright (C) 2008 Colin Willcocks. All rights reserved.
** This file is part of "GT-10B Fx FloorBoard".
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
	//setSwitch("01", "00", "00");
	//setKnob1("01", "00", "31");
	//setKnob2("01", "00", "36");
	//setComboBox("01", "00", "30");
	//setButton("01", "00", "00");
	setEditPages();
};

void stompbox_ch_b::updateSignal()
{
	//updateSwitch("01", "00", "00");
	//updateKnob1("01", "00", "31");
	//updateKnob2("01", "00", "36");
//	updateComboBox("01", "00", "30");
	//updateButton("01", "00", "00");
};

void stompbox_ch_b::setEditPages()
{/*
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00");   // off/on effect

	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "02"); // channel select
	editDetails()->page()->addStackControl();

	//editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(2, 0, 1, 1, "01", "00", "01");   //mode
	//editDetails()->page()->addStackControl();
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
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "10");  //pre type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "18", "bottom", Qt::AlignLeft); //gain sw
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "11", "turbo"); // gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "12");            //bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "13");            // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "14");           // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "15");            // presence
	editDetails()->page()->insertStackField(2, 0, 1, 1, 1);                  // bright button
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "16");     // effect level
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");    // direct level
	editDetails()->page()->addGroupBox(0, 1, 1, 1);  

	editDetails()->page()->newGroupBox("Speaker");
	//editDetails()->page()->newStackControl(4);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "1B");
	//editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "1C", "bottom", Qt::AlignRight);
	editDetails()->page()->addComboBox(1, 0, 1, 2, "01", "00", "1D");
	editDetails()->page()->addKnob(0, 2, 2, 1, "01", "00", "1E");
	editDetails()->page()->addKnob(0, 3, 2, 1, "01", "00", "1F");
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "19", "middle", Qt::AlignLeft | Qt::AlignTop);
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "1A");
	editDetails()->page()->addGroupBox(2, 1, 1, 1);	
	
	
	editDetails()->page()->newGroupBox("Custom PreAmp");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "21");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "22");
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "23");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "24");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "25");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "26");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "27");
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	
	
	//editDetails()->page()->insertStackField(4, 0, 3, 3, 1);
	editDetails()->page()->newGroupBox("Custom Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "29");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "2A");
	editDetails()->page()->addKnob(1, 0, 1, 2, "01", "00", "28");
	editDetails()->page()->addComboBox(2, 0, 1, 1, "01", "00", "2B", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addComboBox(3, 1, 1, 1, "01", "00", "2C", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(0, 3, 3, 1);
	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	editDetails()->page()->addStackField();
	
	
	// CHANNEL B 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Channel B");

	editDetails()->page()->newGroupBox("Pre Amp");
	editDetails()->page()->newStackControl(3);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "30");  // pre type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "38", "bottom", Qt::AlignLeft); // gain sw	
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "31", "turbo");  //gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "32");            // bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "33");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "34");           // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "35");           //presence
	editDetails()->page()->insertStackField(3, 0, 1, 1, 1);                 // bright switch
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "36");  //effect level
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "40");   // direct level
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Custom PreAmp");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "41");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "42");
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "43");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "44");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "45");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "46");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "47");
	editDetails()->page()->addGroupBox(1, 0, 1, 2);

	editDetails()->page()->newGroupBox("Speaker");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "3B");
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "3C", "bottom", Qt::AlignRight);
	editDetails()->page()->addComboBox(1, 0, 1, 2, "01", "00", "3D");
	editDetails()->page()->addKnob(0, 2, 2, 1, "01", "00", "3E");
	editDetails()->page()->addKnob(0, 3, 2, 1, "01", "00", "3F");
	editDetails()->page()->addGroupBox(2, 0, 1, 1);

	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "39", "middle", Qt::AlignLeft | Qt::AlignTop);
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "3A");
	editDetails()->page()->addGroupBox(2, 1, 1, 1);
	
  editDetails()->page()->newGroupBox("Custom Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "49");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "4A");
	editDetails()->page()->addKnob(1, 0, 1, 2, "01", "00", "48");
	editDetails()->page()->addComboBox(2, 0, 1, 1, "01", "00", "4B", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addComboBox(3, 1, 1, 1, "01", "00", "4C", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(0, 3, 3, 1);

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
	*/
	
	/*editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Custom PreAmp");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "41");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "42");
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "43");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "44");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "45");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "46");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "47");
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	
	*/
  /*
  editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Custom Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "29");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "2A");
	editDetails()->page()->addKnob(1, 0, 1, 2, "01", "00", "28");
	editDetails()->page()->addComboBox(2, 0, 1, 1, "01", "00", "2B");
	editDetails()->page()->addComboBox(2, 1, 1, 1, "01", "00", "2C");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);
  
  editDetails()->page()->addStackField();	
 */

	editDetails()->addPage();	
};
