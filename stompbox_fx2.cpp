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

#include "stompbox_fx2.h"

stompbox_fx2::stompbox_fx2(QWidget *parent)
    : stompBox(parent)
{
	/* FX2 */
	setImage(":/images/fx2.png");
  setLSB("01", "00");
	setComboBox("01", "00", "39", QRect(8, 31, 79, 13));
  setButton("00", "00", "00");
  editDetails()->patchPos(103, 71, "01", "00");   //83
	setEditPages();
};

void stompbox_fx2::updateSignal()
{
  updateComboBox("01", "00", "39");
  updateButton("00", "00", "00");
};

void stompbox_fx2::setEditPages()
{

  editDetails()->page()->newGroupBox("Effect");
  editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "39");     
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->insertStackField(0, 1, 0, 1, 1);
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Harmony 1");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "3A");     //voice
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "3B");     //mode
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "3C");         //hr1 pitch
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "3D");         //hr1 pitch fine
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "00", "3E");     // PRESET/USER
	editDetails()->page()->addComboBox(0, 5, 2, 1, "01", "00", "3F");     //hr1 harmony
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "40", "normal","right", 90);//hr1 pre delay
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "42", "turbo");//hr1 feedback
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "43");         //hr1 level
	editDetails()->page()->addGroupBox(1, 0, 1, 3);

	editDetails()->page()->insertStackField(1, 2, 0, 1, 2);
	
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "4D");     //key
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "4E");         //direct level
	editDetails()->page()->addGroupBox(2, 2, 1, 1);
	editDetails()->page()->addStackField(); 

	editDetails()->page()->newStackField(1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(1);
	editDetails()->page()->newGroupBox("Harmony 2");
		editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "44");     //mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "45");         //hr2 pitch
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "46");         //hr2 pitch fine
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "00", "47");     //PRESET/USER
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "00", "48");     //hr2 harmony
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "4A" ,"normal","right", 90);         //hr2 pre delay
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "4C", "turbo");//hr2 level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	editDetails()->page()->addStackField();
	
  editDetails()->page()->newStackField(1);
	editDetails()->page()->newGroupBox("Harmony 2");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "44");     //mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "45");         //hr2 pitch
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "46");         //hr2 pitch fine
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "00", "47");     //hr2 harmony
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "48" ,"normal","right", 90);         //hr2 pre delay
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "4C", "turbo");//hr2 level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	editDetails()->page()->addStackField();
	  // PAGE 1 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Flanger");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "4F", "normal","right", 90);//rate
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "50");         //depth
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "51", "turbo");//manual
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "52");         //resonance
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "53", "turbo");//separation
	editDetails()->page()->addGroupBox(1, 0, 1, 7);
  editDetails()->page()->addStackField();   // PAGE 2 ABOVE
	
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Phaser");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "54");     //type
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "55" ,"normal", "right", 90);         //rate
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "56", "turbo");//depth
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "57");         //manual
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "58", "turbo");//resonance
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "00", "59");     //step
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "5A", "normal", "right", 90);//step rate
	editDetails()->page()->addGroupBox(1, 0, 1, 8);
	editDetails()->page()->addStackField();   // PAGE 3 ABOVE
	


	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Low EQ");
	editDetails()->page()->addKnob(2, 2, 1, 1, "01", "00", "5B", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Low Mid EQ");
	editDetails()->page()->addKnob(2, 0, 1, 1, "01", "00", "5D", "turbo"); //Q
	editDetails()->page()->addKnob(2, 1, 1, 1, "01", "00", "5C");          //freq
	editDetails()->page()->addKnob(2, 2, 1, 1, "01", "00", "5E", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("High Mid EQ");
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "60", "turbo"); //Q
	editDetails()->page()->addKnob(1, 1, 1, 1, "01", "00", "5F");          //freq
	editDetails()->page()->addKnob(1, 2, 1, 1, "01", "00", "61", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->page()->newGroupBox("High EQ");
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "62", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 3, 1, 1);

	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(2, 0, 1, 1, "01", "00", "63");          //level
	editDetails()->page()->addGroupBox(1, 0, 1, 4);
	editDetails()->page()->addStackField();                        // PAGE 5 ABOVE 
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Short Digital Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "64", "normal", "right", 90);//delay time
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "66");         //feedback
	editDetails()->page()->addGroupBox(1, 0, 1, 3);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "67");         //effect level
	editDetails()->page()->addGroupBox(1, 4, 1, 2);
	editDetails()->page()->addStackField();   // PAGE 7 ABOVE	
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Humanizer");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "68");     //mode
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "69");     //vowel 1
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "6A");     //vowel 2
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "6B", "turbo");//sensitivity
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "6C" ,"normal","right", 90);         //rate
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "6D", "turbo");//depth
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "6E");         //manual
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "6F", "turbo");//level
	editDetails()->page()->addGroupBox(1, 0, 1, 9);
	editDetails()->page()->addStackField();      // PAGE 8 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Ring Modulator");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "70");     //mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "71", "turbo");//freq
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "72", "turbo");//effect
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "73");         //direct
	editDetails()->page()->addGroupBox(1, 4, 1, 1);
	editDetails()->page()->addStackField();       // PAGE 11 ABOVE
	
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Vibrato");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "74", "normal","right", 90);//rate
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "75");         //depth
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "76");     //trigger
	editDetails()->page()->addGroupBox(1, 0, 1, 3);
	editDetails()->page()->newGroupBox("Rise Time");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "77");         //RISE
	editDetails()->page()->addGroupBox(1, 4, 1, 2);
	editDetails()->page()->addStackField();     // PAGE 9 ABOVE	
	
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Acoustic Processor");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "78", "normal","right", 90); //  top
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "79", "normal","right", 90); //body
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "7A");         // level
	editDetails()->page()->addGroupBox(1, 0, 1, 4);
	editDetails()->page()->addStackField();    // PAGE 12 ABOVE
        
	
	editDetails()->page()->newStackField(0);  //SYNTH
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "7B", "turbo");//sens
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "00", "7C");//, "middle", Qt::AlignCenter);     //wave
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Wave");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "7D");     //chromatic
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "7E");     //octave
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "7F", "turbo");//pwm rate
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "00");         //pwm depth
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->newGroupBox("Synth");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "06", "turbo");//attack
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "07");         //release
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "08", "turbo");//velocity
	editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "00", "09");     //hold
	editDetails()->page()->addGroupBox(0, 2, 1, 1); 
  editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "01", "turbo");//cutoff freq
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "02");         //resonance
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "03");         //flt sens
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "04");         //flt decay
	editDetails()->page()->addKnob(0, 4, 1, 1, "02", "00", "05", "turbo");//flt depth
	editDetails()->page()->addGroupBox(1, 0, 1, 2);   
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "0A");         //synth level
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "0B", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->page()->addStackField();    // PAGE 10 ABOVE 
	
	
	editDetails()->addPage();		
};
