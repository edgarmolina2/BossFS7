/*
 * PatchesFactory.cpp
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#include "PatchesFactory.h"

namespace controller {

PatchesFactory::PatchesFactory() {
    // TODO Auto-generated constructor stub

}

Message<SYS_EX_MAX> PatchesFactory::createMessage(MidiType type,
        DataByte data1, DataByte data2, int channel) {
    Message<SYS_EX_MAX> message;
    message.channel = channel;
    message.type = type;
    message.data1 = data1;
    message.data2 = data2;
    return message;
}

void PatchesFactory::initializePatches(Vector<Patch>* vectorToInitialize) {
    Patch firstPatch;
    firstPatch.setColor(0x001100);
    firstPatch.addMessage(createMessage(MidiType::ProgramChange, 15, 0, 1));
    firstPatch.addMessage(createMessage(MidiType::ProgramChange, 16, 0, 2));
    firstPatch.addMessage(createMessage(MidiType::ProgramChange, 17, 0, 3));
    vectorToInitialize->push_back(firstPatch);

    Patch secondPatch;
    secondPatch.setColor(0x000011);
    secondPatch.addMessage(createMessage(MidiType::ProgramChange, 18, 0, 1));
    secondPatch.addMessage(createMessage(MidiType::ProgramChange, 19, 0, 2));
    secondPatch.addMessage(createMessage(MidiType::ProgramChange, 20, 0, 3));
    vectorToInitialize->push_back(secondPatch);
}

} /* namespace controller */
