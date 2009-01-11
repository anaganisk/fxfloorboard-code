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
  setImage(":/images/system_pushbutton.png");
  setLSB("00", "00");
	setEditPages();
};

void menuPage_system::updateSignal()
{

};

void menuPage_system::setEditPages()
{

	editDetails()->page()->newGroupBox("Systems Area still under Construction");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "00", "System"); // lcd contrast
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "10", "System"); // preamp mode
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "11", "System"); // patch change mode
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "00", "12", "System"); // bank change mode
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "13", "System"); // bank extent min
	editDetails()->page()->addKnob(0, 5, 1, 1, "00", "00", "15", "System"); // bank extent max
	editDetails()->page()->addComboBox(0, 6, 1, 1, "00", "00", "17", "System"); //exp hold
	editDetails()->page()->addComboBox(0, 7, 1, 1, "00", "00", "18", "System"); //exp indication
	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "20", "System"); //usb driver mode
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "00", "21", "System"); //usb monitor cmd
	editDetails()->page()->addKnob(1, 2, 1, 1, "00", "00", "22", "System"); //dgt out level
	editDetails()->page()->addKnob(1, 3, 1, 1, "00", "00", "23", "System"); //usb mix level
	editDetails()->page()->addComboBox(1, 4, 1, 1, "00", "00", "30", "System"); // tuner pitch
	editDetails()->page()->addComboBox(1, 5, 1, 1, "00", "00", "31", "System"); //tuner bypass
	
	editDetails()->page()->addKnob(2, 0, 1, 1, "00", "00", "40", "System"); // gat 1 input level
	editDetails()->page()->addKnob(2, 1, 1, 1, "00", "00", "41", "System"); // gat 1 input pres
	editDetails()->page()->addKnob(2, 2, 1, 1, "00", "00", "42", "System"); // gat 2 input level
	editDetails()->page()->addKnob(2, 3, 1, 1, "00", "00", "43", "System"); // gat 2 input pres
	editDetails()->page()->addKnob(2, 4, 1, 1, "00", "00", "44", "System"); // gat 3 input level
	editDetails()->page()->addKnob(2, 5, 1, 1, "00", "00", "45", "System"); // gat 3 input pres
	editDetails()->page()->addKnob(2, 6, 1, 1, "00", "00", "46", "System"); // usb input level
	editDetails()->page()->addKnob(2, 7, 1, 1, "00", "00", "47", "System"); // usb input pres
	editDetails()->page()->addKnob(2, 8, 1, 1, "00", "00", "52", "System"); // main out
	
	editDetails()->page()->addKnob(3, 0, 1, 1, "00", "00", "48", "System"); // eq low
  editDetails()->page()->addKnob(3, 1, 1, 1, "00", "00", "49", "System"); // eq mid
  editDetails()->page()->addKnob(3, 2, 1, 1, "00", "00", "4A", "System"); // eq mid
  editDetails()->page()->addKnob(3, 3, 1, 1, "00", "00", "4B", "System"); // eq mid
  editDetails()->page()->addKnob(3, 4, 1, 1, "00", "00", "4C", "System"); // eq high
  editDetails()->page()->addComboBox(3, 5, 1, 1, "00", "00", "4D", "System"); // input select
  editDetails()->page()->addComboBox(3, 6, 1, 1, "00", "00", "4E", "System"); // output mode
  editDetails()->page()->addComboBox(3, 7, 1, 1, "00", "00", "4F", "System"); // output select
  editDetails()->page()->addKnob(3, 8, 1, 1, "00", "00", "50", "System"); // NS threshold
  editDetails()->page()->addKnob(3, 9, 1, 1, "00", "00", "51", "System"); // revberb level
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "00", "System");
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "10");
	
	editDetails()->page()->newGroupBox("Systems Area still under Construction");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "52", "System"); // main out mode
	editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "53", "System"); // sub out mode 
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "54", "System"); // sub out level
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "00", "60", "System"); // PH LOOP mode
	editDetails()->page()->addComboBox(0, 4, 1, 1, "00", "00", "61", "System"); // record mode
	editDetails()->page()->addComboBox(0, 5, 1, 1, "00", "00", "62", "System"); // pedal mode
	editDetails()->page()->addComboBox(0, 6, 1, 1, "00", "00", "63", "System"); // clear pdl
	editDetails()->page()->addKnob(0, 7, 1, 1, "00", "00", "64", "System"); // play level 
	
	
	editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "70", "System"); // sys num pdl ctrl
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "00", "71", "System"); // dial function
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "00", "72", "System"); // knob P1
	editDetails()->page()->addComboBox(1, 3, 1, 1, "00", "00", "74", "System"); // knob P2
	editDetails()->page()->addComboBox(1, 4, 1, 1, "00", "00", "76", "System"); // knob P3
	editDetails()->page()->addComboBox(1, 5, 1, 1, "00", "00", "78", "System"); // knob P4
	
	editDetails()->page()->addComboBox(2, 0, 1, 1, "00", "00", "7A", "System"); //  exp1 pdl
	editDetails()->page()->addComboBox(2, 1, 1, 1, "00", "00", "7B", "System"); // exp1 pdl sw
	editDetails()->page()->addComboBox(2, 2, 1, 1, "00", "00", "7C", "System"); // ctrl 1
	editDetails()->page()->addComboBox(2, 3, 1, 1, "00", "00", "7D", "System"); // ctrl 2
	editDetails()->page()->addComboBox(2, 4, 1, 1, "00", "00", "7E", "System"); // exp2 pdl
	editDetails()->page()->addComboBox(2, 5, 1, 1, "00", "00", "7F", "System"); // ctrl 3
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "01", "System");
	
	editDetails()->page()->newGroupBox("Systems Area still under Construction");
	//editDetails()->page()->addKnob(0, 0, 1, 1, "00", "03", "60", "System"); // ctrl 4
	
	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("00", "00", "01", "02", "System");
	
	
	editDetails()->addPage();

};
