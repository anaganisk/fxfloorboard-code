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

#include <QtGui>
#include "summaryDialog.h"


summaryDialog::summaryDialog(QWidget *parent)
                  : QWidget(parent)
{
            
  this->textDialog = new QTextEdit(parent);
  textDialog->setReadOnly(true);
  
  
  
  QString text = "Hello this is some text to hopefully print out<br>";
  text.append(".                              [PRE-A][NS2][DELAY]                              <br>");
  text.append("[FV][COMP][wha][dist][FX1]                                            [chorus][REV][DGT]<br>");
  text.append(".                               [PRE-B][NS1][EQ] ");
   textDialog->show();
  
	textDialog->setText(text); 
	//QTextDocument *document = textDialog->document(); 
  
	
	QPushButton *cancelButton = new QPushButton(tr("Close"));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
  
  QPushButton *printButton = new QPushButton(tr("Print"));
  connect(printButton, SIGNAL(clicked()), this, SLOT(printFile()));
  
 
	QHBoxLayout *horizontalLayout = new QHBoxLayout;	
	horizontalLayout->addWidget(textDialog);

	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(printButton);
	buttonsLayout->addSpacing(12);
	buttonsLayout->addWidget(cancelButton);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(horizontalLayout);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addLayout(buttonsLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Patch File Summary"));
};

void summaryDialog::valueChanged(int value)
{
  
}; 

 void summaryDialog::cancel()
{
  SysxIO *sysxIO = SysxIO::Instance();
  sysxIO->patchListValue = 0;             
  this->close();
}; 

 void summaryDialog::printFile()
 {
   #ifndef QT_NO_PRINTER
    
     QPrinter printer;
     QPrintDialog *dialog = new QPrintDialog(&printer, this);
     dialog->setWindowTitle(tr("Print Document"));
       if (dialog->exec() != QDialog::Accepted)
         return;

     textDialog->print(&printer);
 #endif
 };

