/****************************************************************************
**
** Copyright (C) 2008 Colin Willcocks
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-8FxFloorBoard".
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
  setImage(":/images/assigns_pushbutton.png");
  setLSB("16", "00");
	setEditPages();
};

void menuPage_assign::updateSignal()
{

};

void menuPage_assign::setEditPages()
{
	editDetails()->page()->newGroupBox("Assigns");
	editDetails()->page()->newGroupBox("Assign 1-8");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "1D", "00", "01");	
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 1");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "16", "00", "00");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Assign 2");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "17", "00", "00");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->newGroupBox("Assign 3");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "18", "00", "00");
	editDetails()->page()->addGroupBox(0, 3, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "19", "00", "00");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->newGroupBox("Assign 5");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "1A", "00", "00");
	editDetails()->page()->addGroupBox(0, 5, 1, 1);
	editDetails()->page()->newGroupBox("Assign 6");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "1B", "00", "00");
	editDetails()->page()->addGroupBox(0, 6, 1, 1);
	editDetails()->page()->newGroupBox("Assign 7");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "1C", "00", "00");
	editDetails()->page()->addGroupBox(0, 7, 1, 1);
	editDetails()->page()->newGroupBox("Assign 8");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "1D", "00", "00");
	editDetails()->page()->addGroupBox(0, 8, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("     ");
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);	
	editDetails()->addPage();

 
  editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Assign 1 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "16", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 1 Source");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "16", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "16", "00", "09");                    // Source Mode
	editDetails()->page()->addRange(0, 1, 1, 2, "16", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(1, 1, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Assign 1 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "16", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "16", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "16", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Assign 1 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "16", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "16", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
	
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 2 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "17", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 2 Source");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "17", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "17", "00", "09");                    // Source Mode
	editDetails()->page()->addRange(0, 1, 1, 2, "17", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(2, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Assign 2 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "17", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "17", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "17", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Assign 2 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "17", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "17", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 3 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "18", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 3 Source");
	editDetails()->page()->newStackControl(3);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "18", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "18", "00", "09");                    // Source Mode
	editDetails()->page()->addRange(0, 1, 1, 2, "18", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(3, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Assign 3 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "18", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "18", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "18", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Assign 3 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "18", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "18", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 4 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "19", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4 Source");
	editDetails()->page()->newStackControl(4);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "19", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "19", "00", "09");                    // Source Mode
	editDetails()->page()->addRange(0, 1, 1, 2, "19", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(4, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Assign 4 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "19", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "19", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "19", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Assign 4 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "19", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "19", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 5 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "1A", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 5 Source");
	editDetails()->page()->newStackControl(5);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "1A", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "1A", "00", "09");                    // Source Mode
	editDetails()->page()->addRange(0, 1, 1, 2, "1A", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(5, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Assign 5 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "1A", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "1A", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "1A", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Assign 5 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "1A", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "1A", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 6 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "1B", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 6 Source");
	editDetails()->page()->newStackControl(6);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "1B", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "1B", "00", "09");                    // Source Mode
	editDetails()->page()->addRange(0, 1, 1, 2, "1B", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(6, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Assign 6 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "1B", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "1B", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "1B", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Assign 6 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "1B", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "1B", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 7 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "1C", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 7 Source");
	editDetails()->page()->newStackControl(7);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "1C", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "1C", "00", "09");                    // Source Mode
	editDetails()->page()->addRange(0, 1, 1, 2, "1C", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(7, 1, 0, 1, 2);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Assign 7 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "1C", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "1C", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "1C", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Assign 7 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "1C", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "1C", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();
  
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 8 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "1D", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 8 Source");
	editDetails()->page()->newStackControl(8);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "1D", "00", "08");                    // Source
	editDetails()->page()->addStackControl();
  editDetails()->page()->addComboBox(1, 0, 1, 1, "1D", "00", "09");                    // Source Mode
	editDetails()->page()->addRange(0, 1, 1, 2, "1D", "00", "0A", "Structure");         // min/max range widget
  editDetails()->page()->addGroupBox(0, 1, 1, 1);
  editDetails()->page()->insertStackField(8, 1, 0, 1, 2);
  editDetails()->page()->addStackField();
  
  
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Assign 8 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "1D", "00", "0C");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(0, 1, 1, 1, "1D", "00", "0D");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 2, 1, 1, "1D", "00", "0E");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Assign 8 Wave Pedal");
	editDetails()->page()->addKnob(1, 0, 1, 1, "1D", "00", "0F", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 1, 1, 1, "1D", "00", "10");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "1E", "00", "00", "normal","right", 85);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);	
  editDetails()->page()->addStackField();

};
