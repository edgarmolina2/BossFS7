/*
 * PatchesFactory.h
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#ifndef PATCHESFACTORY_H_
#define PATCHESFACTORY_H_

#include <Vector.h>

#include "Constants.h"
#include "MIDIMessageBuilder.h"
#include "Patch.h"
#include "SAEqualizer.h"
#include "StrymonPedal.h"

using namespace midi;
namespace controller {

class PatchesFactory {
private:
    SAEqualizer* eq = new SAEqualizer();
    StrymonPedal* bigsky = new StrymonPedal(BIGSKY_CH);
    StrymonPedal* mobius = new StrymonPedal(MOBIUS_CH);
    StrymonPedal* timeLine = new StrymonPedal(TIMELINE_CH);
    MIDIMessageBuilder* messageBuilder = new MIDIMessageBuilder();
public:
    PatchesFactory();
    void initializePatches(Vector<Patch>* vectorToInitialize);
};

} /* namespace controller */

#endif /* PATCHESFACTORY_H_ */
