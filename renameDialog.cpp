/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
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

#include "renameDialog.h"
#include "SysxIO.h"

renameDialog::renameDialog(QWidget *parent)
     : QDialog(parent)
{
	SysxIO *sysxIO = SysxIO::Instance();
  QRegExp rx( QString::fromUtf8( "[\x20-\x7F\xe2\x86\x92\xe2\x86\x90]{1,16}" ) );
	QValidator *validator = new QRegExpValidator(rx, this);
	
	nameLabel = new QLabel(tr("Name:"));
	nameEdit = new QLineEdit(sysxIO->getCurrentPatchName());
	nameEdit->setValidator(validator);
	
	charLabel = new QLabel(tr("Insert :"));
	charLabel->setAlignment(Qt::AlignRight|Qt::AlignBottom);

	QPushButton *cancelButton =	new QPushButton(tr("Cancel"));
	QPushButton *okButton = new QPushButton(tr("Apply"));

	connect(okButton, SIGNAL(clicked()), this, SLOT(emitValue()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

	QGroupBox *renameGroup = new QGroupBox(tr("Rename patch"));
	
	QHBoxLayout *nameEditLayout = new QHBoxLayout;
	nameEditLayout->addWidget(nameEdit);

	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(okButton);
	buttonsLayout->addWidget(cancelButton);

	QHBoxLayout *nameLayout = new QHBoxLayout;
	nameLayout->addWidget(nameLabel);
	nameLayout->addLayout(nameEditLayout);

	QVBoxLayout *renameLayout = new QVBoxLayout;
	renameLayout->addLayout(nameLayout);
	renameGroup->setLayout(renameLayout);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(renameGroup);
	mainLayout->addLayout(buttonsLayout);
	setLayout(mainLayout);

	this->setMinimumWidth(250);
};

void renameDialog::emitValue()
{
	emit nameChanged(nameEdit->text());
	this->accept();
};
