#include "synth.h"
#include <iostream>
#include <math.h>
#include "callback.h"

Synth::Synth()
{
  std::cout << "sine constructor\n";
}

Synth::~Synth(){

}
void Synth::tick(){
sinusje.tick();  
blokje.tick();
zaag.tick();


}
void Synth::calculate(){

}
float Synth::getSample(){

  float allFreqs = (sinusje.getSample()+zaag.getSample()+blokje.getSample())/3;
  return allFreqs;

}

float Synth::mtof(int note){
  double frequency = 440.0 * std::pow(2.0, (note - 69.0) / 12.0);
  
  
  return frequency;
}
float Synth::note(){

  float frequency = mtof();
  std::cout<<frequency << "\n";
  return frequency;
}
float Synth::input(){
  std::cout<<"insert midi note"<<"\n";
  int note;
  std::cin >> note;
}