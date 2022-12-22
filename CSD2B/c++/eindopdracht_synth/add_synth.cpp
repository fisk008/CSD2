#include <iostream>
#include <cmath>
#include "add_synth.h"

//default constructor 
Additive::Additive(){

}

Additive::Additive(float numOsc){
  
  this->numOsc= numOsc;
   numAddOsc();

}
//descructor
Additive::~Additive(){
      
}


//setters and getters for given Sine Oscillators
void Additive::setFrequency(double frequency)
{
  this->frequency = frequency;

  for(int i=0;i<numOsc;i++){
    myOscillators[i]->setFrequency(frequency+frequency*i);
  }

}

double Additive::getFrequency()
{
  return frequency;
}

//funtion that uses function to tick all 
void Additive::tickAll(){
tickAdditiveOsc();
}
//function that adds sine wave to given oscillators
void Additive::numAddOsc(){ 
  for(int i=0;i!=numOsc;i++){
  myOscillators[i] = new Sine(0,samplerate);
  std::cout<<myOscillators[i];
  }
}
//function that gets the samples and counts them with eachother to add up to additive synth.
float Additive::getSamples(){
  sample=0;
      for(int i=0;i!=numOsc;i++){
  sample += myOscillators[i]->getSample(); 
  }
  return sample;
}

//the function that loops to tick all given oscillator
void Additive::tickAdditiveOsc(){
    for(int i=0;i!=numOsc;i++){
  myOscillators[i]->tick();;
  }
}


