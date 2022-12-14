#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"

#include "melody.h"
#include "synth.h"
#include "add_synth.h"
#include "synth_am.h"
#include "user_input.h"
#include "callback.h"
#include "audioToFile.h"
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
  AM am;
  UserInput ui;
  Melody melody;
  Additive add;

  auto callback = Callback {};
  //here my UI line program begins and asks the question for what synth you would like to hear
  std::string synthOptions[2] = {"AM", "additive"};
  int numSynthOptions = 2;
  std::string userSynthChoise = ui.retrieveUserInput(synthOptions,numSynthOptions);  

  if (userSynthChoise == synthOptions[0]){
  std::cout << "You chose the following synth: " << synthOptions[0] << std::endl; 
    

    //carrier choice ui
    std::cout << "You can choose the following carrier wave types: " << std::endl; 
    std::string carrierOptions[3]= {"sine","square","saw"};
    int numCarrierOptions=3;
    int carrierChoise = ui.retrieveUserSelection(carrierOptions,numCarrierOptions);
    //modulator choice
    std::cout << "You can choose the following modulator wave types: " << std::endl;
    std::string modulatorOptions[3]= {"sine","square","saw"};
    int numModulatorOptions=3;
    int modulatorChoise = ui.retrieveUserSelection(modulatorOptions,numModulatorOptions);
    //modulator frequency choice
    std::cout << "What would you like for the modulator frequency?"<<std::endl;
    float modulatorFrequency = ui.retrieveValueInRange(0.1,15000);
    std::cout << "You chose the following modulator frequency: " << modulatorFrequency << std::endl;
    
    // initialise constructor synth with given options from user 
    synth = new AM(modulatorFrequency,modulatorChoise,carrierChoise);
    callback.setSynthChoise(((AM*)synth));
  }

  else if(userSynthChoise == synthOptions[1]) {
    std::cout << "You chose the following synth: " << synthOptions[1] << std::endl;  
    
    // how many oscillators in additive synth question?
    std::cout << "How many oscillators do you want in the additive synth? " << std::endl; 
    float numOsc = ui.retrieveValueInRange(1,5);

    // initialise constructor with given options from user 
    synth = new Additive(numOsc);
    callback.setSynthChoise(((Additive*)synth));
  }
  // bpm question
  std::cout << "What would you like as bpm for tempo?"<<std::endl;
  float bpm = ui.retrieveBPMInRange(30, 250);
  callback.setBPM(bpm);


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

AudioToFile audioFile=AudioToFile();
audioFile.write(callback);
  return 0;
#endif
} // main()
