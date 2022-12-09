#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include <cmath>
#include "oscillator.h"


class Sine : public Oscillator
{
public:
  //Constructor and destructor

  Sine();
  Sine(float frequency,float samplerate);
  ~Sine();

  //return the current sample

  // go to next sample
  void calculate();

};

#endif
