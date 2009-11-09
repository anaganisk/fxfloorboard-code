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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "floorBoard.h"
#include "sysxWriter.h"
#include "MidiTable.h"
#include <QPrintDialog>
#include <QPrinter>

class mainWindow : public QWidget
//class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = 0);
	~mainWindow();
	void closeEvent(QCloseEvent* ce);

signals:
	void updateSignal();
	void closed();

public slots:
	void updateSize(QSize floorSize, QSize oldFloorSize);
	void open();
	void save();
	void saveAs();
	void importSMF();
	void exportSMF();
	void openGXB();
	void saveGXB();
	void systemSave();
	void systemLoad();
	void bulkSave();
	void bulkLoad();
	void settings();
	void upload();
	void summaryPage();
	void help();
	void homepage();
	void donate();
	void license();
	void about();
	void print();

private:
	void createActions();
	void createMenus();
	void createStatusBar();

	QMenuBar *menuBar;
	QStatusBar *statusBar;
	QMenu *fileMenu;
	QMenu *toolsMenu;
	QMenu *helpMenu;
	QAction *openAct;
	QAction *saveAct;
	QAction *saveAsAct;
	QAction *importSMFAct;
	QAction *exportSMFAct;
	QAction *openGXBAct;
	QAction *saveGXBAct;
	QAction *systemLoadAct;
	QAction *systemSaveAct;
	QAction *bulkLoadAct;
	QAction *bulkSaveAct;
	QAction *exitAct;
	QAction *settingsAct;
	QAction *uploadAct;
	QAction *summaryAct;
	QAction *helpAct;
	QAction *homepageAct;
	QAction *donationAct;
	QAction *licenseAct;
	QAction *aboutAct;
	QAction *aboutQtAct;
	QAction *printAct;
  //QWidget *bulkDialog;
	sysxWriter file;
	floorBoard *fxsBoard;
};

#endif // MAINWINDOW_H
