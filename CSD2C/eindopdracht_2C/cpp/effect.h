#include <iostream>
#pragma once

struct Effect {
    virtual void prepareToPlay (double sampleRate) = 0;
    virtual float output (float input) = 0;
    
    void setDryWet(float wet){
        this->wet=wet;
        if(wet){
            dry = 1-wet; 
        }
    }
    float dry{0};
    float wet{0};
};