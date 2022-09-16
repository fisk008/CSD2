#gebruik een lijst en funcitie range

import simpleaudio as sa
import time 
i=0

playback = input("how many times would you like to hear it?")
ritm = input('Enter space-separated floats : ').split()
int_playback = int(playback)
list_of_rithms = [float(item) for item in ritm]
 
int_playback + 1
  
for i in range(int_playback):
    print("loop:",i+1,"     ","time betweem samples:",list_of_rithms[i])
    wave_obj = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/CSD2/audio_files/test1.wav")
    play_obj = wave_obj.play()
    play_obj.wait_done()
    list_of_rithms.append(1)
    time.sleep(list_of_rithms[i])
    i=i+1
      




