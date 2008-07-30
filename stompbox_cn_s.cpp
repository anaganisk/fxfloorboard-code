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

#include "stompbox_cn_s.h"

stompbox_cn_s::stompbox_cn_s(QWidget *parent)
    : stompBox(parent)
{
	/* CHAIN SPLIT */
	this->setImage(":/images/cn_s.png");
	setLSB("0A", "00");
	setComboBox("0A", "00", "6A", QRect(8, 78, 79, 13));
	setEditPages();
};
void stompbox_cn_s::updateSignal()
{
	updateComboBox("0A", "00", "6A");
};

void stompbox_cn_s::setEditPages()
{
  editDetails()->page()->newGroupBox("External Amp Switching");
	editDetails()->page()->addComboBox(0, 1, 1, 1, "0A", "00", "69"); // External Amp control
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Channel");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "6A"); // Channel Mode
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(0, 1, 0, 1, 1);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "6B");     // Channel A level
	editDetails()->page()->addKnob(0, 2, 1, 1, "0A", "00", "6C");     // Channel B Level
	editDetails()->page()->addComboBox(0, 3, 1, 1, "0A", "00", "6D");  // Channel Select A/B
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "6B");     // Channel A level
	editDetails()->page()->addKnob(0, 2, 1, 1, "0A", "00", "6C");     // Channel B Level
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "6B");     // Channel A level
	editDetails()->page()->addKnob(0, 2, 1, 1, "0A", "00", "6C");     // Channel B Level
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "6B");     // Channel A level
	editDetails()->page()->addKnob(0, 2, 1, 1, "0A", "00", "6C");     // Channel B Level
	editDetails()->page()->addComboBox(0, 3, 1, 1, "0A", "00", "6E");  // X-over Frequency
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "6B");     // Channel A level
	editDetails()->page()->addKnob(0, 2, 1, 1, "0A", "00", "6C");     // Channel B Level
	editDetails()->page()->addKnob(0, 3, 1, 1, "0A", "00", "6F");    // sensitivity
	editDetails()->page()->addKnob(0, 4, 1, 1, "0A", "00", "70");      // release
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "6B");     // Channel A level
	editDetails()->page()->addKnob(0, 2, 1, 1, "0A", "00", "6C");     // Channel B Level
	editDetails()->page()->addKnob(0, 3, 1, 1, "0A", "00", "6F");    // sensitivity
	editDetails()->page()->addKnob(0, 4, 1, 1, "0A", "00", "70");      // release
	editDetails()->page()->addStackField();
	
	    
	editDetails()->addPage();	
};
