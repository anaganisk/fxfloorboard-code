/****************************************************************************
**
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

#include "stompbox_ns.h"

stompbox_ns::stompbox_ns(QWidget *parent)
    : stompBox(parent)
{
	/* NS */
	setImage(":/images/ns.png");
	setLSB("0A", "00");
	setKnob1("0A", "00", "72");
	setKnob2("0A", "00", "73");
	setButton("0A", "00", "71");
	setEditPages();
};

void stompbox_ns::updateSignal()
{
	updateKnob1("0A", "00", "72");
	updateKnob2("0A", "00", "73");
	updateButton("0A", "00", "71");
};

void stompbox_ns::setEditPages()
{
   editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0A", "00", "71");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0A", "00", "74");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->page()->newGroupBox("Noise Suppressor");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0A", "00", "72");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "73");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->addPage();	
};
