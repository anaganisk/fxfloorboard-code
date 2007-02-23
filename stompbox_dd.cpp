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

#include "stompbox_dd.h"
#include "MidiTable.h"
#include "SysxIO.h"

#include "customButton.h"
#include "customLed.h"
#include "customDial.h"

stompbox_dd::stompbox_dd(QWidget *parent)
    : stompBox(parent)
{
	SysxIO *sysxIO = SysxIO::Instance();
	MidiTable *midiTable = MidiTable::Instance();

	/* DELAY */
	setImage(":/images/dd.png");
	setKnob1("07", "00", "0C");
	setKnob2("07", "00", "0F");
	setComboBox("07", "00", "02");
	setButton("07", "00", "00");
};

void stompbox_dd::updateSignal()
{
	updateKnob1("07", "00", "0C");
	updateKnob2("07", "00", "0F");
	updateComboBox("07", "00", "02");
	updateButton("07", "00", "00");
};
