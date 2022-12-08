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


void Sine::calculate() {

  sample = sin(M_PI * 2.0f * phase) * amplitude;
}





