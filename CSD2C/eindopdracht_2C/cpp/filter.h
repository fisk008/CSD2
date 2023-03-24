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
    void setCoefficientHi(float cutOff, float resonance);
    void setCoefficientLo(float cutOff, float resonance);
    //filter variables
   
    double sampleRate {0};
    double beta {0};
    double gamma {0};
    double a0 {0};
    double a1 {0};
    double a2 {0};
    double b1 {0};
    double b2 {0};
    double c0 =1.0;
    double d0 {0};
    double d1 {0};

    double x1{0}, x2{0}, y1{0}, y2{0};

};
