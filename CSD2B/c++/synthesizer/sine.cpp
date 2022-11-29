#include "sine.h"
#include "math.h"



Sine::Sine(float frequency, double samplerate) : oscillator(frequency,samplerate)
{
 
}



Sine::~Sine() {

}


float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  phase += frequency / samplerate;
  sample = sin(pi * 2 * phase) * amplitude;
  if(phase > 1.0f){
    phase =-1.0f;
  }
}

