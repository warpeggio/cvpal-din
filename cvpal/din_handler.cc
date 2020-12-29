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

#include "cvpal/din_handler.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <string.h>

namespace cvpal {

/* static */
MidiHandler* DinHandler::midi_handler_;

/* static */
void DinHandler::Init(MidiHandler* midi_handler) {
  midi_handler_ = midi_handler;
  softSerialBegin (31250); // MIDI Baud rate
  sei(); // w#: This is probably important, i don't think SoftwareSerial
         //     is interacting with any interrupts...
}

/* static */
void DinHandler::Poll() {
  // w#: Polling USB like this would likely return data, which
  //     in turn would cause a callback to the midi handler with whaever
  //     data was found.
  //usbPoll();
  //if (usbInterruptIsReady()) {
    // We don't emit anything!
  //}
  if (softSerialAvailable()) {
   // w#: Doesn't work because softSerial isn't declared in this scope...
    cvpal::DinHandler::Parse(softSerial.read(), 1);
  }
}

}  // namespace cvpal
