#include "effect.h"
#pragma once


struct OnePole : public Effect {
    OnePole() {
    }
    ~OnePole() {
    }

    void prepareToPlay(double sampleRate) override {
    }
    float output(float input)override{
        //yn = b * xn + a * yn-1
        float output = b * input + a * y1;
        y1=output;
        return output;
    }

    void setCoefficient(float coefficient){
        a = coefficient;
        b = 1.0f - a;
    }

    float y1 { 0.0 };
    float b { 0.0 };
    float a { 0.0 };
};
