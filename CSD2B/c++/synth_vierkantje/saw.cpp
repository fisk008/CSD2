#include <iostream>
#include "saw.h"



Saw::Saw(){
 std::cout<<"saw contrcutor\n";
}



Saw::Saw(float frequency, float samplerate) : Oscillator(frequency,samplerate){
phase=0;
samplerate= 44100;
}


Saw::~Saw(){
    std::cout<<"saw deconstructor\n";
}



void Saw::tick( ){

    if(phase > 1.0f)
    {
        phase -= 1.0f;
    }
    phase += frequency / samplerate;

    sample = amplitude*2 * phase - amplitude;
}
