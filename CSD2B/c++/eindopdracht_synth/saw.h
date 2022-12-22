#include <iostream>
#include <cmath>
#pragma once
#include "oscillator.h"



class Saw : public Oscillator
{
    public:
    Saw();
    Saw(float frequency, float amplitude);
    ~Saw();
    
    //function of calculation of a Saw waveform with aliasing
    void calculate();
};
