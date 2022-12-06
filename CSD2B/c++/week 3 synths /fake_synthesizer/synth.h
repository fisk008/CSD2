#pragma once
#include <iostream>


class Oscillator
{   
public:

    void pitch( float pitchNote );
    void envelope(float attack,float decay, float sustain, float release);
   


protected:
 float attack;
 float decay;
 float sustain;
 float release;
 double pitchNote;
};