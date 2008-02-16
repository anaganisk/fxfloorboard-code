/****************************************************************************
**
** Copyright (C) 2005-2006 Uco Mesdag. All rights reserved.
**
** This file is part of "GT6B FX FloorBoard".
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

#include "stompbox_eq.h"

stompbox_eq::stompbox_eq(QWidget *parent)
    : stompBox(parent)
{
	/* EQ */
	setImage(":/images/eq.png");
  setLSB("04", "00");
	setSlider1("04", "00", "02");
	setSlider2("04", "00", "05");
	setSlider3("04", "00", "08");
	setSlider4("04", "00", "09");
	setSlider5("04", "00", "0A");
	setButton("04", "00", "00"); 
	setEditPages();
};

void stompbox_eq::updateSignal()
{
	updateSlider1("04", "00", "02");
	updateSlider2("04", "00", "05");
	updateSlider3("04", "00", "08");
	updateSlider4("04", "00", "09");
	updateSlider5("04", "00", "0A");
	updateButton("04", "00", "00");
};

void stompbox_eq::setEditPages()
{
    editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "04", "00", "00", "middle", Qt::AlignCenter);        //on/off
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

	editDetails()->page()->newGroupBox("Low EQ");
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "02", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	
	editDetails()->page()->newGroupBox("Low Mid EQ");
	editDetails()->page()->addKnob(2, 0, 1, 1, "04", "00", "04", "turbo"); //Q
	editDetails()->page()->addKnob(2, 1, 1, 1, "04", "00", "03");          //freq
	editDetails()->page()->addKnob(2, 2, 1, 1, "04", "00", "05", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 1, 1, 1);
	
	editDetails()->page()->newGroupBox("High Mid EQ");
	editDetails()->page()->addKnob(1, 0, 1, 1, "04", "00", "07", "turbo"); //Q
	editDetails()->page()->addKnob(1, 1, 1, 1, "04", "00", "06");          //freq
	editDetails()->page()->addKnob(1, 2, 1, 1, "04", "00", "08", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 2, 1, 1);
	
	
	editDetails()->page()->newGroupBox("High EQ");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "09", "turbo"); //level
	editDetails()->page()->addGroupBox(0, 3, 1, 1);

	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "0A");          //level
	
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage();  // PAGE 1 ABOVE 


};
