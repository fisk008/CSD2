#include <iostream>
#include "saw.h"



// Saw::Saw(){
//  std::cout<<"saw contrcutor\n";
// }

// Saw::Saw(float frequency, float amplitude, float phase, float samplerate) : Oscillator(frequency,amplitude,phase,samplerate)
// {
//   std::cout<<"saw contrcutor\n";  
// }

Saw::Saw(float frequency, float samplerate) : Oscillator(frequency,samplerate){
phase=0;
samplerate= 44100;
}


Saw::~Saw(){
    std::cout<<"saw deconstruct\n";
}

float Saw::getSample(){
    return sample;
}



void Saw::tick( ){

    if(phase > 1.0f)
    {
        phase -= 1.0f;
    }
    phase += frequency / samplerate;

    sample = amplitude*2 * phase - amplitude;
}
