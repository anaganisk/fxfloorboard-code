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
#include "mainWindow.h"
#include "Preferences.h"
#include "preferencesDialog.h"
#include "statusBarWidget.h"
#include "SysxIO.h"
#include "bulkSaveDialog.h"
#include "bulkLoadDialog.h"
#include "summaryDialog.h"
#include "globalVariables.h"


 mainWindow::mainWindow(QWidget *parent)
    : QWidget(parent)
/* For a stange reason when deriving from QMainWindow 
	the performance is dead slow??? */

//mainWindow::mainWindow(QWidget *parent)
	//: QMainWindow(parent) 
{
	floorBoard *fxsBoard = new floorBoard(this);
  //fxsBoard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	

	/* Loads the stylesheet for the current platform if present */
#ifdef Q_OS_WIN
	/* This set the floorboard default style to the "plastique" style, 
	   as it comes the nearest what the stylesheet uses. */
	//fxsBoard->setStyle(QStyleFactory::create("plastique"));
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
	
	
	this->setWindowTitle(deviceType + tr(" Fx FloorBoard"));
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
        //mainLayout->setSizeConstraint(QLayout::SetFixedSize);
	setLayout(mainLayout);

  

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
	openAct = new QAction(QIcon(":/images/fileopen.png"), tr("&Load Patch File... (*.syx *.mid *.gxb *.gxg)"), this);
	openAct->setShortcut(tr("Ctrl+O"));
	openAct->setStatusTip(tr("Open an existing file"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
	
	saveAct = new QAction(QIcon(":/images/filesave.png"), tr("&Save Patch...       (*.syx)"), this);
	saveAct->setShortcut(tr("Ctrl+S"));
	saveAct->setStatusTip(tr("Save the document to disk"));
	connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

	saveAsAct = new QAction(QIcon(":/images/filesave.png"), tr("Save &As Patch...  (*.syx)"), this);
	saveAsAct->setShortcut(tr("Ctrl+Shift+S"));
	saveAsAct->setStatusTip(tr("Save the document under a new name"));
	connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));
	
	importSMFAct = new QAction(QIcon(":/images/fileopen.png"), tr("&Import SMF... (*.mid)"), this);
	importSMFAct->setShortcut(tr("Ctrl+I"));
	importSMFAct->setStatusTip(tr("Import an existing SMF"));
	connect(importSMFAct, SIGNAL(triggered()), this, SLOT(importSMF()));

	exportSMFAct = new QAction(QIcon(":/images/filesave.png"), tr("Save As &SMF Patch... (*.mid)"), this);
	exportSMFAct->setShortcut(tr("Ctrl+Shift+E"));
	exportSMFAct->setStatusTip(tr("Export as a Standard Midi File"));
	connect(exportSMFAct, SIGNAL(triggered()), this, SLOT(exportSMF()));
	
  openGXBAct = new QAction(QIcon(":/images/fileopen.png"), tr("&Open GXB... (*.gxb *.gxg)"), this);
	openGXBAct->setShortcut(tr("Ctrl+K"));
	openGXBAct->setStatusTip(tr("Import a Boss Librarian File"));
	connect(openGXBAct, SIGNAL(triggered()), this, SLOT(openGXB()));

	saveGXBAct = new QAction(QIcon(":/images/filesave.png"), tr("Save As GXB Patch... (*.gxb)"), this);
	saveGXBAct->setShortcut(tr("Ctrl+Shift+G"));
	saveGXBAct->setStatusTip(tr("Export as a Boss Librarian File"));
	connect(saveGXBAct, SIGNAL(triggered()), this, SLOT(saveGXB()));	
	
	systemLoadAct = new QAction(QIcon(":/images/fileopen.png"), tr("&Load System and Global Data..."), this);
	systemLoadAct->setShortcut(tr("Ctrl+L"));
	systemLoadAct->setStatusTip(tr("Load System Data to GT-10B"));
	connect(systemLoadAct, SIGNAL(triggered()), this, SLOT(systemLoad()));

	systemSaveAct = new QAction(QIcon(":/images/filesave.png"), tr("Save System and Global Data to File..."), this);
	systemSaveAct->setShortcut(tr("Ctrl+D"));
	systemSaveAct->setStatusTip(tr("Save System Data to File"));
	connect(systemSaveAct, SIGNAL(triggered()), this, SLOT(systemSave()));
	
	bulkLoadAct = new QAction(QIcon(":/images/fileopen.png"), tr("&Load Bulk Patch File to GT-10B..."), this);
	bulkLoadAct->setShortcut(tr("Ctrl+B"));
	bulkLoadAct->setStatusTip(tr("Load Bulk Data to GT-10B"));
	connect(bulkLoadAct, SIGNAL(triggered()), this, SLOT(bulkLoad()));

	bulkSaveAct = new QAction(QIcon(":/images/filesave.png"), tr("Save Bulk GT-10B Patches to File..."), this);
	bulkSaveAct->setShortcut(tr("Ctrl+G"));
	bulkSaveAct->setStatusTip(tr("Save Bulk Data to File"));
	connect(bulkSaveAct, SIGNAL(triggered()), this, SLOT(bulkSave()));
	
	printAct = new QAction(QIcon(":/images/filesave.png"), tr("Print Page..."), this);
	printAct->setShortcut(tr("Ctrl+F12"));
	printAct->setStatusTip(tr("Print Screen"));
	connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

	exitAct = new QAction(QIcon(":/images/exit.png"),tr("E&xit"), this);
	exitAct->setShortcut(tr("Ctrl+Q"));
	exitAct->setStatusTip(tr("Exit the application"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

	settingsAct = new QAction(QIcon(":/images/preferences.png"), tr("&Preferences"), this);
	settingsAct->setShortcut(tr("Ctrl+P"));
	settingsAct->setStatusTip(tr("...."));
	connect(settingsAct, SIGNAL(triggered()), this, SLOT(settings()));
	
	uploadAct = new QAction(QIcon(":/images/upload.png"), tr("Upload patch to GT-Central"), this);
	uploadAct->setStatusTip(tr("........"));
	connect(uploadAct, SIGNAL(triggered()), this, SLOT(upload()));
	
	summaryAct = new QAction(QIcon(":/images/upload.png"), tr("Summary Page & Print"), this);
	summaryAct->setStatusTip(tr("........"));
	connect(summaryAct, SIGNAL(triggered()), this, SLOT(summaryPage()));

	helpAct = new QAction(QIcon(":/images/help.png"), tr("GT-10B Fx FloorBoard &Help"), this);
	helpAct->setShortcut(tr("Ctrl+F1"));
	helpAct->setStatusTip(tr("....."));
	connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));

	homepageAct = new QAction(QIcon(":/images/webpage.png"), tr("GT-10B Fx FloorBoard &Webpage"), this);
	homepageAct->setStatusTip(tr("........"));
	connect(homepageAct, SIGNAL(triggered()), this, SLOT(homepage()));

	donationAct = new QAction(QIcon(":/images/donate.png"), tr("Donate towards GT test equipment for Gumtown"), this);
	donationAct->setStatusTip(tr("........"));
	connect(donationAct, SIGNAL(triggered()), this, SLOT(donate()));

	licenseAct = new QAction(QIcon(":/images/licence.png"), tr("&License"), this);
	licenseAct->setStatusTip(tr("........"));
	connect(licenseAct, SIGNAL(triggered()), this, SLOT(license()));

	aboutAct = new QAction(QIcon(":/images/GT-10BFxFloorBoard.png"),tr("&About FxFloorBoard"), this);
	aboutAct->setStatusTip(tr("Show the application's About box"));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

	aboutQtAct = new QAction(QIcon(":/images/qt-logo.png"),tr("About &Qt"), this);
	aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
	connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
};

void mainWindow::createMenus()
{
    menuBar = new QMenuBar;

  QMenu *fileMenu = new QMenu(tr("&File"), this);
	fileMenu->addAction(openAct);
	fileMenu->addSeparator();
	fileMenu->addAction(saveAct);
	fileMenu->addAction(saveAsAct);
	fileMenu->addSeparator();
	//fileMenu->addAction(importSMFAct);
	fileMenu->addAction(exportSMFAct);
	fileMenu->addSeparator();
	//fileMenu->addAction(openGXBAct);
	fileMenu->addAction(saveGXBAct);
	fileMenu->addSeparator();
	fileMenu->addAction(systemLoadAct);
	fileMenu->addAction(systemSaveAct);
	fileMenu->addSeparator();
	fileMenu->addAction(bulkLoadAct);
	fileMenu->addAction(bulkSaveAct);
	fileMenu->addSeparator();
  fileMenu->addAction(printAct);
	fileMenu->addSeparator();
  fileMenu->addAction(exitAct);
	menuBar->addMenu(fileMenu);
  

	QMenu *toolsMenu = new QMenu(tr("&Tools"), this);
	toolsMenu->addAction(settingsAct);
	fileMenu->addSeparator();
	toolsMenu->addAction(uploadAct);
	fileMenu->addSeparator();
	toolsMenu->addAction(summaryAct);
	menuBar->addMenu(toolsMenu);
 
	QMenu *helpMenu = new QMenu(tr("&Help"), this);
	helpMenu->addAction(helpAct);
	helpMenu->addAction(homepageAct);
	helpMenu->addSeparator();
	helpMenu->addAction(donationAct);
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

	QObject::connect(sysxIO, SIGNAL(setStatusSymbol(int)), statusInfo, SLOT(setStatusSymbol(int)));
	QObject::connect(sysxIO, SIGNAL(setStatusProgress(int)), statusInfo, SLOT(setStatusProgress(int)));
	QObject::connect(sysxIO, SIGNAL(setStatusMessage(QString)), statusInfo, SLOT(setStatusMessage(QString)));
  QObject::connect(sysxIO, SIGNAL(setStatusdBugMessage(QString)), statusInfo, SLOT(setStatusdBugMessage(QString)));
  
 
  
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
                tr("Choose a file"),
                dir,
                tr("for GT-10B, GT-10, & GT-6B (*.syx *.mid *.gxb *.gxg)"));
	if (!fileName.isEmpty())	
	{
		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
			SysxIO *sysxIO = SysxIO::Instance();
			QString area = "Structure";
			sysxIO->setFileSource(area, file.getFileSource());
			sysxIO->setFileName(fileName);
			sysxIO->setSyncStatus(false);
			sysxIO->setDevice(false);
			emit updateSignal();
			if(sysxIO->isConnected())
			{sysxIO->writeToBuffer(); };
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
						tr("Save As"),
						dir,
						tr("System Exclusive (*.syx)"));
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
				QString area = "Structure";
				sysxIO->setFileSource(area, file.getFileSource());

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
                    tr("Save As"),
                    dir,
                    tr("System Exclusive (*.syx)"));
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
			QString area = "Structure";
			sysxIO->setFileSource(area, file.getFileSource());

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
                tr("Choose a file"),
                dir,
                tr("Standard Midi File (*.mid)"));
	if (!fileName.isEmpty())	
	{
		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
			SysxIO *sysxIO = SysxIO::Instance();
			QString area = "Structure";
			sysxIO->setFileSource(area, file.getFileSource());
			sysxIO->setFileName(fileName);
			sysxIO->setSyncStatus(false);
			sysxIO->setDevice(false);

			emit updateSignal();
			if(sysxIO->isConnected())
			{sysxIO->writeToBuffer(); };
		};
	};
};

void mainWindow::exportSMF()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getSaveFileName(
                    this,
                    tr("Export SMF"),
                    dir,
                    tr("Standard Midi File (*.mid)"));
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
			QString area = "Structure";
			sysxIO->setFileSource(area, file.getFileSource());

			emit updateSignal();
		};
	};
};

void mainWindow::openGXB()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("Choose a file"),
                dir,
                tr("Boss Librarian File (*.gxb *.gxg)"));
	if (!fileName.isEmpty())	
	{
		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
			SysxIO *sysxIO = SysxIO::Instance();
			QString area = "Structure";
			sysxIO->setFileSource(area, file.getFileSource());
			sysxIO->setFileName(fileName);
			sysxIO->setSyncStatus(false);
			sysxIO->setDevice(false);

			emit updateSignal();
			if(sysxIO->isConnected())
			{sysxIO->writeToBuffer(); };
		};
	};
};

void mainWindow::saveGXB()
{
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getSaveFileName(
                    this,
                    tr("Export GXB"),
                    dir,
                    tr("Boss Librarian File (*.gxb)"));
	if (!fileName.isEmpty())	
	{
		if(!fileName.contains(".gxb"))
		{
			fileName.append(".gxb");
		};
		file.writeGXB(fileName);

		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
			SysxIO *sysxIO = SysxIO::Instance();
			QString area = "Structure";
			sysxIO->setFileSource(area, file.getFileSource());

			emit updateSignal();
		};
	};
};

void mainWindow::systemLoad()
{
   SysxIO *sysxIO = SysxIO::Instance();
     if (sysxIO->isConnected())
	       {
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("Choose a file"),
                dir,
                tr("GT10B Bulk Data File (*.GT10B_system_syx)"));
	if (!fileName.isEmpty())	
	{
		file.setFile(fileName);  
		if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
	
		  SysxIO *sysxIO = SysxIO::Instance();
		  sysxIO->setFileName(fileName);

			emit updateSignal();
                        QMessageBox *msgBox = new QMessageBox();
                                        msgBox->setWindowTitle(deviceType + tr(" Fx FloorBoard"));
                                        msgBox->setIcon(QMessageBox::Warning);
                                        msgBox->setTextFormat(Qt::RichText);
                                        QString msgText;
                                        msgText.append("<font size='+1'><b>");
                                        msgText.append(tr("You have chosen to load a BULK DATA backup file."));
                                        msgText.append("<b></font><br>");
                                        msgText.append(tr("This will overwrite the GT-10B DATA currently stored in the GT-10B<br>"));
                                        msgText.append(tr (" and can't be undone.<br>"));
                                        msgText.append(tr("Select 'NO' to only update the Editor - Select 'YES' to update the GT-10B memory<br>"));


                                        msgBox->setInformativeText(tr("Are you sure you want to write to the GT-10B?"));
                                        msgBox->setText(msgText);
                                        msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

                                        if(msgBox->exec() == QMessageBox::Yes)
                                        {	// Accepted to overwrite system data.
                                        sysxIO->systemWrite();
                                        };
		};
	};
	}
         else
             {
              QString snork = tr("Ensure connection is active and retry");
              QMessageBox *msgBox = new QMessageBox();
			        msgBox->setWindowTitle(deviceType + tr(" not connected !!"));
		        	msgBox->setIcon(QMessageBox::Information);
		        	msgBox->setText(snork);
		        	msgBox->setStandardButtons(QMessageBox::Ok);
		        	msgBox->exec(); 
              };  
};

void mainWindow::systemSave()
{ 
SysxIO *sysxIO = SysxIO::Instance();
     if (sysxIO->isConnected())
	       {
  sysxIO->systemDataRequest();
  
	Preferences *preferences = Preferences::Instance();
	QString dir = preferences->getPreferences("General", "Files", "dir");

	QString fileName = QFileDialog::getSaveFileName(
                    this,
                    tr("Save System Data"),
                    dir,
                    tr("System Exclusive File (*.GT10B_system_syx)"));
	if (!fileName.isEmpty())	
	{
	  if(!fileName.contains(".GT10B_system_syx"))
		{
			fileName.append(".GT10B_system_syx");
		};
    	
		file.writeSystemFile(fileName);
		file.setFile(fileName);  
		if(file.readFile())
		{	
		  SysxIO *sysxIO = SysxIO::Instance();
			QString area = "System";
			sysxIO->setFileSource(area, file.getSystemSource());
			emit updateSignal();
		};
	};
	 }
         else
             { 
              QString snork = tr("Ensure connection is active and retry");
              QMessageBox *msgBox = new QMessageBox();
			        msgBox->setWindowTitle(deviceType + tr(" not connected !!"));
		        	msgBox->setIcon(QMessageBox::Information);
		        	msgBox->setText(snork);
		        	msgBox->setStandardButtons(QMessageBox::Ok);
		        	msgBox->exec(); 
              };  
   
};

void mainWindow::bulkLoad()
{
   SysxIO *sysxIO = SysxIO::Instance();
     if (sysxIO->isConnected())
	       {
	
		bulkLoadDialog *loadDialog = new bulkLoadDialog(); 
            loadDialog->exec(); 
 
		/*if(file.readFile())
		{	
			// DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
	
		  SysxIO *sysxIO = SysxIO::Instance();
			sysxIO->setFileName(fileName);

                        QMessageBox *msgBox = new QMessageBox();
                                        msgBox->setWindowTitle(deviceType + tr(" Fx FloorBoard"));
                                        msgBox->setIcon(QMessageBox::Warning);
                                        msgBox->setTextFormat(Qt::RichText);
                                        QString msgText;
                                        msgText.append("<font size='+1'><b>");
                                        msgText.append(tr("You have chosen to load a BULK DATA file."));
                                        msgText.append("<b></font><br>");
                                        msgText.append(tr("This will overwrite the SYSTEM or PATCH DATA currently stored in the GT-10B<br>"));
                                        msgText.append(tr (" and can't be undone.<br>"));
                                        //msgText.append(tr("Select 'NO' to only update the Editor - Select 'YES' to update the GT-10B memory<br>"));


                                        msgBox->setInformativeText(tr("Are you sure you want to write to the GT-10B?"));
                                        msgBox->setText(msgText);
                                        msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

                                        if(msgBox->exec() == QMessageBox::Yes)
                                        {	// Accepted to overwrite system data.
                                        sysxIO->systemWrite();
                                        };
		};
	};      */
	}
         else
             {
              QString snork = tr("Ensure connection is active and retry");
              QMessageBox *msgBox = new QMessageBox();
			        msgBox->setWindowTitle(deviceType + tr(" not connected !!"));
		        	msgBox->setIcon(QMessageBox::Information);
		        	msgBox->setText(snork);
		        	msgBox->setStandardButtons(QMessageBox::Ok);
		        	msgBox->exec(); 
              };  
};

void mainWindow::bulkSave()
{ 
     
 SysxIO *sysxIO = SysxIO::Instance();
     if (sysxIO->isConnected())
	       {
            bulkSaveDialog *bulkDialog = new bulkSaveDialog(); 
            bulkDialog->exec(); 
	        }
           else
             { 
              QString snork = tr("Ensure connection is active and retry");
              QMessageBox *msgBox = new QMessageBox();
			        msgBox->setWindowTitle(deviceType + tr(" not connected !!"));
		        	msgBox->setIcon(QMessageBox::Information);
		        	msgBox->setText(snork);
		        	msgBox->setStandardButtons(QMessageBox::Ok);
		        	msgBox->exec(); 
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
		 QString lang;
    if (dialog->languageSettings->chineseButton->isChecked() ) {lang="3"; }
    else if (dialog->languageSettings->germanButton->isChecked() ) {lang="2"; }
    else if (dialog->languageSettings->frenchButton->isChecked() ) {lang="1"; }
    else  {lang="0"; };
    preferences->setPreferences("Language", "Locale", "select", lang);

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
		preferences->savePreferences();
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

void mainWindow::upload()
{
	Preferences *preferences = Preferences::Instance();
	QDesktopServices::openUrl(QUrl( preferences->getPreferences("General", "Upload", "url") ));
};

void mainWindow::summaryPage()
{
   summaryDialog *summary = new summaryDialog();
   summary->show();
};
void mainWindow::donate()
{
	Preferences *preferences = Preferences::Instance();
	QDesktopServices::openUrl(QUrl( preferences->getPreferences("General", "Donate", "url") ));
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
		QMessageBox::about(this, tr("GT-10B Fx FloorBoard - About"), 
			tr("GT-10B Fx FloorBoard, ") + tr("version") + " " + version + "<br>" + file.readAll());
	};
};

void mainWindow::closeEvent(QCloseEvent* ce)
{
	Preferences *preferences = Preferences::Instance();
	preferences->savePreferences();
	ce->accept();
	emit closed();
};

void mainWindow::print()
 {
   #ifndef QT_NO_PRINTER
    
     QPrinter printer;
     QPrintDialog *dialog = new QPrintDialog(&printer, this);
     dialog->setWindowTitle(tr("Print Document"));
       if (dialog->exec() != QDialog::Accepted)
         return;

     //fxsBoard->print(&printer);
 #endif
 };
