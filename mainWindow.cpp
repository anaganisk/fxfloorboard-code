/****************************************************************************
**
** Copyright (C) 2005-2006 Uco Mesdag. All rights reserved.
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
#include "mainWindow.h"
#include "floorBoard.h"
#include "Preferences.h"	

mainWindow::mainWindow(QWidget *parent)
    : QWidget(parent)
{
	createMenu();

	floorBoard *fxsBoard = new floorBoard(this);

	QObject::connect(fxsBoard, SIGNAL( sizeChanged(QSize) ),
                this, SLOT( updateSize(QSize) ) );

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->setMenuBar(menuBar);
	mainLayout->addWidget(fxsBoard);
	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	mainLayout->setSizeConstraint(QLayout::SetFixedSize);
	setLayout(mainLayout);
	
	/*
	Preferences *preferences = Preferences::Instance();
	QString version = preferences->getPreferences("General", "Application", "version");
	setWindowTitle("GT-8 FX FloorBoard - v" + version);
	*/

	setWindowTitle("GT-8 FX FloorBoard - NON FUNCTIONAL!!! (Interface Preview)");
};

mainWindow::~mainWindow()
{
	Preferences *preferences = Preferences::Instance();
	preferences->setPreferences("Window", "Position", "x", QString::number(this->x(), 10));
	preferences->setPreferences("Window", "Position", "y", QString::number(this->y(), 10));
};

void mainWindow::createMenu()
{
    menuBar = new QMenuBar;

    QMenu *fileMenu = new QMenu("&File", this);
	QAction *openAction = fileMenu->addAction("&Open File...");
	QAction *saveAction = fileMenu->addAction("&Save");
	QAction *saveAsAction = fileMenu->addAction("Save &As...");
	fileMenu->addSeparator();
    QAction *exitAction = fileMenu->addAction("E&xit");
    menuBar->addMenu(fileMenu);

	QMenu *toolsMenu = new QMenu("&Tools", this);
	QAction *settingsAction = toolsMenu->addAction("&Preferences");
    menuBar->addMenu(toolsMenu);

	QMenu *helpMenu = new QMenu("&Help", this);
	QAction *helpAction = helpMenu->addAction("GT-8 FX FloorBoard &Help");
	QAction *homepageAction = helpMenu->addAction("GT-8 FX FloorBoard &Webpage");
	helpMenu->addSeparator();
	QAction *donationAction = helpMenu->addAction("Make a &Donation");
	QAction *licenseAction = helpMenu->addAction("&License");
	helpMenu->addSeparator(); QAction *aboutAction = helpMenu->addAction("&About");
    menuBar->addMenu(helpMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
	
	connect(helpAction, SIGNAL(triggered()), this, SLOT(help()));
	connect(homepageAction, SIGNAL(triggered()), this, SLOT(homepage()));
	connect(donationAction, SIGNAL(triggered()), this, SLOT(donate()));
	connect(licenseAction, SIGNAL(triggered()), this, SLOT(license()));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

};

void mainWindow::updateSize(QSize floorSize)
{
	this->setFixedWidth(floorSize.width());
};

/* HELP MENU */
void mainWindow::help()
{
	Preferences *preferences = Preferences::Instance();
	QUrl helpUrl( preferences->getPreferences("General", "Help", "url") );
	QDesktopServices::openUrl(helpUrl);
};

void mainWindow::homepage()
{
	Preferences *preferences = Preferences::Instance();
	QUrl homepageUrl( preferences->getPreferences("General", "Webpage", "url") );
	QDesktopServices::openUrl(homepageUrl);
};

void mainWindow::donate()
{
	Preferences *preferences = Preferences::Instance();
	QUrl donateUrl( preferences->getPreferences("General", "Donate", "url") );
	QDesktopServices::openUrl(donateUrl);
};

void mainWindow::license()
{
	/*
	QString licensePath = QDir::currentPath();
	licensePath.append("/license.txt");
	QUrl licenseUrl = QUrl::fromLocalFile(licensePath);
	QDesktopServices::openUrl(licenseUrl);
	*/
	QUrl licenseUrl(":license.txt");
	QDesktopServices::openUrl(licenseUrl);
};

void mainWindow::about()
{
    Preferences *preferences = Preferences::Instance();
	QString version = preferences->getPreferences("General", "Application", "version");
	
	QFile file(":about"); 
	if(file.open(QIODevice::ReadOnly))
	{	
		QMessageBox::about(this, "About GT-8 Fx FloorBoard", "GT-8 FX FloorBoard, version " + version + "\n" + file.readAll());
	};
};

