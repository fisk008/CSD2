#include <iostream>
#include <cmath>
#include "synth.h"
#pragma once


class AM : public Synth{

public:


    enum waveForm{
        sine =0,
        square,
        saw,
        Size
    };

    AM();
    AM(float modulatorFrequency,int modulator,int carrier);
    ~AM();

    void tickAll(float numOsc);
    float getSamples(float numOsc);
    void setFrequency(double frequency);
    double getFrequency();

    void setWaveform(waveForm type);
    
    protected:



    Oscillator* myOscillators[3];

    float carrierFrequency;
    float sample;
    float frequency;
    
    
};