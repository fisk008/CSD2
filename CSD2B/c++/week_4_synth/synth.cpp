#include "synth.h"
#include <iostream>
#include <math.h>

Synth::Synth()
{
  std::cout << "sine constructor\n";
}

Synth::~Synth(){

}
void Synth::tick(){
  phase += frequency / samplerate;
  
  if(phase > 1.0f){
    phase -=1.0f;
  }
  calculate();  
}
void Synth::calculate(){

}