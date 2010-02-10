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

#include "stompbox_rv.h"
 
stompbox_rv::stompbox_rv(QWidget *parent)
    : stompBox(parent)
{
	/* REVERB */
	setImage(":/images/rv.png"); 
        setLSB("02", "00");
	setKnob1("02", "00", "25");
	setKnob2("02", "00", "2A");
	setComboBox("02", "00", "24");
        setButton("00", "00", "00");
        editDetails()->patchPos(222, 7, "02", "00");
	setEditPages();
};

void stompbox_rv::updateSignal()
{
        updateKnob1("02", "00", "25");
	updateKnob2("02", "00", "2A");
	updateComboBox("02", "00", "24");
        updateButton("00", "00", "00");
};


void stompbox_rv::setEditPages()
{
        editDetails()->page()->newGroupBox("Effect");
        editDetails()->page()->addSwitch(0, 1, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);  //on/off
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Reverb");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "24");  // type
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "25");      // time
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "26");      // pre delay
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "29");      // density
	editDetails()->page()->addGroupBox(0, 1, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "27");      // hi cut filter
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "28");      // lo cut filter
	editDetails()->page()->addGroupBox(0, 2, 1, 1);


        editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "2A");//effect level
        editDetails()->page()->addGroupBox(0, 3, 1, 1);
	editDetails()->addPage();  // PAGE 1 ABOVE	
};
