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

#include "stompbox_speaker.h"

stompbox_speaker::stompbox_speaker(QWidget *parent)
    : stompBox(parent)
{
	/* PRE  */
	setImage(":/images/speaker.png");
        setLSB("00", "00");
	setKnob1("01", "00", "2E");
	setKnob2("01", "00", "2F");
	setComboBox("01", "00", "2C");
        setButton("00", "00", "00");
        editDetails()->patchPos(90, 4, "01", "00");
	setEditPages();
};

void stompbox_speaker::updateSignal()
{
  updateKnob1("01", "00", "2E");
	updateKnob2("01", "00", "2F");
	updateComboBox("01", "00", "2C");
  updateButton("00", "00", "00");
};

void stompbox_speaker::setEditPages()
{
  editDetails()->page()->newGroupBox("Speaker Cabinet Simulator");

  editDetails()->page()->newGroupBox("Cabinet Type");
  editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "2C");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Cabinet Setting");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "2D");     //mic set
	editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "2E", "turbo");// mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "2F", "turbo");//direct level
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	editDetails()->addPage();		
};
