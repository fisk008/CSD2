from inspect import istraceback
from turtle import right
import simpleaudio as sa
import time
import random

timestamp = []
noteV= []
global tseg
samples = [ sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/Plop.wav"),
            sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/snare.wav"),
            sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/kick.wav")]


#fucntionalities additions
#-input check

#multiple samples and lists/

#dictionary voor list
# function sort?

correctInput = False
bpm = 120
bpmAsk= input('hi...default bpm: 120 would you like too keep it? [y/n] \n')
bpmInput= 120

def userInput(bpmAsk,correctInput):    
    if(bpmAsk == "n"):
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
    
    if(bpmAsk == "y"):
        bpmInput = 120
        print("okay default bpm:",bpmInput, "is used ")
    return(bpmInput)       


# def bpmGen(bpmInput):
#     bpmNow = 60 / bpmInput
    
    

#creates a random list of note values
def noteGen(bpmInput):
    rithms=[]
    noteV=[0.25,0.5,1]
    bpmNow = 60 / bpmInput
    for i in range(16):
        rithms.append(random.choice(noteV))
    
    timelist= []
    for dur in rithms:
        timelist.append(bpmNow * dur)
      
    #converts timelist into time stamps
    timestamp = []
    i=0
    for ts in timelist:
        timestamp.append(i)
        i = i + ts
    if timestamp :
        tseg = timestamp.pop(0)
    else:    
        # print("list empty")
        exit()
    return(tseg)

def Playing(timestamp,tseg):
    print(timestamp)  
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
#samples to choose from


    #lets the sample play out
    time.sleep(1)

userInput(bpmAsk,correctInput)
noteGen(bpmInput)
Playing(timestamp,tseg)