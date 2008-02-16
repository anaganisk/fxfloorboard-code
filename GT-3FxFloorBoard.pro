#############################################################################
##
## Copyright (C) 2005, 2006, 2007 Uco Mesdag. All rights reserved.
##
## This file is part of "GT-3 Fx FloorBoard".
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
TARGET = "GT-3FxFloorBoard"
DESTDIR = ../GT3FxFloorBoard
#else
CONFIG += release
TARGET = "GT-3FxFloorBoard"
DESTDIR = ./packager
#endif
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
	exists("C:/Progra~1/SDK/Windows/v6.0/Lib/WinMM.Lib") {		# <-- Change the path to WinMM.Lib here!
		LIBS +=  C:/Progra~1/SDK/Windows/v6.0/Lib/WinMM.Lib		# <-- Change the path here also!
	} else {
		LIBS +=  WinMM.Lib
		message("WINMM.LIB IS REQUIRED. IF NOT INSTALLED")
		message("PLEASE DOWNLOAD AND INSTALL PLATFORM SDK FROM:")
		message("http://www.microsoft.com/downloads/details.aspx?familyid=0BAF2B35-C656-4969-ACE8-E4C0C0716ADB&displaylang=en")
		message("AFTER INSTALLATION CHANGE THE CORRECT (DOS) PATH IN THE "GT-8FxFloorBoard.pro" FILE")
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
	ICON = GT-3FxFloorBoard.icns
	message(Including Mac OS X specific headers and sources...)
}

#Include file(s)
include(GT-3FxFloorBoard.pri)

#Windows resource file
win32:RC_FILE = GT-3FxFloorBoard.rc
