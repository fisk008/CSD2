#include <iostream>
#include <cmath>
#include "oscillator.h"

Oscillator::Oscillator(float frequency, double samplerate): frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
    
}


Oscillator::~Oscillator()
{}




void Oscillator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}

