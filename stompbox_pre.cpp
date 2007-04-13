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

#include "stompbox_pre.h"

stompbox_pre::stompbox_pre(QWidget *parent)
    : stompBox(parent)
{
	/* PRE  */
	setImage(":/images/pre.png");
	setLSB("04", "00");
	setKnob1("04", "00", "08");
	setKnob2("04", "00", "0F");
	setComboBox("04", "00", "02");
	setButton("04", "00", "00"); 
	setEditPages();
};

void stompbox_pre::updateSignal()
{
    updateKnob1("04", "00", "08");
	updateKnob2("04", "00", "0F");
	updateComboBox("04", "00", "02");
	updateButton("04", "00", "00");
};

void stompbox_pre::setEditPages()
{
    
    editDetails()->page()->newGroupBox("Pre Amplifier");
	editDetails()->page()->newGroupBox("Flip Top");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "08", "turbo");//gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0D");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0B", "turbo");//mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "0C");         //mid freq
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "09", "turbo");//treble
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "05");         //response
	editDetails()->page()->addKnob(0, 6, 1, 1, "04", "00", "03", "turbo");//bright
	editDetails()->page()->addKnob(0, 7, 1, 1, "04", "00", "0F");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("04", "00", "02");  // PAGE 1 ABOVE

	editDetails()->page()->newGroupBox("Pre Amplifier");
	editDetails()->page()->newGroupBox("B Man");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "08", "turbo");//gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0D");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0B", "turbo");//mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "0C");         //mid freq
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "09", "turbo");//treble
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "04", "turbo");//deep
	editDetails()->page()->addKnob(0, 6, 1, 1, "04", "00", "0F");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("04", "00", "02");  // PAGE 2 ABOVE

	editDetails()->page()->newGroupBox("Pre Amplifier");
	editDetails()->page()->newGroupBox("Bass 360");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "08", "turbo");//gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0D");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0B", "turbo");//mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "09", "turbo");//treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "0F");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("04", "00", "02");  // PAGE 3 ABOVE

	editDetails()->page()->newGroupBox("Pre Amplifier");
	editDetails()->page()->newGroupBox("T.E.");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "08", "turbo");//gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0D");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0B", "turbo");//mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "0C");         //mid freq
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "09", "turbo");//treble
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "07", "turbo");//pre shape
	editDetails()->page()->addKnob(0, 6, 1, 1, "04", "00", "0F");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("04", "00", "02");  // PAGE 4 ABOVE	

	editDetails()->page()->newGroupBox("Pre Amplifier");
	editDetails()->page()->newGroupBox("Session");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "08", "turbo");//gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0D");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0B", "turbo");//mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "0C");         //mid freq
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "09", "turbo");//treble
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "06", "turbo");//enhancer
	editDetails()->page()->addKnob(0, 6, 1, 1, "04", "00", "0F");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("04", "00", "02");  // PAGE 5 ABOVE	

	editDetails()->page()->newGroupBox("Pre Amplifier");
	editDetails()->page()->newGroupBox("Concert 810");
	editDetails()->page()->addKnob(0, 0, 1, 1, "04", "00", "08", "turbo");//gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "04", "00", "0E", "turbo");//ultra low
	editDetails()->page()->addKnob(0, 2, 1, 1, "04", "00", "0D");         //bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "04", "00", "0B", "turbo");//mid
	editDetails()->page()->addKnob(0, 4, 1, 1, "04", "00", "0C");         //mid freq
	editDetails()->page()->addKnob(0, 5, 1, 1, "04", "00", "09", "turbo");//treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "04", "00", "05");         //response
	editDetails()->page()->addKnob(0, 7, 1, 1, "04", "00", "03", "turbo");//bright
	editDetails()->page()->addKnob(0, 8, 1, 1, "04", "00", "0A");         //ultra high
	editDetails()->page()->addKnob(0, 9, 1, 1, "04", "00", "0F");         //level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->addPage("04", "00", "02");  // PAGE 6 ABOVE
};
