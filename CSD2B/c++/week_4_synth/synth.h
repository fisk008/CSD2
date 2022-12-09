#pragma once
#include <iostream>
#include "sine.h"
#include "square.h"
#include "saw.h"

// #include "oscillator.h"

class Synth : public Sine{
  public:
  Synth();
  ~Synth();
  void calculate();
  float getSample();
  void tick();
  float mtof(int note);
  float note();
  
  protected:
  
  float samplerate= 44100;
  
  float amplitude;
  float phase;

  float frequency;
  float sample;
  
  Sine sinusje= Sine(note(),samplerate);
  Square blokje= Square(note(),samplerate);
  Saw zaag=Saw(note(),samplerate);

   
};