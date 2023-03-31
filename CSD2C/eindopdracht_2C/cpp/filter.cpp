#include "filter.h"
#include <cmath>
//this filter is based on the biquad filter of will pirkle 
//also got help from my teacher jochem and daan
Filter::Filter() {}

Filter::~Filter() {}

void Filter::prepareToPlay(double sampleRate) {
this->sampleRate = sampleRate;

}
//difference equation for filter
float Filter::output(float input) {
    double output=(d0*input)+(c0*(a0*input)+(a1*x1)+(a2*x2)-(b1*y1)-(b2*y2));
    x2 = x1; 
    x1 = input;
    y2 = y1;
    y1 = output;
    return (output*wet) + (input*dry);;
}
//sets coefficients for highpass filter
void Filter::setCoefficientHi(float cutoff ,float q) {
    double omega = (2.0f * acos(-1.0) * static_cast<double>(cutoff)) / static_cast<double>(sampleRate);
    double d = 1 /q;
    double betaB = 1 - (d/2) * sin(omega);
    double betaO = 1 + (d/2) * sin(omega);

    beta = 0.5 * (betaB/betaO);
    gamma= (0.5+beta)*cos(omega);

    a0 = (0.5+beta+gamma)/2;
    a1 = -(0.5+beta+gamma);
    a2 = (0.5+beta+gamma)/2;
    b1 = -2*gamma;
    b2 = 2*beta;

}
//sets coefficients for lowpass filter
void Filter::setCoefficientLo(float cutoff ,float q) {
    double omega = (2.0f * acos(-1.0) * static_cast<double>(cutoff)) / static_cast<double>(sampleRate);
    double d = 1 /q;
    double betaB = 1 - (d/2) * sin(omega);
    double betaO = 1 + (d/2) * sin(omega);

    beta = 0.5 * (betaB/betaO);
    gamma= (0.5+beta)*cos(omega);

    a0 = (0.5+beta-gamma)/2;
    a1 = (0.5+beta-gamma);
    a2 = (0.5+beta-gamma)/2;
    b1 = -2*gamma;
    b2 = 2*beta;

}
//sets coefficients for filter
void Filter::setDryWet(float wet) {
    this->wet = wet;
    dry = 1.0 - wet;
}



