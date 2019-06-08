/*
 * DebouncedInput.h
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#ifndef DEBOUNCEDINPUT_H_
#define DEBOUNCEDINPUT_H_
#include <Arduino.h>

namespace controller {

class DebouncedInput {
private:
    int pin;
public:
    DebouncedInput(int pin);
    int read();
};

} /* namespace controller */

#endif /* DEBOUNCEDINPUT_H_ */
