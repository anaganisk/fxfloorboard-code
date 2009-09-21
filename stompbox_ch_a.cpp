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

#include "stompbox_ch_a.h"

stompbox_ch_a::stompbox_ch_a(QWidget *parent)
    : stompBox(parent)
{
	/* CHANNEL_A */
	setImage(":/images/ch_a.png");
	setLSB("01", "00");
	
	setKnob1("01", "00", "52");
	setKnob2("01", "00", "56");
	setComboBox("01", "00", "51");
	setButton("01", "00", "50");
	editDetails()->patchPos(464, 66, "01", "50");    // sysx file offset and data length of chorus parameters x2,
                                                  // and hex1 & hex3 address start point. 
	setEditPages();
};

void stompbox_ch_a::updateSignal()
{
	
	updateKnob1("01", "00", "52");
	updateKnob2("01", "00", "56");
	updateComboBox("01", "00", "51");
	updateButton("01", "00", "50");
};

void stompbox_ch_a::setEditPages()
{
	editDetails()->page()->newGroupBox("Effect");
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "50", "middle", Qt::AlignCenter);   // off/on effect
  editDetails()->page()->newStackControl(0);
  editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "51");       // Type select
  editDetails()->page()->addStackControl();
  editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  
  editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
  
	editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Super Flat");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "63");           // GTR presence
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "5F");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	  // PAGE 1 ABOVE
	  
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Flip Top");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "00", "58");       // Mid freq
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "00", "5B");       // Response sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "00", "57", "middle", Qt::AlignCenter);         // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");           // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "5F");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 2 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("B-Man");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "00", "58");       // Mid freq
  editDetails()->page()->addSwitch(0, 1, 1, 1, "01", "00", "5C", "middle", Qt::AlignCenter);         // Deep
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "5F");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 3 ABOVE
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Concert 810");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addComboBox(1, 2, 1, 1, "01", "00", "58");       // Mid freq
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "00", "57", "middle", Qt::AlignCenter);         // Bright sw
	editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "00", "59");       // Ultra Low
	editDetails()->page()->addSwitch(1, 3, 1, 1, "01", "00", "5A", "middle", Qt::AlignCenter);         // Ultra Hi
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "5F");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 4 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Bass 360");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addSwitch(0, 4, 1, 1, "01", "00", "57", "middle", Qt::AlignCenter);         // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "5F");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 5 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("T.E.");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "5D");       // pre shape
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "00", "58");       // Mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "5F");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 6 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Session");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "00", "58");       // Mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "5E");           // Enhancer
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "5F");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 7 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("AC Bass");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "63");           // GTR presence
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "5F");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 8 ABOVE
	
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Clean");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "63");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "64");       // gain sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "00", "57", "middle", Qt::AlignCenter);       // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "00", "65", "middle", Qt::AlignCenter);         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "66");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "67");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "00", "69");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "00", "68");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 9 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Crunch");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "63");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "64");       // gain sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "00", "57", "middle", Qt::AlignCenter);       // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "00", "65", "middle", Qt::AlignCenter);         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "66");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "67");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "00", "69");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "00", "68");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 10 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "63");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "64");       // gain sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "00", "65", "middle", Qt::AlignCenter);         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "66");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "67");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "00", "69");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "00", "68");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 11 ABOVE
	
	editDetails()->page()->newStackField(0);	
	editDetails()->page()->newGroupBox("GTR Metal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "52", "turbo");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "53");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "54");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "55");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "63");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "64");       // gain sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "00", "65", "middle", Qt::AlignCenter);         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "66");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "56");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "67");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "00", "69");       // mic type
	editDetails()->page()->addComboBox(0, 4, 1, 2, "01", "00", "68");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "60");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "61");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "6A");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "00", "62");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 12 ABOVE
	
  editDetails()->addPage();
 	
};
