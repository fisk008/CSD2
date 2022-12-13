#include "synth.h"
#include <iostream>
#include <math.h>
#include "callback.h"

Synth::Synth()
{
  
}

Synth::~Synth(){

}

void Synth::tick(){
sinusje.tick();  
blokje.tick();
zaag.tick();

}

float Synth::combineSamples(){

  float allFreqs = (sinusje.getSample()+zaag.getSample()+blokje.getSample())/3;
  return allFreqs;

}

float Synth::mtof(int note){
  double frequency = 440.0 * std::pow(2.0, (note - 69.0) / 12.0);
  
  
  return frequency;
}

float Synth::getSample(){
  return samplerate;
}

void Synth::setSamplerate(float samplerate) 
{
    this->samplerate = samplerate;
}

