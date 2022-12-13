#include "synth.h"
#include <iostream>
#include <math.h>
#include "callback.h"

Synth::Synth()
{
  
}

Synth::~Synth(){

}


float Synth::mtof(int note){
  double frequency = 440.0 * std::pow(2.0, (note - 69.0) / 12.0);
  
  
  return frequency;
}

float Synth::getSample(){
  return sample;
}

void Synth::setSamplerate(float samplerate) 
{
    this->samplerate = samplerate;
}

// float Synth::getSamplerate(){
// return samplerate;
// }