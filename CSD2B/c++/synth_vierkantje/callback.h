#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "sine.h"
#include "oscillator.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;

  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  Sine sinus = Sine(440, samplerate);
};

#endif //CALLBACK_H
