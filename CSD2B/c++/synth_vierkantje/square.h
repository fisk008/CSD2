#ifndef _SQAURE_H_
#define _SQAURE_H_
#include <iostream>
#include <cmath>
#include "oscillator.h"



class Sqaure : public Oscillator
{
    public:
    Sqaure(float frequency,double sampelrate);
    ~Sqaure();
    float getSample();

    void tick();
};
#endif