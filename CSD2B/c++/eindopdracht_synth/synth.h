#pragma once
#include <iostream>
#include "sine.h"
#include "square.h"
#include "saw.h"
#include "oscillator.h"
// #include "oscillator.h"

class Synth{
  public:
  Synth();
  ~Synth();

  // virtual void tick();
  void setSamplerate(float samplerate);
  void getSamplerate();

  // float getSamplerate();
  float mtof(int note);
  virtual float getSamples()=0;
  virtual void tickAll()= 0;
  virtual void setFrequency(double frequency)=0;
  
  protected:

  float note=440;
  
  float samplerate= 44100;
  private:
  
 
};