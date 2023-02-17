//
// Created by Dean on 27/10/2022.
//
#pragma once

struct Effect {
    virtual void prepareToPlay (double sampleRate) = 0;
    virtual float output (float input) = 0;
    
    void setDryWet(float input){
        if(input >= 1.0){
            wet=0;
        }
       dry -= 1-input;
    }

    float dry{0};
    float wet{0};
};