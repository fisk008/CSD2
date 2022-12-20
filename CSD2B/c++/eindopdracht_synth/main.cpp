#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "melody.h"
#include "synth.h"
#include "add_synth.h"
#include "synth_fm.h"
#include "user_input.h"
#include "callback.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 1
#define sound 1


int main(int argc,char **argv)
{
  Synth* synth= nullptr;
  FM fm;
  UserInput ui;
  Melody melody;
  Additive add;
  
  auto callback = Callback {};
  std::string synthOptions[2] = {"FM", "additive"};
  int numWaveFormOptions = 2;
  std::string waveTypeSelection = ui.retrieveUserSelection(synthOptions,numWaveFormOptions);  

  if (synthOptions[0] == "FM"){
    synth = new FM;
  std::cout << "You chose the following synth: " << synthOptions[0] << std::endl; 
    
    callback.setSynthChoise(((FM*)synth));
  }

  else {
    synth = new Additive;
    std::cout << "You chose the following synth: " << synthOptions[1] << std::endl;  
    callback.setSynthChoise(((Additive*)synth));
  }


  float bpm = ui.retrieveBPMInRange(30, 250);
  callback.setBPM(bpm);

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 5000; i++) {
    fileWriter.write(std::to_string(synth->getSamples()) + "\n");
    synth->tickAll();
  }
  std::cout << "\nWROTE TO FILE = DONE." << std::endl;
#endif

#if sound

  auto jack_module = JackModule(callback);

  jack_module.init(1,1);

  std::cout << "\n\nType 'quit' to exit\n";
  bool running = true;
  while (running) {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        break;
    }
  } // while

  return 0;
#endif
} // main()
