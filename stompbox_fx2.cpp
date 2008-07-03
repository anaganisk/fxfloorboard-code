/****************************************************************************
**
** Copyright (C) 2008 Colin Willcocks
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
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

#include "stompbox_fx2.h"

stompbox_fx2::stompbox_fx2(QWidget *parent)
    : stompBox(parent)
{
	/* fx2 */
	setImage(":/images/fx2.png");
	setLSB("06", "00");
	setComboBox("06", "00", "01", QRect(8, 35, 79, 13));
	setButton("06", "00", "00");
	setEditPages();
};

void stompbox_fx2::updateSignal()
{
	updateComboBox("06", "00", "01");
	updateButton("06", "00", "00");
};

void stompbox_fx2::setEditPages()
{

// T-Wah 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addComboBox(0, 1, 1, 1, "06", "00", "0D", "bottom", Qt::AlignRight);
	editDetails()->page()->addComboBox(1, 0, 1, 2, "06", "00", "0E");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Touch Wah");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "0F");
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "10");
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "11");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "12");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "13");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "00");
	
		// Auto Wah 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "14");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Auto Wah");
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "15", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "16");
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "17");
	editDetails()->page()->addKnob(0, 4, 1, 1, "06", "00", "18");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "19");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "1A");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "01");
	
	// Sub-Wah 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "09", "00", "30", "bottom", Qt::AlignRight);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Sub Wah");
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "31" );
	editDetails()->page()->addKnob(0, 2, 1, 1, "09", "00", "32");
	editDetails()->page()->addKnob(0, 3, 1, 1, "09", "00", "33");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "34");
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "35");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "02");
	
   // Advanced Compressor 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "02");   //#
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Advanced Compressor");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "03");   ///#
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "04");    ////#
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "05");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "06");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "03");

	// Limiter 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "07");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Limiter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "08");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "09");
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "0A");
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "0B");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "0C");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "04");

	// Graphic EQ 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Equalizer");
	editDetails()->page()->newGroupBox("Band");
	editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "37");
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "38");
	editDetails()->page()->addKnob(0, 2, 1, 1, "09", "00", "39");
	editDetails()->page()->addKnob(0, 3, 1, 1, "09", "00", "3A");
	editDetails()->page()->addKnob(0, 4, 1, 1, "09", "00", "3B");
	editDetails()->page()->addKnob(0, 5, 1, 1, "09", "00", "3C");
	editDetails()->page()->addKnob(0, 6, 1, 1, "09", "00", "3D");
	editDetails()->page()->addKnob(0, 7, 1, 1, "09", "00", "3E");
	editDetails()->page()->addKnob(0, 8, 1, 1, "09", "00", "3F");
	editDetails()->page()->addKnob(0, 9, 1, 1, "09", "00", "40");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 1, 2, 1);
    
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "36");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "05");

    // Parametric EQ
  editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Equalizer");
	editDetails()->page()->newGroupBox("Low");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "58");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "59");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Low-Middle");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "5A");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "5B");
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "5C");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("High-Middle");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "5D");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "5E");
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "5F");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("High");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "60");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "61");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "62");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
  editDetails()->addPage("06", "00", "01", "06");
  
  // Enhancer
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "41");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Low Frequency", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "09", "00", "42");
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "43");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("High Frequency");
editDetails()->page()->addComboBox(0, 0, 1, 1, "09", "00", "44");
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "45");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "07");

  	// Tone Modify 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "09", "00", "1F");  //19F from 20 00 00 00
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Tone Modify");
	editDetails()->page()->addKnob(0, 3, 1, 1, "09", "00", "22");
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "20");
	editDetails()->page()->addKnob(0, 2, 1, 1, "09", "00", "21");;
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "23");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "08");

	// Bass Sim 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "09", "00", "46");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Bass Simulator");
	editDetails()->page()->addKnob(0, 3, 1, 1, "09", "00", "47");
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "48");
	editDetails()->page()->addKnob(0, 2, 1, 1, "09", "00", "49");;
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "4A");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "09");
	
	// Slow Gear 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Slow Gear");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "3E");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "3F");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("06", "00", "01", "0A");

	
	// DeFretter 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Defretter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "2D");
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "2E");
	editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "2F");
	//editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "30");
	//editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "31");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "32");
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "33");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "0B");

  
  // Bass Synth 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "09", "00", "4B");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Bass Synth");
	editDetails()->page()->addKnob(1, 0, 1, 1, "09", "00", "4C");
	editDetails()->page()->addKnob(1, 1, 1, 1, "09", "00", "4D");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "4E");
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "4F");
	editDetails()->page()->addKnob(0, 2, 1, 1, "09", "00", "50");
	editDetails()->page()->addGroupBox(0, 2, 1, 2);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "51");
	editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "52");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->addPage("06", "00", "01", "0C");
	
	
	// Octaver
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Octave", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addComboBox(0, 0, 1, 3, "07", "00", "15");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "16");
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "17");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "0D");


  // Pitch Shifter 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "07", "00", "06");	
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->insertStackField(0, 0, 1, 3, 1);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pitch Shifter");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "07");
	editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "0A", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "07", "00", "08");
	editDetails()->page()->addKnob(0, 2, 2, 1, "07", "00", "09");
	editDetails()->page()->addGroupBox(0, 0, 3, 1);
	editDetails()->page()->addKnob(1, 1, 1, 1, "07", "00", "13");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "0C");
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "14");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pitch Shifter");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "07");
	editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "0A", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "07", "00", "08");
	editDetails()->page()->addKnob(0, 2, 2, 1, "07", "00", "09");
	editDetails()->page()->addGroupBox(0, 0, 3, 1);
	editDetails()->page()->addKnob(1, 1, 1, 1, "07", "00", "13");

	editDetails()->page()->newGroupBox("Voice 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "0D");
	editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "10", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "07", "00", "0E");
	editDetails()->page()->addKnob(0, 2, 2, 1, "07", "00", "0F");
	editDetails()->page()->addGroupBox(4, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "0C");
	editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "12");
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "14");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pitch Shifter");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "07");
	editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "0A", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "07", "00", "08");
	editDetails()->page()->addKnob(0, 2, 2, 1, "07", "00", "09");
	editDetails()->page()->addGroupBox(0, 0, 3, 1);
	editDetails()->page()->addKnob(1, 1, 1, 1, "07", "00", "13");

	editDetails()->page()->newGroupBox("Voice 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "0D");
	editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "10", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "07", "00", "0E");
	editDetails()->page()->addKnob(0, 2, 2, 1, "07", "00", "0F");
	editDetails()->page()->addGroupBox(4, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "0C");
	editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "12");
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "14");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();
	editDetails()->addPage("06", "00", "01", "0E");

  // Harmonizer 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "63");	
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->insertStackField(0, 0, 1, 3, 1);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Harmonist");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "06", "00", "64");
	editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "65", "normal","right", 105);
	editDetails()->page()->addGroupBox(0, 0, 2, 1);
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "6C", "normal","right", 50);
	//editDetails()->page()->addKnob(1, 1, 1, 1, "06", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "67");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "6D");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Harmonist");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "06", "00", "64");
	editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "65", "normal","right", 105);
	editDetails()->page()->addGroupBox(0, 0, 2, 1);
	editDetails()->page()->newGroupBox("Voice 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "06", "00", "68");
	editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "69", "normal","right", 105);
	editDetails()->page()->addGroupBox(3, 0, 1, 1);

	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "6C", "normal","right", 50);
	//editDetails()->page()->addKnob(1, 1, 1, 1, "06", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "67");
	editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "6B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "6D");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Harmonist");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "06", "00", "64");
	editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "65", "normal","right", 105);
	editDetails()->page()->addGroupBox(0, 0, 2, 1);
	editDetails()->page()->newGroupBox("Voice 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "06", "00", "68");
	editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "69", "normal","right", 105);
	editDetails()->page()->addGroupBox(3, 0, 1, 1);

	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "6C", "normal","right", 50);
	//editDetails()->page()->addKnob(1, 1, 1, 1, "06", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "67");
	editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "6B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "6D");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();
	editDetails()->addPage("06", "00", "01", "0F");

 
  // Sound Hold 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Sound Hold");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "09", "00", "1C", "middle", Qt::AlignTop | Qt::AlignHCenter);	
	editDetails()->page()->addKnob(0, 2, 1, 1, "09", "00", "1D");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "1E");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "10");
	

  
	// Phaser 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "1E");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Phaser");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "1F", "normal","right", 105);
	editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "23", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "21");
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "22");
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "20");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "24");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "25");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "11");

	// Flanger
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Flanger");
	editDetails()->page()->addKnob(0, 0, 1, 3, "06", "00", "26", "normal","right", 105);
	editDetails()->page()->addKnob(1, 0, 1, 1, "06", "00", "27");
	editDetails()->page()->addKnob(1, 1, 1, 1, "06", "00", "28");
	editDetails()->page()->addKnob(1, 2, 1, 1, "06", "00", "29");
	editDetails()->page()->addKnob(1, 3, 1, 1, "06", "00", "2A");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "2B");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "2C");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "2D");
	editDetails()->page()->addGroupBox(0, 3, 1, 1);
	editDetails()->addPage("06", "00", "01", "12");


	// Tremolo
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Tremelo");
	editDetails()->page()->newGroupBox("Wave");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "1B");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "1C", "normal","right", 105);
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "1D");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("06", "00", "01", "13");
	
		
	// Rotary 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 3, "07", "00", "18");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Rotary");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "19", "normal","right", 105);
	editDetails()->page()->addKnob(1, 0, 1, 1, "07", "00", "1A", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "07", "00", "1B");
	editDetails()->page()->addKnob(0, 2, 2, 1, "07", "00", "1C");
	editDetails()->page()->addKnob(0, 3, 2, 1, "07", "00", "1D");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("06", "00", "01", "14");
	
	// Uni-V 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Uni-V");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "37", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "38");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "39");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "15");

	// Panner
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Pan");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "06", "00", "2E");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "2F");
	editDetails()->page()->newGroupBox("Wave");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "30");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "31", "normal","right", 105);
	editDetails()->page()->addKnob(0, 5, 1, 1, "06", "00", "32");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "16");
	
	// Slicer 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Slicer");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "06", "00", "55");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "56", "normal","right", 105);
	editDetails()->page()->addKnob(0, 2, 1, 1, "06", "00", "57");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("06", "00", "01", "17");

	// Vibrato
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Vibrato");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "33", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "34");

	editDetails()->page()->newGroupBox("Trigger");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "35", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->page()->addKnob(0, 3, 1, 1, "06", "00", "36");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("06", "00", "01", "18");


	// Ring Modulator
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "3A");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Ring Modulator");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "3B");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "3C");
	editDetails()->page()->addKnob(0, 1, 1, 1, "06", "00", "3D");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "19");


	// Humanizer
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "4D");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Humanizer");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "06", "00", "4E");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "06", "00", "4F");
	editDetails()->page()->addKnob(0, 1, 1, 3, "06", "00", "51", "normal","right", 105);
	editDetails()->page()->addKnob(1, 1, 1, 1, "06", "00", "50");
	editDetails()->page()->addKnob(1, 2, 1, 1, "06", "00", "52");
	editDetails()->page()->addKnob(1, 3, 1, 1, "06", "00", "53");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "06", "00", "54");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "1A");

	
		// 2CE 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("2x2 Chorus");
	editDetails()->page()->newGroupBox("Low");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "1F", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "20");
	editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "21");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("High");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "23", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "24");
	editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "25");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addKnob(0, 1, 2, 1, "07", "00", "1E", "normal","right", 63);
	editDetails()->page()->addGroupBox(0, 1, 3, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "22");
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "26");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->addPage("06", "00", "01", "1B");
	
	
	
	// Sub Delay 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "06", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Sub Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "27", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "29");
	editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "2A");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "07", "00", "2B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "2C");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("06", "00", "01", "1C");


editDetails()->addPage();	
};
