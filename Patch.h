/*
 * Patch.h
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#ifndef PATCH_H_
#define PATCH_H_
#include <Vector.h>
#include <MIDI.h>
#include "Constants.h"
#include "Colors.h"

using namespace midi;
namespace controller {

class Patch {
private:
    uint32_t color = BLACK;
    Message<SYS_EX_MAX> messageArray[MAX_MESSAGES_PER_PATCH];
    Vector<Message<SYS_EX_MAX>>* messages;

public:
    Patch();
    void addMessage(Message<SYS_EX_MAX> message);
    Vector<Message<SYS_EX_MAX>>* getMessages();
    void setColor(uint32_t color);
    uint32_t getColor();
};

} /* namespace controller */

#endif /* PATCH_H_ */
