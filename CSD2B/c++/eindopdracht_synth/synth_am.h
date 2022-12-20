#include <iostream>
#include <cmath>
#include "synth.h"
#pragma once


class AM : public Synth{
public:

AM();
~AM();
void tickAll();
float getSamples();
void setFrequency(double frequency);
double getFrequency();
protected:



Oscillator* myOscillators[3];

float carrierFrequency;
float modulatorFrequency;


float sample;
float frequency;

};