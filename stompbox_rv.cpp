/****************************************************************************
**
** Copyright (C) 2006~2010 Colin Willcocks.
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

#include "stompbox_rv.h"
 
stompbox_rv::stompbox_rv(QWidget *parent)
    : stompBox(parent)
{
	/* REVERB */
	setImage(":/images/rv.png");
	setLSB("04", "00");
	setKnob1("04", "00", "14");
	setKnob2("04", "00", "15");
	setComboBox("04", "00", "12");
	setButton("04", "00", "10");
	editDetails()->patchPos(240, 46, "04", "00");
	setEditPages();
};

void stompbox_rv::updateSignal()
{
	updateKnob1("04", "00", "14");
	updateKnob2("04", "00", "15");
	updateComboBox("04", "00", "12");
	updateButton("04", "00", "10");
};


void stompbox_rv::setEditPages()
{
	editDetails()->page()->newGroupBox("Spkr Sim Effect");
	editDetails()->page()->addSwitch(0, 1, 1, 1, "04", "00", "10", "middle", Qt::AlignCenter);       //on/off
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Speaker");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "04", "00", "12");     //type
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "13");         //mic setting
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	/*editDetails()->page()->newGroupBox("Pre-Amp to Speaker Link");
	editDetails()->page()->addComboBox(0, 2, 1, 1, "04", "00", "16");     //link
	editDetails()->page()->addGroupBox(1, 2, 1, 1);  */


    editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "14", "turbo");//mic level
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "15", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage();  // PAGE 1 ABOVE

	
};
