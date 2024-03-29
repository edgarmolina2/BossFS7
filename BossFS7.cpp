#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <MIDI.h>
#include <Vector.h>
#include "Configuration.h"
#include "DebouncedInput.h"

using namespace controller;
using namespace midi;
Configuration* configuration;
DebouncedInput* buttonA;
DebouncedInput* buttonB;
MidiInterface<HardwareSerial>* MIDI;
Adafruit_NeoPixel* aLed;
Adafruit_NeoPixel* bLed;
Vector<Patch>* patches;
unsigned latchA = LOW;
unsigned latchB = LOW;
unsigned nextPatch = 0;
unsigned currentPatch = 0;
unsigned tempo = 120;
unsigned long tempoMicros = 0;
unsigned long nextClock = 0;
unsigned long tap = 0;
unsigned long previousTap = 0;

void setALed(uint32_t color) {
    aLed->setPixelColor(0, color);
    aLed->show();
}

void setBLed(uint32_t color) {
    bLed->setPixelColor(0, color);
    bLed->show();
}

void initializeLeds() {
    aLed->begin();
    bLed->begin();
}

void sendPatch(unsigned patch) {
    Vector<Message<SYS_EX_MAX>>* messages = patches->at(patch).getMessages();

    for (int messageNo = 0; messageNo < messages->size(); messageNo++) {
        Message<SYS_EX_MAX>* message = &(messages->at(messageNo));
        MIDI->send(message->type, message->data1, message->data2,
                message->channel);
    }
    setALed(patches->at(patch).getColor());
    setBLed(BLACK);
}

double getNextClockTime(unsigned bpm) {
    return (60000000 / bpm / 24);
}

unsigned getTempo(unsigned long t1, unsigned long t2) {
    return 60000000 / (t2 - t1);
}

void setup() {
    configuration = new Configuration;
    MIDI = new MidiInterface<HardwareSerial>(
            configuration->getMidiSerialPort());
    aLed = new Adafruit_NeoPixel(1, 6, NEO_GRB + NEO_KHZ800);
    bLed = new Adafruit_NeoPixel(1, 5, NEO_GRB + NEO_KHZ800);
    buttonA = new DebouncedInput(configuration->getButtonAPin());
    buttonB = new DebouncedInput(configuration->getButtonBPin());
    patches = configuration->getPatches();
    pinMode(configuration->getButtonAPin(), INPUT_PULLUP);
    pinMode(configuration->getButtonBPin(), INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
    MIDI->begin();
    initializeLeds();
    nextClock = micros() + getNextClockTime(tempo);
    sendPatch(currentPatch);
}

void loop() {
    if (micros() >= nextClock) {
        MIDI->sendRealTime(MidiType::Clock);
        nextClock = micros() + getNextClockTime(tempo) - 2000;
    }

    int a = buttonA->read();
    int b = buttonB->read();

    if ((a && latchA) || (b && latchB)) {
        return;
    }
    latchA = a;
    latchB = b;

    if (a) {
        nextPatch++;
        if (nextPatch >= patches->size()) {
            nextPatch = 0;
        }
        setBLed(patches->at(nextPatch).getColor());
    } else if (b && currentPatch != nextPatch) {
        currentPatch = nextPatch;
        sendPatch(currentPatch);
    } else if (b) {
        tap = micros();
        if (previousTap != 0) {
            tempo = getTempo(previousTap, tap);
            previousTap = 0;
        } else {
            previousTap = tap;
        }
    }
}
