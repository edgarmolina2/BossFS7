/*
 * SAEqualizer.cpp
 *
 *  Created on: Jun 8, 2019
 *      Author: Edgar
 */

#include "SAEqualizer.h"

namespace controller {

SAEqualizer::SAEqualizer() {

}

void SAEqualizer::loadPreset(Patch* patch, int preset) {
    patch->addMessage(
            messageBuilder->createMessage(MidiType::ProgramChange, preset, 0,
                    channel));
}

} /* namespace controller */
