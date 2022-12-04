#include <iostream>
#include <cmath>
#include "oscillator.h"
#pragma once


class Sqaure : public Oscillator
{
    public:
    Sqaure(float frequency,double sampelrate);
    ~Sqaure();


    void tick();
};