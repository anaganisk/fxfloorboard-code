/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-6BFxFloorBoard".
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
  //setLSB("0B", "00");
	setEditPages();
};

void menuPage_system::updateSignal()
{

};

void menuPage_system::setEditPages()
{
  editDetails()->page()->addLabel(0, 0, 1, 1, "***CAUTION*** Settings changes are automatically written to GT-6B");
  editDetails()->page()->newGroupBox("Global");
  editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "00", "System02"); // lcd contrast
  editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "05", "System02"); // dial function 
	editDetails()->page()->addLabel(0, 3, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "00", "06", "System02"); // knob mode
	editDetails()->page()->addLabel(0, 5, 1, 1, "     ");
  editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "09", "System02"); // DGT level
	
	editDetails()->page()->addLabel(1, 0, 1, 1, "     ");
	editDetails()->page()->addComboBox(1, 1, 1, 1, "01", "00", "04", "System02"); // exp pedal hold
	editDetails()->page()->addLabel(1, 2, 1, 1, "     ");
	editDetails()->page()->addComboBox(1, 3, 1, 1, "01", "00", "07", "System02"); // sub ctl1
	editDetails()->page()->addLabel(1, 4, 1, 1, "     ");
	editDetails()->page()->addComboBox(1, 5, 1, 1, "01", "00", "08", "System02"); // sub ctl2
	
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	
	editDetails()->page()->newGroupBox("Tuner");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "00", "System00"); // tuner pitch
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	      
	editDetails()->page()->newGroupBox("Patch Change");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "03", "System02"); // patch change mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "01", "System02"); // bank extent 
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "02", "System02"); // patch select mode
	editDetails()->page()->addGroupBox(3, 1, 1, 1);

	editDetails()->page()->newGroupBox("NS and Reverb");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "00", "System02"); // NS threshold
	editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
  editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "01", "System02"); // revberb level
	editDetails()->page()->addGroupBox(3, 0, 1, 1);
	
  editDetails()->addPage("1A", "00", "01", "00");


	
	editDetails()->page()->newGroupBox("System Midi  ***CAUTION*** Settings changes are automatically written to GT-6B");
	
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "00", "System02"); // rx channel
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "01", "System02"); // omni mode
	editDetails()->page()->addComboBox(2, 0, 1, 1, "02", "00", "02", "System02"); // tx channel
	editDetails()->page()->addComboBox(3, 0, 1, 1, "02", "00", "03", "System02"); // sync clock
	editDetails()->page()->addComboBox(4, 0, 1, 1, "02", "00", "04", "System02"); // pc out
	editDetails()->page()->addComboBox(5, 0, 1, 1, "02", "00", "0A", "System02"); // map select
	editDetails()->page()->addLabel(0, 1, 1, 1, "                   ");	
	editDetails()->page()->addComboBox(0, 2, 1, 1, "02", "00", "05", "System02"); // exp out
	editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "00", "06", "System02"); // exp sw out
	editDetails()->page()->addComboBox(2, 2, 1, 1, "02", "00", "07", "System02"); // ctl out
	editDetails()->page()->addComboBox(3, 2, 1, 1, "02", "00", "08", "System02"); // sub ctl1 out
	editDetails()->page()->addComboBox(4, 2, 1, 1, "02", "00", "09", "System02"); // sub ctl2 out
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("1A", "00", "01", "01");
   
  editDetails()->page()->addLabel(0, 0, 1, 1, "***CAUTION*** Settings changes are automatically written to GT-6B");
	editDetails()->page()->newGroupBox("Custom Distortion 1");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "00", "00", "System02"); // dist type
  editDetails()->page()->addKnob(0, 1, 1, 1, "07", "00", "01", "System02"); // bottom
  editDetails()->page()->addKnob(0, 2, 1, 1, "07", "00", "02", "System02"); // top
  editDetails()->page()->addKnob(0, 3, 1, 1, "07", "00", "03", "System02"); // low
  editDetails()->page()->addKnob(0, 4, 1, 1, "07", "00", "04", "System02"); // high
  editDetails()->page()->addGroupBox(1, 0, 1, 2);
  
  editDetails()->page()->newGroupBox("Custom Distortion 2");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "07", "01", "00", "System02"); // dist type
  editDetails()->page()->addKnob(0, 1, 1, 1, "07", "01", "01", "System02"); // bottom
  editDetails()->page()->addKnob(0, 2, 1, 1, "07", "01", "02", "System02"); // top
  editDetails()->page()->addKnob(0, 3, 1, 1, "07", "01", "03", "System02"); // low
  editDetails()->page()->addKnob(0, 4, 1, 1, "07", "01", "04", "System02"); // high
  editDetails()->page()->addGroupBox(2, 0, 1, 2);
  editDetails()->addPage("1A", "00", "01", "02");
  
   editDetails()->page()->addLabel(0, 0, 1, 1, "***CAUTION*** Settings changes are automatically written to GT-6");
	editDetails()->page()->newGroupBox("Custom Wah 1");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "08", "00", "00", "System02"); // wah type
  editDetails()->page()->addKnob(0, 1, 1, 1, "08", "00", "01", "System02"); // Q
  editDetails()->page()->addKnob(0, 2, 1, 1, "08", "00", "02", "System02"); // range low
  editDetails()->page()->addKnob(0, 3, 1, 1, "08", "00", "03", "System02"); // range high
  editDetails()->page()->addKnob(0, 4, 1, 1, "08", "00", "04", "System02"); // presence
  editDetails()->page()->addGroupBox(1, 0, 1, 2);
  
  editDetails()->page()->newGroupBox("Custom Wah 2");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "08", "01", "00", "System02"); // wah type
  editDetails()->page()->addKnob(0, 1, 1, 1, "08", "01", "01", "System02"); // Q
  editDetails()->page()->addKnob(0, 2, 1, 1, "08", "01", "02", "System02"); // range low
  editDetails()->page()->addKnob(0, 3, 1, 1, "08", "01", "03", "System02"); // range high
  editDetails()->page()->addKnob(0, 4, 1, 1, "08", "01", "04", "System02"); // presence
  editDetails()->page()->addGroupBox(2, 0, 1, 2);
	editDetails()->addPage("1A", "00", "01", "03");
};
