#include "sine.h"
#include "math.h"


Sine::Sine(float frequency, float samplerate) : Oscillator(frequency,samplerate)
{
  std::cout << "sine constructor\n";
}



Sine::~Sine() {
  std::cout << "sine destructor\n";
}

float Sine::getSample() {
  return sample;
}


void Sine::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  phase += frequency / samplerate;
  if(phase > 1.0f){
    phase -=1.0f;
  }
  sample = sin(M_PI * 2.0f * phase) * amplitude;
}





