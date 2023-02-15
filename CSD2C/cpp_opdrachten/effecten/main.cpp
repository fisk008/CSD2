#include "jack_module.h"
#include "tremolo.h"
#include <array>
#include <iostream>
#include "sine.h"

class Callback : public AudioCallback {

public:
    void prepare (int sampleRate) override {
        for (Sine& sine : sines)
            sine.prepareToPlay (static_cast<double> (sampleRate));
        for (Tremolo& tremolo : tremolos)
            tremolo.prepareToPlay (static_cast<double> (sampleRate));

    }


    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                outputChannels[channel][sample] = tremolos[channel].output(sines[channel].output());
            }
        }
    }

private:
    std::array<Tremolo,2> tremolos;
    std::array<Sine,2> sines;
  

};


int main() {

    auto callback = Callback {};
    auto jack = JackModule (callback);

    // start jack client with 2 inputs and 2 outputs
    jack.init (2, 2);

    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }

    return 0;
}
