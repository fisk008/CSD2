#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "sine.h"
#include "square.h"
#include "saw.h"
#include "oscillator.h"
#include "synth.h"
class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;

  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  Sine sinus = Sine(440, samplerate);
  Square square =Square(440, samplerate);
  Saw zaagje = Saw(440, samplerate);
  
};

#endif //CALLBACK_H
