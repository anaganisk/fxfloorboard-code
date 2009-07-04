/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag.
** All rights reserved.
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

#include "stompbox_ch_b.h"

stompbox_ch_b::stompbox_ch_b(QWidget *parent)
    : stompBox(parent)
{
	/* PRE */
	setImage(":/images/ch_b.png");
	setLSB("01", "00");
	setButton("01", "00", "39");
	setComboBox("01", "00", "30");
	setKnob1("01", "00", "31");
	setKnob2("01", "00", "36");
	setEditPages();

};

void stompbox_ch_b::updateSignal()
{
	updateButton("01", "00", "39");
	updateComboBox("01", "00", "30");
	updateKnob1("01", "00", "31");
	updateKnob2("01", "00", "36");
};

void stompbox_ch_b::setEditPages()
{
	//editDetails()->page()->newGroupBox("Effect");
	//editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "00");   // off/on effect
	//editDetails()->page()->addGroupBox(0, 0, 1, 1);

	
	// CHANNEL B 
	
	editDetails()->page()->newGroupBox("Channel B");

	editDetails()->page()->newGroupBox("Pre Amp");
	editDetails()->page()->newStackControl(0); 
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "30");  // pre type
	editDetails()->page()->addStackControl();
 	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "38", "bottom", Qt::AlignLeft); // gain sw	
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "31", "turbo");  //gain
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "32");            // bass
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "33");           // mid
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "34");           // treble
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "35");           //presence
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "36");          //effect level
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	
  editDetails()->page()->insertStackField(0, 1, 0, 1, 1);                 // bright switch
  	
	editDetails()->page()->newGroupBox("Speaker");
	editDetails()->page()->newStackControl(1);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "3B");   // speaker type
	editDetails()->page()->addStackControl();
	editDetails()->page()->addComboBox(0, 1, 1, 1, "01", "00", "3C", "bottom", Qt::AlignRight);  // mic type
	editDetails()->page()->addComboBox(0, 2, 1, 1, "01", "00", "3D");  // mic dis
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "3E");   // mic pos
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "3F");    // mic level
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "40");   // direct level
	editDetails()->page()->addGroupBox(2, 0, 1, 1);

	editDetails()->page()->newGroupBox("Solo");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "39", "middle", Qt::AlignLeft | Qt::AlignTop);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "3A");
	editDetails()->page()->addGroupBox(0, 1, 3, 1);
	
	
  editDetails()->page()->insertStackField(1, 0, 2, 4, 1);
    
  

	editDetails()->page()->addGroupBox(0, 1, 1, 1);



	
  // Bright Button stack fields
	editDetails()->page()->newStackField(0);  //boss clean
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // jc-120
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //jazz combo
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // full range
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //clean twin
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // pro crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // tweed
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //delux crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //boss crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  //blues
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //wild crunch
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //stack crunch
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); //VO drive
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); //VO lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // VO clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //fat match
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // match lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg lead
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // bg drive
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0);  // bg rhythm
	editDetails()->page()->newGroupBox("");
	editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 I
	editDetails()->page()->addStackField();
	
	editDetails()->page()->newStackField(0); // ms1959 II
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // MS hi gain
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // ms scoop
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier vint
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // r-fier mdn
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // r-fier cln
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp crunch
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // t-amp clean
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // boss drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  //SLDN
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // lead stack
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // heavy lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0);  // boss metal
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // 5150 drive
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // metal lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // edge lead
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // custom
	editDetails()->page()->newGroupBox("Custom PreAmp");
	editDetails()->page()->newStackControl(2);
	editDetails()->page()->addComboBox(0, 0, 1, 1, "01", "00", "41");
	editDetails()->page()->addStackControl();
	editDetails()->page()->insertStackField(2, 0, 1, 1, 1);
	editDetails()->page()->addKnob(0, 2, 1, 1, "01", "00", "42");
	editDetails()->page()->addKnob(0, 3, 1, 1, "01", "00", "43");
	editDetails()->page()->addKnob(0, 4, 1, 1, "01", "00", "44");
	editDetails()->page()->addKnob(0, 5, 1, 1, "01", "00", "45");
	editDetails()->page()->addKnob(0, 6, 1, 1, "01", "00", "46");
	editDetails()->page()->addKnob(0, 7, 1, 1, "01", "00", "47");
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();
  
	editDetails()->page()->newStackField(0); // through
  editDetails()->page()->addStackField();
  

	
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);editDetails()->page()->addStackField();
	editDetails()->page()->newStackField(1);
  editDetails()->page()->newGroupBox("Custom Speaker");
	editDetails()->page()->addKnob(0, 0, 1, 1, "01", "00", "4A", "normal","right", 40);
	editDetails()->page()->addKnob(1, 0, 1, 1, "01", "00", "49", "normal","right", 40);
	editDetails()->page()->addKnob(2, 0, 1, 2, "01", "00", "48", "normal","right", 40);
	editDetails()->page()->addComboBox(3, 0, 1, 1, "01", "00", "4B", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addComboBox(4, 0, 1, 1, "01", "00", "4C", "bottom", Qt::AlignHCenter);
	editDetails()->page()->addGroupBox(0, 0, 1, 1);
  editDetails()->page()->addStackField();

  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);
  editDetails()->page()->addSwitch(0, 0, 1, 1, "01", "00", "37", "middle", Qt::AlignCenter);
  editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  editDetails()->page()->newStackField(2);editDetails()->page()->addStackField();
  
  
	editDetails()->addPage();	
};