#include "callback.h"
#include <fstream>
#include <iostream>
#include<memory>
#include <sys/stat.h>
//this code was given to me by my teachers Cyska and marc and belongs to them, to write samples to a .csv file to see the waveform
class WriteToFile {
public:
  WriteToFile (std::string fileName, bool overwrite = false);
  ~WriteToFile();

  bool write (std::string text);

private:
  bool fileExists (const std::string& fileName);
  bool openFile (std::string fileName);
  std::ofstream file;
};


class AudioToFile {
public:
  // TODO
  // add functionality to set numFrames and channels
  AudioToFile (int numInputchannels = 1,
               int numOutputChannels = 1,
               int numFrames = 48000);
  ~AudioToFile();
  // TODO
  // add functionality to write a given range to file
  void write (AudioCallback& callback);

private:

  std::unique_ptr<WriteToFile> fileWriter;
  std::unique_ptr<AudioBuffer> audioBuffer;

  int numInputChannels = 1;
  int numOutputChannels = 1;
  int numFrames = 48000;
  float** inputChannel;
  float** outputChannel;
};
