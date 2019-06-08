/*
 * Configuration.cpp
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#include "Configuration.h"

namespace controller {

Configuration::Configuration() {
    patches->setStorage(patchesArray);
    patchesFactory->initializePatches(patches);

}

int Configuration::getButtonAPin() {
    return BUTTON_A_PIN;
}

int Configuration::getButtonBPin() {
    return BUTTON_B_PIN;
}

} /* namespace controller */

HardwareSerial& controller::Configuration::getMidiSerialPort() {
    return MIDI_SERIAL;
}

Vector<controller::Patch>* controller::Configuration::getPatches() {
    return patches;
}
