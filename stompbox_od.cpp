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

#include "stompbox_od.h"

stompbox_od::stompbox_od(QWidget *parent)
    : stompBox(parent)
{
	/* OD/DS */
	setImage(":/images/od.png");
	setLSB("03", "00");
	setKnob1("03", "00", "03");
	setKnob2("03", "00", "06");
	setComboBox("03", "00", "02");
	setButton("03", "00", "00");
	setEditPages();
};

void stompbox_od::updateSignal()
{
	updateKnob1("03", "00", "03");
	updateKnob2("03", "00", "06");
	updateComboBox("03", "00", "02");
	updateButton("03", "00", "00");
};

void stompbox_od::setEditPages()
{
   	editDetails()->page()->newGroupBox("Overdrive/Distortion");
	editDetails()->page()->addKnob(0, 0, 1, 1, "03", "00", "02", "turbo");//type
	editDetails()->page()->addKnob(0, 1, 1, 1, "03", "00", "03");         //drive
	editDetails()->page()->addKnob(0, 2, 1, 1, "03", "00", "04", "turbo");//bass
	editDetails()->page()->addKnob(0, 3, 1, 1, "03", "00", "05");         //treble
	editDetails()->page()->addKnob(0, 4, 1, 1, "03", "00", "06");         //effect level
	editDetails()->page()->addKnob(0, 5, 1, 1, "03", "00", "07");         //direct level
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->addPage();  // PAGE 4 ABOVE 
	
};
