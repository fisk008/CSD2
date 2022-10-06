# from inspect import istraceback
# from sqlite3 import Timestamp
# from turtle import right
from unicodedata import name
from venv import create
import simpleaudio as sa
import time
import random
correctInput = False



hihat = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/hihat.wav")
snare = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/snare.wav")
kick = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/kick.wav")

# playEvents = [
# {'name': 'snare','instrument':snare,'timeS':timeListS},
# {'name': 'kick','instrument':kick,'timeS':timeListK} ,
# {'name': 'hihat','instrument':hihat,'timeS':timeListH}]





def eventPlay(playEvent):
    print(playEvent['name'])
    playEvent['instrument'].play()
    # return(sampleEvent)




def userInput(correctInput): # here the user is asked for input   
    bpm = 120
    global bpmInput
    bpmAsk= input('hi...default bpm: 120 would you like too keep it? [y/n] \n')
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

def noteGen(bpmInput):#creates a random list of note values
    global timeListK,timeListS,timeListH
    global noteV

    
    noteV=[0.25,0.5,1]    
    bpmNow = 60 / bpmInput

    kickR  = [random.choice(noteV) for i in range(16)]
    snareR = [random.choice(noteV) for i in range(16)]
    hihatR = [random.choice(noteV) for i in range(16)]  

    # for i in range(16):
    #     rithms.append(random.choice(noteV))
    
    timeListK = []
    timeListS = []
    timeListH = []
    
    for dur in kickR:
        timeListK.append(bpmNow * dur)#creates the timelist for the three samples 

    for dur in snareR:
        timeListS.append(bpmNow * dur)
        
    for dur in hihatR:
        timeListH.append(bpmNow * dur)       
    
    return(timeListK,timeListS,timeListH)  


playEvents = []

# here a function that creates dicts with name instrument en timestamp
def createEvent(name,instrument, timestamp):
    newEvent = {}
    newEvent['name'] = name
    newEvent['instrument'] = instrument
    newEvent['timeS'] = timestamp
    playEvents.append(newEvent)
    
#here the function create event pushes everyeting into a list with all the different samples
def createEvents(timeListH,timeListK,timeListS):
    for ts in timeListH:
        createEvent('hat',hihat, ts)
        #print('HIHAT',ts)
    for ts in timeListK:
        createEvent('kick',kick, ts)
        #print('kick',ts)
    for ts in timeListS:
        createEvent('snare',snare, ts)
        #print('snare',ts)


    print(playEvents[1]['name']['timeS'])  



def tStamps(timeList):    #converts timeList into time stamps
    global timeSeq
    global timeStamp


    
    
    timeStamp = []
    i=0
    for ts in timeList:
        timeStamp.append(i)#here 
        i = i + ts
    if timeStamp :
        timeSeq = timeStamp.pop(0)
    else:    
        # print("list empty")
        exit()
    return(timeSeq,timeList)

def Playing(timeStamp,timeSeq):#handles the note palying part  and handles de deg eventPlay
    print(timeStamp)  
    current = time.time()
    while True :
        #choose a int between 0 and 2 to choose random samples
        #samplerand=random.randint(0,2)
        now = time.time() - current
    #checks if enough time has passed to play next sample
        if(now >= timeSeq):
            eventPlay(sampleEvent)
            #removes sample from list when timeStamp=true
            if timeStamp:
                timeSeq= timeStamp.pop(0)
            else:
                break
            time.sleep(0.001)        
#samples to choose from


    #lets the sample play out
    time.sleep(1)


userInput(correctInput)
noteGen(bpmInput)
createEvents(timeListH,timeListK,timeListS)

#tStamps(timeList)
#Playing(timeStamp,timeSeq)