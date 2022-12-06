#include <iostream>
#include "square.h"



Square::Square(){

}

Square::Square(float frequency, float samplerate) : Oscillator(frequency,samplerate)
{
    
}



Square::~Square(){
    std::cout<<"sqaure deconstructor \n";
}



void Square::tick( ){

    phase += frequency / samplerate;

    if(phase >= 1.0f){
        phase -= 1.0f;
    }
    
    if(phase > 0.5)
    {
        sample = amplitude;
    } else {
        sample = amplitude*-1.0f;
    }
}