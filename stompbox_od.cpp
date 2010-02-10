/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-5 Fx FloorBoard".
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
        setLSB("01", "00");
        setKnob1("01", "00", "1F");
        setKnob2("01", "00", "22");
        setComboBox("01", "00", "1E");
        setButton("00", "00", "00");
        editDetails()->patchPos(76, 5, "01", "00");
        setEditPages();
};

void stompbox_od::updateSignal()
{
      	updateKnob1("01", "00", "1F");
        updateKnob2("01", "00", "22");
        updateComboBox("01", "00", "1E");
        updateButton("00", "00", "00");
};

void stompbox_od::setEditPages()
{
        editDetails()->page()->newGroupBox("Effect");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "1E");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->insertStackField(0, 1, 0, 1, 1);
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Natural O/D");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField(); // PAGE 1 ABOVE 

        editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Vintage O/D");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 2 ABOVE 

  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Turbo O/D");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 3 ABOVE 

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Blues");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 4 ABOVE 

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Crunch");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 5 ABOVE 

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Distortion 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 6 ABOVE 

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Distortion 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 7 ABOVE 

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Grunge");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 8 ABOVE 

	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Metal 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 9 ABOVE 

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Metal 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 10 ABOVE 

  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("FUZZ");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();   // PAGE 11 ABOVE 
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Custom 1 OD/DS");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();    // PAGE 12 ABOVE 
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Custom 2 OD/DS");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1F", "turbo");         //drive
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Tone");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "20");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "21");         //treble
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "22", "turbo");//effect level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();    // PAGE 13 ABOVE 
        
	editDetails()->addPage();  
};
