/****************************************************************************
**
** Copyright (C) 2008 Colin Willcocks
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-6FxFloorBoard".
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
  editDetails()->page()->addLabel(0, 0, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-6"));
  editDetails()->page()->newGroupBox("settings");
  editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "00", "System02"); // lcd contrast
  editDetails()->page()->addLabel(0, 1, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "06", "System02"); // pedal tuner sw
	editDetails()->page()->addLabel(0, 3, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "00", "03", "System02"); //exp hold
	editDetails()->page()->addLabel(0, 5, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 6, 1, 1, "01", "00", "05", "System02"); // knob mode
	editDetails()->page()->addLabel(0, 7, 1, 1, "     ");
	editDetails()->page()->addComboBox(0, 8, 1, 1, "01", "00", "04", "System02"); // dial function 
	editDetails()->page()->addComboBox(1, 2, 1, 1, "01", "00", "07", "System02"); // amp switch
	editDetails()->page()->addComboBox(1, 4, 1, 1, "01", "00", "08", "System02"); // sub ctl1
	editDetails()->page()->addComboBox(1, 6, 1, 1, "01", "00", "09", "System02"); // sub ctl2
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	
	editDetails()->page()->newGroupBox("Tuner");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "00", "System00"); // tuner pitch
	editDetails()->page()->addLabel(0, 1, 1, 1, "               ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "01", "System00"); //tuner bypass
	editDetails()->page()->addGroupBox(2, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Patch Change");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "02", "System02"); // patch change mode
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "01", "System02"); // bank extent 
	editDetails()->page()->addGroupBox(3, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("Output select");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "00", "System01"); // output select
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Global E.Q and NS/Reverb");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "00", "System02"); // eq low
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "01", "System02"); // eq high
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "02", "System02"); // NS threshold
  editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "03", "System02"); // revberb level
	editDetails()->page()->addGroupBox(3, 0, 1, 1);
	
  editDetails()->addPage("19", "00", "01", "00");


	
	editDetails()->page()->newGroupBox(tr("System Midi  ***CAUTION*** Settings changes are automatically written to GT-6"));
	
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "00", "System02"); // rx channel
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "01", "System02"); // omni mode
	editDetails()->page()->addComboBox(2, 0, 1, 1, "02", "00", "02", "System02"); // tx channel
	editDetails()->page()->addComboBox(3, 0, 1, 1, "02", "00", "04", "System02"); // pc out
	editDetails()->page()->addComboBox(4, 0, 1, 1, "02", "00", "0A", "System02"); // map select
		
	editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "05", "System02"); // exp1 out
	editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "00", "06", "System02"); // exp sw out
	editDetails()->page()->addComboBox(2, 1, 1, 1, "02", "00", "07", "System02"); // ctl out
	editDetails()->page()->addComboBox(3, 1, 1, 1, "02", "00", "08", "System02"); // sub ctl1 out
	editDetails()->page()->addComboBox(4, 1, 1, 1, "02", "00", "09", "System02"); // sub ctl2 out
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("19", "00", "01", "01");
  
  editDetails()->page()->newGroupBox(tr("MANUAL settings  ***CAUTION*** Settings changes are automatically written to GT-6"));
  editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "00", "System03"); // manual pedal 1
	editDetails()->page()->addComboBox(1, 1, 1, 1, "00", "00", "01", "System03"); // manual pedal 2
	editDetails()->page()->addComboBox(1, 2, 1, 1, "00", "00", "02", "System03"); // manual pedal 3
	editDetails()->page()->addComboBox(1, 3, 1, 1, "00", "00", "03", "System03"); // manual pedal 4
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "04", "System03"); // manual bank down
	editDetails()->page()->addComboBox(0, 3, 1, 1, "00", "00", "05", "System03"); // manual bank up
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->addPage("19", "00", "01", "02");
  

  
	editDetails()->addPage();
	
};
