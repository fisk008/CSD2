#include <iostream>
#include <cmath>
#include "oscillator.h"


Oscillator::Oscillator(){
  std::cout<<"osc constructor";
}



Oscillator::Oscillator(float frequency, float amplitude, float phase, float samplerate)
:   frequency(frequency), amplitude(amplitude), phase(phase), samplerate(samplerate)
{
    
}


Oscillator::Oscillator(float frequency, float samplerate){
  
}

Oscillator::~Oscillator()
{
  std::cout<<"osc destructor";
}



void Oscillator::setSamplerate(float samplerate) 
{
    this->samplerate = samplerate;
}

float Oscillator::getSample()
{
    return sample;
}



void Oscillator::setFrequency(float frequency)
{
    this->frequency = frequency;
}

float Oscillator::getFrequency()
{
    return frequency;
}

