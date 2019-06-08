/*
 * Patch.cpp
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#include "Patch.h"

#include <MIDI.h>
#include <midi_Message.h>
#include <stdint.h>
#include <Vector/VectorDefinitions.h>

using namespace midi;
namespace controller {

Patch::Patch() {
    messages = new Vector<Message<SYS_EX_MAX>>;
    messages->setStorage(messageArray);

}

void Patch::addMessage(Message<SYS_EX_MAX> message) {
    messages->push_back(message);
}

Vector<Message<SYS_EX_MAX> >* Patch::getMessages() {
    return messages;
}

void Patch::setColor(uint32_t color) {
    this->color = color;
}

uint32_t Patch::getColor() {
    return color;
}
} /* namespace controller */
