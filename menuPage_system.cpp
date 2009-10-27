/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag.
** All rights reserved.
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

#include "menuPage_system.h"

menuPage_system::menuPage_system(QWidget *parent)
    : menuPage(parent)
{ 
  setImage(":/images/menuPage_stomp.png");
  setLSB("00", "00");
	setEditPages();
};

void menuPage_system::updateSignal()
{

};

void menuPage_system::setEditPages()
{
	editDetails()->page()->addLabel(0, 0, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-10B"));
  editDetails()->page()->newGroupBox("settings");
  editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "00", "System"); // lcd contrast
  editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "10", "System"); // preamp mode
	editDetails()->page()->addLabel(0, 3, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 4, 1, 1, "00", "00", "17", "System"); //exp hold
	editDetails()->page()->addLabel(0, 5, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 6, 1, 1, "00", "00", "18", "System"); //exp indication
	editDetails()->page()->addLabel(0, 7, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 8, 1, 1, "00", "00", "70", "System"); // sys num pdl ctrl
	editDetails()->page()->addLabel(0, 9, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 10, 1, 1, "00", "00", "71", "System"); // dial function
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	
	editDetails()->page()->newGroupBox("USB settings");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "20", "System"); //usb driver mode
	editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "21", "System"); //usb monitor cmd
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "22", "System"); //dgt out level
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "23", "System"); //usb mix level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Tuner");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "30", "System"); // tuner pitch
	editDetails()->page()->addLabel(0, 1, 1, 1, "               ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "31", "System"); //tuner bypass
	editDetails()->page()->addGroupBox(2, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Patch Change");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "11", "System"); // patch change mode
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "12", "System"); // bank change mode
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "13", "System"); // bank extent min
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "15", "System"); // bank extent max
	editDetails()->page()->addGroupBox(3, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Input settings and Global NS/Reverb");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "4D", "System"); // input select
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "50", "System"); // NS threshold
  editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "51", "System"); // revberb level
	editDetails()->page()->addGroupBox(3, 0, 1, 1);
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "40", "System"); // gat 1 input level
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "41", "System"); // gat 1 input pres
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "42", "System"); // gat 2 input level
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "43", "System"); // gat 2 input pres
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "44", "System"); // gat 3 input level
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "45", "System"); // gat 3 input pres
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "46", "System"); // usb input level
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "47", "System"); // usb input pres
	editDetails()->page()->addStackField();
  editDetails()->addPage("00", "00", "01", "00", "System");

	
	editDetails()->page()->newGroupBox(tr("User Options  ***CAUTION*** Settings changes are automatically written to GT-10B"));
	editDetails()->page()->newGroupBox("Output");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "4E", "System"); // output mode
  editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
  editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "4F", "System"); // output select
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "52", "System"); // main out
	editDetails()->page()->addComboBox(0, 4, 1, 1, "00", "00", "53", "System"); // sub out mode 
	editDetails()->page()->addKnob(0, 5, 1, 1, "00", "00", "54", "System"); // sub out level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Phrase Looper");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "60", "System"); // PH LOOP mode
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "61", "System"); // record mode
	editDetails()->page()->addComboBox(2, 0, 1, 1, "00", "00", "62", "System"); // pedal mode
	editDetails()->page()->addComboBox(3, 0, 1, 1, "00", "00", "63", "System"); // clear pdl
	editDetails()->page()->addKnob(4, 0, 1, 1, "00", "00", "64", "System"); // play level 
	editDetails()->page()->addGroupBox(0, 1, 4, 1);
	
	editDetails()->page()->newGroupBox("Knob Function");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "72", "System"); // knob P1
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "74", "System"); // knob P2
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "76", "System"); // knob P3
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "00", "78", "System"); // knob P4
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Global Equalizer");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "48", "System"); // eq low
	editDetails()->page()->addLabel(0, 1, 1, 1, "       ");
  editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "49", "System"); // eq mid gain
  editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "4A", "System"); // eq mid Q
  editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "4B", "System"); // eq mid freq
  editDetails()->page()->addLabel(0, 5, 1, 1, "       ");
  editDetails()->page()->addKnob(0, 6, 1, 1, "00", "00", "4C", "System"); // eq high
	editDetails()->page()->addGroupBox(3, 0, 1, 1);
	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "01", "System");
	
	editDetails()->page()->newGroupBox(tr("Internal Pedals  ***CAUTION*** Settings changes are automatically written to GT-10B"));
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "7A", "System"); // exp1 pdl
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "01", "10", "System"); // exp1 setting
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "01", "11", "System"); // exp1 function
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "01", "13", "System"); // exp1 min
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "01", "15", "System"); // exp1 max
	editDetails()->page()->addComboBox(0, 5, 1, 1, "00", "01", "17", "System"); // exp1 src mode
	editDetails()->page()->addRange(0, 6, 1, 2, "00", "01", "18", "System");         // min/max range widget
	//editDetails()->page()->addKnob(0, 6, 1, 1, "00", "01", "18", "System"); // exp1 act range lo
	//editDetails()->page()->addKnob(0, 7, 1, 1, "00", "01", "19", "System"); // exp1 act range hi
	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "7B", "System"); // exp1 pdl sw
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "01", "20", "System"); // exp1 sw setting
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "01", "21", "System"); // exp1 sw function
	editDetails()->page()->addKnob(1, 3, 1, 1, "00", "01", "23", "System"); // exp1 sw min
	editDetails()->page()->addKnob(1, 4, 1, 1, "00", "01", "25", "System"); // exp1 sw max
	editDetails()->page()->addComboBox(1, 5, 1, 1, "00", "01", "27", "System"); // exp1 sw src mode
	editDetails()->page()->addRange(1, 6, 1, 2, "00", "01", "28", "System");         // min/max range widget
	//editDetails()->page()->addKnob(1, 6, 1, 1, "00", "01", "28", "System"); // exp1 sw act range lo
	//editDetails()->page()->addKnob(1, 7, 1, 1, "00", "01", "29", "System"); // exp1 sw act range hi
	
	editDetails()->page()->addComboBox(2, 0, 1, 1, "00", "00", "7C", "System"); // ctrl 1
  editDetails()->page()->addComboBox(2, 1, 1, 1, "00", "01", "30", "System"); // ctl1 setting
	editDetails()->page()->addComboBox(2, 2, 1, 1, "00", "01", "31", "System"); // ctl1 function
	editDetails()->page()->addKnob(2, 3, 1, 1, "00", "01", "33", "System"); // ctl1 min
	editDetails()->page()->addKnob(2, 4, 1, 1, "00", "01", "35", "System"); // ctl1 max
	editDetails()->page()->addComboBox(2, 5, 1, 1, "00", "01", "37", "System"); // ctl1 src mode
	editDetails()->page()->addRange(2, 6, 1, 2, "00", "01", "38", "System");         // min/max range widget
	//editDetails()->page()->addKnob(2, 6, 1, 1, "00", "01", "38", "System"); // ctl1 act range lo
	//editDetails()->page()->addKnob(2, 7, 1, 1, "00", "01", "39", "System"); // ctl1 act range hi
	
	editDetails()->page()->addComboBox(3, 0, 1, 1, "00", "00", "7D", "System"); // ctrl 2
	editDetails()->page()->addComboBox(3, 1, 1, 1, "00", "01", "40", "System"); // ctl2 setting
	editDetails()->page()->addComboBox(3, 2, 1, 1, "00", "01", "41", "System"); // ctl2 function
	editDetails()->page()->addKnob(3, 3, 1, 1, "00", "01", "43", "System"); // ctl2 min
	editDetails()->page()->addKnob(3, 4, 1, 1, "00", "01", "45", "System"); // ctl2 max
	editDetails()->page()->addComboBox(3, 5, 1, 1, "00", "01", "47", "System"); // ctl2 src mode
	editDetails()->page()->addRange(3, 6, 1, 2, "00", "01", "48", "System");         // min/max range widget
	//editDetails()->page()->addKnob(3, 6, 1, 1, "00", "01", "48", "System"); // ctl2 act range lo
	//editDetails()->page()->addKnob(3, 7, 1, 1, "00", "01", "49", "System"); // ctl2 act range hi 
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "02", "System");
	
	editDetails()->page()->newGroupBox(tr("External pedals  ***CAUTION*** Settings changes are automatically written to GT-10B"));
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "7E", "System"); // exp2 pdl
  editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "01", "50", "System"); // exp2 setting
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "01", "51", "System"); // exp2 function
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "01", "53", "System"); // exp2 min
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "01", "55", "System"); // exp2 max
	editDetails()->page()->addComboBox(0, 5, 1, 1, "00", "01", "57", "System"); // exp2 src mode
	editDetails()->page()->addRange(0, 6, 1, 2, "00", "01", "58", "System");         // min/max range widget
	//editDetails()->page()->addKnob(0, 6, 1, 1, "00", "01", "58", "System"); // exp2 act range lo
	//editDetails()->page()->addKnob(0, 7, 1, 1, "00", "01", "59", "System"); // exp2 act range hi
	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "7F", "System"); // ctrl 3
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "01", "60", "System"); // ctl3 setting
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "01", "61", "System"); // ctl3 function
	editDetails()->page()->addKnob(1, 3, 1, 1, "00", "01", "63", "System"); // ctl3 min
	editDetails()->page()->addKnob(1, 4, 1, 1, "00", "01", "65", "System"); // ctl3 max
	editDetails()->page()->addComboBox(1, 5, 1, 1, "00", "01", "67", "System"); // ctl3 src mode
	editDetails()->page()->addRange(1, 6, 1, 2, "00", "01", "68", "System");         // min/max range widget
	//editDetails()->page()->addKnob(1, 6, 1, 1, "00", "01", "68", "System"); // ctl3 act range lo
	//editDetails()->page()->addKnob(1, 7, 1, 1, "00", "01", "69", "System"); // ctl3 act range hi
	
	editDetails()->page()->addComboBox(2, 0, 1, 1, "00", "01", "00", "System"); // ctrl 4
	editDetails()->page()->addComboBox(2, 1, 1, 1, "00", "01", "70", "System"); // ctl4 setting
	editDetails()->page()->addComboBox(2, 2, 1, 1, "00", "01", "71", "System"); // ctl4 function
	editDetails()->page()->addKnob(2, 3, 1, 1, "00", "01", "73", "System"); // ctl4 min
	editDetails()->page()->addKnob(2, 4, 1, 1, "00", "01", "75", "System"); // ctl4 max
	editDetails()->page()->addComboBox(2, 5, 1, 1, "00", "01", "77", "System"); // ctl4 src mode
	editDetails()->page()->addRange(2, 6, 1, 2, "00", "01", "78", "System");         // min/max range widget
	//editDetails()->page()->addKnob(2, 6, 1, 1, "00", "01", "78", "System"); // ctl4 act range lo
	//editDetails()->page()->addKnob(2, 7, 1, 1, "00", "01", "79", "System"); // ctl4 act range hi
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "03", "System"); 
  
  
  editDetails()->page()->newGroupBox(tr("User Category Names  ***CAUTION*** Settings changes are automatically written to GT-10B"));
  //editDetails()->page()->addLabel(0, 0, 1, 1, "THIS AREA IS STILL UNDER CONSTRUCTION !!");
  editDetails()->page()->addNameEdit(0, 0, 1, 1, "00", "02", "00", "System", "8"); //user catagory #1
  editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
  editDetails()->page()->addNameEdit(0, 2, 1, 1, "00", "02", "08", "System", "8"); //user catagory #2
  editDetails()->page()->addLabel(0, 3, 1, 1, "     ");
  editDetails()->page()->addNameEdit(0, 4, 1, 1, "00", "02", "10", "System", "8"); //user catagory #3
  editDetails()->page()->addLabel(0, 5, 1, 1, "     ");
  editDetails()->page()->addNameEdit(0, 6, 1, 1, "00", "02", "18", "System", "8"); //user catagory #4
  editDetails()->page()->addNameEdit(1, 0, 1, 1, "00", "02", "20", "System", "8"); //user catagory #5
  editDetails()->page()->addNameEdit(1, 2, 1, 1, "00", "02", "28", "System", "8"); //user catagory #6
  editDetails()->page()->addNameEdit(1, 4, 1, 1, "00", "02", "30", "System", "8"); //user catagory #7
  editDetails()->page()->addNameEdit(1, 6, 1, 1, "00", "02", "38", "System", "8"); //user catagory #8
  editDetails()->page()->addNameEdit(2, 2, 1, 1, "00", "02", "40", "System", "8"); //user catagory #9
  editDetails()->page()->addNameEdit(2, 4, 1, 1, "00", "02", "48", "System", "8"); //user catagory #10
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "04", "System"); 
  
  editDetails()->page()->newGroupBox(tr("MANUAL and OD/DS variations  ***CAUTION*** Settings changes are automatically written to GT-10B"));
  editDetails()->page()->newGroupBox("MANUAL settings");
  editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "02", "50", "System"); // manual pedal 1
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "02", "51", "System"); // manual pedal 2
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "02", "52", "System"); // manual pedal 3
	editDetails()->page()->addComboBox(1, 3, 1, 1, "00", "02", "53", "System"); // manual pedal 4
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "02", "55", "System"); // manual bank down
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "02", "54", "System"); // manual bank up
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->newGroupBox("Distortion variations");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "02", "60", "System"); // linedriver
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "02", "61", "System"); // OD
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "02", "62", "System"); // dist
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "02", "63", "System"); // metal
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "02", "64", "System"); // fuzz
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "02", "65", "System"); // special
   editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "05", "System"); 
  
  
  
  ////// PREAMP #1 //////////PREAMP #1 //////////PREAMP #1 //////////PREAMP #1 //////////PREAMP #1 //////////
  editDetails()->page()->addLabel(0, 1, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-10B"));
  editDetails()->page()->newGroupBox("Effect");
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "02", "4D", "System");   // off/on effect
  editDetails()->page()->newStackControl(0);
  editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "02", "4E", "System");       // Type select
  editDetails()->page()->addStackControl();
  editDetails()->page()->addGroupBox(1, 0, 1, 1);	
  
  editDetails()->page()->insertStackField(0, 1, 1, 1, 1);
  
	editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Super Flat");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "15", "System");           // GTR presence
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "5C", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	  // PAGE 1 ABOVE
	 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Flip Top");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "02", "55", "System");       // Mid freq
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "02", "58", "System");       // Response sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "02", "54", "System");         // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");           // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "5C", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 2 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("B-Man");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "02", "55", "System");       // Mid freq
  editDetails()->page()->addSwitch(0, 1, 1, 1, "01", "02", "59", "System");         // Deep
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "5C", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 3 ABOVE
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Concert 810");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addComboBox(1, 2, 1, 1, "01", "02", "55", "System");       // Mid freq
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "02", "54", "System");         // Bright sw
	editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "02", "56", "System");       // Ultra Low
	editDetails()->page()->addSwitch(1, 3, 1, 1, "01", "02", "57", "System");         // Ultra Hi
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "5C", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 4 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Bass 360");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addSwitch(0, 4, 1, 1, "01", "02", "54", "System");         // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "5C", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 5 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("T.E.");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "02", "5A", "System");       // pre shape
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "02", "55", "System");       // Mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "5C", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 6 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Session");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "02", "55", "System");       // Mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "5B", "System");           // Enhancer
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "5C", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 7 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("AC Bass");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "15", "System");           // GTR presence
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "5C", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 8 ABOVE
	
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Clean");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "18", "System");       // gain sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "02", "57", "System");       // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "00", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "00", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "00", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 9 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Crunch");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "18", "System");       // gain sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "02", "57", "System");       // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "00", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "00", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "00", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 10 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "18", "System");       // gain sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "00", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "00", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "00", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 11 ABOVE
	
	editDetails()->page()->newStackField(0);	
	editDetails()->page()->newGroupBox("GTR Metal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "4F", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "02", "50", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "02", "51", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "52", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "18", "System");       // gain sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "00", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "53", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "00", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "00", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 4, 1, 2, "01", "00", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "02", "5D", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "02", "5E", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "00", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "02", "5F", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	//editDetails()->page()->addGroupBox(0, 0, 1, 1);
	// PAGE 12 ABOVE  
	editDetails()->addPage("00", "00", "01", "06", "System"); 
	
	
	 ////// PREAMP #2 //////////PREAMP #2 //////////PREAMP #2 //////////PREAMP #2 //////////PREAMP #2 //////////
  editDetails()->page()->addLabel(0, 1, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-10B"));
  editDetails()->page()->newGroupBox("Effect");
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "03", "00", "System");   // off/on effect
  editDetails()->page()->newStackControl(0);
  editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "03", "01", "System");       // Type select
  editDetails()->page()->addStackControl();
  editDetails()->page()->addGroupBox(1, 0, 1, 1);	
 
  editDetails()->page()->insertStackField(0, 1, 1, 1, 1);
  
	editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Super Flat");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "01", "15", "System");           // GTR presence
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "03", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	  // PAGE 1 ABOVE
	 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Flip Top");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "03", "08", "System");       // Mid freq
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "03", "0B", "System");       // Response sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "03", "07", "System");         // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");           // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "03", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 2 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("B-Man");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "03", "08", "System");       // Mid freq
  editDetails()->page()->addSwitch(0, 1, 1, 1, "01", "03", "0C", "System");         // Deep
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "03", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 3 ABOVE
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Concert 810");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addComboBox(1, 2, 1, 1, "01", "03", "08", "System");       // Mid freq
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "03", "07", "System");         // Bright sw
	editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "03", "09", "System");       // Ultra Low
	editDetails()->page()->addSwitch(1, 3, 1, 1, "01", "03", "0A", "System");         // Ultra Hi
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "03", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 4 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Bass 360");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addSwitch(0, 4, 1, 1, "01", "03", "07", "System");         // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "03", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 5 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("T.E.");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "03", "0D", "System");       // pre shape
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "03", "08", "System");       // Mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "03", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 6 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Session");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "03", "08", "System");       // Mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "0E", "System");           // Enhancer
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "03", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 7 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("AC Bass");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "15", "System");           // GTR presence
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "03", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 8 ABOVE
	
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Clean");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "01", "18", "System");       // gain sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "03", "07", "System");       // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "01", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "01", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "01", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "01", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "01", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 9 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Crunch");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "01", "18", "System");       // gain sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "03", "07", "System");       // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "01", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "01", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "01", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "01", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "01", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 10 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "01", "18", "System");       // gain sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "01", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "01", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "01", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "01", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "01", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 11 ABOVE
	
	editDetails()->page()->newStackField(0);	
	editDetails()->page()->newGroupBox("GTR Metal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "03", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "03", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "03", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "01", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "01", "18", "System");       // gain sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "01", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "01", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "03", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "01", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "01", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 4, 1, 2, "01", "01", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "03", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "03", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "01", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "03", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
//	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	// PAGE 12 ABOVE   
	editDetails()->addPage("00", "00", "01", "07", "System");   
	
	
	 ////// PREAMP #3 //////////PREAMP #3 //////////PREAMP #3 //////////PREAMP #3 //////////PREAMP #3 //////////
	editDetails()->page()->addLabel(0, 1, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-10B"));
  editDetails()->page()->newGroupBox("Effect");
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "04", "00", "System");   // off/on effect
  editDetails()->page()->newStackControl(0);
  editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "04", "01", "System");       // Type select
  editDetails()->page()->addStackControl();
  editDetails()->page()->addGroupBox(1, 0, 1, 1);	
 
  editDetails()->page()->insertStackField(0, 1, 1, 1, 1);
  
	editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Super Flat");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "02", "15", "System");           // GTR presence
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "04", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	  // PAGE 1 ABOVE
	 
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Flip Top");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "04", "08", "System");       // Mid freq
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "04", "0B", "System");       // Response sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "04", "07", "System");         // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");           // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "04", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 2 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("B-Man");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "04", "08", "System");       // Mid freq
  editDetails()->page()->addSwitch(0, 1, 1, 1, "01", "04", "0C", "System");         // Deep
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "04", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 3 ABOVE
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Concert 810");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addComboBox(1, 2, 1, 1, "01", "04", "08", "System");       // Mid freq
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "04", "07", "System");         // Bright sw
	editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "04", "09", "System");       // Ultra Low
	editDetails()->page()->addSwitch(1, 3, 1, 1, "01", "04", "0A", "System");         // Ultra Hi
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "04", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 4 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Bass 360");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addSwitch(0, 4, 1, 1, "01", "04", "07", "System");         // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "04", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 5 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("T.E.");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "04", "0D", "System");       // pre shape
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "04", "08", "System");       // Mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "04", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 6 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Session");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addComboBox(0, 3, 1, 1, "01", "04", "08", "System");       // Mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "0E", "System");           // Enhancer
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "04", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 7 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("AC Bass");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "15", "System");           // GTR presence
	editDetails()->page()->addGroupBox(0, 0, 1, 2);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "04", "0F", "System");       // Bass Spkr type
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 8 ABOVE
	
	
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Clean");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "02", "18", "System");       // gain sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "04", "07", "System");       // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "02", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "02", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "02", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 9 ABOVE
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Crunch");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "02", "18", "System");       // gain sw
	editDetails()->page()->addSwitch(1, 4, 1, 1, "01", "04", "07", "System");       // Bright sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "02", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "02", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "02", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 10 ABOVE
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("GTR Drive");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "02", "18", "System");       // gain sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "02", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "02", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 5, 1, 1, "01", "02", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	// PAGE 11 ABOVE
	
	editDetails()->page()->newStackField(0);	
	editDetails()->page()->newGroupBox("GTR Metal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "02", "System");  // gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "04", "03", "System");           //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "04", "04", "System");           // mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "04", "05", "System");           // treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "02", "15", "System");           // GTR presence
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "02", "18", "System");       // gain sw
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SOLO");
	editDetails()->page()->addSwitch(1, 0, 1, 1, "01", "02", "19", "System");         // solo sw
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "02", "1A", "System");           // solo level
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Level");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "04", "06", "System");     // effect level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);  
	editDetails()->page()->newGroupBox("Speaker Cabinet");
	editDetails()->page()->addComboBox(0, 0, 1, 2, "01", "02", "1B", "System");       // GTR spkr type
	editDetails()->page()->addComboBox(0, 2, 1, 2, "01", "02", "1C", "System");       // mic type
	editDetails()->page()->addComboBox(0, 4, 1, 2, "01", "02", "1D", "System");       // mic distance
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "04", "10", "System");           // mic position
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "04", "11", "System");           // mic level
	editDetails()->page()->addKnob(0, 8, 1, 1, "01", "02", "16", "System");           // Bottom level
	editDetails()->page()->addKnob(0, 9, 1, 1, "01", "04", "12", "System");           // GTR direct
	editDetails()->page()->addGroupBox(1, 0, 1, 3);  
	editDetails()->page()->addStackField();
	//editDetails()->page()->addGroupBox(0, 0, 3, 1);
	// PAGE 12 ABOVE   
	editDetails()->addPage("00", "00", "01", "08", "System");   
	
	
	editDetails()->addPage(); 



};
