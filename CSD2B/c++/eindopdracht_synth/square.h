#include <iostream>
#include <cmath>
#include "oscillator.h"
#pragma once



class Square : public Oscillator
{
    public:
    Square();
    Square(float frequency, float samplerate);
    ~Square();
    
    //function of calculation of a square waveform with aliasing
    void calculate();
};
