#include "flanger.h"


Flanger::Flanger() {
    buf = new CircBuffer();
}

Flanger::~Flanger() {
    delete buf;
}

void Flanger::prepareToPlay(double sampleRate) {
    buf->setDistance(44100);
    buf->setBufferSize(22050);
}

void Flanger::setFeedback(float feedback) {
    this->feedback = feedback;

    if (feedback < 0 && feedback > 0.99) {
        feedback = 0;
        std::cout << "feedback cant be higher then 0.99 to protect ears and speakers" << std::endl;
    }
}

float Flanger::output(float input) {
return input;
}

void Flanger::setDryWet(float wet) {
    this->wet = wet;
    dry = 1 - wet;
    
}