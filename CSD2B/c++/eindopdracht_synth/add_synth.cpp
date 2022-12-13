#include <iostream>
#include <cmath>
#include "add_synth.h"

Additive::Additive(){

}
Additive::~Additive(){
    
}


void Additive::tickAll(){
sinusje.tick();  
blokje.tick();
zaag.tick();

}

float Additive::combinedSamples(){

  float allFreqs = (sinusje.getSample()+zaag.getSample()+blokje.getSample())/3;
  return allFreqs;

}

float Additive::getSample(){
return sample;
}