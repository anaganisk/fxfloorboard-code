/**********************************************************************/
/*! \class RtMidi
    \brief An abstract base class for realtime MIDI input/output.

    This class implements some common functionality for the realtime
    MIDI input/output subclasses RtMidiIn and RtMidiOut.

    RtMidi WWW site: http://music.mcgill.ca/~gary/rtmidi/

    RtMidi: realtime MIDI i/o C++ classes
    Copyright (c) 2003-2006 Gary P. Scavone

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation files
    (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    Any person wishing to distribute modifications to the Software is
    requested to send the modifications to the original developer so that
    they can be incorporated into the canonical version.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
    ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
    CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/**********************************************************************/

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
	  sysxIO->errorReturn();
	  QString errorType;
	  errorType.append(type_);
	  QString errorMsg;
	  errorMsg.append(QString::fromStdString(message_));
  /*QMessageBox *msgBox = new QMessageBox();
		msgBox->setWindowTitle("GT-10FxFloorBoard");
		msgBox->setIcon(QMessageBox::Warning);
		msgBox->setTextFormat(Qt::RichText);
		msgBox->setText(errorMsg);
		msgBox->setStandardButtons(QMessageBox::Ok);
		msgBox->exec();*/
  }

  //! Returns the thrown error message type.
  virtual const Type& getType(void) { return type_; }

  //! Returns the thrown error message string.
  virtual const std::string& getMessage(void) { return message_; }

  //! Returns the thrown error message as a C string.
  virtual const char *getMessageString(void) { return message_.c_str(); }
};

#endif
