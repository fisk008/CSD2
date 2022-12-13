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
  
  virtual void tick();
  virtual void setSamplerate(float samplerate);
  virtual float getSample();

  protected:
  float mtof(int note);
  float note=440;
  
  private:
  float samplerate= 44100;
  
  float combineSamples();
  
  Sine sinusje= Sine(note,samplerate);
  Square blokje= Square(note,samplerate);
  Saw zaag=Saw(note,samplerate);

   
};