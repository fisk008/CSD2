import simpleaudio as sa
import time
import random


bpm=60/140
noteV=[0.5,1,1.5,2.0]
rithms=[]
rithms2=[]
rithms3=[]
#creates a random list of note values
for i in range(16):
    rithms.append(random.choice(noteV))
    rithms2.append(random.uniform(0.5, 1.5))
    rithms3.append(random.uniform(0.5, 1.5))

#print(rithms)

timelist= []
for dur in rithms:
    timelist.append(bpm * dur)
#print(timelist)  
#converts timelist into time stamps


timestamp = []
i=0
for ts in timelist:
    timestamp.append(i)
    i = i + ts

print(timestamp)


#samples to choose from
samples = [ sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD2_lesStof/CSD_22-23/blok2a/assigment_3/audioFiles/Pop.wav"),
            sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD2_lesStof/CSD_22-23/blok2a/assigment_3/audioFiles/Laser1.wav"),
            sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD2_lesStof/CSD_22-23/blok2a/assigment_3/audioFiles/Dog2.wav")]



if timestamp :
    tseg = timestamp.pop(0)
else:    
    print("list empty")
    exit()





def Playing():
    if timestamp :
        tseg = timestamp.pop(0)
    else:    
        print("list empty")
        exit()   
    current = time.time()
    while True :
        samplerand=random.randint(0,2)
        now = time.time() - current
    #checks if enough time has passed to play next sample
        if(now >= tseg):
            samples[samplerand].play()
            #removes sample from list when timestamp=true
            if timestamp:
                tseg= timestamp.pop(0)
            else:
                break
            time.sleep(0.001)        


    #lets the sample play out
    time.sleep(1)

samplerand=random.randint(0,2)

Playing()