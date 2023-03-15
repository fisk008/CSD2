#include <iostream>
#pragma once

class Effect {
    public:
    virtual void prepareToPlay (double sampleRate) = 0;
    virtual float output (float input) = 0;
    virtual void setDryWet(float wet)=0;
    float dry{0};
    float wet{0};
};