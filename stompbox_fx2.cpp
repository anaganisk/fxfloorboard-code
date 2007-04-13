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
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**
****************************************************************************/

#include "stompbox_fx2.h"

stompbox_fx2::stompbox_fx2(QWidget *parent)
    : stompBox(parent)
{
	/* FX2 */
	setImage(":/images/fx2.png");
	setLSB("06", "00");
	setComboBox("06", "00", "02", QRect(8, 31, 79, 13));
	setButton("06", "00", "00");
	setEditPages();
};

void stompbox_fx2::updateSignal()
{
	updateComboBox("06", "00", "02");
	updateButton("06", "00", "00");
};

void stompbox_fx2::setEditPages()
{
    editDetails()->page()->newGroupBox("FX 2");
	editDetails()->page()->newGroupBox("Phaser");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "03", "turbo");//type
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "04");         //rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "05", "turbo");//depth
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "06");         //manual
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "07", "turbo");//resonance
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "08");         //step
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "09", "turbo");//step rate
	editDetails()->page()->addKnob(0, 7, 1, 1, "06", "00", "0A");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 8);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("06", "00", "02");  // PAGE 1 ABOVE

	editDetails()->page()->newGroupBox("FX 2");
	editDetails()->page()->newGroupBox("Flanger");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "0B", "turbo");//rate
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "0C");         //depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "0D", "turbo");//manual
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "0E");         //resonance
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "0F", "turbo");//separation
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "6E", "turbo");//low cut
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "10", "turbo");//level
	editDetails()->page()->addGroupBox(1, 0, 1, 7);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("06", "00", "02");  // PAGE 2 ABOVE

	editDetails()->page()->newGroupBox("Harmonizer");
	editDetails()->page()->newGroupBox("Harmony 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "11", "turbo");//voice
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "12");         //hr1 harmony
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "13", "turbo");//hr1 pre delay
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "15", "turbo");//hr1 feedback
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "16");         //hr1 level
	editDetails()->page()->addGroupBox(1, 0, 1, 5);
	editDetails()->page()->newGroupBox("Harmony 2");
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "17", "turbo");//hr2 harmony
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "18");         //hr2 pre delay
	editDetails()->page()->addKnob(0, 7, 1, 1, "06", "00", "1A", "turbo");//hr2 level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	editDetails()->page()->newGroupBox("main");
	editDetails()->page()->addKnob(0, 8, 1, 1, "06", "00", "1B", "turbo");//key
	editDetails()->page()->addKnob(0, 9, 1, 1, "06", "00", "1C");         //direct level
	editDetails()->page()->addGroupBox(2, 1, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("06", "00", "02");  // PAGE 3 ABOVE

	editDetails()->page()->newGroupBox("Pitch Shifter");
	editDetails()->page()->newGroupBox("Pitch 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "1D", "turbo");//voice
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "1E");         //ps1 mode
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "1F", "turbo");//ps1 pitch
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "20");         //ps1 pitch fine
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "21", "turbo");//ps1 pre delay
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "23", "turbo");//ps1 feedback
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "24");         //ps1 level
	editDetails()->page()->addGroupBox(1, 0, 1, 7);
	editDetails()->page()->newGroupBox("Pitch 2");
	editDetails()->page()->addKnob(0, 7, 1, 1, "06", "00", "25", "turbo");//ps2 mode
	editDetails()->page()->addKnob(0, 8, 1, 1, "06", "00", "26");         //ps2 pitch
	editDetails()->page()->addKnob(0, 9, 1, 1, "06", "00", "27", "turbo");//ps2 pitch fine
	editDetails()->page()->addKnob(0, 10, 1, 1, "06", "00", "28");         //ps2 pre delay
	editDetails()->page()->addKnob(0, 11, 1, 1, "06", "00", "2A", "turbo");//ps2 level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
    editDetails()->page()->newGroupBox("main");
	editDetails()->page()->addKnob(0, 12, 1, 1, "06", "00", "2B", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 1, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("06", "00", "02");  // PAGE 4 ABOVE	
	//if (hex3 == "04"){
	editDetails()->page()->newGroupBox("FX 2");
	editDetails()->page()->newGroupBox("Pitch Bend");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "2C", "turbo");//PITCH MIN
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "2D");         //pitch max
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "2E", "turbo");//pdl position   
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "2F");         //effect level
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "30", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 0, 1, 5);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("06", "00", "02"); //}; // PAGE 5 ABOVE	

	
	editDetails()->page()->newGroupBox("Chorus");
	editDetails()->page()->newGroupBox("X-over freq");
	editDetails()->page()->addGroupBox(2, 0, 1, 5);
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "31", "turbo");//x-over freq
	editDetails()->page()->newGroupBox("Low Band");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "32", "turbo");//low rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "33");         //low depth
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "34", "turbo");//low pre-delay
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "35");         //low level
	editDetails()->page()->addGroupBox(3, 0, 1, 5);
	editDetails()->page()->newGroupBox("High Band");
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "36", "turbo");//high rate
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "37");         //high depth
	editDetails()->page()->addKnob(0, 7, 1, 1, "06", "00", "38", "turbo");//high pre delay
	editDetails()->page()->addKnob(0, 8, 1, 1, "06", "00", "39");         //high level
	editDetails()->page()->addGroupBox(1, 0, 1, 5);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("06", "00", "02");  // PAGE 6 ABOVE  

	editDetails()->page()->newGroupBox("Auto Slap");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "3A", "turbo");//phrase
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "3B");         //loop
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "3C", "turbo");//tempo
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "3D");         //sensitivity
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "3F", "turbo");//effect level
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "40");         //direct level
	editDetails()->page()->addGroupBox(0, 0, 1, 6);
	editDetails()->addPage("06", "00", "02");  // PAGE 7 ABOVE
	
	editDetails()->page()->newGroupBox("Short Digital Delay");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "43", "turbo");//delay time
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "45");         //feedback
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "46", "turbo");//effect
	editDetails()->page()->addGroupBox(0, 0, 1, 3);
	editDetails()->addPage("06", "00", "02");  // PAGE 8 ABOVE

    editDetails()->page()->newGroupBox("Vibrato");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "47", "turbo");//rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "48");         //depth
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "49", "turbo");//trigger
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "4A");         //rise time
	editDetails()->page()->addGroupBox(0, 0, 1, 6);
	editDetails()->addPage("06", "00", "02");  // PAGE 9 ABOVE

    editDetails()->page()->newGroupBox("FX 2");
	editDetails()->page()->newGroupBox("Humanizer");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "4B", "turbo");//mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "4C");         //vowel 1
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "4D", "turbo");//vowel 2
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "4E");         //trigger
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "4F", "turbo");//sensitivity
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "50");         //rate
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "51", "turbo");//depth
	editDetails()->page()->addKnob(0, 7, 1, 1, "06", "00", "52");         //manual
	editDetails()->page()->addKnob(0, 8, 1, 1, "06", "00", "53", "turbo");//level
	editDetails()->page()->addGroupBox(1, 0, 1, 9);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("06", "00", "02");  // PAGE 10 ABOVE

	 editDetails()->page()->newGroupBox("Tremolo/Pan");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "54", "turbo");//mode
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "55");         //wave shape
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "56", "turbo");//rate
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "57");         //depth
	editDetails()->page()->addGroupBox(0, 0, 1, 6);
	editDetails()->addPage("06", "00", "02");  // PAGE 11 ABOVE

     editDetails()->page()->newGroupBox("Bass Synth");
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "58", "turbo");//wave
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "59");         //octave
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "5A", "turbo");//pwm rate
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "5B");         //pwm depth
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "5C", "turbo");//noise level
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "5D");         //sensitivity
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "5E", "turbo");//hold
	editDetails()->page()->addKnob(0, 7, 1, 1, "06", "00", "5F");         //attack trigger
	editDetails()->page()->addKnob(0, 8, 1, 1, "06", "00", "60", "turbo");//resonance
	editDetails()->page()->addGroupBox(1, 0, 1, 9);
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "61", "turbo");//cutoff freq
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "62");         //depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "63", "turbo");//decay
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "64");         //synth level
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "65", "turbo");//direct level
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "66");         //bend
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "67", "turbo");//pitch min
	editDetails()->page()->addKnob(0, 7, 1, 1, "06", "00", "68");         //pitch max
	editDetails()->page()->addKnob(0, 8, 1, 1, "06", "00", "69", "turbo");//pedal position
	editDetails()->page()->addGroupBox(2, 0, 1, 9);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("06", "00", "02");  // PAGE 12 ABOVE
};
