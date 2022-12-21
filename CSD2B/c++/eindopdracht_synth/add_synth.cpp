#include <iostream>
#include <cmath>
#include "add_synth.h"

Additive::Additive(){
// initAddOsc();
}

Additive::Additive(float numOsc){
  
  this->numOsc= numOsc;
   numAddOsc();

}

Additive::~Additive(){
      
}



void Additive::setFrequency(double frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;


  for(int i=0;i<numOsc;i++){
    myOscillators[i]->setFrequency(frequency+frequency*i);
  }
  // myOscillators[0]->setFrequency(frequency);
  // myOscillators[1]->setFrequency(frequency * 3);
  // myOscillators[2]->setFrequency(frequency * 2);
  // myOscillators[3]->setFrequency(frequency * 1);
  // // std::cout<<frequency;
}

double Additive::getFrequency()
{
  return frequency;
}


void Additive::tickAll(){
tickAdditiveOsc();
}

void Additive::numAddOsc(){ 
  for(int i=0;i!=numOsc;i++){
  myOscillators[i] = new Sine(0,samplerate);
  std::cout<<myOscillators[i];
  }
}

float Additive::getSamples(){
  sample=0;
      for(int i=0;i!=numOsc;i++){
  sample += myOscillators[i]->getSample(); 
  }
  return sample;
}


void Additive::tickAdditiveOsc(){
    for(int i=0;i!=numOsc;i++){
  myOscillators[i]->tick();;
  }
}


