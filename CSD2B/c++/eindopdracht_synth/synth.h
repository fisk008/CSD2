#pragma once
#include <iostream>
#include "sine.h"
#include "square.h"
#include "saw.h"

// #include "oscillator.h"

class Synth{
  public:
  Synth();
  ~Synth();

  // virtual void tick();
  void setSamplerate(float samplerate);
  // float getSamplerate();
  virtual float getSample()=0;
  float mtof(int note);

  protected:
  float note=440;
  
  private:
  float samplerate= 44100;
  float sample;
 
};