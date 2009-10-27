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

#include "menuPage_assign.h"

menuPage_assign::menuPage_assign(QWidget *parent)
    : menuPage(parent)
{
  setImage(":/images/system_pushbutton.png");
  setLSB("20", "00");
  editDetails()->patchPos(1544, 694, "20", "00");
	setEditPages();
};

void menuPage_assign::updateSignal()
{

};

void menuPage_assign::setEditPages()
{
	editDetails()->page()->newGroupBox(tr("Assigns"));
	editDetails()->page()->newGroupBox(tr("Assign 1-12"));
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "30", "00", "00");	
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("1");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "20", "00", "00");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("2");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "21", "00", "00");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->newGroupBox("3");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "22", "00", "00");
	editDetails()->page()->addGroupBox(0, 3, 1, 1);
	editDetails()->page()->newGroupBox("4");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "23", "00", "00");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->newGroupBox("5");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "24", "00", "00");
	editDetails()->page()->addGroupBox(0, 5, 1, 1);
	editDetails()->page()->newGroupBox("6");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "25", "00", "00");
	editDetails()->page()->addGroupBox(0, 6, 1, 1);
	editDetails()->page()->newGroupBox("7");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "26", "00", "00");
	editDetails()->page()->addGroupBox(0, 7, 1, 1);
	editDetails()->page()->newGroupBox("8");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "27", "00", "00");
	editDetails()->page()->addGroupBox(0, 8, 1, 1);
	editDetails()->page()->newGroupBox("9");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "28", "00", "00");
	editDetails()->page()->addGroupBox(0, 9, 1, 1);
	editDetails()->page()->newGroupBox("10");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "29", "00", "00");
	editDetails()->page()->addGroupBox(0, 10, 1, 1);
	editDetails()->page()->newGroupBox("11");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "2A", "00", "00");
	editDetails()->page()->addGroupBox(0, 11, 1, 1);
	editDetails()->page()->newGroupBox("12");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "2B", "00", "00");
	editDetails()->page()->addGroupBox(0, 12, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("     ");
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);	
	editDetails()->addPage();

 
  editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Assign 1 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "20", "00", "02", "target", "04", "06"); // Target   
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 1 Source");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "20", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "20", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "20", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(1, 1, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Assign 1 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "20", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "20", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "20", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Assign 1 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "20", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "20", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 2 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "21", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 2 Source");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "21", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "21", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "21", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(2, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Assign 2 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "21", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "21", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "21", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Assign 2 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "21", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "21", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 3 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "22", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 3 Source");
	editDetails()->page()->newStackControl(3);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "22", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "22", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "22", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(3, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Assign 3 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "22", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "22", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "22", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Assign 3 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "22", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "22", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 4 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "23", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4 Source");
	editDetails()->page()->newStackControl(4);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "23", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "23", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "23", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(4, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Assign 4 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "23", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "23", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "23", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Assign 4 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "23", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "23", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 5 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "24", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 5 Source");
	editDetails()->page()->newStackControl(5);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "24", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "24", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "24", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(5, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Assign 5 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "24", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "24", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "24", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Assign 5 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "24", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "24", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 6 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "25", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 6 Source");
	editDetails()->page()->newStackControl(6);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "25", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "25", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "25", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(6, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Assign 6 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "25", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "25", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "25", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Assign 6 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "25", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "25", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();

  

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 7 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "26", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 7 Source");
	editDetails()->page()->newStackControl(7);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "26", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "26", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "26", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(7, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Assign 7 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "26", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "26", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "26", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Assign 7 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "26", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "26", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();

  
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 8 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "27", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 8 Source");
	editDetails()->page()->newStackControl(8);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "27", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "27", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "27", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(8, 1, 0, 1, 2);
  editDetails()->page()->addStackField();
  
  
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Assign 8 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "27", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "27", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "27", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Assign 8 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "27", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "27", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();

  
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 9 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "28", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 9 Source");
	editDetails()->page()->newStackControl(9);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "28", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "28", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "28", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(9, 1, 0, 1, 2);
  editDetails()->page()->addStackField();
  
  
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);
  editDetails()->page()->newGroupBox("Assign 9 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "28", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "28", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "28", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);
  editDetails()->page()->newGroupBox("Assign 9 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "28", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "28", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(9);editDetails()->page()->addStackField();

  
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 10 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "29", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 10 Source");
	editDetails()->page()->newStackControl(10);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "29", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "29", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "29", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(10, 1, 0, 1, 2);
  editDetails()->page()->addStackField();
  
  
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);
  editDetails()->page()->newGroupBox("Assign 10 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "29", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "29", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "29", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);
  editDetails()->page()->newGroupBox("Assign 10 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "29", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "29", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(10);editDetails()->page()->addStackField();

  
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 11 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "2A", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 11 Source");
	editDetails()->page()->newStackControl(11);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "2A", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "2A", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "2A", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(11, 1, 0, 1, 2);
  editDetails()->page()->addStackField();
  
  
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);
  editDetails()->page()->newGroupBox("Assign 11 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "2A", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "2A", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "2A", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);
  editDetails()->page()->newGroupBox("Assign 11 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "2A", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "2A", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(11);editDetails()->page()->addStackField();

  
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 12 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "2B", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 12 Source");
	editDetails()->page()->newStackControl(12);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "2B", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "2B", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 1, 1, 2, "2B", "00", "0A", "Structure");         // min/max range widget
	  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(12, 1, 0, 1, 2);
  editDetails()->page()->addStackField();
  
  
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);
  editDetails()->page()->newGroupBox("Assign 12 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "2B", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "2B", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "2B", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);
  editDetails()->page()->newGroupBox("Assign 12 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "2B", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "2B", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(12);editDetails()->page()->addStackField();

};
