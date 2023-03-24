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
float quaX;
float quaY{0};
float quaZ{0};


class localOSC : public OSC
{
  int realcallback(const char *path,const char *types,lo_arg **argv,int argc)
  {
  string msgpath=path;
    if(!msgpath.compare("/compass")){
        int int1 = argv[0]->i;
        compass = int1;
        // std::cout<<"int: "<<int1<<std::endl;
    }
    //   cout << "Message: " << compass << endl;
    if(!msgpath.compare("/qua")){
        int int1 = argv[0]->i;
        quaX = int1+60;
        if(quaX<1)quaX=1;
        
    }
    if(!msgpath.compare("/qua/y")){
        float int1 = argv[0]->i;
        quaY = int1+100; 
        if(quaY<1)quaY=1;
    }
    if(!msgpath.compare("/qua/z")){
        float int1 = argv[0]->i;
        quaZ = int1; 
      
    }
    return 0;
    } // realcallback()
};


float mapInRange (float factor, float xLow, float xHigh, float yLow, float yHigh) {
        return (yLow * (xHigh - factor) + yHigh * (factor - xLow)) / (xHigh - xLow);
}

    float linearMap (float factor, float low, float high) {
        return mapInRange (factor, 0, 1, low, high);
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
            filter.setCoefficientHi(10000,0.7);
            filter.setDryWet(1);
        }   
        

    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                
                outputChannels[channel][sample] = filters[channel].output((delays[channel].output(inputChannels[0][sample])));

            }
                
                delays[channel].setDryWet(mapInRange(compass,0,360,0,0.3));
                delays[channel].setDelaytime(mapInRange(quaY,0,100,0.5,0.1));
                filters[channel].setCoefficientLo(mapInRange(quaX,0,180,40,16000),5);
                 std::cout << "filterValue: " << mapInRange(quaY,0,100,0.5,0.1) << std::endl;

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
    string serverport="5000";
    osc.init(serverport);
    osc.set_callback("/compass","i");
    osc.set_callback("/qua","i");
    osc.set_callback("/qua/y","i");
    osc.set_callback("/qua/z","f");
    // cout << "Listening on port " << serverport << endl;
    cout<< "aan!";
    osc.start();
    // start jack client with 2 inputs and 2 outputs
    jack.init (1, 2);

    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                std::cout<<"uit!"<<endl;
                running = false;
                break;
        }
    }

    return 0;
}
