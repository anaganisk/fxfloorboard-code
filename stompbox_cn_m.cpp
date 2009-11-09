/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-10B Fx FloorBoard".
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

#include "stompbox_cn_m.h"

stompbox_cn_m::stompbox_cn_m(QWidget *parent)
    : stompBox(parent)
{
	/* CHAIN MERGE */
	this->setImage(":/images/cn_m.png");
	setLSB("00", "00");
	setEditPages();
};

void stompbox_cn_m::updateSignal()
{
	
};

void stompbox_cn_m::setEditPages()
{
 editDetails()->addPage();
 editDetails()->patchPos(0, 0, "void", "void");    // don't want buttons on a blank page.	
};
