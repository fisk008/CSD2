#include "jack_module.h"
#include "sine.h"
#include "tremolo.h"   

#pragma once

class Callback : public AudioCallback {

public:
    void prepare (int sampleRate) override {
        for (Sine& sine : sines){
            sine.prepareToPlay (static_cast<double> (sampleRate));
            }
        for (Tremolo& tremolo : tremolos){
            tremolo.prepareToPlay (static_cast<double> (sampleRate));
        }
    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                outputChannels[channel][sample] = (tremolos[channel].output(inputChannels[0][sample]));
                // if (sample % 44100 == 0)std::cout << sines[channel].output();
            }
        }
    }

private:
    std::array<Tremolo,2> tremolos;
    std::array<Sine,2> sines;
  

};