import simpleaudio as sa
import time
import random


#fucntionalities additions
#-input check
#-src and dst
#multiple samples and lists
#dictionary voor list
# function sort
correctInput = False
bpm = 120
bpmInput= input('hi...default bpm: 120 would you like too keep it? [y/n] \n')

if(bpmInput == "n"):
#based on code from the class    
    while (not correctInput):
        
        bpmInput = input("what bpm would you like?\n")

        # check if we 'received' an empty string
        if not bpmInput:
            # empty string --> use default
            correctInput = True
        else:
            
            try:
                bpm = float(bpmInput)
                correctInput = True
            except:
                print("Incorrect input - please enter a bpm (or enter nothing - default bpm)")
    bpmInput= float(bpmInput)
    print('okay bpm is now:',bpm)
    
if(bpmInput == "y"):
    print("okay default bpm:",bpm, "is used ")


bpmNow = 60 / bpmInput
noteV=[0.25,0.5,1]
rithms=[]

#creates a random list of note values
for i in range(16):
    rithms.append(random.choice(noteV))
#print(rithms)

timelist= []
for dur in rithms:
    timelist.append(bpmNow * dur)
print(timelist)  
#converts timelist into time stamps


timestamp = []
i=0
for ts in timelist:
    timestamp.append(i)
    i = i + ts

print(timestamp)


#samples to choose from
samples = [ sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/Plop.wav"),
            sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/snare.wav"),
            sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/kick.wav")]


#code from the lesson
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
        #choose a int between 0 and 2 to choose random samples
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