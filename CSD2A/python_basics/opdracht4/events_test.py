from operator import itemgetter
import simpleaudio as sa
import time
import random
correctInput = False
correctInputYN= False
playEvents = []

hihat = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/hihat.wav")
snare = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/snare.wav")
kick = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/kick.wav")




def userInput(correctInput,correctInputYN): # here the user is asked for input   
    bpm = 120
    global bpmInput
    
    while (not correctInputYN):   
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
            correctInputYN = True
        else:
            print("input is incorrect please enter [y/n]")
            correctInputYN = False
        
        if(bpmAsk == "y"):
            bpmInput = 120
            print("okay default bpm:",bpmInput, "is used ")
            correctInputYN = True
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


# here a list is created with all the
def createEvent(name,instrument, timestamp):
    newEvent = {}
    newEvent['name'] = name
    newEvent['instrument'] = instrument
    newEvent['timeS'] = timestamp
    playEvents.append(newEvent)
    

def createEvents(timeListH,timeListK,timeListS):
    for ts in timeListH:
        createEvent('hat',hihat, ts)
        #print('HIHAT',ts)
    for ts in timeListK:
        createEvent('kick',kick, ts)
        #print('kick',ts)
    for ts in timeListS:
        createEvent('snare',snare, ts)
       



def tStamps(timeList):    #converts timeList into time stamps
    global timeSeq
    list=[]

    i=0
    list.append(0.0)
    for ts in timeList:
        list.append(i)#here 
        i = i + ts
  
    return(list)



def eventPlay(sortedPlayEvents,i):
    sortedPlayEvents[i]['instrument'].play()
    print(sortedPlayEvents[i]['name'],sortedPlayEvents[i]['timeS'])
    

def Playing(timeStamp):#handles the note palying part  and handles de deg eventPlay
    print(timeStamp)  
    current = time.time()
    i = 0
    while True :
        #choose a int between 0 and 2 to choose random samples
        #samplerand=random.randint(0,2)
        
        now = time.time() - current
    #checks if enough time has passed to play next sample
        if(now >= sortedPlayEvents[i]['timeS']):
            eventPlay(sortedPlayEvents,i)
            #removes sample from list when timeStamp=true
            if timeStamp:
                timeSeq= timeStamp.pop(0)
            else:
                break
            time.sleep(0.001)        
#samples to choose from


    #lets the sample play out
    time.sleep(1)


userInput(correctInput,correctInputYN)
noteGen(bpmInput)

kickList= tStamps(timeListK)
snareList=tStamps(timeListS)
hatList=tStamps(timeListH)

createEvents(kickList,snareList,hatList)


sortedPlayEvents = sorted(playEvents, key=itemgetter('timeS'))

Playing(sortedPlayEvents)