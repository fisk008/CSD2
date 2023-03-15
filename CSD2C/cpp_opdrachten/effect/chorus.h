#include "effect.h"
#pragma once
#include "sine.h"
#include "circ_buffer.h"
struct Chorus : Effect
{


    Chorus(){
        buf= new CircBuffer(44100*4);
    }
    ~Chorus(){
        delete buf;
    }

    void prepareToPlay(double samplerate) override{
        osc.prepareToPlay(44100);
        buf->setBufferSize(22050);

    }

    float output(float input) override{
        auto modSignal = osc.output();
        buf->setDistance(22050*2*modSignal);
        buf->incrementHeads(); 
        buf->input(input);
        float outputBuf = buf->output();
        
        return (outputBuf*wet) + (input*dry); 
    }

    void offset(float offset){
        // this->offset=offset;

    }  


    void setRate(float rate=2){
        osc.setDelta(rate);
    }
    
    // float offset{0};
    Sine osc;
    CircBuffer* buf;
    };