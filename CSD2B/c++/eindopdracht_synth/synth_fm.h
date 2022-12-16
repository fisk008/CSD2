#include <iostream>
#include <cmath>
#pragma once
#include "synth.h"


class FM : public Synth{
public:

FM();
~FM();
void tickAll();
float getSamples();
void setFrequency(double frequency);
double getFrequency();
protected:

Sine carrier = Sine(440,samplerate);
Square modulator =Square(100,samplerate);

Oscillator* myOscillators[2];

float ratio;


float sample;
float frequency;

};