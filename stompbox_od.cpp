/****************************************************************************
**
** Copyright (C) 2005-2006 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-3 FX FloorBoard".
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

#include "stompbox_od.h"

stompbox_od::stompbox_od(QWidget *parent)
    : stompBox(parent)
{
	/* OD/DS */
	setImage(":/images/od.png");
	setLSB("03", "00");
	setKnob1("03", "00", "02");
	setKnob2("03", "00", "05");
	setComboBox("03", "00", "01");
	setButton("03", "00", "00");
	editDetails()->patchPos(188, 12, "03", "00");
	setEditPages();
};

void stompbox_od::updateSignal()
{
	updateKnob1("03", "00", "02");
	updateKnob2("03", "00", "05");
	updateComboBox("03", "00", "01");
	updateButton("03", "00", "00");
};

void stompbox_od::setEditPages()
{
    editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Natural O/D");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("03", "00", "01", "00");  // PAGE 1 ABOVE 

    editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Vintage O/D");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("03", "00", "01", "01");  // PAGE 2 ABOVE 

    editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Turbo O/D");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("03", "00", "01", "02");  // PAGE 3 ABOVE 

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Blues");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("03", "00", "01", "03");  // PAGE 4 ABOVE 

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Crunch");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("03", "00", "01", "04");  // PAGE 5 ABOVE 

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Distortion 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("03", "00", "01", "05");  // PAGE 6 ABOVE 

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Distortion 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("03", "00", "01", "06");  // PAGE 7 ABOVE 

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Grunge");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("03", "00", "01", "07");  // PAGE 8 ABOVE 

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Metal 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("03", "00", "01", "08");  // PAGE 9 ABOVE 

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Metal 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);

    //editDetails()->page()->newGroupBox("Custom");
	//editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "03");         //drive
	//editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "04", "turbo");//bass
	//editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "05");         //treble
	//editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "06");         //effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07");         //direct level 
	//editDetails()->page()->addGroupBox(2, 1, 1, 1);
	editDetails()->addPage("03", "00", "01", "09");  // PAGE 10 ABOVE 

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("FUZZ");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	//editDetails()->page()->newGroupBox("Custom");
	//editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "03");         //drive
	//editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "04", "turbo");//bass
	//editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "05");         //treble
	//editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "06");         //effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07");         //direct level
	//()->page()->addGroupBox(2, 1, 1, 1);
	editDetails()->addPage("03", "00", "01", "0A");   // PAGE 11 ABOVE 
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("EXT OD/DS");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05", "turbo");//effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	//editDetails()->page()->newGroupBox("Custom");
	//editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "03");         //drive
	//editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "04", "turbo");//bass
	//editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "05");         //treble
	//editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "06");         //effect level
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07");         //direct level
	//()->page()->addGroupBox(2, 1, 1, 1);
	editDetails()->addPage("03", "00", "01", "0B");   // PAGE 12 ABOVE 

	};
