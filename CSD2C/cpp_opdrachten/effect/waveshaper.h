#pragma once
#include <iostream>
#include <cmath>
#include "effect.h"
#include "Utilities.h"

struct Waveshaper:Effect{

    Waveshaper(int size) : bufferSize (size), buffer (new float[bufferSize]) {
        
    }

    ~Waveshaper() {
        delete[] buffer;
    }

    void prepareToPlay(double sampleRate) override{

    }

    float output(float input){
        // Push the index from -1 - 1 to 0 - 2. Then multiply by half the bufferSize to find its nearest position
        float index = (input + 1.0f) * (bufferSize * 0.5f);
        // truncate index (remove everything after the decimal point)
        int i = (int) trunc (index);
        // subtract from the original value to find the remainder
        float indexDecimal = index - (float) i;

        // the remainder is the interpolation factor. To accurately estimate the value between two buffer positions
        return Util::linearMap (indexDecimal, buffer[i], buffer[i + 1]);
    }
    
    void setDrive(float k){
        for (int i = 0; i < bufferSize; ++i) {
            float x = Util::mapInRange (i, 0.0f, bufferSize, -1.0f, 1.0f);
            buffer[i] = atan (k * x) / atan (k);         
        }
        //jens::cout (std::to_string (k));
    }

    uint bufferSize { 0 };
    float* buffer;
    };
