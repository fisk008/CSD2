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
  float getSamples();
  float mtof(int note);
  void tickAll();

  Oscillator* myOscillators[3];
  protected:

  float note=440;
  
  private:
  float samplerate= 44100;
  float sample;
 
};