#include "sine.h"
#include "math.h"

Sine::Sine(){
  
}



Sine::Sine(float frequency, float samplerate) : Oscillator(frequency,samplerate)
{
  std::cout << "sine constructor\n";
}



Sine::~Sine() {
  std::cout << "sine destructor\n";
}



void Sine::calculate() {

  sample = sin(M_PI * 2.0f * phase) * amplitude;
}





