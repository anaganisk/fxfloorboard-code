/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-8 Fx FloorBoard".
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
	/* PRE */
	setImage(":/images/pre.png");
	setLSB("07", "00");
	setSwitch("07", "00", "00");
	setEditPages();
};

void stompbox_pre::updateSignal()
{
	updateSwitch("07", "00", "00");
};

void stompbox_pre::setEditPages()
{
    editDetails()->page()->addLabel("Work in progress...", QPoint(0,0));
	editDetails()->addPage();
};
