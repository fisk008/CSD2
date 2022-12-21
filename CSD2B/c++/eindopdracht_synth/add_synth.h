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
    float getSamples();
    void tickAll();
    void initAddOsc();
    void numAddOsc();
    void tickAdditiveOsc();
    float getOscSamples();
protected:
    
    Oscillator* myOscillators[5];
    int numOsc;
    float phase;
    float amplitude;
    double frequency;
    float sample;
    float samplerate= 44100;
};