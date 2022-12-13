#ifndef _SQAURE_H_
#define _SQAURE_H_
#include <iostream>
#include <cmath>
#include "oscillator.h"



class Square : public Oscillator
{
    public:
    Square();
    Square(float frequency, float ampliltude, float phase, float samplerate);
    Square(float frequency, float amplitude); 
    ~Square();
    

    void calculate();
};
#endif