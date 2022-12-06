#include "callback.h"


void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    zaagje.setSamplerate(samplerate);
    std::cout << "\nsamplerate: " << samplerate << "\n";
}




void CustomCallback::process(AudioBuffer buffer) {
  for (int i = 0; i < buffer.numFrames; ++i) {
    // write sample to buffer at channel 0, amp = 0.25
    buffer.outputChannels[0][i] = zaagje.getSample();
    zaagje.tick();
  }
}
