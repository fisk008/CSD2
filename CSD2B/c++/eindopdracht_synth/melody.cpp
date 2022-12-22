#include "melody.h"
//this code was given to me by my teachers Cyska and marc and belongs to them, to make melodies using a midi list containing midi notes
Melody::Melody()
{}

Melody::~Melody()
{}

float Melody::getPitch()
{
  // wrap index
  if(index >= NUM_NOTES) {
    index = 0;
  }
  // index++ --> first use current value to read from array, after this
  // increment with 1
  return melody[index++];
}
