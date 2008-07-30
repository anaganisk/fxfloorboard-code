/****************************************************************************
** Copyright (C) 2008 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-10 Fx FloorBoard".
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

#include "stompbox_cn_s.h"

stompbox_cn_s::stompbox_cn_s(QWidget *parent)
    : stompBox(parent)
{
	/* CHAIN SPLIT */
	this->setImage(":/images/cn_s.png");
	setLSB("01", "00");
	setComboBox("01", "00", "01", QRect(8, 78, 79, 13));
	setEditPages();
};

void stompbox_cn_s::updateSignal()
{
	updateComboBox("01", "00", "01");
};

void stompbox_cn_s::setEditPages()
{
  editDetails()->page()->newGroupBox("Channel");
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(2, 0, 1, 1, "01", "00", "01");   //mode
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(0, 0, 1, 1);

	// TYPE SETTINGS 
	editDetails()->page()->insertStackField(0, 1, 0, 1, 1);

	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Channel select");
	editDetails()->page()->addComboBox(1, 0, 1, 1, "01", "00", "02"); // channel select
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0, Qt::AlignCenter);
	editDetails()->page()->newGroupBox("Channel Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "03");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0, Qt::AlignCenter);
	editDetails()->page()->newGroupBox("Channel Delay");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "03");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(0, Qt::AlignCenter);
	editDetails()->page()->newGroupBox("Dynamic switching");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "04");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
    
	editDetails()->addPage();	
};
