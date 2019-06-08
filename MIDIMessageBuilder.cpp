/*
 * MIDIMessageBuilder.cpp
 *
 *  Created on: Jun 8, 2019
 *      Author: Edgar
 */

#include "MIDIMessageBuilder.h"

namespace controller {

MIDIMessageBuilder::MIDIMessageBuilder() {
}

Message<SYS_EX_MAX> MIDIMessageBuilder::createMessage(MidiType type,
        DataByte data1, DataByte data2, int channel) {
    Message<SYS_EX_MAX> message;
    message.channel = channel;
    message.type = type;
    message.data1 = data1;
    message.data2 = data2;
    return message;
}

} /* namespace controller */
