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
//#include <SoftwareSerial.h>

//extern "C" {                
//  #include <SoftwareSerial.h>
//};                          

namespace cvpal {

//class SoftwareSerial;

/* static */
MidiHandler* DinHandler::midi_handler_;
//SoftwareSerial* midiSerial(1,2);
//SoftwareSerial midiSerial(1,2);

/* static */
void DinHandler::Init(MidiHandler* midi_handler) {
  midi_handler_ = midi_handler;
  //SoftwareSerial midiSerial = SoftwareSerial(PA1,PA2);
  //midiSerial(PA1,PA2);
  //midiSerial.begin (31250); // MIDI Baud rate
  softSerialBegin (31250); // MIDI Baud rate
  //usbDeviceDisconnect();
  //_delay_ms(200);
  //usbDeviceConnect();
  //usbInit();
  sei();
}

/* static */
void DinHandler::Poll() {
  //usbPoll();
  //if (usbInterruptIsReady()) {
    // We don't emit anything!
  //}
  if (softSerialAvailable()) {
    midi_handler.Parse(softSerial.read(), 1);
  }
}

}  // namespace cvpal
