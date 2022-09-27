#importent!!
#this patch is a remake of the patch of ciska, as I was strungling to make this assignment i decided to walk trough the patch and rewrite it so i could understand everyting done in the patch
#so understand this is not my work but just a remake of the example


import simpleaudio as sa
import time

bpm = 120.0
note_dur = [1, 1, 1,1]

quartnote_dur = 60.0 / bpm

#loadsample
loadSample = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD2/audio_files/kick.wav")

#quarnote_dur* note_dur to make a list of time segments
timelist= []
for dur in note_dur:
    timelist.append(quartnote_dur * dur)
print(timelist)    


#makes a list of time segments by adding up the time segments before and so on
timeseg = []
print(timeseg)
#timesum is a variable to save the last int and 0 because our loop start on the first count
timesum= 0
for times in timelist:
    timeseg.append(timesum)
    timesum = timesum + times    
print(timeseg)

#this removes each time stamp from the list till its empty and then stops if empty
# if timeseg :
#     tseg = timeseg.pop(0)
# else:    
#     print("list empty")
#     exit()

current= time.time()
#here the sample gets played it checks everytime if enough time has passed til the next sample 
while True :
   now = time.time() - current
   #checks if enough time has passed to play next sample
   if(now >= tseg):
    loadSample.play()
    #removes sample from list when timeseg=true
    if timeseg:
        tseg= timeseg.pop(0)
    else:
        break
    time.sleep(0.001)        


#lets the sample play out
time.sleep(1)