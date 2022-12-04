#include "sine.h"
#include "math.h"


Sine::Sine(float frequency, float amplitude, float phase, float samplerate) : Oscillator(frequency, amplitude, phase, samplerate)
{
  std::cout << "Sine - constructor\n";
}

Sine::Sine(float frequency, float amplitude) : Oscillator(frequency, amplitude)
{
  phase = 0;
  samplerate = 48000;
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

float Sine::getSample() {
  return sample;
}


void Sine::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  sample = sin(pi * 2 * phase) * amplitude;
  
  phase += frequency / samplerate;
  
  if(phase >= 1.0f){
    phase -= 1.0f;
  }
}


