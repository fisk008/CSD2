#include <iostream>
#include <cmath>
#pragma once
class Oscillator{
    public:

    Oscillator(float frequency, double samplerate);
    ~Oscillator();

  //getters and setters
    void setFrequency(float frequency);
    float getFrequency();
    
    
    protected:
    const float pi = acos (-1.0f);  //atan(1) * 4; <-- vak van Pieter.
    float frequency{0};
    float amplitude{0};
    float phase{0};
    
    // sample contains the current sample
    float sample;
    double samplerate;

};