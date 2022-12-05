#include "sine.h"
#include "math.h"

Sine::Sine(){
std::cout << "Sine - constructor\n";
}

Sine::Sine(float frequency, float amplitude, float phase, float samplerate) : Oscillator(frequency, amplitude, phase, samplerate)
{
  
}
Sine::Sine(float frequency,float samplerate){

}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}




void Sine::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  sample = sin(M_PI * 2 * phase) * amplitude;
  
  phase += frequency / samplerate;
  
  if(phase >= 1.0f){
    phase -= 1.0f;
  }
}


