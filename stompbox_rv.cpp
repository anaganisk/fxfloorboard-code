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

#include "stompbox_rv.h"
#include "MidiTable.h"
#include "SysxIO.h"

#include "customButton.h"
#include "customLed.h"
#include "customDial.h"

stompbox_rv::stompbox_rv(QWidget *parent)
    : stompBox(parent)
{
	/* DELAY */
	setImage(":/images/rv.png");
	setLSB("08", "00");
	setKnob1("08", "00", "03");
	setKnob2("08", "00", "08");
	setComboBox("08", "00", "02");
	setButton("08", "00", "00");
	setEditPages();
};

void stompbox_rv::updateSignal()
{
	updateKnob1("08", "00", "03");
	updateKnob2("08", "00", "08");
	updateComboBox("08", "00", "02");
	updateButton("08", "00", "00");
};

void stompbox_rv::setEditPages()
{
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "08", "00", "00", "middle", Qt::AlignCenter);
	//editDetails()->page()->addComboBox(0, 1, 1, 1, "08", "00", "01");     //Quick Setting
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
    editDetails()->page()->newGroupBox("Reverb");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "08", "00", "02");     //rev type
	editDetails()->page()->addKnob(0, 1, 1, 1, "08", "00", "03");         //rev time
	editDetails()->page()->addKnob(0, 2, 1, 1, "08", "00", "04");         //pre delay
	editDetails()->page()->addKnob(0, 5, 1, 1, "08", "00", "07", "turbo");//density
    editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 3, 1, 1, "08", "00", "05");         //low cut
	editDetails()->page()->addKnob(0, 4, 1, 1, "08", "00", "06");         //high cut
    editDetails()->page()->addGroupBox(1, 2, 1, 1);
	
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 6, 1, 1, "08", "00", "08", "turbo");//rev level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->addPage();  // PAGE 1 ABOVE



	};
