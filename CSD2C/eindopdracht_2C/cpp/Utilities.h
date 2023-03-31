//
// Created by Dean on 14/02/2023.
// edited by ruben
//

#include <cmath>
#include <iostream>
#pragma once

class Utils{
    public:
    Utils();
    ~Utils();
    float mapInRange (float factor, float xLow, float xHigh, float yLow, float yHigh);
    float linearMap (float factor, float low, float high);


} ;// Util
