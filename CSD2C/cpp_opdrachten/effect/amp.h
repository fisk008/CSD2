#include "effect.h"
#pragma once
#include <iostream>
struct Amp:Effect{
    void prepareToPlay (double sampleRate) override {
    }
    void setAmpValue(float amp){
        this->amp=amp;
    }
    float output(float input) override{
    amp=0.3;
    amp *= input;
    // std::cout<<"amp value:"<<amp<<std::endl;
    if (amp> 1.0)amp=1;

    return amp;    
    }

    float amp{0};
    
};
