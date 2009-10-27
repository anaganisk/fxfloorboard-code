/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. 
** All rights reserved.
**
** This file is part of "GT-Pro Fx FloorBoard".
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
  setLSB("30", "00");
	setEditPages();
};

void menuPage_system::updateSignal()
{

};

void menuPage_system::setEditPages()
{
  editDetails()->page()->addLabel(0, 0, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-Pro"));     
  editDetails()->page()->newGroupBox(tr("SYSTEM SETTINGS"));
  editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "00", "System01"); // lcd contrast
  editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "09", "System01"); // knob mode
  editDetails()->page()->addComboBox(2, 0, 1, 1, "02", "00", "08", "System01"); // assign hold
  editDetails()->page()->addComboBox(3, 0, 1, 1, "02", "00", "12", "System01"); // cc#1 func 
  
  editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "0B", "System01"); // ctl1 func    
	editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "00", "0C", "System01"); // ctl2 func 
	editDetails()->page()->addComboBox(2, 1, 1, 1, "02", "00", "0E", "System01"); // ctl3 func 
	editDetails()->page()->addComboBox(3, 1, 1, 1, "02", "00", "0F", "System01"); // ctl4 func 
			
	editDetails()->page()->addComboBox(0, 2, 1, 1, "02", "00", "0A", "System01"); // exp1 func	
	editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "00", "0D", "System01"); // exp2 func 	
	editDetails()->page()->addComboBox(2, 2, 1, 1, "02", "00", "10", "System01"); // cc#7 func 
	editDetails()->page()->addComboBox(3, 2, 1, 1, "02", "00", "11", "System01"); // cc#80 func 
 	editDetails()->page()->addGroupBox(1, 0, 1, 2);
 	
 	editDetails()->page()->newGroupBox("LEVEL METER");
 	editDetails()->page()->addComboBox(0, 0, 1, 1, "05", "00", "00", "System01"); // 
 	editDetails()->page()->addGroupBox(1, 2, 1, 1);
	                                                    
	editDetails()->page()->newGroupBox("TUNER");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "00", "System00"); // tuner pitch
	editDetails()->page()->addLabel(0, 1, 1, 1, "            ");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "01", "System00"); //tuner bypass
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	                                        
	editDetails()->page()->newGroupBox("PATCH CHANGE");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "04", "System01"); // patch change mode
	//editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "06", "System01"); // patch extent 
	editDetails()->page()->addGroupBox(2, 1, 1, 2);
	editDetails()->addPage("30", "00", "01", "00");                                       
    
  
  editDetails()->page()->addLabel(0, 0, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-Pro"));                       
  
	editDetails()->page()->newGroupBox("LOOP Levels");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "15", "System01"); // loop1/2 send level
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "16", "System01"); // loop1/2 return level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	                                                         
	editDetails()->page()->newGroupBox("Global NS and Reverb");	
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "05", "System01"); // NS threshold
  editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "06", "System01"); // reverb level  
	editDetails()->page()->addGroupBox(0, 1, 1, 1);                 
	                              	
	editDetails()->page()->newGroupBox("FC-200 Control");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "17", "System01"); // fc200 ctl mode
	editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "18", "System01"); // fc200 ctl pedal
	editDetails()->page()->addComboBox(0, 2, 1, 1, "02", "00", "19", "System01"); // fc200 bank limit
  editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "00", "1A", "System01"); //  fc200 pc out
  editDetails()->page()->addComboBox(0, 4, 1, 1, "02", "00", "1B", "System01"); //  fc200 bank change
  editDetails()->page()->addGroupBox(1, 0, 1, 2);
  
  editDetails()->page()->newGroupBox("USB/DGT");
  editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "0E", "System01"); //  USB/DGT output level
  editDetails()->page()->addComboBox(0, 1, 1, 1, "00", "00", "0F", "System01"); // USB mix channel
  editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "10", "System01"); //  USB/DGT mix level
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "1C", "System01"); // USB monitor cmd
	editDetails()->page()->addComboBox(1, 1, 1, 1, "02", "00", "1D", "System01"); //  USB direct monitor
	editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "00", "1E", "System01"); //  USB driver mode
	editDetails()->page()->addComboBox(1, 3, 1, 1, "00", "00", "0D", "System01"); //  USB/DGT output channel
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	
  editDetails()->addPage("30", "00", "01", "01");


  editDetails()->page()->addLabel(0, 0, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-Pro"));                       
  
  editDetails()->page()->newGroupBox("Output Channel");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "0C", "System01"); // output channel 
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  
  editDetails()->page()->newGroupBox("INPUT");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "01", "System01"); // input select
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "02", "System01"); // input level 
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "03", "System01"); // input presence
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
   
  editDetails()->page()->newGroupBox("Main Output");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "00", "System01"); // main output select
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "13", "System01"); // main output level
  editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "01", "System01"); // eq low    
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "02", "System01"); // eq mid
  editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "03", "System01"); // eq freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "00", "00", "04", "System01"); // eq high
	editDetails()->page()->addGroupBox(2, 0, 1, 2);
	
	editDetails()->page()->newGroupBox("Sub Output");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "07", "System01"); // sub output select
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "14", "System01"); // sub output level
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "08", "System01"); // sub eq low 
  editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "09", "System01"); // sub eq mid
  editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "0A", "System01"); // sub eq mid freq
  editDetails()->page()->addKnob(0, 5, 1, 1, "00", "00", "0B", "System01"); // sub eq high
	editDetails()->page()->addGroupBox(3, 0, 1, 2);
  
  editDetails()->addPage("30", "00", "01", "02");
                      

	editDetails()->page()->addLabel(0, 0, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-Pro"));
	editDetails()->page()->newGroupBox("System Midi");	            
	editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "20", "00", "System01"); // rx channel
	editDetails()->page()->addComboBox(1, 0, 1, 1, "04", "20", "01", "System01"); // omni mode
	editDetails()->page()->addComboBox(2, 0, 1, 1, "04", "20", "02", "System01"); // tx channel
	editDetails()->page()->addComboBox(3, 0, 1, 1, "04", "20", "03", "System01"); // device ID
	editDetails()->page()->addComboBox(4, 0, 1, 1, "04", "20", "04", "System01"); // sync clock
	editDetails()->page()->addComboBox(5, 0, 1, 1, "04", "20", "05", "System01"); //  pc out
	editDetails()->page()->addLabel(0, 1, 1, 1, "                             ");
			
	editDetails()->page()->addComboBox(0, 2, 1, 1, "04", "20", "06", "System01"); // exp1 out
	editDetails()->page()->addComboBox(1, 2, 1, 1, "04", "20", "07", "System01"); // ctrl1 out
	editDetails()->page()->addComboBox(2, 2, 1, 1, "04", "20", "08", "System01"); // ctl2 out
	editDetails()->page()->addComboBox(3, 2, 1, 1, "04", "20", "09", "System01"); // exp2/ctl3 out
	editDetails()->page()->addComboBox(4, 2, 1, 1, "04", "20", "0A", "System01"); // ctl4 out
	editDetails()->page()->addComboBox(5, 2, 1, 1, "04", "20", "0B", "System01"); // map select      
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->addPage("30", "00", "01", "03");
  
  editDetails()->page()->addLabel(0, 0, 1, 1, tr("***CAUTION*** Settings changes are automatically written to GT-Pro"));
  editDetails()->page()->newGroupBox("MANUAL MODE settings");
  editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "00", "System02"); // manual pedal 1
  editDetails()->page()->addLabel(1, 0, 1, 1, "           ");
	editDetails()->page()->addComboBox(2, 0, 1, 1, "01", "00", "01", "System02"); // manual pedal 2
	editDetails()->page()->addLabel(3, 0, 1, 1, "           ");
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "00", "02", "System02"); // manual pedal 3
	editDetails()->page()->addLabel(5, 0, 1, 1, "           ");
	editDetails()->page()->addComboBox(6, 0, 1, 1, "01", "00", "03", "System02"); // manual pedal 4
	editDetails()->page()->addLabel(7, 0, 1, 1, "           ");
	editDetails()->page()->addComboBox(8, 0, 1, 1, "01", "00", "04", "System02"); // manual pedal 5
	editDetails()->page()->addLabel(0, 1, 1, 1, "           ");
	
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "05", "System02"); // manual pedal 6
	editDetails()->page()->addLabel(1, 2, 1, 1, "           ");
	editDetails()->page()->addComboBox(2, 2, 1, 1, "01", "00", "06", "System02"); // manual pedal 7
	editDetails()->page()->addLabel(3, 2, 1, 1, "           ");
	editDetails()->page()->addComboBox(4, 2, 1, 1, "01", "00", "07", "System02"); // manual pedal 8
	editDetails()->page()->addLabel(5, 2, 1, 1, "           ");
	editDetails()->page()->addComboBox(6, 2, 1, 1, "01", "00", "08", "System02"); // manual pedal 9
	editDetails()->page()->addLabel(7, 2, 1, 1, "           ");
	editDetails()->page()->addComboBox(8, 2, 1, 1, "01", "00", "09", "System02"); // manual pedal 10
	editDetails()->page()->addLabel(0, 3, 1, 1, "           ");
	
	editDetails()->page()->addComboBox(0, 4, 1, 1, "01", "00", "0A", "System02"); // manual bank up
	editDetails()->page()->addComboBox(8, 4, 1, 1, "01", "00", "0B", "System02"); // manual bank down     
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->addPage("30", "00", "01", "04");
  
};




