#############################################################################
##
## Copyright (C) 2005-2006 Uco Mesdag. All rights reserved.
##
## This file is part of "GT-8 FX FloorBoard".
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; if not, write to the Free Software Foundation, Inc.,
## 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
##
#############################################################################

TEMPLATE = app
TARGET = GT-8FxFloorBoard
DESTDIR = ./Release
QT += xml
CONFIG += release
INCLUDEPATH += ./GeneratedFiles \
    ./GeneratedFiles/Release \
    .
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/release
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles

LIBS +=  c:/Progra~1/Micros~2/Lib/WinMM.Lib

#Include file(s)
include(GT-8FxFloorBoard.pri)

#Windows resource file
win32:RC_FILE = GT-8FxFloorBoard.rc
