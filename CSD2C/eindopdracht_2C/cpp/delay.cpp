#include "delay.h"

#include "effect.h"
#include "circ_buffer.h"
#include "Utilities.h"
Utils utils;

Delay::Delay(){      
    buf= new CircBuffer(44100*4);
}

Delay::~Delay(){
    delete buf;
}

void Delay::prepareToPlay (double sampleRate) {//set buffersize and delay distance
    buf->setDistance(44100);
    buf->setBufferSize(22050);

}

float Delay::output(float input){
    
    float outputBuf = buf->output();
    buf->input(input+(outputBuf*feedback));//writing into the buffer and adding feedback amount also to the buffer 
    buf->incrementHeads(); 
    
    
    return (utils.linearMap(outputBuf,-1,1)*wet) + (input*dry);//dry wet 
}

void Delay::setFeedback(float feedback){
    this->feedback=feedback;

    if(feedback<0&&feedback>0.99){
        feedback=0;
        std::cout<<"feedback cant be higher then 0.99 to protect ears and speakers"<<std::endl;
    }
}

void Delay::setDryWet(float wet){
    this->wet=wet;
    dry = 1.0-wet;
    // std::cout<<"wet: "<<wet<<std::endl;
   
}

void Delay::setDelaytime(float delayTime){
    buf->setDistance(delayTime*44100.0);
}
