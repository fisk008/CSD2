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
        buf->setDistance(44100);
        buf->setBufferSize(22050);

    }

    float output(float input) override{
       
        float outputBuf = buf->output();
        buf->input(input+(outputBuf*feedback));//writing into the buffer and adding feedback amount also to the buffer 
        buf->incrementHeads(); 
        

        return (outputBuf*wet) + (input*dry);//dry wet 
    }

    void setFeedback(float feedback){
        this->feedback=feedback;

        if(feedback<0&&feedback>0.99){
            feedback=0;
            std::cout<<"feedback cant be higher then 0.99 to protect ears and speakers"<<std::endl;
        }
    }

    
    CircBuffer* buf;
    float buffersize= {0};
    float feedback {0};
};