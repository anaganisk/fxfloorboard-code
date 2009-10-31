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

#include "stompbox_dd.h"
#include "MidiTable.h"
#include "SysxIO.h"

#include "customButton.h"
#include "customLed.h"
#include "customDial.h"

stompbox_dd::stompbox_dd(QWidget *parent)
    : stompBox(parent)
{
	/* DELAY */
	setImage(":/images/dd.png");
	setLSB("08", "00");
	setKnob1("08", "00", "0C");
	setKnob2("08", "00", "0F");
	setComboBox("08", "00", "02");
	setButton("08", "00", "00");
	editDetails()->patchPos(644, 50, "08", "00");
	setEditPages();
};

void stompbox_dd::updateSignal()
{
	updateKnob1("08", "00", "0C");
	updateKnob2("08", "00", "0F");
	updateComboBox("08", "00", "02");
	updateButton("08", "00", "00");
};

void stompbox_dd::setEditPages()
{
	editDetails()->page()->newGroupBox("Effect");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "08", "00", "00", "middle", Qt::AlignCenter);
	editDetails()->page()->newStackControl(0);
	editDetails()->page()->addComboBox(0, 1, 1, 1, "08", "00", "02");
  editDetails()->page()->addStackControl();	    
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->insertStackField(0, 1, 0, 1, 1);
	 
  editDetails()->page()->newStackField(0); 
  editDetails()->page()->newGroupBox("Reverb");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "08", "00", "03");     //rev type
	editDetails()->page()->addKnob(0, 1, 1, 1, "08", "00", "04");         //rev time
	editDetails()->page()->addKnob(0, 2, 1, 1, "08", "00", "05");         //pre delay
	editDetails()->page()->addKnob(0, 5, 1, 1, "08", "00", "08", "turbo");//density
  editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 3, 1, 1, "08", "00", "06");         //low cut
	editDetails()->page()->addKnob(0, 4, 1, 1, "08", "00", "07");         //high cut
    editDetails()->page()->addGroupBox(1, 2, 1, 1);
	
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 6, 1, 1, "08", "00", "09", "turbo");//rev level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);
	editDetails()->page()->addStackField();    // PAGE 1 ABOVE

//-------------------------------- DELAY ------------------------------------------------//
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "08", "00", "0B");     //delay type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Time");
	editDetails()->page()->addKnob(0, 1, 1, 1, "08", "00", "0C","normal","right", 60);//delay time
	editDetails()->page()->addKnob(0, 2, 1, 1, "08", "00", "0D");         //time fine
	editDetails()->page()->insertStackField(1, 0, 3, 1, 1);
	
	editDetails()->page()->addKnob(0, 4, 1, 1, "08", "00", "0F", "turbo");//feedback
  editDetails()->page()->addGroupBox(1, 2, 1, 1);
	
	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 5, 1, 1, "08", "00", "10");         //high cut
	editDetails()->page()->addGroupBox(1, 3, 1, 1);

	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 6, 1, 1, "08", "00", "11", "turbo");//level
	editDetails()->page()->addGroupBox(1, 4, 1, 1);
	editDetails()->page()->addStackField();

	editDetails()->page()->newStackField(1);
	editDetails()->page()->addStackField();
	
  editDetails()->page()->newStackField(1);
	editDetails()->page()->addKnob(0, 3, 1, 1, "08", "00", "0E");         //tap time
	editDetails()->page()->addStackField();  // PAGE 2 ABOVE

	//--------------------------------REVERB & DELAY ------------------------------------------------//
	editDetails()->page()->newStackField(0);
  editDetails()->page()->newGroupBox("Reverb");
	editDetails()->page()->addComboBox(0, 0, 1, 1, "08", "00", "03");     //rev type
	editDetails()->page()->addKnob(0, 1, 1, 1, "08", "00", "04");         //rev time
	editDetails()->page()->addKnob(0, 2, 1, 1, "08", "00", "05");         //pre delay
	editDetails()->page()->addKnob(0, 5, 1, 1, "08", "00", "08", "turbo");//density
  editDetails()->page()->addGroupBox(1, 1, 1, 1);

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 3, 1, 1, "08", "00", "06");         //low cut
	editDetails()->page()->addKnob(0, 4, 1, 1, "08", "00", "07");         //high cut
  editDetails()->page()->addGroupBox(1, 2, 1, 1);
	
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 6, 1, 1, "08", "00", "09", "turbo");//rev level
	editDetails()->page()->addGroupBox(1, 3, 1, 1);

	editDetails()->page()->newGroupBox("Delay");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "08", "00", "0B");     //delay type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addGroupBox(2, 0, 1, 1);
	
	editDetails()->page()->newGroupBox("Time");
	editDetails()->page()->addKnob(0, 1, 1, 1, "08", "00", "0C","normal","right", 60);//delay time
	editDetails()->page()->addKnob(0, 2, 1, 1, "08", "00", "0D");         //time fine
	editDetails()->page()->insertStackField(1, 0, 3, 1, 1);
	
	editDetails()->page()->addKnob(0, 4, 1, 1, "08", "00", "0F", "turbo");//feedback
  editDetails()->page()->addGroupBox(2, 1, 1, 1);	

	editDetails()->page()->newGroupBox("Filter");
	editDetails()->page()->addKnob(0, 5, 1, 1, "08", "00", "10");         //high cut
	editDetails()->page()->addGroupBox(2, 2, 1, 1);

	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 6, 1, 1, "08", "00", "11", "turbo");//level
	editDetails()->page()->addGroupBox(2, 3, 1, 1);
	editDetails()->page()->addStackField(); 

	editDetails()->page()->newStackField(1);
	editDetails()->page()->addStackField();
	
  editDetails()->page()->newStackField(1);
	editDetails()->page()->addKnob(0, 3, 1, 1, "08", "00", "0E");         //tap time
	editDetails()->page()->addStackField();   // PAGE 3 ABOVE

//------------------------- Sound on Sound -----------------------------------------------//
	editDetails()->page()->newStackField(0);
	editDetails()->page()->newGroupBox("Sound on Sound");
	editDetails()->page()->addComboBox(0, 0, 2, 1, "08", "00", "13");        //sos mode
	editDetails()->page()->addSwitch(0, 1, 2, 1, "08", "00", "14", "middle", Qt::AlignCenter);          //sos quantize
	editDetails()->page()->addKnob(0, 2, 2, 1, "08", "00", "15","normal","right", 60);//sos tempo
	editDetails()->page()->addGroupBox(1, 1, 1, 1);
	editDetails()->page()->newGroupBox("Output");
	editDetails()->page()->addKnob(0, 3, 2, 1, "08", "00", "16", "turbo");   //sos level
	editDetails()->page()->addGroupBox(1, 2, 1, 1);
  editDetails()->page()->addStackField();// PAGE 4 ABOVE  
  
  editDetails()->addPage();
	};
