#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include <cmath>
#include "oscillator.h"



class Saw : public Oscillator
{
    public:
    Saw();
    Saw(float frequency, float amplitude);
    ~Saw();
    

    void calculate();
};
#endif