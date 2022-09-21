
import simpleaudio as sa
import time

bpm = 120.0
note_dur = [1, 1.5, 1.2,0.8]

quartnote_dur = 60.0 / bpm

#loadsample
loadSample = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/CSD2/audio_files/kick.wav")

#quarnote_dur* note_dur to make a list of time segments
timelist= []
for dur in note_dur:
    timelist.append(quartnote_dur * dur)
print(timelist)    


#todo make a list of time segments
timeseg = []
timesum= 0
for times in timelist:
    timeseg.append(timesum)
    timesum = timesum+ times    
print(timeseg)



# while True :
#     if 


# timestamps = []
# ts=0
# timestamps.append(ts)