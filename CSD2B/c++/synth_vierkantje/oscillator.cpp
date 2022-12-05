#include <iostream>
#include <cmath>
#include "oscillator.h"


Oscillator::Oscillator(){
  std::cout<<"osc constructor\n";
}

Oscillator::~Oscillator()
{
  std::cout<<"osc destructor\n";
}


Oscillator::Oscillator(float frequency, float amplitude, float phase, float samplerate)
:   frequency(0), amplitude(1.0), phase(0), samplerate(samplerate)
{
    std::cout<<"osc constructor\n";
}


Oscillator::Oscillator(float frequency, float samplerate):frequency(frequency),samplerate(samplerate){
    phase = 0;
    samplerate = 44100;
    std::cout << "phase:"<< phase << "\n";
    std::cout << "frequency: " << this->frequency << "\n";
    std::cout << "samplerate: " << this->samplerate << "\n";

}




void Oscillator::setSamplerate(float samplerate) 
{
    this->samplerate = samplerate;
}


float Oscillator::getSamplerate(){
  return samplerate;
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

