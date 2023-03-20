#include "jack_module.h"
#include "effect.h"
#include "sine.h"
#include "delay.h"
#include <array>
#include <iostream>
#include "osc.h"
class Callback : public AudioCallback {

public:
    void prepare (int sampleRate) override {    
        for (Sine& sine : sines){
            sine.prepareToPlay(static_cast<double> (sampleRate));
            }
        for (Delay& delay :delays){
            delay.setDryWet(0.5);
            delay.prepareToPlay(static_cast<double>(sampleRate));
            delay.setFeedback(0.3);
        }

    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                outputChannels[channel][sample] = (delays[channel].output(inputChannels[0][sample]));
            }
        }
    }

private:
    std::array<Sine,2> sines;
    std::array<Delay,2> delays;


};

int gyroX; 
// subclass OSC into a local class so we can provide our own callback
class localOSC : public OSC{
  int realcallback(const char *path,const char *types,lo_arg **argv,int argc){
  string msgpath=path;
    if(!msgpath.compare("/gyroX")){
      int int1 = argv[0]->i;
        gyroX = int1;  
    }
    return 0;
  } // realcallback()
};

int main() {
    
    auto callback = Callback{};
    auto jack = JackModule (callback);

    localOSC osc;
    string serverport="7777";
    osc.init(serverport);
    osc.set_callback("/gyroX","i");
    cout << "Listening on port " << serverport << endl;
    osc.start();

    // start jack client with 2 inputs and 2 outputs
    jack.init (1, 2);

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
