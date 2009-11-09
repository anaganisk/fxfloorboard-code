/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-6 Fx FloorBoard".
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
  setLSB("0F", "00");
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
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0F", "00", "00");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->newGroupBox("Assign 2");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "10", "00", "00");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->newGroupBox("Assign 3");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "11", "00", "00");
	editDetails()->page()->addGroupBox(0, 3, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "12", "00", "00");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->newGroupBox("Assign 5");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "13", "00", "00");
	editDetails()->page()->addGroupBox(0, 5, 1, 1);
	editDetails()->page()->newGroupBox("Assign 6");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "14", "00", "00");
	editDetails()->page()->addGroupBox(0, 6, 1, 1);
	editDetails()->page()->newGroupBox("Assign 7");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "15", "00", "00");
	editDetails()->page()->addGroupBox(0, 7, 1, 1);
	editDetails()->page()->newGroupBox("Assign 8");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "16", "00", "00");
	editDetails()->page()->addGroupBox(0, 8, 1, 1);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage();

  editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Assign 1 Target");
	editDetails()->page()->addTarget(0, 0, 1, 4, "0F", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 1 Source");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0F", "00", "08");                    // Source
  editDetails()->page()->addComboBox(1, 0, 1, 1, "0F", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 2, 1, 2, "0F", "00", "0A", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(0, 2, 1, 1, "0F", "00", "0A");                        // Active Range High
	//editDetails()->page()->addKnob(0, 3, 1, 1, "0F", "00", "0B");                        // Active Range Low
  editDetails()->page()->addGroupBox(1, 0, 1, 1); 
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 2 Target");
	editDetails()->page()->addTarget(0, 0, 1, 4, "10", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 2 Source");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "10", "00", "08");                    // Source
  editDetails()->page()->addComboBox(1, 0, 1, 1, "10", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 2, 1, 2, "10", "00", "0A", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(0, 2, 1, 1, "10", "00", "0A");                        // Active Range High
	//editDetails()->page()->addKnob(0, 3, 1, 1, "10", "00", "0B");                        // Active Range Low
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 3 Target");
	editDetails()->page()->addTarget(0, 0, 1, 4, "11", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 3 Source");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "11", "00", "08");                    // Source
  editDetails()->page()->addComboBox(1, 0, 1, 1, "11", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 2, 1, 2, "11", "00", "0A", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(0, 2, 1, 1, "11", "00", "0A");                        // Active Range High
	//editDetails()->page()->addKnob(0, 3, 1, 1, "11", "00", "0B");                        // Active Range Low
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
editDetails()->page()->newGroupBox("Assign 4 Target");
	editDetails()->page()->addTarget(0, 0, 1, 4, "12", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4 Source");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "12", "00", "08");                    // Source
  editDetails()->page()->addComboBox(1, 0, 1, 1, "12", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 2, 1, 2, "12", "00", "0A", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(0, 2, 1, 1, "12", "00", "0A");                        // Active Range High
	//editDetails()->page()->addKnob(0, 3, 1, 1, "12", "00", "0B");                        // Active Range Low
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 5 Target");
	editDetails()->page()->addTarget(0, 0, 1, 4, "13", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 5 Source");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "13", "00", "08");                    // Source
  editDetails()->page()->addComboBox(1, 0, 1, 1, "13", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 2, 1, 2, "13", "00", "0A", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(0, 2, 1, 1, "13", "00", "0A");                        // Active Range High
	//editDetails()->page()->addKnob(0, 3, 1, 1, "13", "00", "0B");                        // Active Range Low
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();


	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 6 Target");
	editDetails()->page()->addTarget(0, 0, 1, 4, "14", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 6 Source");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "14", "00", "08");                    // Source
  editDetails()->page()->addComboBox(1, 0, 1, 1, "14", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 2, 1, 2, "14", "00", "0A", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(0, 2, 1, 1, "14", "00", "0A");                        // Active Range High
	//editDetails()->page()->addKnob(0, 3, 1, 1, "14", "00", "0B");                        // Active Range Low
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 7 Target");
	editDetails()->page()->addTarget(0, 0, 1, 4, "15", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 7 Source");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "15", "00", "08");                    // Source
  editDetails()->page()->addComboBox(1, 0, 1, 1, "15", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 2, 1, 2, "15", "00", "0A", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(0, 2, 1, 1, "15", "00", "0A");                        // Active Range High
	//editDetails()->page()->addKnob(0, 3, 1, 1, "15", "00", "0B");                        // Active Range Low
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addStackField();


	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Assign 8 Target");
	editDetails()->page()->addTarget(0, 0, 1, 4, "16", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 8 Source");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "16", "00", "08");                    // Source
  editDetails()->page()->addComboBox(1, 0, 1, 1, "16", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(0, 2, 1, 2, "16", "00", "0A", "Structure");         // min/max range widget
	//editDetails()->page()->addKnob(0, 2, 1, 1, "16", "00", "0A");                        // Active Range High
	//editDetails()->page()->addKnob(0, 3, 1, 1, "16", "00", "0B");                        // Active Range Low
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->page()->addStackField();
};
