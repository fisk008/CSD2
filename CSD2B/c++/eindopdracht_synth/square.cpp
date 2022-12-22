#include "square.h"


//Constructor and destructor
Square::Square(){
}

Square::~Square(){
}

Square::Square(float frequency, float samplerate) : Oscillator(frequency,samplerate){ 
}

//function of calculation of a square waveform with aliasing
void Square::calculate( ){
    if(phase > 0.5)
    {
        sample = amplitude;
    } else {
        sample = amplitude*-1.0f;
    }
}