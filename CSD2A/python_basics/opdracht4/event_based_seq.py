from inspect import istraceback
from turtle import right
import simpleaudio as sa
import time
import random




samples = [ sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/Plop.wav"),
            sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/snare.wav"),
            sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/kick.wav")]


#fucntionalities additions
#-input check

#multiple samples and lists/

#dictionary for list
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
    global timelist 
    global noteV
    rithms=[]
    
    noteV=[0.25,0.5,1]
    bpmNow = 60 / bpmInput
    for i in range(16):
        rithms.append(random.choice(noteV))
    
    timelist= []
    for dur in rithms:
        timelist.append(bpmNow * dur)
    return(timelist)  

def tStamps(timelist):    #converts timelist into time stamps
    global time_seq
    global timestamp
    
    timestamp = []
    i=0
    for ts in timelist:
        timestamp.append(i)
        i = i + ts
    if timestamp :
        time_seq = timestamp.pop(0)
    else:    
        # print("list empty")
        exit()
    return(time_seq,timelist)

def Playing(timestamp,time_seq):
    print(timestamp)  
    current = time.time()
    while True :
        #choose a int between 0 and 2 to choose random samples
        samplerand=random.randint(0,2)
        now = time.time() - current
    #checks if enough time has passed to play next sample
        if(now >= time_seq):
            samples[samplerand].play()
            #removes sample from list when timestamp=true
            if timestamp:
                time_seq= timestamp.pop(0)
            else:
                break
            time.sleep(0.001)        
#samples to choose from


    #lets the sample play out
    time.sleep(1)

userInput(bpmAsk,correctInput)
noteGen(bpmInput)
tStamps(timelist)
Playing(timestamp,time_seq)