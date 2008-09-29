/****************************************************************************
**
** Copyright (C) 2008 Colin Willcocks.
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

#include "stompbox_cn_m.h"

stompbox_cn_m::stompbox_cn_m(QWidget *parent)
    : stompBox(parent)
{
	/* CHAIN MERGE */
	this->setImage(":/images/cn_m.png");
	setLSB("0B", "00");
	setEditPages();
};

void stompbox_cn_m::updateSignal()
{
	//updateSwitch("0B", "00", "20");
	//updateButton("0B", "00", "20");
	//updateButton("0B", "00", "30");
};

void stompbox_cn_m::setEditPages()
{
  editDetails()->page()->newGroupBox("Assign 1-8");
  editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0C", "00", "21");	
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	
	editDetails()->page()->newGroupBox("Assigns");
	editDetails()->page()->newGroupBox("Assign 1");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "20");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 2");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "30");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Assign 3");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "40");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "50");
	editDetails()->page()->addGroupBox(0, 3, 1, 1);
	editDetails()->page()->newGroupBox("Assign 5");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "60");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->newGroupBox("Assign 6");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "70");
	editDetails()->page()->addGroupBox(0, 5, 1, 1);
	editDetails()->page()->newGroupBox("Assign 7");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0C", "00", "00");
	editDetails()->page()->addGroupBox(0, 6, 1, 1);
	editDetails()->page()->newGroupBox("Assign 8");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0C", "00", "10");
	editDetails()->page()->addGroupBox(0, 7, 1, 1);
	editDetails()->page()->newGroupBox("Input");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "20");
	editDetails()->page()->addGroupBox(0, 8, 1, 1);	
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage();

  editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Assign 1");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "20");
	editDetails()->page()->addTarget(0, 1, 1, 1, "0B", "00", "21", "normal","target", 120); // Target
	//editDetails()->page()->addTarget(0, 2, 1, 1, "0B", "00", "23", "normal","min", 105);                        // Min
	//editDetails()->page()->addTarget(0, 3, 1, 1, "0B", "00", "25", "normal","max", 105);                        // Max
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "27", "normal","bottom", 105);                        // Source
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "28");                    // Source Mode
	editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "29");                        // Active Range High
	editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "2A");                        // Active Range Low
	editDetails()->page()->addKnob(0, 4, 1, 1, "0B", "00", "2B", "normal","bottom", 105);                        // Internal Pedal Trigger
	editDetails()->page()->addKnob(0, 5, 1, 1, "0B", "00", "2C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 6, 1, 1, "0B", "00", "2D");                    // Internal Pedal Curve
	editDetails()->page()->addKnob(1, 4, 1, 1, "0B", "00", "2E", "normal","bottom", 105);                        // Wave Form Rate
	editDetails()->page()->addComboBox(1, 5, 1, 1, "0B", "00", "2F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 2");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "30");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "31", "normal","bottom", 120); // Target
	editDetails()->page()->addKnob(0, 2, 1, 1, "0B", "00", "33", "normal","bottom", 105);                        // Min
	editDetails()->page()->addKnob(0, 3, 1, 1, "0B", "00", "35", "normal","bottom", 105);                        // Max
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "37", "normal","bottom", 105);                        // Source
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "38");                    // Source Mode
	editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "39");                        // Active Range High
	editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "3A");                        // Active Range Low
	editDetails()->page()->addKnob(0, 4, 1, 1, "0B", "00", "3B", "normal","bottom", 105);                        // Internal Pedal Trigger
	editDetails()->page()->addKnob(0, 5, 1, 1, "0B", "00", "3C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 6, 1, 1, "0B", "00", "3D");                    // Internal Pedal Curve
	editDetails()->page()->addKnob(1, 4, 1, 1, "0B", "00", "3E", "normal","bottom", 105);                        // Wave Form Rate
	editDetails()->page()->addComboBox(1, 5, 1, 1, "0B", "00", "3F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 3");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "40");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "41", "normal","bottom", 120); // Target
	editDetails()->page()->addKnob(0, 2, 1, 1, "0B", "00", "43", "normal","bottom", 105);                        // Min
	editDetails()->page()->addKnob(0, 3, 1, 1, "0B", "00", "45", "normal","bottom", 105);                        // Max
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "47", "normal","bottom", 105);                        // Source
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "48");                    // Source Mode
	editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "49");                        // Active Range High
	editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "4A");                        // Active Range Low
	editDetails()->page()->addKnob(0, 4, 1, 1, "0B", "00", "4B", "normal","bottom", 105);                        // Internal Pedal Trigger
	editDetails()->page()->addKnob(0, 5, 1, 1, "0B", "00", "4C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 6, 1, 1, "0B", "00", "4D");                    // Internal Pedal Curve
	editDetails()->page()->addKnob(1, 4, 1, 1, "0B", "00", "4E", "normal","bottom", 105);                        // Wave Form Rate
	editDetails()->page()->addComboBox(1, 5, 1, 1, "0B", "00", "4F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 4");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "50");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "51", "normal","bottom", 120); // Target
	editDetails()->page()->addKnob(0, 2, 1, 1, "0B", "00", "53", "normal","bottom", 105);                        // Min
	editDetails()->page()->addKnob(0, 3, 1, 1, "0B", "00", "55", "normal","bottom", 105);                        // Max
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "57", "normal","bottom", 105);                        // Source
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "58");                    // Source Mode
	editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "59");                        // Active Range High
	editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "5A");                        // Active Range Low
	editDetails()->page()->addKnob(0, 4, 1, 1, "0B", "00", "5B", "normal","bottom", 105);                        // Internal Pedal Trigger
	editDetails()->page()->addKnob(0, 5, 1, 1, "0B", "00", "5C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 6, 1, 1, "0B", "00", "5D");                    // Internal Pedal Curve
	editDetails()->page()->addKnob(1, 4, 1, 1, "0B", "00", "5E", "normal","bottom", 105);                        // Wave Form Rate
	editDetails()->page()->addComboBox(1, 5, 1, 1, "0B", "00", "5F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 5");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "60");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "61", "normal","bottom", 120); // Target
	editDetails()->page()->addKnob(0, 2, 1, 1, "0B", "00", "63", "normal","bottom", 105);                        // Min
	editDetails()->page()->addKnob(0, 3, 1, 1, "0B", "00", "65", "normal","bottom", 105);                        // Max
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "67", "normal","bottom", 105);                        // Source
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "68");                    // Source Mode
	editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "69");                        // Active Range High
	editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "6A");                        // Active Range Low
	editDetails()->page()->addKnob(0, 4, 1, 1, "0B", "00", "6B", "normal","bottom", 105);                        // Internal Pedal Trigger
	editDetails()->page()->addKnob(0, 5, 1, 1, "0B", "00", "6C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 6, 1, 1, "0B", "00", "6D");                    // Internal Pedal Curve
	editDetails()->page()->addKnob(1, 4, 1, 1, "0B", "00", "6E", "normal","bottom", 105);                        // Wave Form Rate
	editDetails()->page()->addComboBox(1, 5, 1, 1, "0B", "00", "6F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 6");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "0B", "00", "70");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0B", "00", "71", "normal","bottom", 120); // Target
	editDetails()->page()->addKnob(0, 2, 1, 1, "0B", "00", "73", "normal","bottom", 105);                        // Min
	editDetails()->page()->addKnob(0, 3, 1, 1, "0B", "00", "75", "normal","bottom", 105);                        // Max
	editDetails()->page()->addKnob(1, 0, 1, 1, "0B", "00", "77", "normal","bottom", 105);                        // Source
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0B", "00", "78");                    // Source Mode
	editDetails()->page()->addKnob(1, 2, 1, 1, "0B", "00", "79");                        // Active Range High
	editDetails()->page()->addKnob(1, 3, 1, 1, "0B", "00", "7A");                        // Active Range Low
	editDetails()->page()->addKnob(0, 4, 1, 1, "0B", "00", "7B", "normal","bottom", 105);                        // Internal Pedal Trigger
	editDetails()->page()->addKnob(0, 5, 1, 1, "0B", "00", "7C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 6, 1, 1, "0B", "00", "7D");                    // Internal Pedal Curve
	editDetails()->page()->addKnob(1, 4, 1, 1, "0B", "00", "7E", "normal","bottom", 105);                        // Wave Form Rate
	editDetails()->page()->addComboBox(1, 5, 1, 1, "0B", "00", "7F");                    // Wave Form	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 7");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "0C", "00", "00");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0C", "00", "01", "normal","bottom", 120); // Target
	editDetails()->page()->addKnob(0, 2, 1, 1, "0C", "00", "03", "normal","bottom", 105);                        // Min
	editDetails()->page()->addKnob(0, 3, 1, 1, "0C", "00", "05", "normal","bottom", 105);                        // Max
	editDetails()->page()->addKnob(1, 0, 1, 1, "0C", "00", "07", "normal","bottom", 105);                        // Source
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0C", "00", "08");                    // Source Mode
	editDetails()->page()->addKnob(1, 2, 1, 1, "0C", "00", "09");                        // Active Range High
	editDetails()->page()->addKnob(1, 3, 1, 1, "0C", "00", "0A");                        // Active Range Low
	editDetails()->page()->addKnob(0, 4, 1, 1, "0C", "00", "0B", "normal","bottom", 105);                        // Internal Pedal Trigger
	editDetails()->page()->addKnob(0, 5, 1, 1, "0C", "00", "0C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 6, 1, 1, "0C", "00", "0D");                    // Internal Pedal Curve
	editDetails()->page()->addKnob(1, 4, 1, 1, "0C", "00", "0E", "normal","bottom", 105);                        // Wave Form Rate
	editDetails()->page()->addComboBox(1, 5, 1, 1, "0C", "00", "0F");                    // Wave Form
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 8");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "0C", "00", "10");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0C", "00", "11", "normal","bottom", 120); // Target
	editDetails()->page()->addKnob(0, 2, 1, 1, "0C", "00", "13", "normal","bottom", 105);                        // Min
	editDetails()->page()->addKnob(0, 3, 1, 1, "0C", "00", "15", "normal","bottom", 105);                        // Max
	editDetails()->page()->addKnob(1, 0, 1, 1, "0C", "00", "17", "normal","bottom", 105);                        // Source
	editDetails()->page()->addComboBox(1, 1, 1, 1, "0C", "00", "18");                    // Source Mode
	editDetails()->page()->addKnob(1, 2, 1, 1, "0C", "00", "19");                        // Active Range High
	editDetails()->page()->addKnob(1, 3, 1, 1, "0C", "00", "1A");                        // Active Range Low
	editDetails()->page()->addKnob(0, 4, 1, 1, "0C", "00", "1B", "normal","bottom", 105);                        // Internal Pedal Trigger
	editDetails()->page()->addKnob(0, 5, 1, 1, "0C", "00", "1C");                        // Internal Pedal Time
	editDetails()->page()->addComboBox(0, 6, 1, 1, "0C", "00", "1D");                    // Internal Pedal Curve
	editDetails()->page()->addKnob(1, 4, 1, 1, "0C", "00", "1E", "normal","bottom", 105);                        // Wave Form Rate
	editDetails()->page()->addComboBox(1, 5, 1, 1, "0C", "00", "1F");                    // Wave Form	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();


	
};
