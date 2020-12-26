// Copyright 2013 Emilie Gillet.
//
// Author: Emilie Gillet (emilie.o.gillet@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef CVPAL_DIN_HANDLER_H_
#define CVPAL_DIN_HANDLER_H_

//extern "C" {
//  #include <SoftwareSerial.h>
//};
//#include <SoftwareSerial.h>
#include "avrlib/base.h"

// w#: This was a callout to some C code. We don't need
//     the  driver anymore though, so it's removed.
//extern "C" {
//  #include "usbdrv/usbdrv.h"
//};

#include "cvpal/midi_handler.h"

namespace cvpal {

//class SoftwareSerial;

class DinHandler {


 public:
  // w#: I think these are the Constructor and Destructor?
  DinHandler() { }
  ~DinHandler() { }
  
  static void Init(MidiHandler* midi_handler);
  //static void Init(MidiHandler* midi_handler,SoftwareSerial* midiSerial);
  static void Poll();
  static void Parse(const uint8_t* data, uint8_t size) {
    midi_handler_->Parse(data, size);
  }

 private:
  static MidiHandler* midi_handler_;
  //static SoftwareSerial *midiSerial;
  //SoftwareSerial midiSerial;

  DISALLOW_COPY_AND_ASSIGN(DinHandler);
};

}  // namespace

#endif  // CVPAL_DIN_HANDLER_H_
