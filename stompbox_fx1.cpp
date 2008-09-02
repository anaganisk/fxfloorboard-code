/****************************************************************************
**
** Copyright (C) 2005-2006 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-3 FX FloorBoard".
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
** 51 Franklin Street, Fifth Floor, Boston, MA 0210C-1301 USA.
**
****************************************************************************/

#include "stompbox_fx1.h"

stompbox_fx1::stompbox_fx1(QWidget *parent)
    : stompBox(parent)
{
	/* FX1 */
	setImage(":/images/fx1.png");
	setLSB("00", "00");
	setComboBox("00", "00", "01", QRect(8, 31, 79, 13));
	setButton("00", "00", "00");
	setEditPages();
};

void stompbox_fx1::updateSignal()
{
	updateComboBox("00", "00", "01");
	updateButton("00", "00", "00");
};

void stompbox_fx1::setEditPages()
{
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "01");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("AC");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "02", "turbo");  //ac top
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "03", "turbo");   //ac body
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "04", "turbo");   //ac level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "01", "00");   //combo selection address
	  // PAGE 1 ABOVE

	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "01");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("SG");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "05");
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "06");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "01", "01");  // PAGE 2 ABOVE

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "01");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("AFB");
	editDetails()->page()->addKnob(0, 0, 1, 1, "00", "00", "07");  //afb freq
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "08");  //afb depth
	editDetails()->page()->addComboBox(0, 2, 1, 1, "00", "00", "09");   //afb search
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "01", "02");  // PAGE 3 ABOVE

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "01");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("FB");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "0A");  //fb mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "0B");      //fb rise time
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "0C");      //fb rise time fine
	editDetails()->page()->addKnob(0, 3, 1, 1, "00", "00", "0D", "turbo"); //fb f.b.level
	editDetails()->page()->addKnob(0, 4, 1, 1, "00", "00", "0E", "turbo"); //fb f.b. level fine
	editDetails()->page()->addKnob(0, 5, 1, 1, "00", "00", "0F");      //fb vibe rate
	editDetails()->page()->addKnob(0, 6, 1, 1, "00", "00", "10");      //fb vibe depth
	editDetails()->page()->addKnob(0, 7, 1, 1, "00", "00", "11");      //fb vibe depth
	editDetails()->page()->addComboBox(0, 8, 1, 1, "00", "00", "12");  //fb tone
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "01", "03");  // PAGE 4 ABOVE

	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "01");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("PIC");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "13");      //pic type
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "14");          // pic tone
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "15", "turbo"); //pic level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "01", "04");// PAGE 5 ABOVE
	
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(1, 0, 1, 1, "00", "00", "01");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->newGroupBox("TR");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "00", "00", "16");      //tr mode
	editDetails()->page()->addKnob(0, 1, 1, 1, "00", "00", "17");          // tr wave shape
	editDetails()->page()->addKnob(0, 2, 1, 1, "00", "00", "18", "turbo"); //tr depth
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage("00", "00", "01", "05");// PAGE 6 ABOVE

	
};
