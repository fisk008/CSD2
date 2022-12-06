#include "oscillator.h"
#include <iostream>

oscillator::oscillator(float frequency, double samplerate) : frequency(frequency),amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{

}

oscillator::~oscillator(){
    
}

void oscillator::setFrequency(float frequency)
{

  this->frequency = frequency;
}

float oscillator::getFrequency()
{
  return frequency;
}