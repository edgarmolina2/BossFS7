/*
 * MIDIMessageBuilder.h
 *
 *  Created on: Jun 8, 2019
 *      Author: Edgar
 */

#ifndef MIDIMESSAGEBUILDER_H_
#define MIDIMESSAGEBUILDER_H_
#include <MIDI.h>
#include "Constants.h"

using namespace midi;
namespace controller {

class MIDIMessageBuilder {
public:
    MIDIMessageBuilder();
    Message<SYS_EX_MAX> createMessage(MidiType type, DataByte data1,
            DataByte data2, int channel);
};

} /* namespace controller */

#endif /* MIDIMESSAGEBUILDER_H_ */
