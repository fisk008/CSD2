#include "saw.h"


//def contructors/desctructors 
Saw::Saw(){
}

Saw::~Saw(){    
}

Saw::Saw(float frequency, float samplerate) : Oscillator(frequency,samplerate){
phase=0;
samplerate= 44100;
}


//calculation of a Saw waveform with aliasing
void Saw::calculate( ){
    sample = amplitude*2 * phase - amplitude;
}
