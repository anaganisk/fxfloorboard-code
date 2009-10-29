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

#include "stompbox_pre.h"

stompbox_pre::stompbox_pre(QWidget *parent)
    : stompBox(parent)
{
	/* PRE  */
	setImage(":/images/pre.png");
	setLSB("04", "00");
	setKnob1("04", "00", "02");
	setKnob2("04", "00", "07");
	setComboBox("04", "00", "01");
	setButton("04", "00", "00");
  editDetails()->patchPos(224, 26, "04", "00"); 
	setEditPages();
};

void stompbox_pre::updateSignal()
{
  updateKnob1("04", "00", "02");
	updateKnob2("04", "00", "07");
	updateComboBox("04", "00", "01");
	updateButton("04", "00", "00");
};

void stompbox_pre::setEditPages()
{
    //editDetails()->page()->newGroupBox("Pre Amplifier");

  editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("JC-120");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	
	editDetails()->addPage("04", "00", "01", "00");
	  // PAGE 1 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Clean Twin");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "01");
	  // PAGE 2 ABOVE  

	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Crunch");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "02");
	  // PAGE 3 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("MATCH Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "03");
	  // PAGE 4 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("VOXY Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "04");
	  // PAGE 5 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Blues");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "05");
	  // PAGE 6 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("BG Lead");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "06");
	  // PAGE 7 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("MS1959(1)");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "07");
	  // PAGE 8 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("MS1959(2)");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "08");
	  // PAGE 9 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("MS1959(1+2)");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "09");
	  // PAGE 10 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("SLDN Lead");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "0A");
	  // PAGE 11 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Metal 5150");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "0B");
	  // PAGE 12 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Metal Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "0C");
	  // PAGE 13 ABOVE
	  
	editDetails()->page()->newGroupBox("Pre-Amp Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("AC. Guitar");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "02", "turbo");//volume
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "03");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "04");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "06");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "04", "00", "08", "middle", Qt::AlignCenter);       //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "04", "00", "09");     //gain
	
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0B", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0C", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("04", "00", "01", "0D");
	  // PAGE 14 ABOVE
	  
	  
	
};
