#pragma once
#include <iostream>


class Synth{
    public:
    Synth();
    ~Synth();
    void calculate();
    
    
    protected:
    float amplitude;
    float phase;
  // sample contains the current sample
    float samplerate;
    float frequency;
    float sample;
    
    void tick();
};