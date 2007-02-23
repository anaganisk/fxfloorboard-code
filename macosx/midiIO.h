/****************************************************************************
**
** Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
**
** This file is part of "GT6B FX FloorBoard".
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

#ifndef MIDIIO_H
#define MIDIIO_H

#include <QThread>
#include <QString>
#include <QStringList>
#include <QList>

class midiIO: public QThread
{
	Q_OBJECT

public:
	void run();
	void sendSysxMsg(QString sysxOutMsg, int midiOut, int midiIn);
	void sendMidi(QString midiMsg, int midiOut);
	QList<QString> getMidiOutDevices();
	QList<QString> getMidiInDevices();

signals:
	void errorSignal(QString windowTitle, QString errorMsg);
	void replyMsg(QString sysxInMsg);
	void midiFinished();
	void started();
	void finished();
	void terminated();

private:
	void queryMidiInDevices();
	void queryMidiOutDevices();

	QString getMidiOutErrorMsg(unsigned long err);
	QString getMidiInErrorMsg(unsigned long err);

	void showErrorMsg(QString errorMsg, QString type);
	void sendMsg(QString sysxOutMsg, int midiOut);

	QList<QString> midiOutDevices;
	QList<QString> midiInDevices;

	static QString sysxBuffer;
	static bool dataReceive;
	static unsigned char SysXFlag;
	static int count;
	static unsigned char SysXBuffer[256];

	int midiOut;
	int midiIn;
	QString sysxOutMsg;
	QString sysxInMsg;
	bool multiple;
};

#endif // MIDIIO_H