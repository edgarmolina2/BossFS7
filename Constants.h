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
    // Config Constants
    static HardwareSerial& MIDI_SERIAL = Serial;
    static const unsigned SYS_EX_MAX = 0;
    static const unsigned MAX_MESSAGES_PER_PATCH = 10;
    static const unsigned MAX_PATCHES = 5;
    static const unsigned BUTTON_A_PIN = 3;
    static const unsigned BUTTON_B_PIN = 2;
    static const unsigned BIGSKY_CH = 1;
    static const unsigned TIMELINE_CH = 2;
    static const unsigned MOBIUS_CH = 3;
    static const unsigned EQ_CH = 4;

    // Strymon CCs
    static const unsigned BYPASS_CC = 102;
    static const unsigned BYPASS = 0;
    static const unsigned ENGAGE = 127;
    static const unsigned PRESET_CHANGE = 1;
}

#endif /* CONSTANTS_H_ */
