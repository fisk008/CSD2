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
protected:

Sine carrier = Sine(440,samplerate);
Square modulator =Square(100,samplerate);
float modulator;
float ratio;


float sample;
float frequency;

};