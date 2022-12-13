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



void Square::calculate( ){
    if(phase > 0.5)
    {
        sample = amplitude;
    } else {
        sample = amplitude*-1.0f;
    }
}