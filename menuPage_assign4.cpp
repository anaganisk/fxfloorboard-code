/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** All rights reserved.
** This file is part of "GT-6B Fx FloorBoard".
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

#include "menuPage_assign4.h"

menuPage_assign4::menuPage_assign4(QWidget *parent)
    : menuPage(parent)
{
  setLSB("13", "00");
  editDetails()->patchPos(1148, 26, "13", "00");   
  setEditPages();
};

void menuPage_assign4::updateSignal()
{

};

void menuPage_assign4::setEditPages()
{
  editDetails()->page()->newGroupBox("Assign 4");
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "13", "00", "00");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->newGroupBox("Assign 4 Target");
	editDetails()->page()->addTarget(0, 0, 1, 3, "13", "00", "02", "target", "04", "06"); // Target
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Assign 4 Source");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "13", "00", "08");                    // Source
  editDetails()->page()->addComboBox(1, 1, 1, 1, "13", "00", "09");                    // Source Mode
  editDetails()->page()->addRange(1, 2, 1, 2, "13", "00", "0A", "Structure");         // min/max range widget
	editDetails()->page()->addGroupBox(2, 0, 1, 1); 
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage();
};
