/*
 * StrymonPedal.cpp
 *
 *  Created on: Jun 8, 2019
 *      Author: Edgar
 */

#include "StrymonPedal.h"

namespace controller {

StrymonPedal::StrymonPedal(int channel) {
    this->channel = channel;
}

void StrymonPedal::bypass(Patch* patch) {
    patch->addMessage(
            messageBuilder->createMessage(MidiType::ControlChange, BYPASS_CC,
                    BYPASS, channel));
}

void StrymonPedal::loadPreset(Patch* patch, int bank, int preset) {
    patch->addMessage(
            messageBuilder->createMessage(MidiType::ControlChange, 0, bank,
                    channel));
    patch->addMessage(
            messageBuilder->createMessage(MidiType::ProgramChange, preset, 0,
                    channel));
}

} /* namespace controller */

void controller::StrymonPedal::engage(Patch* patch) {
    patch->addMessage(
            messageBuilder->createMessage(MidiType::ControlChange, BYPASS_CC,
                    ENGAGE, channel));
}
