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

#include "menuPage_midi.h"

menuPage_midi::menuPage_midi(QWidget *parent)
    : menuPage(parent)
{
  setImage(":/images/system_pushbutton.png");
  //setLSB("0B", "00");
	setEditPages();
};

void menuPage_midi::updateSignal()
{

};

void menuPage_midi::setEditPages()
{ 
  editDetails()->page()->newGroupBox(tr("Master"));
  editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "03");   // effect level
  editDetails()->page()->addKnob(0, 1, 1, 1, "09", "00", "04");   // master bpm
  editDetails()->page()->addComboBox(0, 2, 1, 1, "09", "00", "06");  // bypass routing
  editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->newGroupBox(tr("Manual"));
  editDetails()->page()->addKnob(0, 0, 1, 1, "0F", "00", "00");   //  pedal 1
  editDetails()->page()->addKnob(0, 1, 1, 1, "0F", "00", "01");   //  pedal 2
  editDetails()->page()->addKnob(0, 2, 1, 1, "0F", "00", "02");   //  pedal 3
  editDetails()->page()->addKnob(0, 3, 1, 1, "0F", "00", "03");   //  pedal 4
  editDetails()->page()->addGroupBox(1, 0, 1, 1);
  editDetails()->addPage();
};
