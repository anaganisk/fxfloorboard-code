/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-10 Fx FloorBoard".
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

#include "stompbox_fx1.h"

stompbox_fx1::stompbox_fx1(QWidget *parent)
    : stompBox(parent)
{
	/* FX1 */
	setImage(":/images/fx1.png");
	setLSB("02", "00");
	setComboBox("02", "00", "01", QRect(8, 35, 79, 13));
	setButton("02", "00", "00");
	//setComboBox("0B", "00", "05", QRect(7, 141, 30, 20));
	setEditPages();
};

void stompbox_fx1::updateSignal()
{
	updateComboBox("02", "00", "01");
	updateButton("02", "00", "00");
};

void stompbox_fx1::setEditPages()
{

// T-Wah 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "0D", "bottom", Qt::AlignRight);
	editDetails()->page()->addComboBox(1, 0, 1, 2, "02", "00", "0E");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Touch Wah");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "0F");
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "10");
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "11");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "12");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "13");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "00");
	
		// Auto Wah 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "14");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Auto Wah");
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "15", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "16");
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "17");
	editDetails()->page()->addKnob(0, 4, 1, 1, "02", "00", "19");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "1B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "1A");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "01");
	
	// Sub-Wah 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "05", "00", "30", "bottom", Qt::AlignRight);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Sub Wah");
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "31" );
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "32");
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "33");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "34");
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "35");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "02");
	
   // Advanced Compressor 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "02");   //#
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Advanced Compressor");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "03");   ///#
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "04");    ////#
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "05");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "06");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "03");

	// Limiter 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "07");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Limitter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "08");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "09");
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "0A");
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "0B");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "0C");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "04");

	// Graphic EQ 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Equalizer");
	editDetails()->page()->newGroupBox("Band");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "36");
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "37");
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "38");
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "39");
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "3A");
	editDetails()->page()->addKnob(0, 5, 1, 1, "05", "00", "3B");
	editDetails()->page()->addKnob(0, 6, 1, 1, "05", "00", "3C");
	editDetails()->page()->addKnob(0, 7, 1, 1, "05", "00", "3D");
	editDetails()->page()->addKnob(0, 8, 1, 1, "05", "00", "3E");
	editDetails()->page()->addKnob(0, 9, 1, 1, "05", "00", "3F");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 1, 2, 1);
    
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "40");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "05");

    // Parametric EQ
  editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Equalizer");
	editDetails()->page()->newGroupBox("Low");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "58");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "59");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Low-Middle");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "5A");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "5B");
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "5C");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("High-Middle");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "5D");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "5E");
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "5F");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("High");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "60");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "61");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "62");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
  editDetails()->addPage("02", "00", "01", "06");

  	// Tone Modify 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "05", "00", "1F");  //19F from 20 00 00 00
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Tone Modify");
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "20");
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "21");
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "22");;
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "23");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "07");

	// Guitar Sim 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "05", "00", "24");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Guitar Simulator");
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "25");
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "26");
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "27");;
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "28");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "08");
	
	// Slow Gear 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Slow Gear");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "3E");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "3F");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("02", "00", "01", "09");

	
	// DeFretter 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Defretter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "2D");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "2E");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "2F");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "30");
	editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "31");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "32");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "33");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "0A");

  // Wave Synth 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "3B");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Wave Synth");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "3C");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "3D");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "3E");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "3F");
	editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "40");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "41");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "42");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "0B");


  // Guitar Synth 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "43");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->insertStackField(0, 0, 1, 2, 1);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Guitar Synth");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "46");
	editDetails()->page()->addSwitch(0, 1, 1, 1, "03", "00", "45", "middle", Qt::AlignCenter);
	editDetails()->page()->addSwitch(0, 2, 1, 1, "03", "00", "51", "middle", Qt::AlignCenter);
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "44");
	editDetails()->page()->addKnob(1, 1, 1, 1, "03", "00", "49");
	editDetails()->page()->addKnob(1, 2, 1, 1, "03", "00", "4A");
	editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "4E");
	editDetails()->page()->addKnob(2, 1, 1, 1, "03", "00", "4F");
	editDetails()->page()->addKnob(2, 2, 1, 1, "03", "00", "50");
	editDetails()->page()->addGroupBox(0, 0, 2, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "4B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "4C");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "4D");
	editDetails()->page()->addGroupBox(0, 1, 1, 2);

	editDetails()->page()->newGroupBox("PWM");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "47");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "48");
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "52");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "53");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Guitar Synth");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "46");
	editDetails()->page()->addSwitch(0, 1, 1, 1, "03", "00", "45", "middle", Qt::AlignCenter);
	editDetails()->page()->addSwitch(0, 2, 1, 1, "03", "00", "51", "middle", Qt::AlignCenter);
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "44");
	editDetails()->page()->addKnob(1, 1, 1, 1, "03", "00", "49");
	editDetails()->page()->addKnob(1, 2, 1, 1, "03", "00", "4A");
	editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "4E");
	editDetails()->page()->addKnob(2, 1, 1, 1, "03", "00", "4F");
	editDetails()->page()->addKnob(2, 2, 1, 1, "03", "00", "50");
	editDetails()->page()->addGroupBox(0, 0, 2, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "4B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "4C");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "4C");
	editDetails()->page()->addGroupBox(0, 1, 1, 2);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "52");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "53");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Guitar Synth");
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "44");
	editDetails()->page()->addKnob(1, 1, 1, 1, "03", "00", "49");
	editDetails()->page()->addKnob(1, 2, 1, 1, "03", "00", "4A");
	editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "4E");
	editDetails()->page()->addKnob(2, 1, 1, 1, "03", "00", "4F");
	editDetails()->page()->addKnob(2, 2, 1, 1, "03", "00", "50");
	editDetails()->page()->addGroupBox(0, 0, 2, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "4B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "4C");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "4D");
	editDetails()->page()->addGroupBox(0, 1, 1, 2);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "52");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "53");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Guitar Synth");
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "44");
	editDetails()->page()->addKnob(1, 1, 1, 1, "03", "00", "49");
	editDetails()->page()->addKnob(1, 2, 1, 1, "03", "00", "4A");
	editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "4E");
	editDetails()->page()->addKnob(2, 1, 1, 1, "03", "00", "4F");
	editDetails()->page()->addKnob(2, 2, 1, 1, "03", "00", "50");
	editDetails()->page()->addGroupBox(0, 0, 2, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "4B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "4C");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "4D");
	editDetails()->page()->addGroupBox(0, 1, 1, 2);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "52");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "53");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->addStackField();
	editDetails()->addPage("02", "00", "01", "0C");
	
		// Sitar Sim
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Sitar");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "34");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "35");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "36");
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "37");
	editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "38");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "39");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "3A");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "0D");
	
	// Octaver
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Octave", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addComboBox(0, 0, 1, 3, "03", "00", "15");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "16");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "17");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "0E");


  // Pitch Shifter 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "06");	
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->insertStackField(0, 0, 1, 3, 1);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pitch Shifter");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "07");
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "0A", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "03", "00", "08");
	editDetails()->page()->addKnob(0, 2, 2, 1, "03", "00", "09");
	editDetails()->page()->addGroupBox(0, 0, 3, 1);
	editDetails()->page()->addKnob(1, 1, 1, 1, "03", "00", "13");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "0C");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "14");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pitch Shifter");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "07");
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "0A", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "03", "00", "08");
	editDetails()->page()->addKnob(0, 2, 2, 1, "03", "00", "09");
	editDetails()->page()->addGroupBox(0, 0, 3, 1);
	editDetails()->page()->addKnob(1, 1, 1, 1, "03", "00", "13");

	editDetails()->page()->newGroupBox("Voice 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "0D");
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "10", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "03", "00", "0E");
	editDetails()->page()->addKnob(0, 2, 2, 1, "03", "00", "0F");
	editDetails()->page()->addGroupBox(4, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "0C");
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "12");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "14");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pitch Shifter");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "07");
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "0A", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "03", "00", "08");
	editDetails()->page()->addKnob(0, 2, 2, 1, "03", "00", "09");
	editDetails()->page()->addGroupBox(0, 0, 3, 1);
	editDetails()->page()->addKnob(1, 1, 1, 1, "03", "00", "13");

	editDetails()->page()->newGroupBox("Voice 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "0D");
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "10", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "03", "00", "0E");
	editDetails()->page()->addKnob(0, 2, 2, 1, "03", "00", "0F");
	editDetails()->page()->addGroupBox(4, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "0C");
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "12");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "14");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();
	editDetails()->addPage("02", "00", "01", "0F");

  // Harmonizer 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "63");	
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->insertStackField(0, 0, 1, 3, 1);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Harmonist");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "64");
	editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "65", "normal","right", 105);
	editDetails()->page()->addGroupBox(0, 0, 2, 1);
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "6C", "normal","right", 50);
	//editDetails()->page()->addKnob(1, 1, 1, 1, "02", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "67");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "6D");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Harmonist");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "64");
	editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "65", "normal","right", 105);
	editDetails()->page()->addGroupBox(0, 0, 2, 1);
	editDetails()->page()->newGroupBox("Voice 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "68");
	editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "69", "normal","right", 105);
	editDetails()->page()->addGroupBox(3, 0, 1, 1);

	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "6C", "normal","right", 50);
	//editDetails()->page()->addKnob(1, 1, 1, 1, "02", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "67");
	editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "6B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "6D");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Harmonist");
	editDetails()->page()->newGroupBox("Voice 1");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "64");
	editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "65", "normal","right", 105);
	editDetails()->page()->addGroupBox(0, 0, 2, 1);
	editDetails()->page()->newGroupBox("Voice 2");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "68");
	editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "69", "normal","right", 105);
	editDetails()->page()->addGroupBox(3, 0, 1, 1);

	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "6C", "normal","right", 50);
	//editDetails()->page()->addKnob(1, 1, 1, 1, "02", "00", "06");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "67");
	editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "6B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "6D");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();
	editDetails()->addPage("02", "00", "01", "10");

  // Auto Riff 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Auto Riff");

	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "54");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "57");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "58");
	//editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "38", "normal","right", 50);
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "56", "normal","right", 105);
	editDetails()->page()->addSwitch(1, 2, 1, 1, "03", "00", "55", "middle", Qt::AlignCenter);
	editDetails()->page()->addSwitch(1, 3, 1, 1, "03", "00", "59", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "5A");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "5B");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "11");

  // Sound Hold 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Sound Hold");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "05", "00", "1C", "middle", Qt::AlignTop | Qt::AlignHCenter);	
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "1D");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "1E");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "12");
	
	
		// Acoustic Processor
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "05", "00", "29");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Acoustic Processor");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "2A");
	editDetails()->page()->addKnob(0, 1, 1, 1, "05", "00", "2B");
	editDetails()->page()->addKnob(0, 2, 1, 1, "05", "00", "2C");
	editDetails()->page()->addKnob(0, 3, 1, 1, "05", "00", "2D");
	editDetails()->page()->addKnob(0, 4, 1, 1, "05", "00", "2E");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "05", "00", "2F");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "13");


  	// FeedBacker 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "40");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->insertStackField(0, 0, 1, 2, 1);
	// OSC 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Feedbacker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "41");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "43");

	editDetails()->page()->newGroupBox("Hi Oct");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "42");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "44");
	editDetails()->page()->addGroupBox(1, 0, 1, 2);

	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "45", "normal","right", 105);
	editDetails()->page()->addKnob(1, 2, 1, 1, "02", "00", "46");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	// NATURAL 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Feedbacker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "41");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->addPage("02", "00", "01", "14");

	// AntiFeedBacker 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Anti-Feedback");

	editDetails()->page()->newGroupBox("Frequency 1");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "47");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "48");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Frequency 2");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "49");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "4A");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Frequency 3");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "4B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "4C");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("02", "00", "01", "15");

  
	// Phaser 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "1E");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Phaser");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "1F", "normal","right", 105);
	editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "23", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "21");
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "22");
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "20");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "24");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "25");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "16");

	// Flanger
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Flanger");
	editDetails()->page()->addKnob(0, 0, 1, 3, "02", "00", "26", "normal","right", 105);
	editDetails()->page()->addKnob(1, 0, 1, 1, "02", "00", "27");
	editDetails()->page()->addKnob(1, 1, 1, 1, "02", "00", "28");
	editDetails()->page()->addKnob(1, 2, 1, 1, "02", "00", "29");
	editDetails()->page()->addKnob(1, 3, 1, 1, "02", "00", "2A");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "2B");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "2C");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "2D");
	editDetails()->page()->addGroupBox(0, 3, 1, 1);
	editDetails()->addPage("02", "00", "01", "17");


	// Tremolo
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Tremelo");
	editDetails()->page()->newGroupBox("Wave");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "1B");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "1C", "normal","right", 105);
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "1D");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("02", "00", "01", "18");
	
		
	// Rotary 
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 3, "03", "00", "18");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Rotary");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "19", "normal","right", 105);
	editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "1A", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 2, 1, "03", "00", "1B");
	editDetails()->page()->addKnob(0, 2, 2, 1, "03", "00", "1C");
	editDetails()->page()->addKnob(0, 3, 2, 1, "03", "00", "1D");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("02", "00", "01", "19");
	
	// Uni-V 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Uni-V");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "37", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "38");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "39");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "1A");

	// Panner
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Pan");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "2E");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "2F");
	editDetails()->page()->newGroupBox("Wave");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "30");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "31", "normal","right", 105);
	editDetails()->page()->addKnob(0, 5, 1, 1, "02", "00", "32");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "1B");
	
	// Slicer 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Slicer");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "55");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "56", "normal","right", 105);
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "57");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("02", "00", "01", "1C");

	// Vibrato
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Vibrato");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "33", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "34");

	editDetails()->page()->newGroupBox("Trigger");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "35", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "36");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage("02", "00", "01", "1D");


	// Ring Modulator
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "3A");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Ring Modulator");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "3B");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "3C");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "3D");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "1E");


	// Humanizer
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "4D");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Humanizer");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "4E");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "4F");
	editDetails()->page()->addKnob(0, 1, 1, 3, "02", "00", "51", "normal","right", 105);
	editDetails()->page()->addKnob(1, 1, 1, 1, "02", "00", "50");
	editDetails()->page()->addKnob(1, 2, 1, 1, "02", "00", "52");
	editDetails()->page()->addKnob(1, 3, 1, 1, "02", "00", "53");
	editDetails()->page()->addGroupBox(0, 1, 2, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "54");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "1F");

	
		// 2CE 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("2x2 Chorus");
	editDetails()->page()->newGroupBox("Low");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "1F", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "20");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "21");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("High");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "23", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "24");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "25");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addKnob(0, 1, 2, 1, "03", "00", "1E", "normal","right", 63);
	editDetails()->page()->addGroupBox(0, 1, 3, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "22");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "26");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);

	editDetails()->addPage("02", "00", "01", "20");
	
	
	
	// Sub Delay 
	editDetails()->page()->newGroupBox("Effect", Qt::AlignTop | Qt::AlignHCenter);
	editDetails()->page()->addSwitch(0, 0, 1, 1, "02", "00", "00");	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Sub Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "27", "normal","right", 105);
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "29");
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "2A");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "2B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "2C");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->addPage("02", "00", "01", "21");


editDetails()->addPage();	
};
