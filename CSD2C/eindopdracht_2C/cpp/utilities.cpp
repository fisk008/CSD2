#include "Utilities.h"


Utils::Utils() {
}

Utils::~Utils() {
}

float Utils::mapInRange (float factor, float xLow, float xHigh, float yLow, float yHigh) {
    return (yLow * (xHigh - factor) + yHigh * (factor - xLow)) / (xHigh - xLow);
}

float Utils::linearMap (float factor, float low, float high) {
    return mapInRange (factor, 0, 1, low, high);
}