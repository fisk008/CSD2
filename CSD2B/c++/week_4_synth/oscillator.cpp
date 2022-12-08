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


Oscillator::Oscillator(float frequency, float samplerate)
:   frequency(frequency), amplitude(1.0), phase(0), samplerate(samplerate)
{
    std::cout<<"osc constructor\n";
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

void Oscillator::tick(){
  phase += frequency / samplerate;
  
  if(phase > 1.0f){
    phase -=1.0f;
  }

  calculate();
}