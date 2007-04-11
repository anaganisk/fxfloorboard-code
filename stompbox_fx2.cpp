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
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage();  // PAGE 1 ABOVE

	editDetails()->page()->newGroupBox("FX 2");
	editDetails()->page()->newGroupBox("Flanger");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "0B", "turbo");//rate
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "0C");         //depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "0D", "turbo");//manual
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "0E");         //resonance
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "0F", "turbo");//separation
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "10", "turbo");//level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage();  // PAGE 2 ABOVE

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
	editDetails()->addPage();  // PAGE 3 ABOVE

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
	editDetails()->addPage();  // PAGE 4 ABOVE	
	//if (hex3 == "04"){
	editDetails()->page()->newGroupBox("FX 2");
	editDetails()->page()->newGroupBox("Pitch Bend");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "2C", "turbo");//PITCH MIN
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "2D");         //pitch max
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "2E", "turbo");//pdl position    // <-------------- hey Uco !!   this one here 
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "2F");         //effect level
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "30", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 0, 1, 5);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage(); //}; // PAGE 5 ABOVE	

	/*editDetails()->page()->newGroupBox("Pre Amplifier");
	editDetails()->page()->newGroupBox("Concert 810");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "08", "turbo");//gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "0E", "turbo");//ultra low
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "0D");         //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "0B", "turbo");//mid
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "0C");         //mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "09", "turbo");//treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "06", "00", "05");         //response
	editDetails()->page()->addKnob(0, 7, 1, 1, "06", "00", "03", "turbo");//bright
	editDetails()->page()->addKnob(0, 8, 1, 1, "06", "00", "0A");         //ultra high
	editDetails()->page()->addKnob(0, 9, 1, 1, "06", "00", "0F");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage();  // PAGE 6 ABOVE  */
	
};
