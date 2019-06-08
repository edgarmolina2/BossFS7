/*
 * Configuration.h
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_
#include <Arduino.h>
#include "Constants.h"
#include "PatchesFactory.h"
#include "Patch.h"

namespace controller {

class Configuration {
private:
    Patch patchesArray[MAX_PATCHES];
    PatchesFactory* patchesFactory = new PatchesFactory();
    Vector<Patch>* patches = new Vector<Patch>;

public:
    Configuration();
    int getButtonAPin();
    int getButtonBPin();
    HardwareSerial& getMidiSerialPort();
    Vector<controller::Patch>* getPatches();
};

} /* namespace controller */

#endif /* CONFIGURATION_H_ */
