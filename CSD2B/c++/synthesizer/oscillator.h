#include <iostream>
#include <cmath>


class oscillator{
public:
    oscillator(float frequency, double samplerate);
    ~oscillator();

    float getSample();
  //getters and setters
    void setFrequency(float frequency);
    float getFrequency();
    virtual void tick() = 0;
     
protected:
  const float pi = acos (-1);  //atan(1) * 4; <-- vak van Pieter.
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  double samplerate;
};
