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



Oscillator* myOscillators[2];

float ratio;


float sample;
float frequency;

};