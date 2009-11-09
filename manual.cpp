/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-6 Fx FloorBoard".
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

#include "manual.h"

manual::manual(QWidget *parent)
    : stompBox(parent)
{
	/* MANUAL */
	//setImage(":/images/fv.png");
	setLSB("0F", "00");
//	setButton("0C", "00", "00", QPoint::QPoint(0, 109), ":/images/pedal.png");
	setEditPages();
};

void manual::updateSignal()
{
//	updateButton("0C", "00", "00");
};

void manual::setEditPages()
{
    editDetails()->page()->newGroupBox("Manual");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "0F", "00", "00");         // source mode
	editDetails()->page()->addComboBox(0, 1, 1, 1, "0F", "00", "01");         // source mode
	editDetails()->page()->addComboBox(0, 2, 1, 1, "0F", "00", "02");         // source mode
	editDetails()->page()->addComboBox(0, 3, 1, 1, "0F", "00", "03");         // source mode
	editDetails()->page()->addGroupBox(0, 4, 1, 4);
	editDetails()->addPage();  // PAGE ABOVE   
	
};
