/****************************************************************************
**
** Copyright (C) 2008 Colin Willcocks
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-10BFxFloorBoard".
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

#include "menuPage_midi.h"

menuPage_midi::menuPage_midi(QWidget *parent)
    : menuPage(parent)
{
  setImage(":/images/midi_pushbutton.png");
  //setLSB("0B", "00");
	setEditPages();
};

void menuPage_midi::updateSignal()
{

};

void menuPage_midi::setEditPages()
{
  editDetails()->page()->newGroupBox("System Midi area still under Construction.");
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
	editDetails()->addPage();

 

};
