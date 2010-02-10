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

#include "stompbox_pre.h"

stompbox_pre::stompbox_pre(QWidget *parent)
    : stompBox(parent)
{
	/* PRE  */
	setImage(":/images/pre.png");
        setLSB("01", "00");
	setKnob1("01", "00", "2B");
	setKnob2("01", "00", "24");
	setComboBox("01", "00", "23");
        setButton("00", "00", "00");
        editDetails()->patchPos(81, 9, "01", "00");
	setEditPages();
};

void stompbox_pre::updateSignal()
{
        updateKnob1("01", "00", "2B");
	updateKnob2("01", "00", "24");
	updateComboBox("01", "00", "23");
        updateButton("00", "00", "00");
};

void stompbox_pre::setEditPages()
{
        editDetails()->page()->newGroupBox("Pre-Amp Effect");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "23");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	
	 editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("JC-120");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 1 ABOVE
	  
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Clean Twin");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField(); // PAGE 2 ABOVE  

	editDetails()->page()->newStackField(0);	
	editDetails()->page()->newGroupBox("Crunch");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain	
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField(); // PAGE 3 ABOVE
	  
	editDetails()->page()->newStackField(0);	
	editDetails()->page()->newGroupBox("MATCH Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain	
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField(); // PAGE 4 ABOVE
	  
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("VOXY Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 5 ABOVE
	  
	editDetails()->page()->newStackField(0);	
	editDetails()->page()->newGroupBox("Blues");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain	
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField(); // PAGE 6 ABOVE
	  
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("BG Lead");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 7 ABOVE
	  
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("MS1959(1)");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
        editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 8 ABOVE
	  
  editDetails()->page()->newStackField(0);	
	editDetails()->page()->newGroupBox("MS1959(2)");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField(); // PAGE 9 ABOVE
	  
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("MS1959(1+2)");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain	
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField(); // PAGE 10 ABOVE
	  
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("SLDN Lead");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField(); // PAGE 11 ABOVE
	  
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Metal 5150");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 12 ABOVE
	  
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Metal Lead");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField(); // PAGE 13 ABOVE
	  
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Custom PreAmp 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 14 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Custom PreAmp 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "24", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "25");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "26");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "27");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "28");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "29", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "01", "00", "2A", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "01", "00", "2B");     //gain
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 15 ABOVE
          
	editDetails()->addPage();		
};
