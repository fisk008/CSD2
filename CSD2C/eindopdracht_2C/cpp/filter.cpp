#include "filter.h"
#include <cmath>

Filter::Filter() {}

Filter::~Filter() {}

void Filter::prepareToPlay(double sampleRate) {
    // Calculate filter coefficients
    double rc = 1.0 / (cutOff * 2 * M_PI);
    double dt = 1.0 / sampleRate;
    alpha_ = rc / (rc + dt);
    prevOutput_ = 0.0;
}

float Filter::output(float input) {
    float output = alpha_ * (prevOutput_ + input - prevInput_);
    prevInput_ = input;
    prevOutput_ = output;
    // std::cout << "Filter output: " << output << std::endl;
    return output;
}

void Filter::setDryWet(float wet) {
    this->wet = wet;
    dry = 1.0 - wet;
}

void Filter::setCutOff(float cutOff) {
    this->cutOff = cutOff;
}

void Filter::setResonance(float resonance) {
    this->resonance = resonance;
}

