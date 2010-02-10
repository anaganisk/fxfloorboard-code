/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GT-5 Fx FloorBoard".
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

#include "stompbox_loop.h"

stompbox_loop::stompbox_loop(QWidget *parent)
    : stompBox(parent)
{
        /* LOOP */
	setImage(":/images/loop.png");
        setLSB("01", "00");
        setButton("00", "00", "00", QPoint::QPoint(0, 109), ":/images/pedal.png");
        setKnob1("01", "00", "1D");
        editDetails()->patchPos(75, 1, "01", "00");
	setEditPages();
};

void stompbox_loop::updateSignal()
{
        updateButton("00", "00", "00");
        updateKnob1("01", "00", "1D");
};

void stompbox_loop::setEditPages()
{
        editDetails()->page()->newGroupBox("S/R external Loop");
        editDetails()->page()->newGroupBox("Send");
        editDetails()->page()->addKnob(0, 1, 1, 1, "01", "00", "1D");
        editDetails()->page()->addGroupBox(0, 0, 1, 1);
        editDetails()->page()->newGroupBox("Effect");
        editDetails()->page()->addSwitch(0, 0, 1, 1, "00", "00", "00", "middle", Qt::AlignCenter);         //on
        editDetails()->page()->addGroupBox(0, 1, 1, 1);
        editDetails()->page()->addGroupBox(0, 0, 1, 1);
        editDetails()->addPage();
};
