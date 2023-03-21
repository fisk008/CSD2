#include "effect.h"
#pragma once
#include <iostream>

class Filter : Effect{
    public:
    Filter();
    ~Filter();
    void prepareToPlay (double sampleRate) override;
    float output(float input) override;
    void setDryWet(float wet) override;   

    void setCutOff(float cutOff);
    void setResonance(float resonance);
    float cutOff {0};
    float resonance {0};
};
