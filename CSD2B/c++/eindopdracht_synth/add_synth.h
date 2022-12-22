#include <iostream>
#include <cmath>
#pragma once
#include "synth.h"
#include "sine.h"
#include "square.h"
#include "saw.h"

class Additive:public Synth{
    //here is my sublass of Synth: Additive synth 
    public:
    //def construct/destructor
    Additive();
    Additive(float numOsc);
    ~Additive();

    //setters and getters frequency
    void setFrequency(double frequency);
    double getFrequency();
    //gets samples for given oscillators
    float getSamples();
    //ticks samples for given oscillators
    void tickAll();
    //assigns new sine wave to myOscillator for given oscillators
    void numAddOsc();
    //this functions is used in tickAll to tick given oscillators
    void tickAdditiveOsc();

protected:
    //creates 5 oscillators objects in a list
    Oscillator* myOscillators[5];
    int numOsc;
    double frequency;
    
    //holds current sample
    float sample;
    
    float samplerate= 44100;
};