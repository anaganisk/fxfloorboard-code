/****************************************************************************
**
** Copyright (C) 2007, 2008, 2009 Colin Willcocks.
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. 
** All rights reserved.
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

#include <QtGui>
#include "fileDialog.h"


fileDialog::fileDialog(QString fileName, QList<QString> patchList)
{
    QObject::connect(this, SIGNAL(patchIndex(int)),
                this->parent(), SLOT(patchIndex(int)));
                
  QLabel *patchLabel = new QLabel(tr("Select patch to load"));
  QLabel *nameLabel = new QLabel(fileName);
	QComboBox *patchCombo = new QComboBox;
	patchCombo->addItems(patchList);
	
  QObject::connect(patchCombo, SIGNAL(currentIndexChanged(int)),
                this, SLOT(valueChanged(int)));
  
	QPushButton *cancelButton = new QPushButton(tr("Cancel"));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
  
 
	QHBoxLayout *horizontalLayout = new QHBoxLayout;	
	horizontalLayout->addWidget(patchLabel);
	horizontalLayout->addWidget(patchCombo);

	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addStretch(1);
	//buttonsLayout->addWidget(cancelButton);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(nameLabel);
	mainLayout->addLayout(horizontalLayout);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addLayout(buttonsLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Bulk File Patch Extraction"));
};

void fileDialog::valueChanged(int value)
{
  SysxIO *sysxIO = SysxIO::Instance();
  sysxIO->patchListValue = value;             
  this->close();
}; 





