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
	setKnob1("04", "00", "08");
	setKnob2("04", "00", "0F");
	setComboBox("04", "00", "02");
	setButton("04", "00", "00"); 
};

void stompbox_pre::updateSignal()
{
    updateKnob1("04", "00", "08");
	updateKnob2("04", "00", "0F");
	updateComboBox("04", "00", "02");
	updateButton("04", "00", "00");
};
