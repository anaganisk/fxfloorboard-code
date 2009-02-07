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

#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QList>
#include <QCloseEvent>
#include "editPage.h"
#include "customControlLabel.h"

class editWindow : public QWidget
{
    Q_OBJECT

public:
    editWindow(QWidget *parent = 0);
	~editWindow();
	//virtual void closeEvent(QCloseEvent* ce);

	void setLSB(QString hex1, QString hex2);
	void setWindow(QString title);
	QString getTitle();
	void addPage(QString hex1 = "void", QString hex2 = "void", QString hex3 = "void", QString hex4 = "void", QString area = "Structure");
	editPage* page();

signals:
	void dialogUpdateSignal();
	void updateSignal();
	void updateDisplay(QString text);
	void closeWindow();

public slots:
	void valueChanged(int index);
	void pageUpdateSignal();
	virtual void closeEvent(QCloseEvent* ce);
	
protected:
	void paintEvent(QPaintEvent *event);

private:
	QPixmap image;
	QString hex1;
	QString hex2;
	QString hex3;
	QString area;
	int pages;
	QLabel* title;
	QLabel* comboBoxLabel;
	QStackedWidget* pagesWidget;
	QComboBox* pageComboBox;
	customControlLabel* closeButton;
	editPage* tempPage;
	QList<editPage*> editPages;
};

#endif // EDITWINDOW_H

