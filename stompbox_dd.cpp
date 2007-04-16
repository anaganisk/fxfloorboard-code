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
	/* DELAY */
	setImage(":/images/dd.png");
	setLSB("08", "00");
	setKnob1("08", "00", "0C");
	setKnob2("08", "00", "0F");
	setComboBox("08", "00", "02");
	setButton("08", "00", "00");
	setEditPages();
};

void stompbox_dd::updateSignal()
{
	updateKnob1("08", "00", "0C");
	updateKnob2("08", "00", "0F");
	updateComboBox("08", "00", "02");
	updateButton("08", "00", "00");
};

void stompbox_dd::setEditPages()
{
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "08", "00", "00");
	editDetails()->page()->newStackControl(0, 0, 1, 2, 1);
	editDetails()->page()->addComboBox(1, 0, 1, 1, "08", "00", "02");
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Reverb");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "08", "00", "03");//rev type
	editDetails()->page()->addKnob(0, 1, 1, 1, "08", "00", "04");         //rev time
	editDetails()->page()->addKnob(0, 2, 1, 1, "08", "00", "05", "turbo");//pre delay
	editDetails()->page()->addKnob(0, 5, 1, 1, "08", "00", "08");         //density
    editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 3, 1, 1, "08", "00", "06");         //low cut
	editDetails()->page()->addKnob(0, 4, 1, 1, "08", "00", "07", "turbo");//high cut
    editDetails()->page()->addGroupBox(1, 2, 1, 1);
	
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 6, 1, 1, "08", "00", "09", "turbo");//rev level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();  // PAGE 1 ABOVE


	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "08", "00", "0B");//delay type
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Time");
	editDetails()->page()->addKnob(0, 1, 1, 1, "08", "00", "0C","normal","right", 60);         //delay time
	editDetails()->page()->addKnob(0, 2, 1, 1, "08", "00", "0D", "turbo");//time fine
	editDetails()->page()->addKnob(0, 3, 1, 1, "08", "00", "0E");         //tap time
	editDetails()->page()->addKnob(0, 4, 1, 1, "08", "00", "0F", "turbo");//feedback
    editDetails()->page()->addGroupBox(1, 2, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 5, 1, 1, "08", "00", "10", "turbo");//high cut
	editDetails()->page()->addGroupBox(1, 3, 1, 1);

	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 6, 1, 1, "08", "00", "11");         //level
	editDetails()->page()->addGroupBox(1, 4, 1, 1);
	editDetails()->page()->addStackField();// PAGE 2 ABOVE


	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Sound on Sound");
	editDetails()->page()->addComboBox(0, 0, 2, 1, "08", "00", "13");         //sos mode
	editDetails()->page()->addKnob(0, 1, 2, 1, "08", "00", "14");         //sos quantize
	editDetails()->page()->addKnob(0, 2, 2, 1, "08", "00", "15","normal","right", 60);         //sos tempo
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 2, 1, "08", "00", "16", "turbo");//sos level
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
    editDetails()->page()->addStackField();// PAGE 3 ABOVE

	editDetails()->addPage();  	
};
