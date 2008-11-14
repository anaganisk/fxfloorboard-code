/****************************************************************************
**
** Copyright (C) 2008 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
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

void stompbox_ch_a::setEditPages()
{
	// CHANNEL A 
	
	editDetails()->page()->newGroupBox("Channel A");

	editDetails()->page()->newGroupBox("Pre Amp");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "10");        //pre type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "18", "bottom", Qt::AlignLeft); //gain sw
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "11", "turbo");   // gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "12");            //bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "13");            // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "14");            // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "15");            // presence
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);                // bright button
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "16");            // effect level
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");            // direct level
	editDetails()->page()->addGroupBox(0, 1, 1, 1);  

	editDetails()->page()->newGroupBox("Speaker");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "1B");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "1C", "bottom", Qt::AlignRight);
	editDetails()->page()->addComboBox(1, 0, 1, 2, "01", "00", "1D");
	editDetails()->page()->addKnob(0, 2, 2, 1, "01", "00", "1E");
	editDetails()->page()->addKnob(0, 3, 2, 1, "01", "00", "1F");
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "19", "middle", Qt::AlignLeft | Qt::AlignTop);
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "1A");
	editDetails()->page()->addGroupBox(2, 1, 1, 1);	
	
	editDetails()->page()->insertStackField(1, 0, 3, 3, 1);
	
	editDetails()->page()->newGroupBox("Custom PreAmp");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "21");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "22");
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "23");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "24");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "25");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "26");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "27");
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	
	

	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "17", "middle", Qt::AlignCenter);
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
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "29");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "2A");
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "00", "28");
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "00", "2B", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addComboBox(4, 1, 1, 1, "01", "00", "2C", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(0, 3, 3, 1);
  editDetails()->page()->addStackField();

	editDetails()->addPage();	
};
