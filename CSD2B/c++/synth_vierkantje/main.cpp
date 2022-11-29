#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "writeToFile.h"
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override {
    samplerate = (float) rate;

   WriteToFile fileWriter("output.csv", true);
  for(int i = 0; i < samplerate; i++) {
    fileWriter.write(std::to_string((harm1.getSample() + harm2.getSample() + harm3.getSample() + harm4.getSample()+ harm5.getSample() )/5.) + "\n");
          
          
    harm1.tick();
    harm2.tick();
    harm3.tick();
    harm4.tick();
    harm5.tick();
  }

  }

  void process(AudioBuffer buffer) override {
    for (int i = 0; i < buffer.numFrames; ++i) {
      // write sample to buffer at channel 0, amp = 0.25
      buffer.outputChannels[0][i] =( harm1.getSample() + harm2.getSample() + harm3.getSample() + harm4.getSample()+ harm5.getSample()) /5.;
      harm1.tick();
      harm2.tick();
      harm3.tick();
      harm4.tick();
      harm5.tick();
      }
  }
  private:
  float samplerate = 44100;
  Sine harm1 = Sine(50, samplerate);
  Sine harm2 =Sine(150,samplerate);
  Sine harm3 =Sine(250,samplerate);
  Sine harm4 =Sine(350,samplerate);
  Sine harm5 =Sine(450,samplerate);


};

int main(int argc,char **argv)
{
  auto callback = CustomCallback {};
  auto jackModule = JackModule { callback };

  jackModule.init (0, 1);

  bool running = true;
  while (running) {
      switch (std::cin.get()) {
          case 'q':
              running = false;
      }
  }

  //end the program
  return 0;
} // main()
