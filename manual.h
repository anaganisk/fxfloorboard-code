/****************************************************************************
**
** Copyright (C) 2006, 2007 Colin Willcocks. All rights reserved.
**
** This file is part of "GT6B Fx FloorBoard".
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

#ifndef MANUAL_H
#define MANUAL_H

#include <QtGui>
#include <QWidget>
#include "stompBox.h"

class manual : public stompBox
{
    Q_OBJECT

public:
	manual(QWidget *parent);
	void setEditPages();

public slots:
	void updateSignal();
};

#endif // MANUAL_H