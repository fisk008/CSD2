#include "jack_module.h"
#include "math.h"
#include "square.h"
#include "melody.h"
#include "synth_am.h"
#include "user_input.h"
#pragma once

class Callback : public AudioCallback
{

public:

double mtof(float pitch);
void updatePitch(Melody& melody, Synth& synth);
void prepare(double sampleRate) override;
void setSynthChoise(Synth* synth);
void process (AudioBuffer buffer) override;
void setBPM(float bpm);


private:
  double sampleRate;
  UserInput ui;
  Synth* synth;
  float amplitude = 0.025;
  Melody melody;
  int frameIndex = 0;
  float AdjustedBpm;

};