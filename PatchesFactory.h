/*
 * PatchesFactory.h
 *
 *  Created on: Jun 1, 2019
 *      Author: Edgar
 */

#ifndef PATCHESFACTORY_H_
#define PATCHESFACTORY_H_
#include <Vector.h>
#include <MIDI.h>
#include "Patch.h"
#include "Colors.h"

using namespace midi;
namespace controller {

class PatchesFactory {
private:
    Message<SYS_EX_MAX> createMessage(MidiType type, DataByte data1,
            DataByte data2, int channel);
public:
    PatchesFactory();
    void initializePatches(Vector<Patch>* vectorToInitialize);
};

} /* namespace controller */

#endif /* PATCHESFACTORY_H_ */
