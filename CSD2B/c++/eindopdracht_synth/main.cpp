#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "square.h"
#include "melody.h"
#include "synth.h"
#include "add_synth.h"
#include "synth_fm.h"
#include "user_input.h"
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 1
#define sound 1


double mtof(float mPitch)
{
  // source of the mtof calculation:
  // https://www.musicdsp.org/en/latest/Other/125-midi-note-frequency-conversion.html
  return 440.0 * pow(2.0, (mPitch - 57.0f)/12.0f);
}

void updatePitch(Melody* melody, FM* fm) {
  float pitch = melody->getPitch();
  double freq = mtof(pitch);
  std::cout << "next pitch: " << pitch << ", freq is: " << freq << std::endl;
  fm->setFrequency(freq);
}



int main(int argc,char **argv)
{
  // create the modules
  UserInput ui;
  JackModule jack;
  Melody melody;
  Additive add;
  FM fm;


  
  std::string synthOptions[2] = {"FM", "Additive synth"};
  int numWaveFormOptions = 2;

  std::string waveTypeSelection = ui.retrieveUserSelection(synthOptions,
      numWaveFormOptions);

  std::cout << "You selected: " << waveTypeSelection << std::endl;


  // float value =  ui.retrieveValueInRange(20, 20499);
  // std::cout << "You chose the following value: " << value << std::endl;
  
  // // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  const double samplerate = jack.getSamplerate();

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 5000; i++) {
    fileWriter.write(std::to_string(fm.getSamples()) + "\n");
    fm.tickAll();
  }
  std::cout << "\nWROTE TO FILE = DONE." << std::endl;
#endif


#if sound

  float amplitude = 0.025;

  // keep track of the frameIndex, to play notes at a given frame interval
  int frameIndex = 0;
  const int frameInterval = 0.20 * samplerate;
  // start with the first pitch
  updatePitch(&melody, &fm);


  //assign a function to the JackModule::onProces
  jack.onProcess = [&fm,&amplitude, &melody, &frameIndex, frameInterval](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    // fill output buffer
        
    for(unsigned int i = 0; i < nframes; i++) {

      // check if we need to set the frequency to the next note
      if(frameIndex >= frameInterval) {
        // reset frameIndex
        frameIndex = 0;
        updatePitch(&melody, &fm);
      } else {
        // increment frameindex
        frameIndex++;
      }

      // write sample to output
      outBuf[i] = fm.getSamples() * amplitude;

      // calculate next sample
      fm.tickAll();

    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }
#endif
  //end the program
  return 0;

} // main()
