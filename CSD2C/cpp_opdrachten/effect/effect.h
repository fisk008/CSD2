#pragma once

struct Effect {
    virtual void prepareToPlay (double sampleRate) = 0;
    virtual float output (float input) = 0;
    
    void setDryWet(float wet){
        if(wet >= 1.0){
            wet=1.0;
        }
       dry -= 1-wet;
    }

    float dry{0};
    float wet{0};
};