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

extern "C" {
  #include "SoftwareSerial/SoftwareSerial.h"
};
#include "avrlib/base.h"

#include "cvpal/midi_handler.h"

namespace cvpal {

class DinHandler {
 public:
  DinHandler() { }
  ~DinHandler() { }
  
  static void Init(MidiHandler* midi_handler);
  static void Poll();
  static void Parse(const uint8_t* data, uint8_t size) {
    midi_handler_->Parse(data, size);
  }

 private:
  static MidiHandler* midi_handler_;

  DISALLOW_COPY_AND_ASSIGN(DinHandler);
};

}  // namespace

#endif  // CVPAL_DIN_HANDLER_H_
