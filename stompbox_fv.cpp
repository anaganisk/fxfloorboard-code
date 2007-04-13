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

#include "stompbox_fv.h"

stompbox_fv::stompbox_fv(QWidget *parent)
    : stompBox(parent)
{
	/* VOLUME */
	setImage(":/images/fv.png");
	setLSB("0C", "00");
//	setButton("0C", "00", "00", QPoint::QPoint(0, 109), ":/images/pedal.png");
	setEditPages();
};

void stompbox_fv::updateSignal()
{
//	updateButton("0C", "00", "00");
};

void stompbox_fv::setEditPages()
{
    editDetails()->page()->newGroupBox("Expression Pedal");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0C", "00", "01", "turbo");//foot volume minimum
	editDetails()->page()->addKnob(0, 1, 1, 1, "0C", "00", "02");         //foot volume maximum
	editDetails()->page()->addGroupBox(0, 1, 1, 2);
	editDetails()->page()->newGroupBox("Expression Pedal Switch");
	editDetails()->page()->addKnob(0, 0, 1, 1, "0D", "00", "00", "turbo");//on/off
	//editDetails()->page()->addKnob(0, 1, 1, 1, "0D", "00", "02");         //target
	//editDetails()->page()->addKnob(0, 2, 1, 1, "0D", "00", "04", "turbo");//
	//editDetails()->page()->addKnob(0, 3, 1, 1, "0D", "00", "15", "turbo");//
	//editDetails()->page()->addKnob(0, 4, 1, 1, "0D", "00", "16");         //
	editDetails()->page()->addGroupBox(1, 0, 1, 2);
	editDetails()->addPage();  // PAGE ABOVE   
	
};
