
from operator import itemgetter
import simpleaudio as sa
import time
import random
import pyautogui
import numpy as np

correctInput = False
correctInputYN= False
correctInputV= False
playEvents = []


hihat = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/hihat.wav")
snare = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/snare.wav")
kick = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/kick.wav")


#altered code based on jochem practicum lesson we made toghether 
def askQuestion(type: str, questionString: str, options: dict = {}):
   
    # Print the question
    print(questionString)

    # Ask the question
    result = input('> ')

    # Check if the requested type is a string
    if type == 'string':
        isError = False

        # Check if the answer is empty
        if 'allowEmpty' in options and options['allowEmpty'] == False and result == "":
            print('Value cannot be empty.')
            isError = True
        # Check if the answer is too long
        elif 'max' in options and len(result) > options['max']:
            print('Value cannot be longer than ' + str(options['max']) + ' characters.')
            isError = True

        # If there is an error, ask the question again
        if isError:
            print('Please enter a valid option.')
            return askQuestion(type, questionString, options)

    # Check if the requested type is a boolean
    elif type == 'bool':
        isError = False

        # Check if the answer is an allowed value
        if (result not in [
            'y', 'Y','YES', 'yes', 'ja',  'j', 'true',  'True',  'TRUE',
            'def','default'
            'n', 'N','NO', 'no',  'nee', 'n', 'false', 'False', 'FALSE'
        ]):
            isError = True

        # If there is an error, ask the question again
        if isError:
            print('Please enter a valid option.')
            return askQuestion(type, questionString, options)

        # Check if the answer is yes
        result = result in ['y', 'Y', 'yes', 'ja', 'j', 'true', 'True', 'TRUE','custom','cus']

    # Check if the requested type is an integer
    elif type == 'int':
        # Try to parse the answer to an integer. If it fails, ask the question again
        try:
            result = int(result)
            # Check if the answer is in bounds, throw an error if it is not
            if ('min' in options and result < options['min']):
                print('Value cannot be smaller than ' +
                      str(options['min']) + '.')
                raise ValueError
            if ('max' in options and result > options['max']):
                print('Value cannot be larger than ' +
                      str(options['max']) + '.')
                raise ValueError
        except:
            print('Please enter a valid number.')
            return askQuestion(type, questionString, options)

    # Return the result
    return result


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
    
    for ts in timeList:
        list.append(i)#here 
        i = i + ts
  
    return(list)


def eventPlay(sortedPlayEvents,i):
    sortedPlayEvents[i]['instrument'].play()
    print(sortedPlayEvents[i]['name'],sortedPlayEvents[i]['timeS'])
    

def Playing(timeStamp):#handles the note palying part  and handles de deg eventPlay
    current = time.time()
    i = 0
   
    while True :
        #choose a int between 0 and 2 to choose random samples
        #samplerand=random.randint(0,2)
        
        now = time.time() - current
        
        #checks if enough time has passed to play next sample
        if(now >= sortedPlayEvents[i]['timeS']):
            eventPlay(sortedPlayEvents,i)
            
            if sortedPlayEvents:
                sortedPlayEvents.pop(0)   

        if(i == len(sortedPlayEvents)):
        
            break   
        #removes sample from list when timeStamp=true
        time.sleep(0.001)  
              
#samples to choose from

    #lets the sample play out
    time.sleep(1)


answerYN = askQuestion('bool','HI today we are making a irregular beat, would you like to hear one?')

if (answerYN): 
    customBpm = askQuestion('bool','OKAY GREAT!, I have A default BPM:120. Or would you like to choose a custom one ?')
    
    if (customBpm):
        bpmInput = askQuestion('int','I see, custom Bpm is much beter anyway then the boring 120.. tell me what would you like to replace it with. ',{'min': 50, 'max': 200})
        print('allright bpm:',bpmInput, 'is a great choise')
    else:
        bpmInput=120
        print('okay default bpm',bpmInput, 'is used')
        bpmInput=120
        
    if(bpmInput):
        askReady = askQuestion('bool','are you ready to play it?') 
    #noteEvent is generated on requested input
        if(askReady):
            print('okay, ready? the sequence will play in:')
            print('Starting in ', end=''); pyautogui.countdown(5)
            
            noteGen(bpmInput)

            #function for all the timestamps per sample
            kickList= tStamps(timeListK)
            snareList=tStamps(timeListS)
            hatList=tStamps(timeListH)

            createEvents(kickList,snareList,hatList)

            sortedPlayEvents = sorted(playEvents, key=itemgetter('timeS'))

            Playing(sortedPlayEvents)
        elif(not askReady):
            print('Okay ill wait...... type: [yes] if you are ready to play!')
            notReady = askQuestion('bool','ready?')
            if (notReady):
                noteGen(bpmInput)

                #function for all the timestamps per sample
                kickList= tStamps(timeListK)
                snareList=tStamps(timeListS)
                hatList=tStamps(timeListH)

                createEvents(kickList,snareList,hatList)

                sortedPlayEvents = sorted(playEvents, key=itemgetter('timeS'))

                Playing(sortedPlayEvents)
else:           
                
    print(':(     okay, next time maybe...bye')