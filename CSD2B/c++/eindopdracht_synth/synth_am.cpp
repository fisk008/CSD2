#include <iostream>
#include <cmath>
#include "synth_am.h"


AM::AM(){
myOscillators[0]=new Sine(440,samplerate);
myOscillators[1]=new Sine(1,samplerate);

}

AM::~AM(){

}

void AM::setFrequency(double frequency){
    this->frequency = frequency;
    myOscillators[0]->setFrequency(frequency);
 
}

double AM::getFrequency()
{
  return frequency;
}
void AM::tickAll(){
myOscillators[0]->tick();
myOscillators[1]->tick();
}


float AM::getSamples(){
sample = myOscillators[0]->getSample()*myOscillators[1]->getSample();

return sample;
}