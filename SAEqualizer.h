/*
 * SAEqualizer.h
 *
 *  Created on: Jun 8, 2019
 *      Author: Edgar
 */

#ifndef SAEQUALIZER_H_
#define SAEQUALIZER_H_

#include "Patch.h"
#include "Constants.h"
#include "MIDIMessageBuilder.h"

namespace controller {

class SAEqualizer {
private:
    int channel = EQ_CH;
    MIDIMessageBuilder* messageBuilder = new MIDIMessageBuilder();
public:
    SAEqualizer();
    void loadPreset(Patch* patch, int preset);
};

} /* namespace controller */

#endif /* SAEQUALIZER_H_ */
