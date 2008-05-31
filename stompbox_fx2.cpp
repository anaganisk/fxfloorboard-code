/****************************************************************************
**
** Copyright (C) 2005-2006 Uco Mesdag. All rights reserved.
** Copyright (C) 2005-2006-2007 Colin Willcocks. All rights reserved.
**
** This file is part of "GT6 FX FloorBoard".
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
	setLSB("05", "00");
//#ifdef Q_OS_MAC
//	setComboBox("05", "00", "02", QRect(4, 31, 88, 20));
//#else
	setComboBox("05", "00", "02", QRect(8, 31, 79, 13));
//#endif
	setButton("05", "00", "00");
	setEditPages();
};

void stompbox_fx2::updateSignal()
{
	updateComboBox("05", "00", "02");
	updateButton("05", "00", "00");
};

void stompbox_fx2::setEditPages()
{
    editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 8);
	editDetails()->page()->newGroupBox("Phaser");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "03");     //type
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "04");         //rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "05", "turbo");//depth
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "06");         //manual
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "07", "turbo");//resonance
	editDetails()->page()->addComboBox(0, 5, 1, 1, "05", "00", "08");     //step
	editDetails()->page()->addKnob(0, 6, 1, 1, "05", "00", "09", "normal", "right", 60);//step rate
	editDetails()->page()->addKnob(0, 7, 1, 1, "05", "00", "0A");         //level
	editDetails()->page()->addKnob(0, 8, 1, 1, "05", "00", "0B");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 8);
	editDetails()->addPage("05", "00", "02", "00");  // PAGE 1 ABOVE

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 7);
	editDetails()->page()->newGroupBox("Flanger");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "0C", "normal", "right", 60);//rate
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "0D");         //depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "0E", "turbo");//manual
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "0F");         //resonance
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "10", "turbo");//separation
	editDetails()->page()->addKnob(0, 5, 1, 1, "05", "00", "11", "turbo");//effect level
	editDetails()->page()->addKnob(0, 6, 1, 1, "05", "00", "12", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 0, 1, 7);
    editDetails()->addPage("05", "00", "02", "01");  // PAGE 2 ABOVE

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "13");     //voice
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 5);
	
	editDetails()->page()->newGroupBox("Harmony 1");
	editDetails()->page()->addComboBox(0, 0, 2, 1, "05", "00", "14");     //hr1 harmony
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "15", "turbo");//hr1 pre delay
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "17", "turbo");//hr1 feedback
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "18");         //hr1 level
	editDetails()->page()->addGroupBox(1, 0, 1, 5);

	editDetails()->page()->insertStackField(0, 2, 0, 1, 1);

	
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "1D");     //key
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "1E");         //direct level
	editDetails()->page()->addGroupBox(2, 3, 1, 2);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Harmony 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "19");     //hr2 harmony
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "1A");         //hr2 pre delay
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "1C", "turbo");//hr2 level
	editDetails()->page()->addGroupBox(2, 0, 1, 3);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Harmony 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "19");     //hr2 harmony
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "1A");         //hr2 pre delay
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "1C", "turbo");//hr2 level
	editDetails()->page()->addGroupBox(2, 0, 1, 3);
	editDetails()->page()->addStackField();

	editDetails()->addPage("05", "00", "02", "02");  // PAGE 3 ABOVE

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
		editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "1F");     //voice
		editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 8);
	
	editDetails()->page()->newGroupBox("Pitch 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "20");     //ps1 mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "21", "turbo");//ps1 pitch
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "22");         //ps1 pitch fine
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "23", "turbo");//ps1 pre delay
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "25", "turbo");//ps1 feedback
	editDetails()->page()->addKnob(0, 5, 1, 1, "05", "00", "26");         //ps1 level
	editDetails()->page()->addGroupBox(1, 0, 1, 8);
	
	editDetails()->page()->insertStackField(0, 2, 0, 1, 1);
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pitch 2");
	editDetails()->page()->addComboBox(0, 7, 1, 1, "05", "00", "27");      //ps2 mode
	editDetails()->page()->addKnob(0, 8, 1, 1, "05", "00", "28");          //ps2 pitch
	editDetails()->page()->addKnob(0, 9, 1, 1, "05", "00", "29", "turbo"); //ps2 pitch fine
	editDetails()->page()->addKnob(0, 10, 1, 1, "05", "00", "2A");         //ps2 pre delay
	editDetails()->page()->addKnob(0, 11, 1, 1, "05", "00", "2C", "turbo");//ps2 level
	editDetails()->page()->addGroupBox(2, 0, 1, 6);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pitch 2");
	editDetails()->page()->addComboBox(0, 7, 1, 1, "05", "00", "27");      //ps2 mode
	editDetails()->page()->addKnob(0, 8, 1, 1, "05", "00", "28");          //ps2 pitch
	editDetails()->page()->addKnob(0, 9, 1, 1, "05", "00", "29", "turbo"); //ps2 pitch fine
	editDetails()->page()->addKnob(0, 10, 1, 1, "05", "00", "2A");         //ps2 pre delay
	editDetails()->page()->addKnob(0, 11, 1, 1, "05", "00", "2C", "turbo");//ps2 level
	editDetails()->page()->addGroupBox(2, 0, 1, 6);
	editDetails()->page()->addStackField();
	
    editDetails()->page()->newGroupBox("Direct Output");
	editDetails()->page()->addKnob(0, 12, 1, 1, "05", "00", "2D", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 7, 1, 1);
	editDetails()->addPage("05", "00", "02", "03");  // PAGE 4 ABOVE	
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 6);
	editDetails()->page()->newGroupBox("Pitch Bend");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "2E", "turbo");//PITCH MIN
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "2F");         //pitch max
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "30", "turbo");//pdl position  
	editDetails()->page()->addGroupBox(1, 0, 1, 3);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "31");         //effect level
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "32", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 4, 1, 2);
	editDetails()->addPage("05", "00", "02", "04");  // PAGE 5 ABOVE	

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 6);
	editDetails()->page()->newGroupBox("X-over freq");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "33", "turbo");//x-over freq
	editDetails()->page()->addGroupBox(1, 5, 1, 1);
	editDetails()->page()->newGroupBox("Low Band");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "34", "normal", "right", 60);//low rate
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "35");         //low depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "36", "turbo");//low pre-delay
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "37");         //low level
	editDetails()->page()->addGroupBox(2, 0, 1, 6);
	editDetails()->page()->newGroupBox("High Band");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "38", "normal", "right", 60);//high rate
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "39");         //high depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "3A", "turbo");//high pre delay
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "3B");         //high level
	editDetails()->page()->addGroupBox(1, 0, 1, 4);
	editDetails()->addPage("05", "00", "02", "05");  // PAGE 6 ABOVE  
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 4);
	editDetails()->page()->newGroupBox("Pan");
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "3C");         //wave shape
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "3D", "normal", "right", 60);//rate
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "3E");         //depth
	editDetails()->page()->addGroupBox(1, 0, 1, 4);
	editDetails()->addPage("05", "00", "02", "06");// PAGE 7 ABOVE
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 4);
	editDetails()->page()->newGroupBox("Vibrato");
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "3F", "normal", "right", 60);//rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "40");         //depth
	editDetails()->page()->addComboBox(0, 3, 1, 1, "05", "00", "41");     //trigger
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "42");         //rise time
	editDetails()->page()->addGroupBox(1, 0, 1, 4);
	editDetails()->addPage("05", "00", "02", "07");  // PAGE 8 ABOVE
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 4);
	editDetails()->page()->newGroupBox("Uni-V");
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "43", "normal", "right", 60);//rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "44");         //depth
  editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "45");     //level
	editDetails()->page()->addGroupBox(1, 0, 1, 4);
	editDetails()->addPage("05", "00", "02", "08");  // PAGE 9 ABOVE
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 2, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 5);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "46", "normal", "right", 60);//delay time
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "48");         //feedback
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "49", "turbo");//effect
	editDetails()->page()->addGroupBox(1, 4, 1, 1);
	editDetails()->addPage("05", "00", "02", "09");  // PAGE 10 ABOVE
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 9);
	editDetails()->page()->newGroupBox("Humanizer");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "4A");     //mode
	editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "4B");     //vowel 1
	editDetails()->page()->addComboBox(0, 2, 1, 1, "05", "00", "4C");     //vowel 2
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "4D", "turbo");//sensitivity
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "4E", "normal", "right", 60);         //rate
	editDetails()->page()->addKnob(0, 5, 1, 1, "05", "00", "4F", "turbo");//depth
	editDetails()->page()->addKnob(0, 6, 1, 1, "05", "00", "50");         //manual
	editDetails()->page()->addKnob(0, 7, 1, 1, "05", "00", "51", "turbo");//level
	editDetails()->page()->addGroupBox(1, 0, 1, 8);
	editDetails()->addPage("05", "00", "02", "0A");  // PAGE 10 ABOVE
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 4);
	editDetails()->page()->newGroupBox("Ring Modulator");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "52");     //mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "53");         //freq
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "54");         //effect level
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "55");         //direct level
	editDetails()->page()->addGroupBox(1, 0, 1, 4);
	editDetails()->addPage("05", "00", "02", "0B");// PAGE 11 ABOVE
	
		editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 4);
	editDetails()->page()->newGroupBox("SL");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "56");     //pattern
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "57", "normal", "right", 60);         //rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "58");         //trigger sense
	editDetails()->page()->addGroupBox(1, 0, 1, 3);
	editDetails()->addPage("05", "00", "02", "0C");// PAGE 12 ABOVE

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Riff Phrase");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "59");     //phrase
	editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "5A");     //loop
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "5B", "turbo");//tempo
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "5C");         //sensitivity
	editDetails()->page()->addGroupBox(0, 2, 1, 4);
	editDetails()->page()->newGroupBox("Riff Key");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "5D");     //key
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "5E", "turbo");//attack
	editDetails()->page()->addComboBox(0, 2, 1, 1, "05", "00", "5F");     //hold
	editDetails()->page()->addGroupBox(1, 0, 1, 4);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "60", "turbo");//effect level
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "61");         //direct level
	editDetails()->page()->addGroupBox(1, 4, 1, 2);
	editDetails()->addPage("05", "00", "02", "0D");  // PAGE 13 ABOVE
	

  editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "63");//, "middle", Qt::AlignCenter);     //wave
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	
    editDetails()->page()->insertStackField(0, 1, 0, 1, 1);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Square Wave");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "65");     //octave
	editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "64");     //chromatic
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "66", "turbo");//pwm rate
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "67");         //pwm depth
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "62");         //sensitivity
	editDetails()->page()->addComboBox(0, 5, 1, 1, "05", "00", "70");     //hold
	editDetails()->page()->addKnob(0, 6, 1, 1, "05", "00", "6D");         //attack
	editDetails()->page()->addKnob(0, 7, 1, 1, "05", "00", "69", "turbo");//resonance
	editDetails()->page()->addGroupBox(1, 0, 1, 7);
	editDetails()->page()->newGroupBox("Synth Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "68", "turbo");//cutoff freq
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "6C");         //depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "6A");         //flt sense
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "6B", "turbo");//decay
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "6E", "turbo");//release
	editDetails()->page()->addKnob(0, 5, 1, 1, "05", "00", "6F");         //velocity
	editDetails()->page()->addGroupBox(2, 0, 1, 5);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "71");         //synth level
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "72", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 5, 1, 2);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Saw Wave");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "65");     //octave
	editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "64");     //chromatic
	//editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "66", "turbo");//pwm rate
	//editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "67");         //pwm depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "62");         //sensitivity
	editDetails()->page()->addComboBox(0, 3, 1, 1, "05", "00", "70");     //hold
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "6D");         //attack
	editDetails()->page()->addKnob(0, 5, 1, 1, "05", "00", "69", "turbo");//resonance
	editDetails()->page()->addGroupBox(1, 0, 1, 5);
	editDetails()->page()->newGroupBox("Synth Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "68", "turbo");//cutoff freq
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "6C");         //depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "6A");         //flt sense
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "6B", "turbo");//decay
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "6E", "turbo");//release
	editDetails()->page()->addKnob(0, 5, 1, 1, "05", "00", "6F");         //velocity
	editDetails()->page()->addGroupBox(2, 0, 1, 5);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "71");         //synth level
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "72", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 7, 1, 2);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Brass Wave");
	//editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "65");     //octave
	//editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "64");     //chromatic
	//editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "66", "turbo");//pwm rate
	//editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "67");         //pwm depth
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "62");         //sensitivity
	//editDetails()->page()->addComboBox(0, 6, 1, 1, "05", "00", "70");     //hold
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "6D");         //attack
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "69", "turbo");//resonance
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	editDetails()->page()->newGroupBox("Synth Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "68", "turbo");//cutoff freq
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "6C");         //depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "6A");         //flt sense
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "6B", "turbo");//decay
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "6E", "turbo");//release
	editDetails()->page()->addKnob(0, 5, 1, 1, "05", "00", "6F");         //velocity
	editDetails()->page()->addGroupBox(2, 0, 1, 5);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "71");         //synth level
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "72", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 7, 1, 2);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Bow Wave");
	//editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "65");     //octave
	//editDetails()->page()->addComboBox(0, 1, 1, 1, "05", "00", "64");     //chromatic
	//editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "66", "turbo");//pwm rate
	//editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "67");         //pwm depth
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "62");         //sensitivity
	//editDetails()->page()->addComboBox(0, 6, 1, 1, "05", "00", "70");     //hold
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "6D");         //attack
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "69", "turbo");//resonance
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	editDetails()->page()->newGroupBox("Synth Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "68", "turbo");//cutoff freq
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "6C");         //depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "6A");         //flt sense
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "6B", "turbo");//decay
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "6E", "turbo");//release
	editDetails()->page()->addKnob(0, 5, 1, 1, "05", "00", "6F");         //velocity
	editDetails()->page()->addGroupBox(2, 0, 1, 5);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "71");         //synth level
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "72", "turbo");//direct level
	editDetails()->page()->addGroupBox(2, 7, 1, 2);
	editDetails()->page()->addStackField();

	editDetails()->addPage("05", "00", "02", "0E");// PAGE 14 ABOVE 
	
	 editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "00", "middle", Qt::AlignCenter);        //on/off
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Low EQ");
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "73", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
	editDetails()->page()->newGroupBox("Low Mid EQ");
	editDetails()->page()->addKnob(2, 0, 1, 1, "05", "00", "75", "turbo"); //Q
	editDetails()->page()->addKnob(2, 1, 1, 1, "05", "00", "74");          //freq
	editDetails()->page()->addKnob(2, 2, 1, 1, "05", "00", "76", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("High Mid EQ");
	editDetails()->page()->addKnob(1, 0, 1, 1, "05", "00", "78", "turbo"); //Q
	editDetails()->page()->addKnob(1, 1, 1, 1, "05", "00", "77");          //freq
	editDetails()->page()->addKnob(1, 2, 1, 1, "05", "00", "79", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->newGroupBox("High EQ");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "7A", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 3, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "7B");          //level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage("05", "00", "02", "0F");  // PAGE 15 ABOVE 


	
};
