/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag.
** All rights reserved.
**
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

#include "stompbox_cs.h"

stompbox_cs::stompbox_cs(QWidget *parent)
    : stompBox(parent)
{
	/* COMP */
	setImage(":/images/cs.png");
	setLSB("00", "00");
	setKnob1("00", "00", "54");
	setKnob2("00", "00", "53");
	setComboBox("00", "00", "51");
	setButton("00", "00", "50");
	editDetails()->patchPos(182, 36, "00", "50");    // sysx file offset and data length of chorus parameters x2,
	setEditPages();
};

void stompbox_cs::updateSignal()
{
	updateKnob1("00", "00", "54");
	updateKnob2("00", "00", "53");
	updateComboBox("00", "00", "51");
	updateButton("00", "00", "50");
};

void stompbox_cs::setEditPages()
{
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "50", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "51");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	// BOSS Comp
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	editDetails()->page()->newStackField(0);
				
	editDetails()->page()->newGroupBox("Compressor");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "54"); //sustain
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "55"); //attack
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "52");  // tone
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "53");  // level
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(2, 0, 2, 2);
	editDetails()->page()->addStackField();
	
	// D-Comp
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Compressor");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "54"); //sustain
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "55"); //attack
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "52");  // tone
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "53");  // level
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(2, 0, 2, 2);
	editDetails()->page()->addStackField();

	// BOSS Limiter 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Limiter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "58");  // attack
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "56");   // thresh
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "57");  // ratio
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "59");   // release
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "52");  // tone
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "53");  // level
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(2, 0, 2, 2);
	editDetails()->page()->addStackField();
	
	// Rack 160D 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Limiter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "58");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "56");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "57");
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "59");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "52");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "53");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(2, 0, 2, 2);
	editDetails()->page()->addStackField();
	
	//  Vtg Rack U
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Limiter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "58");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "56");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "57");
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "59");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "52");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "53");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(2, 0, 2, 2);
	editDetails()->page()->addStackField();
	
	// Multi Band 
	editDetails()->page()->newStackField(0);
	
	editDetails()->page()->newGroupBox("Multi Band");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "5E");
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "5F");
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "60");
	editDetails()->page()->addKnob(1, 1, 1, 1, "00", "00", "5B");
	editDetails()->page()->addKnob(2, 1, 1, 1, "00", "00", "5A");
	editDetails()->page()->addKnob(1, 3, 1, 1, "00", "00", "5D");
	editDetails()->page()->addKnob(2, 3, 1, 1, "00", "00", "5C");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "52");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "53");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();
	
	// Natural 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Compressor");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "61");  // drive
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "52");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "53");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(2, 0, 2, 2);
	editDetails()->page()->addStackField();

	editDetails()->addPage();                                               // and hex1 & hex3 address start point.
};
