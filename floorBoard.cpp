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

#include <QList>
#include <QVector>

#include "dragBar.h"
#include "bankTreeList.h"
#include "floorBoardDisplay.h"
#include "floorPanelBar.h"
#include "floorBoard.h"
#include "Preferences.h"
#include "MidiTable.h"
#include "sysxWriter.h"
#include "SysxIO.h"
#include "globalVariables.h"

#include "menuPage_assign.h"
#include "menuPage_midi.h"
#include "menuPage_system.h"
#include "menuPage_autoriff.h"
#include "menuPage_autoriff_FX2.h"
#include "menuPage_master.h"

#include "stompbox_fx1.h"
#include "stompbox_ch_a.h"
#include "stompbox_ch_b.h"
#include "stompbox_cn_s.h"
#include "stompbox_cn_m.h"
#include "stompbox_cs.h"
#include "stompbox_pdl.h"
#include "stompbox_lp.h"
#include "stompbox_od.h"
#include "stompbox_eq.h"
#include "stompbox_fx2.h"
#include "stompbox_dd.h"
#include "stompbox_ce.h"
#include "stompbox_rv.h"
#include "stompbox_fv.h"
#include "stompbox_ns_1.h"
#include "stompbox_ns_2.h"
#include "stompbox_dgt.h"


floorBoard::floorBoard(QWidget *parent, 
						QString imagePathFloor, 
						QString imagePathStompBG, 
						QString imagePathInfoBar,
						unsigned int marginStompBoxesTop, 
						unsigned int marginStompBoxesBottom, 
						unsigned int marginStompBoxesWidth,
						unsigned int panelBarOffset,
						unsigned int borderWidth,
						QPoint pos)
    : QWidget(parent)
{

	this->imagePathFloor = imagePathFloor;
	this->imagePathStompBG = imagePathStompBG;
	this->imagePathInfoBar = imagePathInfoBar;

	this->marginStompBoxesTop = marginStompBoxesTop;
	this->marginStompBoxesBottom = marginStompBoxesBottom;
	this->marginStompBoxesWidth = marginStompBoxesWidth;
	this->panelBarOffset = panelBarOffset;
	this->borderWidth = borderWidth;
	this->pos = pos;

	bankTreeList *bankList = new bankTreeList(this);
	
	setFloorBoard();

	floorBoardDisplay *display = new floorBoardDisplay(this);
	display->setPos(displayPos);

	floorPanelBar *panelBar = new floorPanelBar(this);
	panelBar->setPos(panelBarPos);	

	dragBar *bar = new dragBar(this);
	bar->setDragBarSize(QSize::QSize(4, panelBar->height() ));
	bar->setDragBarMinOffset(2, 8);
	bar->setDragBarMaxOffset(offset - panelBarOffset + 5);
  initStomps();
	initMenuPages();
	this->editDialog = new editWindow(this);
	this->editDialog->hide();

	floorBoardDisplay *display2 = new floorBoardDisplay(this);
	display2->setPos(liberainPos);

	QObject::connect(this, SIGNAL( resizeSignal(QRect) ), bankList, SLOT( updateSize(QRect) ) );
	QObject::connect(display, SIGNAL(connectedSignal()), bankList, SLOT(connectedSignal()));
	QObject::connect(this, SIGNAL(valueChanged(QString, QString, QString)), display, SLOT(setValueDisplay(QString, QString, QString)));
	QObject::connect(panelBar, SIGNAL(resizeSignal(int)), this, SLOT(setWidth(int)));
	QObject::connect(panelBar, SIGNAL(collapseSignal()), this, SLOT(setCollapse()));
	QObject::connect(this, SIGNAL(setCollapseState(bool)), panelBar, SIGNAL(collapseState(bool)));
	QObject::connect(this, SIGNAL(setDisplayPos(QPoint)), display, SLOT(setPos(QPoint)));
	QObject::connect(this, SIGNAL(setFloorPanelBarPos(QPoint)), panelBar, SLOT(setPos(QPoint)));
	QObject::connect(this->parent(), SIGNAL(updateSignal()), this, SIGNAL(updateSignal()));
	QObject::connect(this, SIGNAL(updateSignal()), this, SLOT(updateStompBoxes()));
	QObject::connect(bankList, SIGNAL(patchSelectSignal(int, int)), display, SLOT(patchSelectSignal(int, int)));
	QObject::connect(bankList, SIGNAL(patchLoadSignal(int, int)), display, SLOT(patchLoadSignal(int, int)));

	QObject::connect(panelBar, SIGNAL(showDragBar(QPoint)), this, SIGNAL(showDragBar(QPoint)));
	QObject::connect(panelBar, SIGNAL(hideDragBar()), this, SIGNAL(hideDragBar()));


	bool ok;
	Preferences *preferences = Preferences::Instance();
	QString collapseState = preferences->getPreferences("Window", "Collapsed", "bool");
	QString width = preferences->getPreferences("Window", "Collapsed", "width");
	QString defaultwidth = preferences->getPreferences("Window", "Collapsed", "defaultwidth");
	if(width.isEmpty()){ width = defaultwidth; }

	this->l_floorSize = QSize::QSize(width.toInt(&ok, 10), floorSize.height());
	
	if(preferences->getPreferences("Window", "Restore", "sidepanel")=="true")
	{
		if(collapseState=="true")
		{ 
			this->setSize(l_floorSize);
			this->colapseState = true;
			emit setCollapseState(true);
		}
		else
		{ 
			this->setSize(minSize);
			this->colapseState = false;
			emit setCollapseState(false);
		};
	}
	else
	{
		//this->l_floorSize = QSize::QSize(defaultwidth.toInt(&ok, 10), floorSize.height());
		this->setSize(minSize);
		this->colapseState = false;
		emit setCollapseState(false);
	};

	emit updateSignal();
};

floorBoard::~floorBoard()
{
	Preferences *preferences = Preferences::Instance();
	if(preferences->getPreferences("Window", "Restore", "sidepanel")=="true")
	{
		preferences->setPreferences("Window", "Collapsed", "width", QString::number(this->l_floorSize.width(), 10));
	}
	else
	{
		preferences->setPreferences("Window", "Collapsed", "width", "");
	};
	preferences->setPreferences("Window", "Collapsed", "bool", QString(this->colapseState?"true":"false"));
	preferences->savePreferences();
};					

void floorBoard::paintEvent(QPaintEvent *)
{
	QRectF target(pos.x(), pos.y(), floorSize.width(), floorSize.height());
	QRectF source(0.0, 0.0, floorSize.width(), floorSize.height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);
	this->setAcceptDrops(true);
};

void floorBoard::setFloorBoard() {
	QPixmap imageFloor(imagePathFloor);
	QPixmap imagestompBG(imagePathStompBG);
	QPixmap imageInfoBar(imagePathInfoBar);
	QPixmap buffer = imageFloor;
	QPainter painter(&buffer);

	this->offset = imageFloor.width() - imageInfoBar.width();
	this->infoBarWidth = imageInfoBar.width();
	this->stompSize = imagestompBG.size();

	initSize(imageFloor.size());
	this->maxSize = floorSize;
	this->minSize = QSize::QSize(imageInfoBar.width() + borderWidth + panelBarOffset, imageFloor.height());

	// Draw InfoBar
	QRectF sourceInfoBar(0.0, 0.0, imageInfoBar.width(), imageInfoBar.height());
	QRectF targetInfoBar(offset, 0.0, imageInfoBar.width(), imageInfoBar.height());
	painter.drawPixmap(targetInfoBar, imageInfoBar, sourceInfoBar);

	// Draw LiberianBar
	QRectF sourceLiberianBar(0.0, 0.0, imageInfoBar.width(), imageInfoBar.height());
	QRectF targetLiberianBar(offset, (imageFloor.height() - imageInfoBar.height()) - 2, imageInfoBar.width(), imageInfoBar.height());
	painter.drawPixmap(targetLiberianBar, imageInfoBar, sourceLiberianBar);

	// Draw stomp boxes background
	QRectF source(0.0, 0.0, imagestompBG.width(), imagestompBG.height());
	for(int i=0;i<fxPos.size();i++)
	{
		QRectF target(fxPos.at(i).x(), fxPos.at(i).y(), imagestompBG.width(), imagestompBG.height());
		painter.drawPixmap(target, imagestompBG, source);
	};
	painter.end();

	this->baseImage = buffer;
	this->image = buffer;
	this->floorHeight = imageFloor.height();

	QPoint newPanelBarPos = QPoint::QPoint(offset - panelBarOffset, borderWidth);
	this->panelBarPos = newPanelBarPos;
	
	QPoint newDisplayPos = QPoint::QPoint(offset, 0);
	this->displayPos = newDisplayPos;

	QPoint newLiberainPos = QPoint::QPoint(offset, floorHeight);
	this->liberainPos = newLiberainPos;

	QRect newBankListRect = QRect::QRect(borderWidth, borderWidth, offset - panelBarOffset - (borderWidth*2), floorHeight - (borderWidth*2));
	emit resizeSignal(newBankListRect);
};

void floorBoard::dragEnterEvent(QDragEnterEvent *event)
{
	QByteArray data = event->mimeData()->data("text/uri-list");
	QString uri(data);
	
	if (event->mimeData()->hasFormat("application/x-stompbox") ||
		uri.contains(".syx", Qt::CaseInsensitive) &&
		event->answerRect().intersects(this->geometry())) 
	{
        if (children().contains(event->source())) 
		{
            event->setDropAction(Qt::MoveAction);
			event->accept();
        } else {
            event->acceptProposedAction();
        };
    } else {
        event->ignore();
    };
};

void floorBoard::dragMoveEvent(QDragMoveEvent *event)
{
	QByteArray data = event->mimeData()->data("text/uri-list");
	QString uri(data);
	
	if ( event->mimeData()->hasFormat("application/x-stompbox") ||
		uri.contains(".syx", Qt::CaseInsensitive) &&
		event->answerRect().intersects(this->geometry()) ) 
	{
        if (children().contains(event->source())) 
		{
            event->setDropAction(Qt::MoveAction);
			event->accept();
        } else {
            //event->acceptProposedAction();
        };
    } else {
        event->ignore();
    };
};

void floorBoard::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-stompbox")) 
	{
        QByteArray itemData = event->mimeData()->data("application/x-stompbox");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        int stompId;
        QPoint stompPos;
		QSize stompSize;
		QPoint topLeftOffset;
        dataStream >> stompId >> stompPos >> stompSize >> topLeftOffset;
		QPoint dragPoint = (event->pos() - topLeftOffset) + QPoint::QPoint(stompSize.width()/2, stompSize.height()/2);
		int stompSpacing = fxPos.at(1).x() - (fxPos.at(0).x() + stompSize.width());
		
		int destIndex = -1; // Set to out of range by default.
		int orgIndex = fx.indexOf(stompId);
		for(int x=0;x<fx.size();x++) 
        { 
            QRect dropRect = QRect::QRect(fxPos.at(x).x() - stompSpacing - (stompSize.width()/2), fxPos.at(x).y(), stompSize.width() + stompSpacing, stompSize.height()); 
            QRect lastDropRect = QRect::QRect(fxPos.at(x).x() + (stompSize.width()/2), fxPos.at(x).y(), stompSize.width() + stompSpacing, stompSize.height()); 
            if( dropRect.contains(dragPoint) ) 
            { 
                destIndex = fx.indexOf(fx.at(x)); 
            } 
            else if( (x == (int)fx.size()-1 ||  
                        ( x == (int)(fx.size()/2)-1 && fx.at(stompId) != fx.size()/2 ) )  
                        && lastDropRect.contains(dragPoint)) 
            { 
                destIndex = fx.indexOf(fx.at(x)) + 1; 
            }; 
        }; 
 

		if((destIndex > -1 && destIndex < fx.size() + 1) && (stompId != 16) && (stompId != 17) && (stompId != 2) && (stompId != 3)) 
			// Make sure we are not dropping the stomp out of range. 
		{
			if( orgIndex < destIndex )
			{
				destIndex = destIndex - 1;
				for(int i=orgIndex;i<destIndex ;i++)
				{
					setStompPos(fx.at(i + 1), i);
				};
				setStompPos(stompId, destIndex );
			}
			else if( orgIndex > destIndex )
			{
				for(int i=orgIndex;i>destIndex;i--)
				{
					setStompPos(fx.at(i - 1), i);
				};
				setStompPos(stompId, destIndex);
			};

			if(orgIndex != destIndex) // Prevent sending data when stomp was dropped in the same place.
			{
				SysxIO *sysxIO = SysxIO::Instance();
					QList<QString> fxChain = sysxIO->getFileSource("0B", "00");
		
	MidiTable *midiTable = MidiTable::Instance();
	//QList<QString> stompOrderName;
	QList<QString> stompOrderHex;
  QString shit;
	QString hexdata_A;
	QString hexdata_B;
	QString namedata;
	QList<QString> hexData;
	QString hexData2;
	int hex_A;
	int hex_B;
				
				for(int i= sysxDataOffset;i< (sysxDataOffset + 18);i++ ) 
				{     	
        	//stompOrderName.append( midiTable->getMidiMap("Structure", "0B", "00", "00", fxChain.at(i)).name );
		      shit.append( midiTable->getMidiMap("Structure", "0B", "00", "00", fxChain.at(i)).value );
		      shit.append(" ");
        };  
            hex_A = fx.indexOf(16);
            hex_B = fx.indexOf(17); 
            bool ok; 
            int hex_pos = 0; 
            QString crap;   
        for(int index=0;index<fx.size();index++)
        {        
					QString fxHexValue = QString::number(fx.at(index), 16).toUpper();
					int pos = fxHexValue.toInt(&ok, 16);
					hex_pos = fx.indexOf(pos); 				
					if(fxHexValue.length() < 2 &&  fx.at(index) == 3){ fxHexValue.prepend("4");}  // PreAmp B must always be 43
					if(fxHexValue.length() < 2)
            {
              if (hex_pos > hex_A && hex_pos < hex_B)
                { 
                  QString carrots = fxHexValue;
                  if(carrots.length() < 2){carrots.prepend("0");};
                   if (shit.contains(carrots)){fxHexValue.prepend("0");}
                       else {fxHexValue.prepend("4"); };
                  
                } else { fxHexValue.prepend("0"); };
					  };	    
          hexData2.append(fxHexValue);
          hexData2.append(" ");
          crap.append(QString::number(hex_pos, 16).toUpper());
          crap.append(" ");
			  };
			 			  QString part1;
			  for (int index = 0;index<((hex_A*3)+3);index++)     // copy chain data up to the split point.
			  {
          part1.append(hexData2.at(index));
        };
			  QString part4;
			  for (int index = ((hex_B*3));index<54;index++)     // copy chain data after the merge point.
			  {
          part4.append(hexData2.at(index));
        };
        QString part2;
        QString part3;
        for ( int index = ((hex_A*3)+3);index<((hex_B*3));index++  )  // seperate and copy A path and B path data
        {   
          QString hexa = hexData2.at(index);
          QString hexc = hexData2.at(index-1);
          if ( hexa =="4" && hexc ==" "   ){
           part3.append(hexData2.at(index)); 
           index++; 
           part3.append(hexData2.at(index));
           index++;
           part3.append(hexData2.at(index)); }
           else { part2.append(hexData2.at(index));
           index++; 
           part2.append(hexData2.at(index));
           index++; 
           part2.append(hexData2.at(index)); };
        };
        hexData2 ="";
        hexData2.append(part1).append(part2).append(part3).append(part4).remove(" ");
        for (int index=0; index<36; index++)
           {
             QString hex = hexData2.at(index);
             index++;
             hex.append(hexData2.at(index));
             hexData.append(hex);
           };     
			  		  
				sysxIO->setFileSource("0B", "00", "00", "11", hexData);
				emit pathUpdateSignal();
				updateStompBoxes();
			};
		}
		else
		{
			event->ignore();
		};
	} 
	else 
	{
		if(event->mimeData()->hasFormat("text/uri-list"))
		{
			QByteArray data = event->mimeData()->data("text/uri-list");
			QString uri(data);
			if(uri.contains(".syx", Qt::CaseInsensitive))
			{
				QString removeFromStart = "file:///";
				QString removeFromEnd = ".syx";
				QString filePath = uri;
				filePath.replace(0, filePath.indexOf(removeFromStart) + removeFromStart.length(), "");
				filePath.truncate(filePath.indexOf(removeFromEnd) + removeFromEnd.length());
				filePath.replace("%20", " ");
				
				SysxIO *sysxIO = SysxIO::Instance();
				sysxIO->setFileName(filePath);
				sysxIO->setSyncStatus(false);
				sysxIO->setDevice(false);
				
				sysxWriter file;
				file.setFile(filePath);
				if(file.readFile())
				{	
					emit updateSignal();
				}
				else
				{
					event->ignore();
				};
			}
			else
			{
				event->ignore();
			};
		}
		else
		{
			event->ignore();
		};
    };
};

void floorBoard::initSize(QSize floorSize)
{
	this->floorSize = floorSize;
	this->l_floorSize = floorSize;
	QList<QPoint> fxPos; 
	
	unsigned int spacingV = (floorSize.height() - (marginStompBoxesTop + marginStompBoxesBottom)) - (stompSize.height() * 2);
	unsigned int spacingH = ( (floorSize.width() - offset - (marginStompBoxesWidth * 2)) - (stompSize.width() * 9) ) / 9;
	//for(unsigned int i=0;i<14;i++)
	for(int i=17;i>=0;i--)
	{
		unsigned int y = marginStompBoxesTop;
		unsigned int x = marginStompBoxesWidth + (( stompSize.width() + spacingH ) * i);
		if(i>8)
		{
			y = y + stompSize.height() + spacingV;
			x = x - (( stompSize.width() + spacingH ) * 9);
		};
		fxPos.append(QPoint::QPoint(offset + x, y));
	};

	this->fxPos = fxPos;
	this->setFixedSize(floorSize);
};

QPoint floorBoard::getStompPos(int id) 
{
	return fxPos.at(id);
};

void floorBoard::setCollapse()
{
	if(floorSize.width() > minSize.width())
	{ 
		this->l_floorSize = floorSize;
		this->setSize(minSize);
		this->colapseState = false;
		emit setCollapseState(false);
	}
	else
	{ 
		this->setSize(l_floorSize);
		emit setCollapseState(true);
		this->colapseState = true;
	};
};

void floorBoard::setSize(QSize newSize)
{
	unsigned int oldOffset = offset;
	this->offset = newSize.width() - infoBarWidth;
	QSize oldFloorSize = this->floorSize;
	this->floorSize = newSize;

	for(int i=0;i<fxPos.size();i++)
	{
		fxPos[i] = fxPos[i] + QPoint::QPoint(offset - oldOffset, 0);
	};
	emit updateStompOffset(offset - oldOffset);
	
	QPoint newPanelBarPos = QPoint::QPoint(offset - panelBarOffset, panelBarPos.y());
	emit setFloorPanelBarPos(newPanelBarPos);
	this->panelBarPos = newPanelBarPos;
	
	QPoint newDisplayPos = QPoint::QPoint(offset, displayPos.y());
	emit setDisplayPos(newDisplayPos);
	this->displayPos = newDisplayPos;

	QPixmap buffer = QPixmap::QPixmap(floorSize);
	QPainter painter(&buffer);

	// Redraw new resized floor
	QRectF source(maxSize.width() - floorSize.width(), 0.0, floorSize.width(), floorSize.height());
	QRectF target(0.0, 0.0, floorSize.width(), floorSize.height());
	painter.drawPixmap(target, baseImage, source);

	// Redraw clipped border
	/*QRectF sourceBorder(0.0, 0.0, borderWidth, floorSize.height());
	QRectF targetBorder(0.0, 0.0, borderWidth, floorSize.height());
	painter.drawPixmap(sourceBorder, baseImage, targetBorder);*/

	painter.end();

	this->image = buffer;	
	this->setFixedSize(floorSize);
	
	QRect newBankListRect = QRect::QRect(borderWidth, borderWidth, offset - panelBarOffset - (borderWidth*2), floorHeight - (borderWidth*2));
	emit resizeSignal(newBankListRect);
	
	emit sizeChanged(floorSize, oldFloorSize);
	this->centerEditDialog();
};

void floorBoard::setWidth(int dist)
{
	QSize newSize;
	if(floorSize.width() + dist < minSize.width())
	{
		newSize = minSize;
		this->colapseState = false;
		emit setCollapseState(false);
	}
	else if(floorSize.width() + dist > maxSize.width())
	{
		newSize = maxSize;
		this->l_floorSize = newSize;
		this->colapseState = true;
		emit setCollapseState(true);
	}
	else
	{
		newSize = QSize::QSize(floorSize.width() + dist, floorSize.height());
		this->l_floorSize = newSize;
		this->colapseState = true;
		emit setCollapseState(true);
	};
	this->setSize(newSize);
};

void floorBoard::initStomps()
{
	QList<signed int> fx;
	fx << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13 << 14 << 15 << 16 << 17;
	/*   FX1   CS  PDL  LP   OD   CH_A  EQ  FX2  DD    CE   RV    NS1    FV   DGT   CH_B  NS2   cn_s  cn_m :depend on midi.xml   */
	this->fx = fx;

	QVector<QString> initStompNames(18);
	this->stompNames = initStompNames.toList();;

	QVector<stompBox *> initStompBoxes(18);
	this->stompBoxes = initStompBoxes.toList();;

	MidiTable *midiTable = MidiTable::Instance();
	Midi midimap = midiTable->getMidiMap("Structure", "0B", "00", "00");
	QList<int> fxID;
	QList<QString> fxNAMES;
	for(int i=0;i<=17;i++)
 
	{
		bool ok;
		fxID.append(midimap.level.at(i).value.toInt(&ok, 16));
		fxNAMES.append(midimap.level.at(i).name);
	};

	/* FX1 */
	stompBox *fx1 = new stompbox_fx1(this);
	fx1->setId( fxID.at(fxNAMES.indexOf("FX1")) ); 
	fx1->setPos(this->getStompPos(fx1->getId()));
	this->stompBoxes.replace(fx1->getId(), fx1);
	this->stompNames.replace(fx1->getId(), "FX1");

	/* COMP */	
	stompBox *cs = new stompbox_cs(this);
	cs->setId( fxID.at(fxNAMES.indexOf("CS")) );
	cs->setPos(this->getStompPos(cs->getId()));
	this->stompBoxes.replace(cs->getId(), cs);
	this->stompNames.replace(cs->getId(), "CS");

	
		/* PDL */
	stompBox *pdl = new stompbox_pdl(this);
	pdl->setId( fxID.at(fxNAMES.indexOf("PDL")) );
	pdl->setPos(this->getStompPos(pdl->getId()));
	this->stompBoxes.replace(pdl->getId(), pdl);
	this->stompNames.replace(pdl->getId(), "PDL");

	/* LOOP	*/
	stompBox *lp = new stompbox_lp(this);
	lp->setId( fxID.at(fxNAMES.indexOf("LP")) );
	lp->setPos(this->getStompPos(lp->getId()));
	this->stompBoxes.replace(lp->getId(), lp);
	this->stompNames.replace(lp->getId(), "LP");

	/* OD/DS */
	stompBox *od = new stompbox_od(this);
	od->setId( fxID.at(fxNAMES.indexOf("OD")) );
	od->setPos(this->getStompPos(od->getId()));
	this->stompBoxes.replace(od->getId(), od);
	this->stompNames.replace(od->getId(), "OD");

	/* CH_A */ 
	stompBox *ch_a = new stompbox_ch_a(this);
	ch_a->setId( fxID.at(fxNAMES.indexOf("CH_A")) );
	ch_a->setPos(this->getStompPos(ch_a->getId()));
	this->stompBoxes.replace(ch_a->getId(), ch_a);
	this->stompNames.replace(ch_a->getId(), "CH_A");
	
	/* CH_B */ 
	stompBox *ch_b = new stompbox_ch_b(this);
	ch_b->setId( fxID.at(fxNAMES.indexOf("CH_B")) );
	ch_b->setPos(this->getStompPos(ch_b->getId()));
	this->stompBoxes.replace(ch_b->getId(), ch_b);
	this->stompNames.replace(ch_b->getId(), "CH_B");

	/* EQ */
	stompBox *eq = new stompbox_eq(this);
	eq->setId( fxID.at(fxNAMES.indexOf("EQ")) );
	eq->setPos(this->getStompPos(eq->getId()));
	this->stompBoxes.replace(eq->getId(), eq);
	this->stompNames.replace(eq->getId(), "EQ");

	/* FX 2 */
	stompBox *fx2 = new stompbox_fx2(this);
	fx2->setId( fxID.at(fxNAMES.indexOf("FX2")) );
	fx2->setPos(this->getStompPos(fx2->getId()));
	this->stompBoxes.replace(fx2->getId(), fx2);
	this->stompNames.replace(fx2->getId(), "FX2");

	/* Delay */
	stompBox *dd = new stompbox_dd(this);
	dd->setId( fxID.at(fxNAMES.indexOf("DD")) );
	dd->setPos(this->getStompPos(dd->getId()));
	this->stompBoxes.replace(dd->getId(), dd);
	this->stompNames.replace(dd->getId(), "DD");

	/* Chorus */
	stompBox *ce = new stompbox_ce(this);
	ce->setId( fxID.at(fxNAMES.indexOf("CE")) );
	ce->setPos(this->getStompPos(ce->getId()));
	this->stompBoxes.replace(ce->getId(), ce);
	this->stompNames.replace(ce->getId(), "CE");

	/* REVERB */
	stompBox *rv = new stompbox_rv(this);
	rv->setId( fxID.at(fxNAMES.indexOf("RV")) );
	rv->setPos(this->getStompPos(rv->getId()));
	this->stompBoxes.replace(rv->getId(), rv);
	this->stompNames.replace(rv->getId(), "RV");

	/* NS_1 */
	stompBox *ns_1 = new stompbox_ns_1(this);
	ns_1->setId( fxID.at(fxNAMES.indexOf("NS_1")) );
	ns_1->setPos(this->getStompPos(ns_1->getId()));
	this->stompBoxes.replace(ns_1->getId(), ns_1);
	this->stompNames.replace(ns_1->getId(), "NS_1");
	
		/* NS_2 */
	stompBox *ns_2 = new stompbox_ns_2(this);
	ns_2->setId( fxID.at(fxNAMES.indexOf("NS_2")) );
	ns_2->setPos(this->getStompPos(ns_2->getId()));
	this->stompBoxes.replace(ns_2->getId(), ns_2);
	this->stompNames.replace(ns_2->getId(), "NS_2");

	/* D-OUT */
	stompBox *dgt = new stompbox_dgt(this);
	dgt->setId( fxID.at(fxNAMES.indexOf("DGT")) );
	dgt->setPos(this->getStompPos(dgt->getId()));
	this->stompBoxes.replace(dgt->getId(), dgt);
	this->stompNames.replace(dgt->getId(), "DGT");

	/* VOLUME */
	stompBox *fv = new stompbox_fv(this);
	fv->setId( fxID.at(fxNAMES.indexOf("FV")) );
	fv->setPos(this->getStompPos(fv->getId()));
	this->stompBoxes.replace(fv->getId(), fv);
	this->stompNames.replace(fv->getId(), "FV");
	
		/* CHAIN SPLIT */
	stompBox *cn_s = new stompbox_cn_s(this);
	cn_s->setId( fxID.at(fxNAMES.indexOf("CN_S")) );
	cn_s->setPos(this->getStompPos(cn_s->getId()));
	this->stompBoxes.replace(cn_s->getId(), cn_s);
	this->stompNames.replace(cn_s->getId(), "CN_S");
	
		/* CHAIN MERGE */
	stompBox *cn_m = new stompbox_cn_m(this);
	cn_m->setId( fxID.at(fxNAMES.indexOf("CN_M")) );
	cn_m->setPos(this->getStompPos(cn_m->getId()));
	this->stompBoxes.replace(cn_m->getId(), cn_m);
	this->stompNames.replace(cn_m->getId(), "CN_M");
};

void floorBoard::setStomps(QList<QString> stompOrder)
{
	for(int i=0;i<stompOrder.size();i++)
	{
		QString name = stompOrder.at(i);
		setStompPos(name, i);
		this->fx.replace(i, stompNames.indexOf(name));
	};
};

void floorBoard::setStompPos(QString name, int order)
{
	this->stompBoxes.at(stompNames.indexOf(name))->setPos(this->getStompPos(order));
	this->fx.replace(order, stompNames.indexOf(name));
};

void floorBoard::setStompPos(int index, int order)
{
	this->stompBoxes.at(index)->setPos(this->getStompPos(order));
	this->fx.replace(order, index);
};

void floorBoard::updateStompBoxes()
{
	SysxIO *sysxIO = SysxIO::Instance();
	QList<QString> fxChain = sysxIO->getFileSource("0B", "00");
		
	MidiTable *midiTable = MidiTable::Instance();
	QList<QString> stompOrder;
  	
  for(int i= sysxDataOffset;i< (sysxDataOffset + 18);i++ )
	{
		stompOrder.append( midiTable->getMidiMap("Structure", "0B", "00", "00", fxChain.at(i)).name );
	};
	setStomps(stompOrder);
};

void floorBoard::setEditDialog(editWindow* editDialog)
{
  this->oldDialog = this->editDialog; 
	this->editDialog = editDialog;	
	this->editDialog->setParent(this);
	this->centerEditDialog();
	this->editDialog->pageUpdateSignal();
	this->editDialog->show();
};

void floorBoard::centerEditDialog()
{
	int x = this->displayPos.x() + (((this->floorSize.width() - this->displayPos.x()) - this->editDialog->width()) / 2);
	int y = this->pos.y() + ((this->floorSize.height() - this->editDialog->height()) / 2);
	this->editDialog->move(x, y);
};

void floorBoard::initMenuPages()
{
	QVector<menuPage *> initMenuPages(6);
	this->menuPages = initMenuPages.toList();;
	
	/* MENU_PAGES */
	menuPage *system = new menuPage_system(this);
	system->setId(18);
	system->setPos(QPoint(1239, 5));
	
	menuPage *midi = new menuPage_midi(this);
	midi->setId(19);
	midi->setPos(QPoint(1150, 5));
	
	menuPage *assign = new menuPage_assign(this);
	assign->setId(20);
	assign->setPos(QPoint(1061, 5));
	
	menuPage *autoriff = new menuPage_autoriff(this);
	autoriff->setId(21);
	autoriff->setPos(QPoint(1150, 24));
	
	menuPage *autoriff_FX2 = new menuPage_autoriff_FX2(this);
	autoriff_FX2->setId(22);
	autoriff_FX2->setPos(QPoint(1239, 24));
	
	menuPage *master = new menuPage_master(this);
	master->setId(23);
	master->setPos(QPoint(1061, 24));
	
	};
	
void floorBoard::menuButtonSignal()
{
  this->oldDialog->hide();
  this->editDialog->show();
};
