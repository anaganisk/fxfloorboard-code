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

#include <QtGui>
#include "mainWindow.h"
#include "Preferences.h"
#include "preferencesDialog.h"
#include "statusBarWidget.h"
#include "SysxIO.h"
#include "globalVariables.h"


mainWindow::mainWindow(QWidget *parent)
    : QWidget(parent)
/* For a stange reason when deriving from QMainWindow 
	the performance is dead slow???

mainWindow::mainWindow(QWidget *parent)
	: QMainWindow(parent) */
{
	fxsBoard = new floorBoard(this);

	

	/* Loads the stylesheet for the current platform if present */
	#ifdef Q_OS_WIN
	/* This set the floorboard default style to the "plastique" style, 
	   as it comes the nearest what the stylesheet uses. */
	fxsBoard->setStyle(QStyleFactory::create("plastique"));
		if(QFile(":qss/windows.qss").exists())
		{
			QFile file(":qss/windows.qss");
			file.open(QFile::ReadOnly);
			QString styleSheet = QLatin1String(file.readAll());
			fxsBoard->setStyleSheet(styleSheet);
		}; 
	#endif

	#ifdef Q_WS_X11
	fxsBoard->setStyle(QStyleFactory::create("plastique"));
		if(QFile(":qss/linux.qss").exists())
		{
			QFile file(":qss/linux.qss");
			file.open(QFile::ReadOnly);
			QString styleSheet = QLatin1String(file.readAll());
			fxsBoard->setStyleSheet(styleSheet);
		}; 
	#endif

	#ifdef Q_WS_MAC
	fxsBoard->setStyle(QStyleFactory::create("plastique"));
		if(QFile(":qss/macosx.qss").exists())
		{
			QFile file(":qss/macosx.qss");
			file.open(QFile::ReadOnly);
			QString styleSheet = QLatin1String(file.readAll());
			fxsBoard->setStyleSheet(styleSheet);
		}; 
	#endif
	
	
	this->setWindowTitle(deviceType + " Fx FloorBoard");
	//this->setCentralWidget(fxsBoard);
	
	this->createActions();
	this->createMenus();
	this->createStatusBar();

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->setMenuBar(menuBar);
	mainLayout->addWidget(fxsBoard);
	mainLayout->addWidget(statusBar);
	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	mainLayout->setSizeConstraint(QLayout::SetFixedSize);
	setLayout(mainLayout);

	//this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	QObject::connect(fxsBoard, SIGNAL( sizeChanged(QSize, QSize) ),
                this, SLOT( updateSize(QSize, QSize) ) );
};

mainWindow::~mainWindow()
{
	Preferences *preferences = Preferences::Instance();
	if(preferences->getPreferences("Window", "Restore", "window")=="true")
	{
		QString posx, width;
		if(preferences->getPreferences("Window", "Restore", "sidepanel")=="true" &&
			preferences->getPreferences("Window", "Collapsed", "bool")=="true")
		{
			width = QString::number(this->geometry().width(), 10);
			posx = QString::number(this->geometry().x(), 10);
		}
		else
		{
			bool ok;
			width = preferences->getPreferences("Window", "Size", "minwidth");
			posx = QString::number(this->geometry().x()+((this->geometry().width()-width.toInt(&ok,10))/2), 10);
		};
		preferences->setPreferences("Window", "Position", "x", posx);
		preferences->setPreferences("Window", "Position", "y", QString::number(this->geometry().y(), 10));
		preferences->setPreferences("Window", "Size", "width", width);
		preferences->setPreferences("Window", "Size", "height", QString::number(this->geometry().height(), 10));
	}
	else
	{
		preferences->setPreferences("Window", "Position", "x", "");
		preferences->setPreferences("Window", "Position", "y", "");
		preferences->setPreferences("Window", "Size", "width", "");
		preferences->setPreferences("Window", "Size", "height", "");
	};
	preferences->savePreferences();
};

void mainWindow::updateSize(QSize floorSize, QSize oldFloorSize)
{
	this->setFixedWidth(floorSize.width());
	int x = this->geometry().x() - ((floorSize.width() - oldFloorSize.width()) / 2);
	int y = this->geometry().y();	
	this->setGeometry(x, y, floorSize.width(), this->geometry().height());
};

void mainWindow::createActions()
{
	openAct = new QAction(/*QIcon(":/images/open.png"),*/ tr("&Open File... (*.syx)"), this);
	openAct->setShortcut(tr("Ctrl+O"));
	openAct->setStatusTip(tr("Open an existing file"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
	
	saveAct = new QAction(/*QIcon(":/images/save.png"),*/ tr("&Save...       (*.syx)"), this);
	saveAct->setShortcut(tr("Ctrl+S"));
	saveAct->setStatusTip(tr("Save the document to disk"));
	connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

	saveAsAct = new QAction(/*QIcon(":/images/saveas.png"),*/ tr("Save &As...  (*.syx)"), this);
	saveAsAct->setShortcut(tr("Ctrl+Shift+S"));
	saveAsAct->setStatusTip(tr("Save the document under a new name"));
	connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));
	
	importSMFAct = new QAction(/*QIcon(":/images/importSMF.png"),*/ tr("&Import SMF... (*.mid)"), this);
	importSMFAct->setShortcut(tr("Ctrl+I"));
	importSMFAct->setStatusTip(tr("Import an existing SMF"));
	connect(importSMFAct, SIGNAL(triggered()), this, SLOT(importSMF()));
	
	exportSMFAct = new QAction(/*QIcon(":/images/exportSMF.png"),*/ tr("Export &SMF... (*.mid)"), this);
	exportSMFAct->setShortcut(tr("Ctrl+Shift+E"));
	exportSMFAct->setStatusTip(tr("Export as a Standard Midi File"));
	connect(exportSMFAct, SIGNAL(triggered()), this, SLOT(exportSMF()));
	
	bulkLoadAct = new QAction(/*QIcon(":/images/importSMF.png"),*/ tr("&Load Bulk Dump..."), this);
	bulkLoadAct->setShortcut(tr("Ctrl+L"));
	bulkLoadAct->setStatusTip(tr("Load Bulk Dump to GT-10B"));
	connect(bulkLoadAct, SIGNAL(triggered()), this, SLOT(bulkLoad()));

	bulkSaveAct = new QAction(/*QIcon(":/images/exportSMF.png"),*/ tr("Save &Bulk Dump..."), this);
	bulkSaveAct->setShortcut(tr("Ctrl+D"));
	bulkSaveAct->setStatusTip(tr("Save Bulk Dump to File"));
	connect(bulkSaveAct, SIGNAL(triggered()), this, SLOT(bulkSave()));

	exitAct = new QAction(tr("E&xit"), this);
	exitAct->setShortcut(tr("Ctrl+Q"));
	exitAct->setStatusTip(tr("Exit the application"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

	settingsAct = new QAction(/*QIcon(":/images/preferences.png"),*/ tr("&Preferences"), this);
	settingsAct->setShortcut(tr("Ctrl+P"));
	settingsAct->setStatusTip(tr("...."));
	connect(settingsAct, SIGNAL(triggered()), this, SLOT(settings()));

	helpAct = new QAction(/*QIcon(":/images/help.png"),*/ tr("GT-10 Fx FloorBoard &Help"), this);
	helpAct->setShortcut(tr("Ctrl+F1"));
	helpAct->setStatusTip(tr("....."));
	connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));

	homepageAct = new QAction(/*QIcon(":/images/home.png"),*/ tr("GT-10 Fx FloorBoard &Webpage"), this);
	homepageAct->setStatusTip(tr("........"));
	connect(homepageAct, SIGNAL(triggered()), this, SLOT(homepage()));

	donationAct = new QAction(/*QIcon(":/images/donate.png"),*/ tr("Donate towards a GT-10 for Gumtown"), this);
	donationAct->setStatusTip(tr("........"));
	connect(donationAct, SIGNAL(triggered()), this, SLOT(donate()));
	
	manualAct = new QAction(/*QIcon(":/images/manual.png"),*/ tr("User Manual PDF"), this);
	manualAct->setStatusTip(tr("........"));
	connect(manualAct, SIGNAL(triggered()), this, SLOT(manual())); 

	licenseAct = new QAction(/*QIcon(":/images/license.png"),*/ tr("&License"), this);
	licenseAct->setStatusTip(tr("........"));
	connect(licenseAct, SIGNAL(triggered()), this, SLOT(license()));

	aboutAct = new QAction(tr("&About FxFloorBoard"), this);
	aboutAct->setStatusTip(tr("Show the application's About box"));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

	aboutQtAct = new QAction(tr("About &Qt"), this);
	aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
	connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
};

void mainWindow::createMenus()
{
    menuBar = new QMenuBar;

    QMenu *fileMenu = new QMenu(tr("&File"), this);
	fileMenu->addAction(openAct);
	fileMenu->addAction(saveAct);
	fileMenu->addAction(saveAsAct);
	fileMenu->addSeparator();
	fileMenu->addAction(importSMFAct);
	fileMenu->addAction(exportSMFAct);
	fileMenu->addSeparator();
	fileMenu->addAction(bulkLoadAct);
	fileMenu->addAction(bulkSaveAct);
	fileMenu->addSeparator();
  fileMenu->addAction(exitAct);
	menuBar->addMenu(fileMenu);
    //menuBar()->addMenu(fileMenu);


	QMenu *toolsMenu = new QMenu(tr("&Tools"), this);
	toolsMenu->addAction(settingsAct);
	menuBar->addMenu(toolsMenu);
    //menuBar()->addMenu(toolsMenu);

	QMenu *helpMenu = new QMenu(tr("&Help"), this);
	helpMenu->addAction(helpAct);
	helpMenu->addAction(homepageAct);
	helpMenu->addSeparator();
	helpMenu->addAction(donationAct);
	helpMenu->addSeparator();
	helpMenu->addAction(manualAct);
	helpMenu->addAction(licenseAct);
	helpMenu->addSeparator(); 
	helpMenu->addAction(aboutAct);
	helpMenu->addAction(aboutQtAct);
	menuBar->addMenu(helpMenu);
    //menuBar()->addMenu(helpMenu);
};

void mainWindow::createStatusBar()
{
	SysxIO *sysxIO = SysxIO::Instance();

	statusBarWidget *statusInfo = new statusBarWidget(this);
	statusInfo->setStatusSymbol(0);
	statusInfo->setStatusMessage(tr("Not connected"));

	QObject::connect(sysxIO, SIGNAL(setStatusSymbol(int)),
                statusInfo, SLOT(setStatusSymbol(int)));
	QObject::connect(sysxIO, SIGNAL(setStatusProgress(int)),
                statusInfo, SLOT(setStatusProgress(int)));;
	QObject::connect(sysxIO, SIGNAL(setStatusMessage(QString)),
                statusInfo, SLOT(setStatusMessage(QString)));
  QObject::connect(sysxIO, SIGNAL(setStatusdBugMessage(QString)),
                statusInfo, SLOT(setStatusdBugMessage(QString)));


	statusBar = new QStatusBar;
	statusBar->addWidget(statusInfo);
	statusBar->setSizeGripEnabled(false);
};

/* FILE MENU */
void mainWindow::open()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getOpenFileName(
                this,
                "Choose a file",
                dir,
                "System Exclusive GT-10 & GT-8 (*.syx)");
	if (!fileName.isEmpty())	
	{
		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
			SysxIO *sysxIO = SysxIO::Instance();
			sysxIO->setFileSource(file.getFileSource());
			sysxIO->setFileName(fileName);
			sysxIO->setSyncStatus(false);
			sysxIO->setDevice(false);

			emit updateSignal();
		};
	};
};

void mainWindow::save()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	SysxIO *sysxIO = SysxIO::Instance();
	file.setFile(sysxIO->getFileName());

	if(file.getFileName().isEmpty())
	{
		QString fileName = QFileDialog::getSaveFileName(
						this,
						"Save As",
						dir,
						"System Exclusive (*.syx)");
		if (!fileName.isEmpty())	
		{
			if(!fileName.contains(".syx"))
			{
				fileName.append(".syx");
			};
			file.writeFile(fileName);

			file.setFile(fileName);  
			if(file.readFile())
			{	
				// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
				SysxIO *sysxIO = SysxIO::Instance();
				sysxIO->setFileSource(file.getFileSource());

				emit updateSignal();
			};
		};
	}
	else
	{
		file.writeFile(file.getFileName());
	};
};

void mainWindow::saveAs()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getSaveFileName(
                    this,
                    "Save As",
                    dir,
                    "System Exclusive (*.syx)");
	if (!fileName.isEmpty())	
	{
		if(!fileName.contains(".syx"))
		{
			fileName.append(".syx");
		};
		file.writeFile(fileName);

		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
			SysxIO *sysxIO = SysxIO::Instance();
			sysxIO->setFileSource(file.getFileSource());

			emit updateSignal();
		};
	};
};

void mainWindow::importSMF()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getOpenFileName(
                this,
                "Choose a file",
                dir,
                "Standard Midi File (*.mid)");
	if (!fileName.isEmpty())	
	{
		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
			SysxIO *sysxIO = SysxIO::Instance();
			sysxIO->setFileSource(file.getFileSource());
			sysxIO->setFileName(fileName);
			sysxIO->setSyncStatus(false);
			sysxIO->setDevice(false);

			emit updateSignal();
		};
	};
};

void mainWindow::exportSMF()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getSaveFileName(
                    this,
                    "Export SMF",
                    dir,
                    "Standard Midi File (*.mid)");
	if (!fileName.isEmpty())	
	{
		if(!fileName.contains(".mid"))
		{
			fileName.append(".mid");
		};
		file.writeSMF(fileName);

		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
			SysxIO *sysxIO = SysxIO::Instance();
			sysxIO->setFileSource(file.getFileSource());

			emit updateSignal();
		};
	};
};

void mainWindow::bulkLoad()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getOpenFileName(
                this,
                "Choose a file",
                dir,
                "Bulk Dump File (*.syx)");
	if (!fileName.isEmpty())	
	{
		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
		
		};
	};
};

void mainWindow::bulkSave()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getSaveFileName(
                    this,
                    "Save Bulk Dump",
                    dir,
                    "System Exclusive File (*.syx)");
	if (!fileName.isEmpty())	
	{
		if(!fileName.contains(".syx"))
		{
			fileName.append(".syx");
		};
		
		file.writeFile(fileName);

		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
		
		};
	};
};

/* TOOLS MENU */
void mainWindow::settings()
{
	preferencesDialog *dialog = new preferencesDialog();
	if (dialog->exec())
	{
		Preferences *preferences = Preferences::Instance();

		QString dir = dialog->generalSettings->dirEdit->text();
		QString sidepanel = (dialog->windowSettings->sidepanelCheckBox->checkState())?QString("true"):QString("false");
		QString window = (dialog->windowSettings->windowCheckBox->checkState())?QString("true"):QString("false");
		QString splash = (dialog->windowSettings->splashCheckBox->checkState())?QString("true"):QString("false");
		QString dBug = (dialog->midiSettings->dBugCheckBox->checkState())?QString("true"):QString("false");
		QString midiIn = QString::number(dialog->midiSettings->midiInCombo->currentIndex() - 1, 10); // -1 because there is a default entry at index 0
		QString midiOut = QString::number(dialog->midiSettings->midiOutCombo->currentIndex() - 1, 10);
		QString midiTimeSet =QString::number(dialog->midiSettings->midiTimeSpinBox->value());
		QString receiveTimeout =QString::number(dialog->midiSettings->midiDelaySpinBox->value());

		if(midiIn=="-1") { midiIn = ""; };
		if(midiOut=="-1") {	midiOut = ""; };

		preferences->setPreferences("General", "Files", "dir", dir);
		preferences->setPreferences("Midi", "MidiIn", "device", midiIn);
		preferences->setPreferences("Midi", "MidiOut", "device", midiOut);
		preferences->setPreferences("Midi", "DBug", "bool", dBug);
		preferences->setPreferences("Midi", "Time", "set", midiTimeSet);
		preferences->setPreferences("Midi", "Delay", "set", receiveTimeout);
		preferences->setPreferences("Window", "Restore", "sidepanel", sidepanel);
		preferences->setPreferences("Window", "Restore", "window", window);
		preferences->setPreferences("Window", "Splash", "bool", splash);
	};
};

/* HELP MENU */
void mainWindow::help()
{
	Preferences *preferences = Preferences::Instance();
	QDesktopServices::openUrl(QUrl( preferences->getPreferences("General", "Help", "url") ));
};

void mainWindow::homepage()
{
	Preferences *preferences = Preferences::Instance();
	QDesktopServices::openUrl(QUrl( preferences->getPreferences("General", "Webpage", "url") ));
};

void mainWindow::donate()
{
	Preferences *preferences = Preferences::Instance();
	QDesktopServices::openUrl(QUrl( preferences->getPreferences("General", "Donate", "url") ));
};

void mainWindow::manual()
{
	Preferences *preferences = Preferences::Instance();
	QDesktopServices::openUrl(QUrl( preferences->getPreferences("General", "Manual", "url") ));
}; 

void mainWindow::license()
{
	QDesktopServices::openUrl(QUrl(":license.txt"));
};

void mainWindow::about()
{
    Preferences *preferences = Preferences::Instance();
	QString version = preferences->getPreferences("General", "Application", "version");
	
	QFile file(":about"); 
	if(file.open(QIODevice::ReadOnly))
	{	
		QMessageBox::about(this, tr("GT-10 Fx FloorBoard - About"), 
			"GT-10 Fx FloorBoard, " + tr("version") + " " + version + "\n" + file.readAll());
	};
};

void mainWindow::closeEvent(QCloseEvent* ce)
{
	Preferences *preferences = Preferences::Instance();
	preferences->savePreferences();
	ce->accept();
	emit closed();
};
