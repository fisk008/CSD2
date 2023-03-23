#include "jack_module.h"
#include "effect.h"
#include "sine.h"
#include "delay.h"
#include <array>
#include <iostream>
#include "osc.h"
#include "filter.h"
#include <map>

int compass;
class localOSC : public OSC
{
  int realcallback(const char *path,const char *types,lo_arg **argv,int argc)
  {
  string msgpath=path;
    if(!msgpath.compare("/compass")){
      int int1 = argv[0]->i;
      compass = int1;
    //   cout << "Message: " << compass << endl;

    }
    return 0;
  } // realcallback()
};

float mapComp(float compass){
    float mapped=compass /360.0;
    return mapped;
}


class Callback : public AudioCallback {


public:
    void prepare (int sampleRate) override {    
        for (Sine& sine : sines){
            sine.prepareToPlay(static_cast<double> (sampleRate));
            }
        for (Delay& delay :delays){
            delay.prepareToPlay(static_cast<double>(sampleRate));
            delay.setFeedback(0.3);
            delay.setDryWet(0);
        }
        for(Filter& filter : filters){
            filter.prepareToPlay(static_cast<double>(sampleRate));
            filter.setCoefficient(1000,0.7);
            filter.setDryWet(1);
        }

    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                // outputChannels[channel][sample] = (delays[channel].output(inputChannels[0][sample]));
                outputChannels[channel][sample] = (filters[channel].output(inputChannels[0][sample]));
            }
                delays[channel].setDryWet(mapComp(compass));
        }
    }

private:
    std::array<Sine,2> sines;
    std::array<Delay,2> delays;
    std::array<Filter,2> filters;
};




int main() {
    
    auto callback = Callback{};
    auto jack = JackModule (callback);
   
    //osc messages         
    localOSC osc;
    
    string serverport="7776";
    osc.init(serverport);
    ///ZIGSIM/1/deviceinfo "\"unknown device (iPhone13,2)\"" \"1\" \"ios\" \"16.3.1\" 1125 2001
    osc.set_callback("/compass","i");
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
