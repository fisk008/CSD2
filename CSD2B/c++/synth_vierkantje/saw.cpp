#include <iostream>
#include "saw.h"



Saw::Saw(){

}

Saw::Saw(float frequency, float amplitude, float phase, float samplerate) : Oscillator(frequency,amplitude,phase,samplerate)
{
    
}

Saw::Saw(float frequency, float samplerate) : Oscillator(frequency,samplerate){

}


Saw::~Saw(){
    std::cout<<"sqaure =deconstruct\n";
}



void Saw::tick( ){

    if(phase > 1.0f)
    {
        phase -= 1.0f;
    }
    phase += frequency / samplerate;

    sample = amplitude*2 * phase - amplitude;
}
