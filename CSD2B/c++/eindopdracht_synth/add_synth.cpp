#include <iostream>
#include <cmath>
#include "add_synth.h"

Additive::Additive(){
initAddOsc();
}
Additive::~Additive(){
    
}



void Additive::setFrequency(double frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
  myOscillators[0]->setFrequency(frequency);
  myOscillators[1]->setFrequency(frequency * 2.0);
  myOscillators[2]->setFrequency(frequency * 3.0);
  myOscillators[3]->setFrequency(frequency * 4.0);
  // std::cout<<frequency;
}

double Additive::getFrequency()
{
  return frequency;
}

void Additive::initAddOsc(){
  myOscillators[0]= new Sine(0,samplerate);
  myOscillators[1]= new Sine(0,samplerate);
  myOscillators[2]= new Sine(0,samplerate);
  myOscillators[3]= new Sine(0,samplerate);
}

void Additive::tickAll(){
  myOscillators[0]->tick();
  myOscillators[1]->tick();
  myOscillators[2]->tick();
  myOscillators[3]->tick();
}
float Additive::getSamples(){
  sample = (myOscillators[0]->getSample()+myOscillators[1]->getSample()+myOscillators[2]->getSample())/3;
  
  
  return sample;
}