/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-10 Fx FloorBoard".
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

#include "stompbox_pdl.h"

stompbox_pdl::stompbox_pdl(QWidget *parent)
    : stompBox(parent)
{
	/* PDL */ 
	setImage(":/images/pdl.png");
	setLSB("0A", "00");
	setComboBox("0A", "00", "45");
	setButton("0A", "00", "40", QPoint::QPoint(0, 110), ":/images/pedal.png");
	setEditPages();
};

void stompbox_pdl::updateSignal()
{
	updateComboBox("0A", "00", "45");
	updateButton("0A", "00", "40");
};

void stompbox_pdl::setEditPages()
{
  editDetails()->page()->newGroupBox("Pedal FX");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0A", "00", "40");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "0A", "00", "45");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(2, 0, 1, 1, "0A", "00", "46");
	editDetails()->page()->addComboBox(3, 0, 1, 1, "0A", "00", "47");
	editDetails()->page()->addComboBox(4, 0, 1, 1, "0A", "00", "48");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

  editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
  
  editDetails()->page()->newStackField(0);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Foot Volume");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "5D");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "5B");
	editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "5C");
	editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "5A");
	editDetails()->page()->addGroupBox(0, 1, 3, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pedal Bend");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "54");
	editDetails()->page()->addKnob(2, 0, 1, 1, "0A", "00", "57");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "56");
	editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "55");
	editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "58");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	editDetails()->page()->addStackField();
  
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Wah");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "49");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "4B");
	editDetails()->page()->addKnob(2, 0, 1, 1, "0A", "00", "4D");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "4A");
	editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "4C");
	editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "4E");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->insertStackField(1, 0, 2, 1, 3);
  editDetails()->page()->addStackField();
  
  editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Pedal Bend");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "54");
	editDetails()->page()->addKnob(2, 0, 1, 1, "0A", "00", "57");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "56");
	editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "55");
	editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "58");
	editDetails()->page()->addGroupBox(0, 2, 1, 1);	
	editDetails()->page()->newGroupBox("Foot Volume");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "5D");
	editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "5B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "5A");
	editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "5C");
	editDetails()->page()->addGroupBox(0, 4, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Wah");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "49");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "4B");
	editDetails()->page()->addKnob(2, 0, 1, 1, "0A", "00", "4D");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "4A");
	editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "4C");
	editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "4E");
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	editDetails()->page()->insertStackField(2, 0, 2, 1, 3);
	editDetails()->page()->newGroupBox("Foot Volume");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "5D");
	editDetails()->page()->addKnob(2, 1, 1, 1, "0A", "00", "5B");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "5A");
	editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "5C");
	editDetails()->page()->addGroupBox(0, 5, 1, 1);
	editDetails()->page()->addStackField();
	
	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
	editDetails()->page()->newGroupBox("Custom Wah");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "4F");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "50");
	editDetails()->page()->addKnob(2, 0, 1, 1, "0A", "00", "51");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "52");
	editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "53");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(2);
	editDetails()->page()->newGroupBox("Custom Wah");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0A", "00", "4F");
	editDetails()->page()->addKnob(1, 0, 1, 1, "0A", "00", "50");
	editDetails()->page()->addKnob(2, 0, 1, 1, "0A", "00", "51");
	editDetails()->page()->addKnob(0, 1, 1, 1, "0A", "00", "52");
	editDetails()->page()->addKnob(1, 1, 1, 1, "0A", "00", "53");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->addPage();	
};
