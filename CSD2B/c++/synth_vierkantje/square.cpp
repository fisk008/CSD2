#include <iostream>
#include "square.h"

Sqaure::Sqaure(float frequency, double samplerate) : Oscillator(frequency,samplerate)
{
    std::cout << "sqaure- constructor\n";
}

Sqaure::~Sqaure(){
    std::cout<<"sqaure =deconstruct\n";
}



void Sqaure::tick( ){

    phase += frequency / samplerate;

    if(phase >= 1.0f){
        phase -= 1.0f;
    }
    
    if(phase < 0.5)
    {
        sample = amplitude;
    } else {
        sample = amplitude*-1.0f;
    }
}