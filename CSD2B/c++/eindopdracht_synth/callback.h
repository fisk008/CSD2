#include "jack_module.h"
#include "math.h"
#include "square.h"
#include "melody.h"
#include "synth_am.h"
#include "user_input.h"
#pragma once
//this code is given to me by my teacher Cyska to make buffers from synthesizer wich gives samples to jack audio 
//added some small changes
class Callback : public AudioCallback
{

public:

double mtof(float pitch);
void updatePitch(Melody& melody, Synth& synth);
void prepare(double sampleRate) override;
void setSynthChoise(Synth* synth);
void process (AudioBuffer buffer) override;
void setBPM(float bpm);
float numOsc =4;


private:
  double sampleRate;
  UserInput ui;
  Synth* synth;
  float amplitude = 0.025;
  Melody melody;
  int frameIndex = 0;
  float AdjustedBpm;
};