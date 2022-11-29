#include <iostream>
#include "synth.h"


int main()
{
    Oscillator osc;
    std::cout << "\n in main\n";
    

    osc.pitch(50.33);
    osc.envelope(3.5,3.6,4.0,2.0);
    
    return 0;

}