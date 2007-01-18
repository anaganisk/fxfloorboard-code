/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT-8 FX FloorBoard".
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

#include <QLayout>
#include "bankTreeList.h"
#include "Preferences.h"
#include "MidiTable.h"
#include "midiIO.h"
#include "SysxIO.h"
#include "globalVariables.h"

bankTreeList::bankTreeList(QWidget *parent)
    : QWidget(parent)
{
	QPalette pal;
    pal.setColor(QPalette::Base,QColor(0,1,62));
    pal.setColor(QPalette::Text,QColor(0,255,204));
	pal.setColor(QPalette::Highlight,QColor(0,1,62));
	pal.setColor(QPalette::HighlightedText,QColor(0,255,204));

	//pal.setColor(QPalette::Window,QColor(Qt::red));
	//pal.setColor(QPalette::WindowText,QColor(0,255,204));	//List Border
	//pal.setColor(QPalette::Button,QColor(0,1,62));
	//pal.setColor(QPalette::ButtonText,QColor(0,255,204));

	//pal.setColor(QPalette::Light,QColor(Qt::red));				//Lighter than Button color.
	//pal.setColor(QPalette::Midlight,QColor(Qt::red));				//Between Button and Light.
	//pal.setColor(QPalette::Dark,QColor(Qt::gray));				//Darker than Button. (Dots)
	//pal.setColor(QPalette::Mid,QColor(0,1,62));					//Between Button and Dark.
	//pal.setColor(QPalette::Shadow,QColor(Qt::red));
	this->pal = pal;

	QFont font;
	font.setFamily("Verdana");
	font.setBold(true);
	font.setPixelSize(10);
	font.setStretch(90);
	this->font = font;

	this->treeList = newTreeList();

	QObject::connect(treeList, SIGNAL(itemExpanded(QTreeWidgetItem*)), 
			this, SLOT(setOpenItems(QTreeWidgetItem*)));
	QObject::connect(treeList, SIGNAL(itemCollapsed(QTreeWidgetItem*)), 
			this, SLOT(setClosedItems(QTreeWidgetItem*)));
	
	QVBoxLayout *treeListLayout = new QVBoxLayout;
	treeListLayout->addWidget(treeList);
	treeListLayout->setMargin(0);
	treeListLayout->setSpacing(0);
	setLayout(treeListLayout);
};

QPalette bankTreeList::getPal()
{
	return this->pal;
};

QFont bankTreeList::getFont()
{
	return this->font;
};

void bankTreeList::updateSize(QRect newrect)
{
	this->setGeometry(newrect);
};

void bankTreeList::setClosedItems(QTreeWidgetItem *item)
{
	if(item->childCount() == patchPerBank)
	{
		int index = openPatchTreeItems.indexOf(item);
		openPatchTreeItems.removeAt(index);
		for(int i=index+1;i<openPatchTreeItems.size();++i)
		{
			//openPatchTreeItems.move(i, i-1);
		};
	}
	else if(item->childCount() == 5)
	{
		int index = openBankTreeItems.indexOf(item);
		openBankTreeItems.removeAt(index);
		for(int i=index+1;i<openBankTreeItems.size();++i)
		{
			//openBankTreeItems.move(i, i-1);
		};
		closeChildren(item);
	}
	else
	{
		closeChildren(item);
	};
};

void bankTreeList::closeChildren(QTreeWidgetItem *item)
{
	for(int i=0;i<item->childCount();++i)
	{
		for(int n=0;n<item->child(i)->childCount();++n)
		{
			item->child(i)->child(n)->setExpanded(false);
		};
		item->child(i)->setExpanded(false);
	};
};

void bankTreeList::setOpenItems(QTreeWidgetItem *item)
{
	QString type = "root";
	if(item->childCount() == patchPerBank)
	{
		openPatchTreeItems.append(item);
		updateTree(item);
		type = "patch";
	}
	else if(item->childCount() == 5)
	{
		openBankTreeItems.append(item);
		type = "bank";
	};
	
	int c = openPatchTreeItems.size();
	int b = openBankTreeItems.size();
	int a = 0;
	if(treeList->isExpanded(treeList->model()->index(0, 0)) && 
		treeList->isExpanded(treeList->model()->index(1, 0)))
	{
		a = 2;
	}
	else if(treeList->isExpanded(treeList->model()->index(0, 0)) || 
		treeList->isExpanded(treeList->model()->index(1, 0)))
	{
		a = 1;
	};

	int userBankCount = 0;
	for(int i=0;i<openBankTreeItems.size();++i)
	{
		if(openBankTreeItems.at(i)->parent()->text(0).contains("User"))
		{
			userBankCount++;
		};
	};


	if(type == "root")
	{
		if(a > 1)
		{
			int maxExpandedItems;
			while(c > 3) 
			{
				openPatchTreeItems.first()->setExpanded(false); 
				c = openPatchTreeItems.size();			
			};
			switch(c)
			{
				case 0: maxExpandedItems = 3; break;
				case 1: maxExpandedItems = 2; break;
				case 2: maxExpandedItems = 1; break;
				case 3: maxExpandedItems = 1; break;
			};
			
			while(b > maxExpandedItems)
			{
				openBankTreeItems.first()->setExpanded(false);;
				b = openBankTreeItems.size();
			};
		};
	}
	else if(type == "bank")
	{
		int maxExpandedItems;
		if(a > 1)
		{	
			switch(c)
			{
				case 0: maxExpandedItems = 3; break;
				case 1: maxExpandedItems = 2; break;
				case 2: maxExpandedItems = 1; break;
				case 3: maxExpandedItems = 1; break;
			};
		}
		else
		{
			if(treeList->isExpanded(treeList->model()->index(0, 0)))
			{
				switch(c)
				{
					case 0: maxExpandedItems = 5; break;	
					case 1: maxExpandedItems = 4; break;
					case 2: maxExpandedItems = 3; break;
					case 3: maxExpandedItems = 3; break;
					case 4: maxExpandedItems = 2; break;
					case 5: maxExpandedItems = 1; break;
				};
			}
			else
			{
				switch(c)
				{
					case 0: maxExpandedItems = 4; break;	
					case 1: maxExpandedItems = 4; break;
					case 2: maxExpandedItems = 3; break;
					case 3: maxExpandedItems = 3; break;
					case 4: maxExpandedItems = 1; break;
					case 5: maxExpandedItems = 1; break;
				};
			};
		};

		if(maxExpandedItems == 1)
		{
			openPatchTreeItems.first()->setExpanded(false);
			if(treeList->isExpanded(treeList->model()->index(1, 0)))
			{
				openPatchTreeItems.first()->setExpanded(false);
			}
			maxExpandedItems = 2;
		};
		if(b > maxExpandedItems)
		{
			openBankTreeItems.first()->setExpanded(false);;
		};
	}
	else if(type == "patch")
	{
		for(int i=0;i<openBankTreeItems.size();++i)
		{
			bool allCollapsed = true;
			for(int n=0;n<openBankTreeItems.at(i)->childCount();++n)
			{
				if(openBankTreeItems.at(i)->child(n)->isExpanded())
				{
					allCollapsed = false;
				};
			};
			if(allCollapsed)
			{
				openBankTreeItems.at(i)->setExpanded(false);
				b = openBankTreeItems.size();
				break;
			};
		};

		int maxExpandedItems;
		if(a > 1)
		{	
			switch(b)
			{
				case 1: maxExpandedItems = 3; break;
				case 2: maxExpandedItems = 1; break;
				case 3: maxExpandedItems = 0; break;
			};
		}
		else
		{
			if(treeList->isExpanded(treeList->model()->index(0, 0)))
			{
				switch(b)
				{
					case 1: maxExpandedItems = 5; break;
					case 2: maxExpandedItems = 4; break;
					case 3: maxExpandedItems = 3; break;
					case 4: maxExpandedItems = 1; break;
				};
			}
			else
			{
				switch(b)
				{
					case 1: maxExpandedItems = 4; break;
					case 2: maxExpandedItems = 3; break;
					case 3: maxExpandedItems = 3; break;
					case 4: maxExpandedItems = 1; break;
				};
			};
		};

		if(maxExpandedItems == 0)
		{
			openBankTreeItems.first()->setExpanded(false);
			maxExpandedItems = 1;
		};
		if(c > maxExpandedItems)
		{
			openPatchTreeItems.first()->setExpanded(false);
		};
	};
};

QTreeWidget* bankTreeList::newTreeList()
{
	QTreeWidget *newTreeList = new QTreeWidget();
	newTreeList->setColumnCount(1);
	newTreeList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	newTreeList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Qt::ScrollBarAsNeeded
	newTreeList->setPalette(getPal());
	newTreeList->setFont(getFont());
	
	QStringList headers;
	headers << "Boss GT-8";
    newTreeList->setHeaderLabels(headers);

	QTreeWidgetItem *user = new QTreeWidgetItem(newTreeList);
	user->setText(0, "User");
	user->setWhatsThis(0, "User Banks");
	//user->setIcon(...);

    QList<QTreeWidgetItem *> userBankRanges;
    for (int a=1; a<=35; a++)
	{
		QTreeWidgetItem* bankRange = new QTreeWidgetItem; // don't pass a parent here!
		bankRange->setText(0, QString::QString("Bank ").append(QString::number(a, 10)).append(" - ").append(QString::number(a+4, 10)) );
		bankRange->setWhatsThis(0, "");
		//bankRange->setIcon(...);

		for (int b=a; b<=(a+4); b++)
		{
			QTreeWidgetItem* bank = new QTreeWidgetItem(bankRange);
			bank->setText(0, QString::QString("Bank ").append(QString::number(b, 10)));
			bank->setWhatsThis(0, "");
			//bank->setIcon(...);

			for (int c=1; c<=4; c++)
			{
				QTreeWidgetItem* patch = new QTreeWidgetItem(bank);
				patch->setText(0, QString::QString("Patch ").append(QString::number(c, 10)));
				patch->setWhatsThis(0, "");
				//patch->setIcon(...);
			};
		};
		userBankRanges << bankRange;
		a += 4;
	};
	user->addChildren(userBankRanges);


	QTreeWidgetItem *preset = new QTreeWidgetItem(newTreeList);
	preset->setText(0, "Preset");
	preset->setWhatsThis(0, "Preset Banks");
	//user->setIcon(...);

    QList<QTreeWidgetItem *> presetBankRanges;
    for (int a=36; a<=85; a++)
	{
		QTreeWidgetItem* bankRange = new QTreeWidgetItem; // don't pass a parent here!
		bankRange->setText(0, QString::QString("Bank ").append(QString::number(a, 10)).append(" - ").append(QString::number(a+4, 10)) );
		bankRange->setWhatsThis(0, "");
		//bankRange->setIcon(...);

		for (int b=a; b<=(a+4); b++)
		{
			QTreeWidgetItem* bank = new QTreeWidgetItem(bankRange);
			bank->setText(0, QString::QString("Bank ").append(QString::number(b, 10)));
			bank->setWhatsThis(0, "");
			//bank->setIcon(...);

			for (int c=1; c<=4; c++)
			{
				QTreeWidgetItem* patch = new QTreeWidgetItem(bank);
				patch->setText(0, QString::QString("Patch ").append(QString::number(c, 10)));
				patch->setWhatsThis(0, "");
				//patch->setIcon(...);
			};
		};
		presetBankRanges << bankRange;
		a += 4;
	};
	preset->addChildren(presetBankRanges);

	newTreeList->setExpanded(newTreeList->model()->index(0, 0), true);
	newTreeList->setExpanded(newTreeList->model()->index(1, 0), true);
	return newTreeList;
};

void bankTreeList::connectedSignal()
{
	if(!noItem && ready)
	{
		ready = false;
		this->listIndex = 0;
		this->itemIndex = 0;
		this->currentPatchTreeItems.clear();
		this->currentPatchTreeItems = this->openPatchTreeItems;
		qSort(this->currentPatchTreeItems);
		updatePatchNames("");
	};
};

void bankTreeList::updateTree(QTreeWidgetItem *item)
{
	SysxIO *sysxIO = SysxIO::Instance();
	this->noItem = false;
	if(sysxIO->getConnected() && ready)
	{
		ready = false;
		this->listIndex = 0;
		this->itemIndex = 0;
		this->currentPatchTreeItems.clear();
		this->currentPatchTreeItems.append(item);
		updatePatchNames("");
	};
};

void bankTreeList::updatePatchNames(QString replyMsg)
{
	MidiTable *midiTable = MidiTable::Instance();
	Preferences *preferences = Preferences::Instance(); bool ok;
	int midiOut = preferences->getPreferences("Midi", "MidiOut", "device").toInt(&ok, 10);
	int midiIn = preferences->getPreferences("Midi", "MidiIn", "device").toInt(&ok, 10);

	midiIO *midi = new midiIO();
	QObject::connect(midi, SIGNAL(replyMsg(QString)), 
			this, SLOT(updatePatchNames(QString)));

	replyMsg = replyMsg.remove(" ").toUpper();
	
	if(replyMsg != "")
	{
		QString patchName; 
		int count = 0;
		int dataStartOffset = sysxDataOffset - 1;
		QString hex1, hex2, hex3, hex4;
		for(int i=dataStartOffset*2; i<replyMsg.size()-(2*2);++i)
		{
			hex1 = replyMsg.mid((sysxAddressOffset + 1)*2, 2);
			hex2 = replyMsg.mid((sysxAddressOffset + 2)*2, 2);
			hex3 = QString::number(count, 16).toUpper();
			if (hex3.length() < 2) hex3.prepend("0");
			hex4 = replyMsg.mid(i, 2);;
			patchName.append( midiTable->getValue("Stucture", hex1, hex2, hex3, hex4) );
			i++;
		};

		this->currentPatchTreeItems.at(listIndex)->child(itemIndex)->setText(0, patchName.trimmed());
		if(itemIndex >= patchPerBank - 1)
		{
			this->listIndex++;
		};
		itemIndex++;		
	};

	if(itemIndex >= patchPerBank)
	{
		this->itemIndex = 0;
	};

	if(listIndex < currentPatchTreeItems.size())
	{		
		int bank = this->currentPatchTreeItems.at(listIndex)->text(0).section(" ", 1, 1).trimmed().toInt(&ok, 10);
		int patch = itemIndex + 1 ;
		
		/* Patch name request. */
		QString sysxOut = midiTable->nameRequest(bank, patch);
		midi->sendSysxMsg(sysxOut, midiOut, midiIn);
	}
	else
	{
		ready = true;
	};
};