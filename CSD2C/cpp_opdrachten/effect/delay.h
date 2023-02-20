#pragma once

#include "effect.h"
#include "circ_buffer.h"

struct Delay : Effect{
    Delay(){      
        buf= new CircBuffer(44100*4);
    }

    ~Delay(){
        delete buf;
    }
    
    void prepareToPlay (double sampleRate) override {//set buffersize and delay distance
        buf->setDistance(22050);
        buf->setBufferSize(44100);

    }

    void calculate(float signalInput){//sending samples into buffer and incrementing the heads
        buf->input(signalInput);
        buf->incrementHeads(); 

    }


    float output(float input) override{
        calculate(input);
        float outputBuf = buf->output();
        return (outputBuf*wet) + (input*dry);//dry wet 
    }

    
    CircBuffer* buf;
    float buffersize= {0};
};