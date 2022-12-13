#include <iostream>
#include <cmath>
#pragma once

class Oscillator
{
public:
Oscillator();

  Oscillator(float frequency, float samplerate);
  ~Oscillator();

  //return the current sample
  float getSample();

  //getters and setters
  
  void setFrequency(float frequency);
  float getFrequency();

  void tick();
  
protected:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  
  float sample;
  float samplerate;
  virtual void calculate()=0;
};


