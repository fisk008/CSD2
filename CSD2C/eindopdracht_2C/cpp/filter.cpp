#include "filter.h"
#include <cmath>

Filter::Filter() {}

Filter::~Filter() {}

void Filter::prepareToPlay(double sampleRate) {
this->sampleRate = sampleRate;

}

float Filter::output(float input) {

    double output=(d0*input)+(c0*(a0*input)+(a1*x1)+(a2*x2)-(b1*y1)-(b2*y2));
    x2 = x1;
    x1 = input;
    y2 = y1;
    y1 = output;
    std::cout<<"output: "<<output<<std::endl;
    return output;
}

void Filter::setCoefficient(float cutoff ,float q) {
    double omega = (2.0f * acos(-1.0) * static_cast<double>(cutoff)) / static_cast<double>(sampleRate);
    double d = 1 /q;
    std::cout<<d<<std::endl;
    double betaB = 1 - (d/2) * sin(omega);
    double betaO = 1 + (d/2) * sin(omega);
    beta = 0.5 * (betaB/betaO);
    std::cout << "beta: " << beta << std::endl;
    gamma= (0.5+beta)*cos(omega);
    std::cout << "gamma: " << gamma << std::endl;
    a0 = (0.5+beta+gamma)/2;
    a1 = -(0.5+beta+gamma);
    a2 = (0.5+beta+gamma)/2;
    b1 = -2*gamma;
    b2 = 2*beta;

    std::cout << "a: " << a0 << ", " << a1 << ", " << a2 << std::endl;
    std::cout << "b: " << 1 << ", " << b1 << ", " << b2 << std::endl;
}
void Filter::setDryWet(float wet) {
    this->wet = wet;
    dry = 1.0 - wet;
}

void Filter::setCutOff(float cutOff) {
    this->cutOff = cutOff;
}

