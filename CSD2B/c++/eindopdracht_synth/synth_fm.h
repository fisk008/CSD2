#include <iostream>
#include <cmath>
#pragma once
#include "synth.h"

class FM : public Synth{
public:

FM();
~FM();


protected:
float carrierFreq;
float ratio;


float sample;
float frequency;

};