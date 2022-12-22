#pragma once

#include <iostream>

#define NUM_NOTES 9

//this code was given to me by my teachers Cyska and marc and belongs to them, to make melodies using a midi list containing midi notes
class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  float getPitch();

protected:
  // Cmaj7 -  arpeggio
  float melody[NUM_NOTES] = {60, 64, 67, 71, 64, 67, 64, 60, 55};
  // the index of the current note - readIndex
  int index;
};
