#include <iostream>
#include <cmath>


class Oscillator{
public:
    Oscillator(float frequency, double samplerate);
    ~Oscillator();

  //getters and setters
    void setFrequency(float frequency);
    float getFrequency();
    
protected:
  const float pi = acos (-1);  //atan(1) * 4; <-- vak van Pieter.
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  double samplerate;
};
