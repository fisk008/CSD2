#pragma once

#include "effect.h"
#include "circ_buffer.h"

class Flanger : Effect{
    public:
    Flanger();
    ~Flanger();  
    void prepareToPlay (double sampleRate) override ;//set buffersize and delay distance
    float output(float input) override;
    void setFeedback(float feedback);
    void setDryWet(float wet) override;
    // void setRate(float rate);
    // void setDepth(float depth);

    CircBuffer* buf;
    float buffersize= {0};
    float feedback {0};
//     float rate {0};
//     float depth {0};
};