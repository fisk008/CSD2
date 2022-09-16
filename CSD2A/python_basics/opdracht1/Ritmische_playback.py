#gebruik een lijst en funcitie range

import simpleaudio as sa
import time 
i=0

playback = int(input("how many times would you like to hear it?"))
ritm = input('Enter space-separated floats : ').split()
inputbpm= int(input("bpm?:"))
bpm = 60/inputbpm
list_of_rithms = [float(item) for item in ritm]
total_rithms= sum(list_of_rithms)
playback + 1
print(total_rithms)

for i in range(playback):
    print("loop:",i+1,"     ","time in ms betweem samples:",list_of_rithms[i]*bpm)
    wave_obj = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/CSD2/audio_files/test1.wav")
    play_obj = wave_obj.play()
    play_obj.wait_done()
    list_of_rithms.append(1)
    time.sleep(list_of_rithms[i]*bpm)
    i=i+1
      
