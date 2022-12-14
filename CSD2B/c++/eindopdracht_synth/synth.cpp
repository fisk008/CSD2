#include "synth.h"
#include <iostream>
#include <math.h>


Synth::Synth()
{
  
}

Synth::~Synth(){

}


float Synth::mtof(int note){
  double frequency = 440.0 * std::pow(2.0, (note - 69.0) / 12.0);
  
  
  return frequency;
}

float Synth::getSamples(){
  sample = myOscillators[0]->getSample(),myOscillators[1]->getSample(),myOscillators[2]->getSample();
  
  
  return sample;
}

void Synth::setSamplerate(float samplerate) 
{
    this->samplerate = samplerate;
}

void Synth::getSamplerate(){
  
}


void Synth::tickAll(){
  myOscillators[0]->tick();
  myOscillators[1]->tick();
  myOscillators[2]->tick();
}
// float Synth::getSamplerate(){
// return samplerate;
// }