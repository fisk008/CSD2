#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"


#include "synth.h"
#include "add_synth.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;

  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  
  Additive ad = Additive();
  
};

#endif //CALLBACK_H
