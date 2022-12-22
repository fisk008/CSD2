#pragma once
#include <iostream>
#include <math.h>
#include "sine.h"
#include "square.h"
#include "saw.h"
#include "oscillator.h"
// #include "oscillator.h"

class Synth{
  public:
  //def construct/destructors
  Synth();
  ~Synth();

  //setters and getters samplerate
  void setSamplerate(float samplerate);
  float getSamplerate();
  //virtual functions for subclas synths
  
  virtual float getSamples()=0;
  virtual void tickAll()= 0;
  virtual void setFrequency(double frequency)=0;

  
  float samplerate= 44100;
  
};