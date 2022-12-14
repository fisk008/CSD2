#include <iostream>
#include <cmath>
#include "add_synth.h"

Additive::Additive(){

}
Additive::~Additive(){
    
}



void Additive::setFrequency(double frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

double Additive::getFrequency()
{
  return frequency;
}

void Additive::additiveOscillators(){
myOscillators[0]= new Sine(440,samplerate);
myOscillators[1]= new Sine(540,samplerate);
myOscillators[2]= new Sine(640,samplerate);
}