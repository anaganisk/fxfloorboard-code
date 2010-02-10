/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-5 Fx FloorBoard".
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
  setLSB("02", "00");
	setKnob1("02", "00", "0E");
	setKnob2("02", "00", "12");
	setComboBox("02", "00", "0D");
  setButton("00", "00", "00");
  editDetails()->patchPos(198, 13, "02", "00");
	setEditPages();
};

void stompbox_dd::updateSignal()
{
	updateKnob1("02", "00", "0E");
	updateKnob2("02", "00", "12");
	updateComboBox("02", "00", "0D");
  updateButton("00", "00", "00");
};

void stompbox_dd::setEditPages()
{
	
	editDetails()->page()->newGroupBox("Effect");
  editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(1, 0, 1, 1);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "02", "00", "0D");     //delay type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "02", "00", "0C");     //delay mode
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	
	editDetails()->page()->newGroupBox("Time");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "0E","normal","right", 60);//delay time
	editDetails()->page()->addComboBox(1, 0, 1, 1, "02", "00", "10");     //interval
	editDetails()->page()->insertStackField(0, 0, 1, 1, 1);
	
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "12", "turbo");//feedback
	editDetails()->page()->addComboBox(0, 3, 1, 1, "02", "00", "13");     //  hold
	editDetails()->page()->addComboBox(1, 2, 1, 1, "02", "00", "14");     //  record 
	editDetails()->page()->addComboBox(1, 3, 1, 1, "02", "00", "15");     //  smooth
  editDetails()->page()->addGroupBox(1, 2, 1, 1);
	

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "16");         //high cut
	editDetails()->page()->addGroupBox(1, 3, 1, 1);

	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 0, 1, 1, "02", "00", "17", "turbo");//Effect level
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "18");//Direct level
	editDetails()->page()->addGroupBox(1, 4, 1, 1);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(0);
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "11");         //tap time
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(0);
	editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(0);
	editDetails()->page()->addStackField();
	
	editDetails()->addPage();// PAGE 2 ABOVE


	};
