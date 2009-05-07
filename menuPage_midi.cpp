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
  setLSB("0B", "00");
	setEditPages();
};

void menuPage_midi::updateSignal()
{

};

void menuPage_midi::setEditPages()
{
	editDetails()->page()->newGroupBox("System Midi area still under Construction.");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage();
};
