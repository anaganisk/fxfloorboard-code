#############################################################################
##
## Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
##
## This file is part of "GT6B Fx FloorBoard".
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

CONFIG += static
CONFIG += embed_manifest_exe
CONFIG += release
TARGET = "GT6BFxFloorBoard"
DESTDIR = ./release
MOC_DIR += ./generatedfiles/release
OBJECTS_DIR += release
UI_DIR += ./generatedfiles
INCLUDEPATH += ./generatedfiles \
	./generatedfiles/release \
	.
DEPENDPATH += .
QT += xml


#Platform dependent file(s)
win32 {
	exists("c:/Progra~1/sdk/Lib/WinMM.Lib") {		# <-- Change the path to WinMM.Lib here!
		LIBS +=  c:/Progra~1/sdk/Lib/WinMM.Lib		# <-- Change the path here also!
	} else {
		LIBS +=  WinMM.Lib
		message("WINMM.LIB IS REQUIRED. IF NOT INSTALLED")
		message("PLEASE DOWNLOAD AND INSTALL PLATFORM SDK FROM:")
		message("http://www.microsoft.com/downloads/details.aspx?familyid=0BAF2B35-C656-4969-ACE8-E4C0C0716ADB&displaylang=en")
		message("AFTER INSTALLATION CHANGE THE CORRECT (DOS) PATH IN THE "GT-8FxFloorBoard.pro" FILE")
	}
	HEADERS += ./windows/midiIO.h
	SOURCES += ./windows/midiIO.cpp
	INCLUDEPATH += ./windows
	message(Including Windows specific headers and sources...)
}
linux-g++ {
	HEADERS += ./linux/midiIO.h
	SOURCES += ./linux/midiIO.cpp
	INCLUDEPATH += ./linux
	message(Including Linux specifique headers and sources...)
}
macx {
	HEADERS += ./macosx/midiIO.h
	SOURCES += ./macosx/midiIO.cpp
	INCLUDEPATH += ./macosx
	message(Including Mac OS X specifique headers and sources...)
}

#Include file(s)
include(GT6BFxFloorBoard.pri)

#Windows resource file
win32:RC_FILE = GT6BFxFloorBoard.rc
