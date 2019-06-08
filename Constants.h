/*
 * Constants.h
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <Arduino.h>

namespace controller {
    static HardwareSerial& MIDI_SERIAL = Serial;
    static const unsigned SYS_EX_MAX = 0;
    static const unsigned MAX_MESSAGES_PER_PATCH = 4;
    static const unsigned MAX_PATCHES = 5;
    static const unsigned BUTTON_A_PIN = 3;
    static const unsigned BUTTON_B_PIN = 2;
}

#endif /* CONSTANTS_H_ */
