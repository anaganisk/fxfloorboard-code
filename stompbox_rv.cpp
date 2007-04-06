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
 
stompbox_rv::stompbox_rv(QWidget *parent)
    : stompBox(parent)
{
	/* REVERB */
	setImage(":/images/rv.png");
	setLSB("04", "00");
	setKnob1("04", "00", "14");
	setKnob2("04", "00", "15");
	setComboBox("04", "00", "12");
	setButton("04", "00", "10");
	setEditPages();
};

void stompbox_rv::updateSignal()
{
	updateKnob1("04", "00", "14");
	updateKnob2("04", "00", "15");
	updateComboBox("04", "00", "12");
	updateButton("04", "00", "10");
};


void stompbox_rv::setEditPages()
{
	editDetails()->page()->addKnob(QPoint(0,20), "04", "00", "10");
	editDetails()->page()->addKnob(QPoint(55,20), "04", "00", "12");
	editDetails()->page()->addKnob(QPoint(110,20), "04", "00", "13");
	editDetails()->page()->addKnob(QPoint(165,20), "04", "00", "14");
	editDetails()->page()->addKnob(QPoint(220,20), "04", "00", "15");
	editDetails()->page()->addKnob(QPoint(275,20), "04", "00", "16");
	editDetails()->addPage();
};
