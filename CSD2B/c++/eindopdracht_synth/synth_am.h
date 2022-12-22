#include <iostream>
#include <cmath>
#include "synth.h"
#pragma once


class AM : public Synth{

public:
    AM();
    AM(float modulatorFrequency,int modulator,int carrier);
    ~AM();
    //ticks all oscillators
    void tickAll();
    //gets all samples and returns 
    float getSamples();
    //setters and getters for frequency
    void setFrequency(double frequency);
    double getFrequency();

    
    protected:
    //creates a list of oscillators with 2 oscillator one for carrier and one for modulator
    Oscillator* myOscillators[2];

    float carrierFrequency;
    float sample;
    float frequency; 
};