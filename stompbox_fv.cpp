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
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0C", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->addKnob(0, 1, 1, 1, "0C", "00", "01");         //foot volume minimum
	editDetails()->page()->addKnob(0, 2, 1, 1, "0C", "00", "02");         //foot volume maximum
	editDetails()->page()->addGroupBox(1, 0, 1, 3);
/*
	editDetails()->page()->newGroupBox("Expression Pedal Switch");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0D", "00", "00", "middle", Qt::AlignCenter); //on/off 
	editDetails()->page()->addComboBox(0, 1, 1, 1, "0D", "00", "01"); //QUICK SETTING
	editDetails()->page()->addKnob(0, 2, 1, 1, "0D", "00", "02", "normal", "right", 135);//target
	editDetails()->page()->addComboBox(0, 3, 1, 1, "0D", "00", "04");   
	//editDetails()->page()->addKnob(0, 2, 1, 1, "0D", "00", "04", "turbo");       // target min
	editDetails()->page()->addComboBox(0, 4, 1, 1, "0D", "00", "06"); 
	//editDetails()->page()->addKnob(0, 3, 1, 1, "0D", "00", "06", "turbo");    //  target max
	editDetails()->page()->addComboBox(0, 5, 1, 1, "0D", "00", "08");         // source mode
	editDetails()->page()->addGroupBox(2, 0, 1, 4);
*/
	editDetails()->page()->newGroupBox("Foot Volume");
	editDetails()->page()->addKnob(0, 0, 1, 1, "09", "00", "06");         //foot volume level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
/*
	editDetails()->page()->newGroupBox("CTRL Pedal");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "0E", "00", "00", "middle", Qt::AlignCenter); //on/off 
	editDetails()->page()->addComboBox(0, 1, 1, 1, "0E", "00", "01"); //QUICK SETTING
	editDetails()->page()->addKnob(0, 2, 1, 1, "0E", "00", "02", "normal", "right", 135);//target
	editDetails()->page()->addComboBox(0, 3, 1, 1, "0E", "00", "04");   
	//editDetails()->page()->addKnob(0, 2, 1, 1, "0D", "00", "04", "turbo");       // target min
	editDetails()->page()->addComboBox(0, 4, 1, 1, "0E", "00", "06"); 
	//editDetails()->page()->addKnob(0, 3, 1, 1, "0D", "00", "06", "turbo");    //  target max
	editDetails()->page()->addComboBox(0, 5, 1, 1, "0E", "00", "08");         // source mode
	editDetails()->page()->addGroupBox(3, 0, 1, 4);
	*/
	
	editDetails()->addPage();  // PAGE ABOVE   
	
};
