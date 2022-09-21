#gebruik een lijst en funcitie range

import simpleaudio as sa
import time 
i=0
#all the inputs 
playback = int(input("how many times would you like to hear it?"))
ritm = input('Enter space-separated floats : ').split()
inputbpm= 60/int(input("bpm?:"))

#list for the rithms
list_of_rithms = [float(item) for item in ritm]

#sum of total Rithms
total_rithms= sum(list_of_rithms)
playback + 1
length_notes= list_of_rithms[i]*inputbpm
#here is a forloop that loops everytime on basis from the user inputs above
for i in range(playback):
    print("loop:",i+1,"     ","time in sec betweem samples:",length_notes)
    wave_obj = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/CSD2/audio_files/test1.wav")
    
    #plays samples
    play_obj = wave_obj.play()
    list_of_rithms.append(1)
   
    #program sleeps at every loop 
    time.sleep(length_notes)
    i=i+1
      
