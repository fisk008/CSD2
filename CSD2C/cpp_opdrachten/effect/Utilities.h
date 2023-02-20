//
// Created by Dean on 14/02/2023.
//

#include <cmath>
#include <iostream>

namespace Util{

    float mapInRange (float factor, float xLow, float xHigh, float yLow, float yHigh) {
        return (yLow * (xHigh - factor) + yHigh * (factor - xLow)) / (xHigh - xLow);
    }
    float linearMap (float factor, float low, float high) {
        return mapInRange (factor, 0, 1, low, high);
    }


} // Util

namespace Jens {
    void cout(std::string input){
        std::cout << "Jens new Cout function! " << input << std::endl;
    }
}