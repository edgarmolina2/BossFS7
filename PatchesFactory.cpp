/*
 * PatchesFactory.cpp
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#include "PatchesFactory.h"

#include <Vector/VectorDefinitions.h>

#include "MIDIMessageBuilder.h"

using namespace midi;
namespace controller {

PatchesFactory::PatchesFactory() {
}

void PatchesFactory::initializePatches(Vector<Patch>* vectorToInitialize) {
    Patch firstPatch;

    firstPatch.setColor(0x001100);
    timeLine->bypass(&firstPatch);
    mobius->bypass(&firstPatch);
    bigsky->loadPreset(&firstPatch, 0, 0);
    bigsky->engage(&firstPatch);
    eq->loadPreset(&firstPatch, 1);
    vectorToInitialize->push_back(firstPatch);

    Patch secondPatch;
    secondPatch.setColor(0x000011);
    secondPatch.addMessage(messageBuilder->createMessage(MidiType::ProgramChange, 18, 0, 1));
    secondPatch.addMessage(messageBuilder->createMessage(MidiType::ProgramChange, 19, 0, 2));
    secondPatch.addMessage(messageBuilder->createMessage(MidiType::ProgramChange, 20, 0, 3));
    vectorToInitialize->push_back(secondPatch);
}

} /* namespace controller */
