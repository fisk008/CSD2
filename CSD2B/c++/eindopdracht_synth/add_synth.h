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
    ~Additive();



    float combinedSamples();

    void setFrequency(double frequency);
    double getFrequency();
    void additiveOscillators();

protected:

    double frequency;
    float sample;
    float samplerate= 44100;
};