#include <iostream>
#include <cmath>
#include "oscillator.h"

//def constructor
Oscillator::Oscillator(){

}
//def descructor
Oscillator::~Oscillator(){

}

//construct with given arguments
Oscillator::Oscillator(float frequency, float samplerate)
:   frequency(frequency), amplitude(1.0), phase(0), samplerate(samplerate){

}


//returns sample
float Oscillator::getSample(){
    return sample;
}

//setters getters frequency
void Oscillator::setFrequency(float frequency){
    this->frequency = frequency;
}

float Oscillator::getFrequency(){
    return frequency;
}
//tick given oscillator and flips phase
void Oscillator::tick(){
  phase += frequency / samplerate;
  
  if(phase > 1.0f){
    phase -=1.0f;
  }

  calculate();
}