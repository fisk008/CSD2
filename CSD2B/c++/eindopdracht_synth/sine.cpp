#include "sine.h"

//def contructors/desctructors 
Sine::Sine(){
}

Sine::~Sine() {
}

Sine::Sine(float frequency, float samplerate) : Oscillator(frequency,samplerate){
}

//function of calculation of a Sine waveform with aliasing
void Sine::calculate(){
  sample = sin(M_PI * 2.0f * phase) * amplitude;
}





