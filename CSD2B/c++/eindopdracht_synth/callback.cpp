/*
  Example program that plays a simple hard coded melody using a square wave oscillator
*/

#include <iostream>
#include <thread>
#include "callback.h"



double Callback::mtof(float mPitch)
{
    // source of the mtof calculation:
    // https://www.musicdsp.org/en/latest/Other/125-midi-note-frequency-conversion.html
    return 440.0 * pow(2.0, (mPitch - 57.0f)/12.0f);
} // mtof()


void Callback::updatePitch(Melody& melody, Synth& synth) {
    float pitch = melody.getPitch();
    double freq = mtof(pitch);
    std::cout << "next pitch: " << pitch << ", freq is: " << freq << std::endl;
    synth.setFrequency(freq);
} // updatePitch()


void Callback::prepare(double sampleRate)  {
    this->sampleRate=sampleRate;
    updatePitch(melody,*synth);
} // prepare()

void Callback::setSynthChoise(Synth* synth){
this->synth = synth;
    
} //setSynthChoise()


/*
    * process() gets called by the JACK engine.
    *
    * If you are interested in incoming audio, use inputChannels[channel][sample]
    * For sending audio to the output(s), use outputChannels[channel][sample]
    */
void Callback::process (AudioBuffer buffer){
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

for (int channel = 0; channel < numOutputChannels; ++channel) {
    for (int sample = 0; sample < numFrames; ++sample) {
    outputChannels[channel][sample] = synth->getSamples() * amplitude;
    synth->tickAll(); // rather mixed up functionality

    /* After every sample, check if we need to advance to the next note
        * This is a bit awkward in this scheme of buffers per channel
        *  In a multichannel setting we should update pitches independently per channel!
        */
    if(frameIndex >= AdjustedBpm * sampleRate) {
        // reset frameIndex
        frameIndex = 0;
        updatePitch(melody,*synth);
    }
    else {
        // increment frameindex
        frameIndex++;
    }

    } // for sample
} // for channel
} // process()

void Callback::setBPM(float bpm){
    AdjustedBpm = 60/ bpm;
    std::cout<<AdjustedBpm;
    }








