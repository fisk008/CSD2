#include "synth_am.h"


//def Constructor and destructor
AM::AM(){
}
AM::~AM(){
}
//contructor used in main to pass on arguments to choose modulator carrier and modulator frequency
AM::AM(float modulatorFrequency,int modulator,int carrier){
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

//sets and gets frequency for carrier 
void AM::setFrequency(double frequency){
    this->frequency = frequency;
    myOscillators[0]->setFrequency(frequency);
}

double AM::getFrequency(){
  return frequency;
}

//ticks both carrier and modulator
void AM::tickAll(){
myOscillators[0]->tick();
myOscillators[1]->tick();
}

// multiplies to carrier with the modulator and returns sample
float AM::getSamples(){
sample = myOscillators[0]->getSample()*myOscillators[1]->getSample();

return sample;
}

