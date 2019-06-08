/*
 * StrymonPedal.h
 *
 *  Created on: Jun 8, 2019
 *      Author: Edgar
 */

#ifndef STRYMONPEDAL_H_
#define STRYMONPEDAL_H_

#include "MIDIMessageBuilder.h"
#include "Patch.h"

namespace controller {
class StrymonPedal {
private:
    int channel;
    MIDIMessageBuilder* messageBuilder = new MIDIMessageBuilder();
public:
    StrymonPedal(int channel);
    void bypass(Patch* patch);
    void engage(Patch* patch);
    void loadPreset(Patch* patch, int bank, int preset);
};

} /* namespace controller */

#endif /* STRYMONPEDAL_H_ */
