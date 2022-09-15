#gebruik een lijst en funcitie range

import simpleaudio as sa
import time 
i=0

playback = input("how many times would you like to hear it?")
ritm = input('Enter space-separated : ').split()
int_playback = int(playback)
list_of_rithms = [int(item) for item in ritm]
 
int_playback + 1
  
for i in range(int_playback):
    print(i+1)
    wave_obj = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/CSD2/audio_files/test1.wav")
    play_obj = wave_obj.play()
    play_obj.wait_done()
    time.sleep(loop)
    i=i+1
      




