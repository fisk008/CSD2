#pragma once

#include "effect.h"
#include "circ_buffer.h"

class Delay : Effect{
    public:
    Delay();
    ~Delay();  
    void prepareToPlay (double sampleRate) override ;//set buffersize and delay distance
    float output(float input) override;//returns output of delay
    void setFeedback(float feedback);//sets feedback amount
    void setDryWet(float wet) override;//sets dry wet amount
    void setDelaytime(float delayTime);//sets delay time
    
    CircBuffer* buf;//buffer for delay
    float buffersize= {0};
    float feedback {0};
};