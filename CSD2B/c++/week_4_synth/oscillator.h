#include <iostream>
#include <cmath>
#pragma once

class Oscillator
{
public:
Oscillator();
  // Oscillator(float frequency, float amplitude, float phase, float samplerate);
  Oscillator(float frequency, float samplerate);
~Oscillator();

  // allow to set samplerate after initialization
  void setSamplerate(float samplerate);
  
  //return the current sample
  float getSample();
  // go to next sample
  float getSamplerate();
  // float getSamplerate();
  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

protected:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  float samplerate;
};


