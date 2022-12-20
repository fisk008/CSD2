#include <iostream>
#include <cmath>
#include "synth_am.h"

AM::AM(){

}

AM::AM(float modulatorFrequency,int modulator,int carrier){
// myOscillators[0]=new Sine(frequency,samplerate);
// myOscillators[1]=new Sine(modulatorfrequency,samplerate);

if(carrier==1){
  myOscillators[0]=new Sine(frequency,samplerate);
}
else if(carrier==2){
myOscillators[0]=new Square(frequency,samplerate);
}
else{
  myOscillators[0]=new Saw(frequency,samplerate);


}
if(modulator==1){
  myOscillators[1]=new Sine(modulatorFrequency,samplerate);
}
else if(modulator==2){
myOscillators[1]=new Square(modulatorFrequency,samplerate);
}
else{
  myOscillators[1]=new Saw(modulatorFrequency,samplerate);
}


}

AM::~AM(){

}

void AM::setFrequency(double frequency){
    this->frequency = frequency;
    myOscillators[0]->setFrequency(frequency);
 
}

double AM::getFrequency(){
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

