#include "jack_module.h"
#include "effect.h"
#include "sine.h"
#include "tremolo.h"   
#include "amp.h"
#include "delay.h"
// #include "waveshaper.h"
#include <array>
#include <iostream>
class Callback : public AudioCallback {

public:
    void prepare (int sampleRate) override {    
        for (Sine& sine : sines){
            sine.prepareToPlay(static_cast<double> (sampleRate));
            }
        for (Tremolo& tremolo : tremolos){
            tremolo.prepareToPlay(static_cast<double> (sampleRate));
            tremolo.setDryWet(0.5);
        }
        for (Amp& amp : amps){
            amp.prepareToPlay(static_cast<double>(sampleRate));
        }
        for (Delay& delay :delays){
            delay.setDryWet(1);
            delay.prepareToPlay(static_cast<double>(sampleRate));
            delay.setFeedback(0.3);
        }
        // for (Waveshaper& Waveshaper:waveshapers){
        //     Waveshaper.prepareToPlay(static_cast<double>(sampleRate));
        // }
        
    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                outputChannels[channel][sample] = tremolos[channel].output((delays[channel].output(inputChannels[0][sample])));
                //outputChannels[channel][sample] = (tremolos[channel].output(inputChannels[0][sample]));
            
            }
        }
    }

private:
    std::array<Tremolo,2> tremolos;
    std::array<Sine,2> sines;
    std::array<Amp,2> amps;
    std::array<Delay,2> delays;
    //std::array<Waveshaper,2>waveshapers;

};
int main() {
    
    auto callback = Callback{};
    auto jack = JackModule (callback);
    Amp amp;
    
    // start jack client with 2 inputs and 2 outputs
    jack.init (1, 2);
    amp.setAmpValue(0.3);
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
