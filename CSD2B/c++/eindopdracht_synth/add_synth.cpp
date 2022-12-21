#include <iostream>
#include <cmath>
#include "add_synth.h"

Additive::Additive(){
// initAddOsc();
}

Additive::Additive(float numOsc){
  
  numAddOsc(numOsc);


  // if(additiveOsc==1){
  //   myOscillators[0]=new Sine(frequency,samplerate);
  //   myOscillators[1]=new Sine(frequency,samplerate);
  //   myOscillators[3]=new Sine(frequency,samplerate);
  //   myOscillators[4]=new Sine(frequency,samplerate);
  // }
  // else if(additiveOsc==2){

  // }
  // // else{


  // }
}

Additive::~Additive(){
      
}



void Additive::setFrequency(double frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
  myOscillators[0]->setFrequency(frequency);
  myOscillators[1]->setFrequency(frequency * 3);
  myOscillators[2]->setFrequency(frequency * 2);
  myOscillators[3]->setFrequency(frequency * 1);
  // std::cout<<frequency;
}

double Additive::getFrequency()
{
  return frequency;
}


void Additive::tickAll(float numOsc){
tickAdditiveOsc(numOsc);
}

void Additive::numAddOsc(float numOsc){
  
  for(int i=0;i!=numOsc;i++){
  ;
  myOscillators[i] = new Sine(0,samplerate);
  }
}
float Additive::getSamples(float numOsc){
  sample = (getOscSamples(numOsc))/numOsc;
  
  
  return sample;
}


void Additive::tickAdditiveOsc(float numOsc){
    for(int i=0;i!=numOsc;i++){
  myOscillators[i]->tick();;
  }
}


float Additive::getOscSamples(float numOsc){
      for(int i=0;i!=numOsc;i++){
  sample = myOscillators[i]->getSample();
  return sample;
  }
  std::cout << sample ;
}