/****************************************************************************
**
** Copyright (C) 2005-2006 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-6B Fx FloorBoard".
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
 
stompbox_rv::stompbox_rv(QWidget *parent)
    : stompBox(parent)
{
	/* REVERB */
	setImage(":/images/rv.png");
	//setKnob1("0D", "00", "00");
	//setKnob2("0D", "00", "00");
	setComboBox("04", "00", "12");
	setButton("04", "00", "10");
};

void stompbox_rv::updateSignal()
{
	//updateKnob1("0D", "00", "00");
	//updateKnob2("0D", "00", "00");
	updateComboBox("04", "00", "12");
	updateButton("04", "00", "10");
};
