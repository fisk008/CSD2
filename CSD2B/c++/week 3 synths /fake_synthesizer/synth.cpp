#include <iostream>
#include "synth.h"


void Oscillator::pitch(float pitchNote)
{
    this->pitchNote = pitchNote;
    std::cout << "Inside Oscillator constructor ()\n";

}

void Oscillator::envelope(float attack,float decay, float sustain, float release)
{
    this->attack = attack;
    this->decay = decay;
    this->release = release;
    this->sustain = sustain;
    std::cout << "inside the Envelope constructor\n";
    
}

