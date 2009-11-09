/****************************************************************************
**
** Copyright (C) 2007~2010 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
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
/************************************************************************/
/*! \class RtError
    \brief Exception handling class for RtAudio & RtMidi.

    The RtError class is quite simple but it does allow errors to be
    "caught" by RtError::Type. See the RtAudio and RtMidi
    documentation to know which methods can throw an RtError.

*/
/************************************************************************/

#ifndef RTERROR_H
#define RTERROR_H

#include <iostream>
#include <string>
#include <QMessageBox>
#include "SysxIO.h"

class RtError
{
public:
  //! Defined RtError types.
  enum Type {
    WARNING,           /*!< A non-critical error. */
    DeBug_WARNING,     /*!< A non-critical error which might be useful for DeBugging. */
    UNSPECIFIED,       /*!< The default, unspecified error type. */
    NO_DEVICES_FOUND,  /*!< No devices found on system. */
    INVALID_DEVICE,    /*!< An invalid device ID was specified. */
    INVALID_STREAM,    /*!< An invalid stream ID was specified. */
    MEMORY_ERROR,      /*!< An error occured during memory allocation. */
    INVALID_PARAMETER, /*!< An invalid parameter was specified to a function. */
    DRIVER_ERROR,      /*!< A system driver error occured. */
    SYSTEM_ERROR,      /*!< A system error occured. */
    THREAD_ERROR       /*!< A thread error occured. */
  };

protected:
  std::string message_;
  Type type_;

public:
  //! The constructor.
  RtError(const std::string& message, Type type = RtError::UNSPECIFIED) : message_(message), type_(type) {}

  //! The destructor.
  virtual ~RtError(void) {};
   
  //! Prints thrown error message to stderr.
  virtual void printMessage(void) { 
  
	  //std::cerr << '\n' << message_ << "\n\n"; 
	  SysxIO *sysxIO = SysxIO::Instance();
	  QString errorType = "Midi Error";
	  QString errorMsg;
	  errorMsg.append(QString::fromStdString(message_));
	  sysxIO->errorReturn(errorType, errorMsg);
	 
    }
 
   
  //! Returns the thrown error message type.
  virtual const Type& getType(void) { return type_; }

  //! Returns the thrown error message string.
  virtual const std::string& getMessage(void) { return message_; }

  //! Returns the thrown error message as a C string.
  virtual const char *getMessageString(void) { return message_.c_str(); }
  
  
};

#endif
