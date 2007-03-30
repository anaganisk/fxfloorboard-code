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

#include "stompbox_eq.h"

stompbox_eq::stompbox_eq(QWidget *parent)
    : stompBox(parent)
{
	/* EQ */
	setImage(":/images/eq.png");
  setLSB("05", "00");
	setSlider1("05", "00", "04");
	setSlider2("05", "00", "07");
	setSlider3("05", "00", "0A");
	////setSlider4("05", "00", "0A");
	setSlider5("05", "00", "0B");
	setButton("05", "00", "00"); 
	setEditPages();
};

void stompbox_eq::updateSignal()
{
	updateSlider1("05", "00", "04");
	updateSlider2("05", "00", "07");
	updateSlider3("05", "00", "0A");
	////updateSlider4("05", "00", "0A");
	updateSlider5("05", "00", "0B");
	updateButton("05", "00", "00");
};

void stompbox_eq::setEditPages()
{
    editDetails()->page()->addLabel("_________Low Eq________", QPoint(20,0));
	editDetails()->page()->addKnob(QPoint(0,30));
	editDetails()->page()->addLabel("Q", QPoint(17,15));
	editDetails()->page()->addKnob(QPoint(80,30));
	editDetails()->page()->addLabel("Freq", QPoint(88,15));
	editDetails()->page()->addKnob(QPoint(160,30));
	editDetails()->page()->addLabel("Level", QPoint(164,15));
	
	editDetails()->page()->addLabel("_________Mid Eq_________", QPoint(20,100));
	editDetails()->page()->addKnob(QPoint(0,130));
	editDetails()->page()->addLabel("Q", QPoint(17,115));
	editDetails()->page()->addKnob(QPoint(80,130));
	editDetails()->page()->addLabel("Freq", QPoint(88,115));
	editDetails()->page()->addKnob(QPoint(160,130));
	editDetails()->page()->addLabel("Level", QPoint(164,115));
	
	editDetails()->page()->addLabel("_________High Eq________", QPoint(20,200));
	editDetails()->page()->addKnob(QPoint(0,230));
	editDetails()->page()->addLabel("Q", QPoint(17,215));
	editDetails()->page()->addKnob(QPoint(80,230));
	editDetails()->page()->addLabel("Freq", QPoint(88,215));
	editDetails()->page()->addKnob(QPoint(160,230));
	editDetails()->page()->addLabel("Level", QPoint(164,215));
	
	editDetails()->page()->addKnob(QPoint(264,230));
	editDetails()->page()->addLabel("EQ Level", QPoint(264,215));
	editDetails()->page()->addSwitch(QPoint(264,30));
	editDetails()->page()->addLabel("Fx On/Off", QPoint(254,15));
	editDetails()->addPage();
};