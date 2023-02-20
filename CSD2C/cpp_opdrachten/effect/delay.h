#pragma once

#include "effect.h"
#include "circ_buffer.h"

struct Delay : Effect{
    void prepareToPlay (double sampleRate) override {
        buf.setDistance(22050);
        buf.setBufferSize(44100);

    }

    void calculate(float signalInput){
        buf.input(signalInput);
        buf.incrementHeads(); 
    }


    float output(float input) override{
        calculate(input);
        return buf.output();
    }


    CircBuffer buf;
    float buffersize= {0};
};