#include <iostream>
#include <cmath>
#include "synth_fm.h"


FM::FM(){
myOscillators[0]=new Sine(440,samplerate);
myOscillators[1]=new Sine(1,samplerate);
}

FM::~FM(){

}

void FM::setFrequency(double frequency){
    this->frequency = frequency;
    myOscillators[0]->setFrequency(frequency);
 
}

double FM::getFrequency()
{
  return frequency;
}
void FM::tickAll(){
myOscillators[0]->tick();
myOscillators[1]->tick();
}

float FM::getSamples(){
sample = (myOscillators[0]->getSample()*myOscillators[1]->getSample())/2;

return sample;
}