#include <iostream>
#include <cmath>
#pragma once
#include "synth.h"
#include "sine.h"
#include "square.h"
#include "saw.h"

class Additive:public Synth{
    public:
    Additive();
    Additive(float numOsc);
    ~Additive();



    float combinedSamples();

    void setFrequency(double frequency);
    double getFrequency();
    float getSamples(float numOsc);
    void tickAll(float numOsc);
    void initAddOsc();
    void numAddOsc(float numOsc);
    void tickAdditiveOsc(float numOsc);
    float getOscSamples(float numOsc);
protected:
    
    Oscillator* myOscillators[5];
    float phase;
    float amplitude;
    double frequency;
    float sample;
    float samplerate= 44100;
};