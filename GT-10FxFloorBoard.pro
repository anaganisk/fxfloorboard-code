#############################################################################
##
## Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
##
## This file is part of "GT-10 Fx FloorBoard".
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
#ifdef Q_OS_MAC
CONFIG += release ppc x86
TARGET = "GT-10FxFloorBoard"
DESTDIR = ../GT-10FxFloorBoard
#else 
CONFIG += release
TARGET = "GT-10FxFloorBoard"
DESTDIR = ./packager
#endif
	OBJECTS_DIR += release
	UI_DIR += ./generatedfiles
	MOC_DIR += ./generatedfiles/release
	INCLUDEPATH += ./generatedfiles \
    ./generatedfiles/release \
    .

DEPENDPATH += .
QT += xml

#Platform dependent file(s)
win32 {
	exists("c:/Progra~1/SDK/Lib/WinMM.Lib") {	# <-- Change the path to WinMM.Lib here!
		LIBS += c:/Progra~1/SDK/Lib/WinMM.Lib	# <-- Change the path here also!
    } else { 
        exists("c:/PROGRA~1/MICROS~3/VC/PLATFO~1/Lib/WinMM.Lib") { # Path vs2005 (Vista)
        	LIBS += c:/PROGRA~1/MICROS~3/VC/PLATFO~1/Lib/WinMM.Lib
        } else { 
            LIBS += .\WinMM.Lib
            message("WINMM.LIB IS REQUIRED. IF NOT INSTALLED THEN")
            message("PLEASE DOWNLOAD AND INSTALL THE LATEST PLATFORM SDK")
            message("FROM MICROSOFT.COM AND AFTER INSTALLATION")
            message("CHANGE THE CORRECT (DOS) PATH TO WinMM.lib")
            message("IN THIS (GT-10FxFloorBoard.pro) FILE WHERE INDICATED")
        }
	}
	 HEADERS += 
	 SOURCES += ./windows/RtMidi.cpp                        
	 INCLUDEPATH += ./windows
	message(Including Windows specific headers and sources...)
}
linux-g++ {
        LIBS += -lasound
	message("ALSA LIBRARIES SHOULD BE INSTALLED or ERROR will Occur") 
	message("Please install the ALSA Audio System packages if not present") 	
 
	 HEADERS += 
	 SOURCES += ./linux/RtMidi.cpp 
	 INCLUDEPATH += ./linux
	message(Including Linux specific headers and sources...)
}
macx {
	LIBS += -framework CoreMidi -framework CoreAudio -framework CoreFoundation
	message("X-Code LIBRARIES SHOULD BE INSTALLED or ERROR will Occur") 
	message("Please install the X-Code Audio System packages if not present") 
	 HEADERS += 
	 SOURCES += ./macosx/RtMidi.cpp 
	INCLUDEPATH += ./macosx
	ICON = GT10FxFloorBoard.icns
	message(Including Mac OS X specific headers and sources...)
}


#Include file(s)
include(GT-10FxFloorBoard.pri)

#Windows resource file
win32:RC_FILE = GT-10FxFloorBoard.rc
