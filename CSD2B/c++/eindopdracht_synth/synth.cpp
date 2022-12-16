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



void Synth::setSamplerate(float samplerate) 
{
    this->samplerate = samplerate;
}

void Synth::getSamplerate(){

}



// float Synth::getSamplerate(){
// return samplerate;
// }