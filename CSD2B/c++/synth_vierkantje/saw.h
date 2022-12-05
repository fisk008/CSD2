#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include <cmath>
#include "oscillator.h"



class Saw : public Oscillator
{
    public:
    Saw();
    Saw(float frequency, float ampliltude, float phase, float samplerate);
    Saw(float frequency, float amplitude);
    float getSample(); 
    ~Saw();
    

    void tick();
};
#endif