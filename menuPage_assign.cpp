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

#include "menuPage_assign.h"

menuPage_assign::menuPage_assign(QWidget *parent)
    : menuPage(parent)
{
  setImage(":/images/system_pushbutton.png");
  setLSB("03", "00");
  editDetails()->patchPos(260, 114, "03", "00");
  setEditPages();
};

void menuPage_assign::updateSignal()
{

};

void menuPage_assign::setEditPages()
{
        editDetails()->page()->newGroupBox(tr("Assigns"));
	      editDetails()->page()->newGroupBox(tr("Assign 1-8"));
        editDetails()->page()->newStackControl(0);
        editDetails()->page()->addComboBox(0, 0, 1, 1, "19", "00", "00");
        editDetails()->page()->addStackControl();
        editDetails()->page()->addGroupBox(0, 0, 1, 1);
	      editDetails()->page()->newGroupBox("Assign 1");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00");
	      editDetails()->page()->addGroupBox(0, 1, 1, 1);
	      editDetails()->page()->newGroupBox("Assign 2");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00");
	      editDetails()->page()->addGroupBox(0, 2, 1, 1);
	      editDetails()->page()->newGroupBox("Assign 3");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00");
	      editDetails()->page()->addGroupBox(0, 3, 1, 1);
	      editDetails()->page()->newGroupBox("Assign 4");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00");
	      editDetails()->page()->addGroupBox(0, 4, 1, 1);
	      editDetails()->page()->newGroupBox("Assign 5");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00");
	      editDetails()->page()->addGroupBox(0, 5, 1, 1);
	      editDetails()->page()->newGroupBox("Assign 6");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00");
	      editDetails()->page()->addGroupBox(0, 6, 1, 1);
	      editDetails()->page()->newGroupBox("Assign 7");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00");
	      editDetails()->page()->addGroupBox(0, 7, 1, 1);
	      editDetails()->page()->newGroupBox("Assign 8");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00");
	      editDetails()->page()->addGroupBox(0, 8, 1, 1);
	
	      editDetails()->page()->addGroupBox(0, 0, 1, 1);
	      editDetails()->page()->newGroupBox("");
	      editDetails()->page()->addLabel(0, 0, 1, 1, "                             ");
        editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
        editDetails()->page()->addGroupBox(1, 0, 1, 1);
	      editDetails()->addPage();


        editDetails()->page()->newStackField(0);
        editDetails()->page()->newGroupBox("Assign 1");
        editDetails()->page()->addTarget(0, 0, 1, 3, "03", "00", "0E", "target","10", "12"); // Target
        editDetails()->page()->newStackControl(1);
        editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "14");                    // Source
        editDetails()->page()->addStackControl();
	      editDetails()->page()->addLabel(1, 1, 1, 1, "          ");
        editDetails()->page()->addComboBox(1, 1, 1, 1, "03", "00", "15");                    // Source Mode
        editDetails()->page()->addRange(0, 3, 1, 2, "03", "00", "16", "Structure");         // min/max range widget
	      editDetails()->page()->addGroupBox(1, 0, 1, 1);
        editDetails()->page()->insertStackField(1, 1, 2, 1, 1);
        editDetails()->page()->addStackField();
	
        //editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
        editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
        editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
        editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
        editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
        editDetails()->page()->newStackField(1);
        editDetails()->page()->newGroupBox("Assign 1 Internal Pedal");
        //editDetails()->page()->addComboBox(0, 0, 1, 1, "03" "00", "18");                    // Internal Pedal Trigger
        editDetails()->page()->addKnob(2, 0, 1, 1, "03", "00", "19");                        // Internal Pedal Time
        editDetails()->page()->addComboBox(4, 0, 1, 1, "03", "00", "1A");                    // Internal Pedal Curve
	      editDetails()->page()->addGroupBox(0, 0, 3, 1);
        editDetails()->page()->addStackField();
        editDetails()->page()->newStackField(1);
        editDetails()->page()->newGroupBox("Assign 1 Wave Pedal");
        editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "1B", "normal","right", 105);// Wave Form Rate
        editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "1C");                    // Wave Form
	      editDetails()->page()->addGroupBox(0, 0, 3, 1);
        editDetails()->page()->addStackField();
        editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 2");
	editDetails()->page()->addTarget(0, 0, 1, 3, "03", "00", "1E", "target","20", "22"); // Target
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "24");                    // Source
	editDetails()->page()->addStackControl();
	editDetails()->page()->addLabel(1, 1, 1, 1, "          ");
  editDetails()->page()->addComboBox(1, 1, 1, 1, "03", "00", "25");                    // Source Mode
  editDetails()->page()->addRange(0, 3, 1, 2, "03", "00", "26", "Structure");         // min/max range widget
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->insertStackField(2, 1, 2, 1, 1);
	editDetails()->page()->addStackField();
	
        //editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Assign 2 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "28");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "29");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(2, 0, 1, 1, "03", "00", "2A");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
  editDetails()->page()->newGroupBox("Assign 2 Wave Pedal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "2B", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "2C");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 3");
	editDetails()->page()->addTarget(0, 0, 1, 3, "03", "00", "2E", "target","30", "32"); // Target
	editDetails()->page()->newStackControl(3);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "34");                    // Source
	editDetails()->page()->addStackControl();
	editDetails()->page()->addLabel(1, 1, 1, 1, "          ");
  editDetails()->page()->addComboBox(1, 1, 1, 1, "03", "00", "35");                    // Source Mode
  editDetails()->page()->addRange(0, 3, 1, 2, "03", "00", "36", "Structure");         // min/max range widget
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->insertStackField(3, 1, 2, 1, 1);
	editDetails()->page()->addStackField();
	
        //editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Assign 3 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "38");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "39");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(2, 0, 1, 1, "03", "00", "3A");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);
  editDetails()->page()->newGroupBox("Assign 3 Wave Pedal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "3B", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "3C");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(3);editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 4");
	editDetails()->page()->addTarget(0, 0, 1, 3, "03", "00", "3E", "target","40", "42"); // Target
	editDetails()->page()->newStackControl(4);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "44");                    // Source
	editDetails()->page()->addStackControl();
	editDetails()->page()->addLabel(1, 1, 1, 1, "          ");
  editDetails()->page()->addComboBox(1, 1, 1, 1, "03", "00", "45");                    // Source Mode
  editDetails()->page()->addRange(0, 3, 1, 2, "03", "00", "46", "Structure");         // min/max range widget
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->insertStackField(4, 1, 2, 1, 1);
	editDetails()->page()->addStackField();
	
        //editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Assign 4 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "48");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "49");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(2, 0, 1, 1, "03", "00", "4A");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(4);
  editDetails()->page()->newGroupBox("Assign 4 Wave Pedal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "4B", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "4C");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(4);editDetails()->page()->addStackField();
  
		
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 5");
	editDetails()->page()->addTarget(0, 0, 1, 3, "03", "00", "4E", "target","50", "52"); // Target
	editDetails()->page()->newStackControl(5);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "54");                    // Source
	editDetails()->page()->addStackControl();
	editDetails()->page()->addLabel(1, 1, 1, 1, "          ");
  editDetails()->page()->addComboBox(1, 1, 1, 1, "03", "00", "55");                    // Source Mode
  editDetails()->page()->addRange(0, 3, 1, 2, "03", "00", "56", "Structure");         // min/max range widget
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->insertStackField(5, 1, 2, 1, 1);
	editDetails()->page()->addStackField();
	
        //editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Assign 5 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "58");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "59");                        // Internal Pedal Time
        editDetails()->page()->addComboBox(2, 0, 1, 1, "03", "00", "5A");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);
  editDetails()->page()->newGroupBox("Assign 5 Wave Pedal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "5B", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "5C");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(5);editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 6");
	editDetails()->page()->addTarget(0, 0, 1, 3, "03", "00", "5E", "target","60", "62"); // Target
	editDetails()->page()->newStackControl(6);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "64");                    // Source
	editDetails()->page()->addStackControl();
	editDetails()->page()->addLabel(1, 1, 1, 1, "          ");
  editDetails()->page()->addComboBox(1, 1, 1, 1, "03", "00", "65");                    // Source Mode
  editDetails()->page()->addRange(0, 3, 1, 2, "03", "00", "66", "Structure");         // min/max range widget
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->insertStackField(6, 1, 2, 1, 1);
	editDetails()->page()->addStackField();
	
  //editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Assign 6 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "68");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "69");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(2, 0, 1, 1, "03", "00", "6A");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);
  editDetails()->page()->newGroupBox("Assign 6 Wave Pedal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "6B", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "6C");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(6);editDetails()->page()->addStackField();
	  

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 7");
	editDetails()->page()->addTarget(0, 0, 1, 3, "03", "00", "6E", "target","70", "72"); // Target
	editDetails()->page()->newStackControl(7);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "74");                    // Source
	editDetails()->page()->addStackControl();
	editDetails()->page()->addLabel(1, 1, 1, 1, "          ");
  editDetails()->page()->addComboBox(1, 1, 1, 1, "03", "00", "75");                    // Source Mode
  editDetails()->page()->addRange(0, 3, 1, 2, "03", "00", "76", "Structure");         // min/max range widget
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->insertStackField(7, 1, 2, 1, 1);
	editDetails()->page()->addStackField();
	
        //editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Assign 7 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "03", "00", "78");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(1, 0, 1, 1, "03", "00", "79");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(2, 0, 1, 1, "03", "00", "7A");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);
  editDetails()->page()->newGroupBox("Assign 7 Wave Pedal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "7B", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 0, 1, 1, "03", "00", "7C");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(7);editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 8");
	editDetails()->page()->addTarget(0, 0, 1, 3, "03", "00", "7E", "target","00", "02"); // Target
	editDetails()->page()->newStackControl(8);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "04", "00", "04");                    // Source
	editDetails()->page()->addStackControl();
	editDetails()->page()->addLabel(1, 1, 1, 1, "          ");
  editDetails()->page()->addComboBox(1, 1, 1, 1, "04", "00", "05");                    // Source Mode
  editDetails()->page()->addRange(0, 3, 1, 2, "04", "00", "06", "Structure");         // min/max range widget
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->insertStackField(8, 1, 2, 1, 1);
  editDetails()->page()->addStackField();
  
  //editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Assign 8 Internal Pedal");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "08");                    // Internal Pedal Trigger
  editDetails()->page()->addKnob(1, 0, 1, 1, "04", "00", "09");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(2, 0, 1, 1, "04", "00", "0A");                    // Internal Pedal Curve
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);
  editDetails()->page()->newGroupBox("Assign 8 Wave Pedal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0B", "normal","right", 105);// Wave Form Rate
	editDetails()->page()->addComboBox(1, 0, 1, 1, "04", "00", "0C");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(8);editDetails()->page()->addStackField();
  
};
