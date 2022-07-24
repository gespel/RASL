/*
  ==============================================================================

    RASLProcessor.cpp
    Created: 19 Jul 2022 7:15:40pm
    Author:  Sten

  ==============================================================================
*/

#include "RASLProcessor.h"

typedef struct sine {
    SineSynth a;
    int channelNumber;
} sine;

RASLProcessor::RASLProcessor() {
    std::cout << "Bla";
}
void RASLProcessor::createSineSynth(int channelNumber, int freq) {
    sine neu = {SineSynth(freq), channelNumber};
}
