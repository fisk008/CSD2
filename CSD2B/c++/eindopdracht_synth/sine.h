#include <iostream>
#include <cmath>
#include "oscillator.h"
#pragma once


class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine();
  Sine(float frequency,float samplerate);
  ~Sine();

  //function of calculation of a Sine waveform with aliasing
  void calculate();
};


