#include "effect.h"
#pragma once
#include "sine.h"
#include "circ_buffer.h"
struct StereoChorus : Effect
{


    StereoChorus(){
        buf= new CircBuffer(44100*4);
    }
    ~StereoChorus(){
        delete buf;
    }

    void prepareToPlay(double samplerate) override{
        osc.prepareToPlay(44100);
        buf->setBufferSize(22050);

    }

    float output(float input) override{
        auto modSignal = osc.output();
        buf->incrementHeads(); 
        buf->input(input);
        buf->setDistance(44100*modSignal);
        float outputBuf = buf->output();
        
        //return;
    }

    void offset(float offset){
        // this->offset=offset;

    }
    
    float offset{0};
    Sine osc;
    CircBuffer* buf;
    };