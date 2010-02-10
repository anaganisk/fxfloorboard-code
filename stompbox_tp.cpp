/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-5 Fx FloorBoard".
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public Litpnse as published by
** the Free Software Foundation; either version 2 of the Litpnse, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public Litpnse for more details.
**
** You should have retpived a copy of the GNU General Public Litpnse along
** with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**
****************************************************************************/

#include "stompbox_tp.h"

stompbox_tp::stompbox_tp(QWidget *parent)
    : stompBox(parent)
{
	/* Tremolo/Pan */
	setImage(":/images/tp.png");
  setLSB("02", "00");
  setKnob1("02", "00", "21");
  setKnob2("02", "00", "22");
  setComboBox("02", "00", "1F");
  setButton("00", "00", "00");
  editDetails()->patchPos(217, 5, "02", "00");
	setEditPages();
};

void stompbox_tp::updateSignal()
{
        updateKnob1("02", "00", "21");
	updateKnob2("02", "00", "22");
	updateComboBox("02", "00", "1F");
        updateButton("00", "00", "00");
};

void stompbox_tp::setEditPages()
{
        editDetails()->page()->newGroupBox("Effect");
        editDetails()->page()->addSwitch(0, 0, 2, 1, "00", "00", "00", "middle", Qt::AlignCenter);
        editDetails()->page()->addComboBox(0, 1, 2, 1, "02", "00", "1F");
	editDetails()->page()->addGroupBox(1, 0, 1, 1);

        editDetails()->page()->newGroupBox("Tremolo/Pan");
	editDetails()->page()->addComboBox(0, 1, 2, 1, "02", "00", "20");    // wave type
	editDetails()->page()->addKnob(0, 2, 1, 1, "02", "00", "21", "normal","right", 105);          //rate
	editDetails()->page()->addKnob(0, 3, 1, 1, "02", "00", "22", "turbo"); //depth
        editDetails()->page()->addGroupBox(1, 1, 1, 1);

        editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 1, 1, 1, "02", "00", "23");          //balance
        editDetails()->page()->addGroupBox(1, 2, 1, 1);
	editDetails()->addPage();  // PAGE 1 ABOVE 
	
};
