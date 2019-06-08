/*
 * DebouncedInput.cpp
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#include "DebouncedInput.h"

namespace controller {

DebouncedInput::DebouncedInput(int pin) {
    this->pin = pin;
}

int DebouncedInput::read() {
    int firstRead = digitalRead(pin);
    delay(1);
    if (firstRead == digitalRead(pin)) {
        return firstRead;
    }
    return LOW;
}

} /* namespace controller */
