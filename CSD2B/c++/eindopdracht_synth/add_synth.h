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
void tickAll();
float getSample()override;
float combinedSamples();
protected:
    float sample;
    float samplerate= 44100;
    Sine sinusje= Sine(note,samplerate);
    Square blokje= Square(note,samplerate);
    Saw zaag=Saw(note,samplerate);
};