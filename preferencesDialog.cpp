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

#include <QtGui>
#include "preferencesDialog.h"
#include "preferencesPages.h"


preferencesDialog::preferencesDialog()
{
	contentsWidget = new QListWidget;
	contentsWidget->setViewMode(QListView::IconMode);
	contentsWidget->setIconSize(QSize(55, 50));
	contentsWidget->setMovement(QListView::Static);
	contentsWidget->setSpacing(4);
	contentsWidget->setFixedWidth(75); // 70 to 75 for OS X.

	GeneralPage *generalSettings = new GeneralPage;
	MidiPage *midiSettings = new MidiPage;
	WindowPage *windowSettings = new WindowPage;

	this->generalSettings = generalSettings;
	this->midiSettings = midiSettings;
	this->windowSettings = windowSettings;

	pagesWidget = new QStackedWidget;
	pagesWidget->addWidget(generalSettings);
	pagesWidget->addWidget(midiSettings);
	pagesWidget->addWidget(windowSettings);
	/*pagesWidget->addWidget(new GeneralPage);
	pagesWidget->addWidget(new MidiPage);
	pagesWidget->addWidget(new WindowPage);*/
	
	QPushButton *okButton = new QPushButton(tr("Ok"));
	QPushButton *cancelButton = new QPushButton(tr("Cancel"));

	createIcons();
	contentsWidget->setCurrentRow(0);

	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *horizontalLayout = new QHBoxLayout;
	horizontalLayout->addWidget(contentsWidget);
	horizontalLayout->addWidget(pagesWidget, 1);

	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(okButton);
	buttonsLayout->addWidget(cancelButton);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(horizontalLayout);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addLayout(buttonsLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("GT-8 Fx FloorBoard - Preferences"));
};

void preferencesDialog::createIcons()
{
	QListWidgetItem *generalButton = new QListWidgetItem(contentsWidget);
	generalButton->setIcon(QIcon(":images/general.png"));
	generalButton->setText(tr("General"));
	generalButton->setTextAlignment(Qt::AlignHCenter);
	generalButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	QListWidgetItem *midiButton = new QListWidgetItem(contentsWidget);
	midiButton->setIcon(QIcon(":images/midi.png"));
	midiButton->setText(tr("Midi"));
	midiButton->setTextAlignment(Qt::AlignHCenter);
	midiButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	QListWidgetItem *windowButton = new QListWidgetItem(contentsWidget);
	windowButton->setIcon(QIcon(":images/window.png"));
	windowButton->setText(tr("Window"));
	windowButton->setTextAlignment(Qt::AlignHCenter);
	windowButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	connect(contentsWidget,
		SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
		this, SLOT(changePage(QListWidgetItem *, QListWidgetItem*)));
}

void preferencesDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
	if (!current)
	{
		current = previous;
	};
	pagesWidget->setCurrentIndex(contentsWidget->row(current));
};
