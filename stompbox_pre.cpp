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
	setLSB("03", "00");
	setKnob1("03", "00", "03");
	setKnob2("03", "00", "08");
	setComboBox("03", "00", "02");
	setButton("03", "00", "00"); 
	editDetails()->patchPos(224, 32, "03", "00");
	setEditPages();
};

void stompbox_pre::updateSignal()
{
  updateKnob1("03", "00", "03");
	updateKnob2("03", "00", "08");
	updateComboBox("03", "00", "02");
	updateButton("03", "00", "00");
};

void stompbox_pre::setEditPages()
{
   
    editDetails()->page()->newGroupBox("Pre-Amp");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "03", "00", "02");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Pre");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "03", "turbo");//gain
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "04");         //bass
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "05");         //mid
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "06");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "07");         //presence
	editDetails()->page()->addKnob(0, 5, 1, 1, "03", "00", "08");         //amp level
	editDetails()->page()->addSwitch(0, 6, 1, 1, "03", "00", "09", "middle", Qt::AlignCenter); //bright
	editDetails()->page()->addComboBox(0, 7, 1, 1, "03", "00", "0A");     //gain
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->addPage();
	  // PAGE 1 ABOVE

	editDetails()->page()->newGroupBox("Speaker Cabnet");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "03", "00", "0B", "middle", Qt::AlignCenter);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "03", "00", "0C");     //type
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	editDetails()->page()->newGroupBox("Spkr");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "0D", "turbo");//mic
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "0E");         //mic level
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "0F");         //direct level
	editDetails()->page()->addGroupBox(2, 1, 1, 1);
	editDetails()->addPage();
	  // PAGE 2 ABOVE
};
