
from operator import itemgetter
from midiutil import MIDIFile
import simpleaudio as sa
import time
import pyautogui
import numpy as np

correctInput = False
correctInputYN= False
correctInputV= False
playEvents = []


hat = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/hihat.wav")
snare = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/snare.wav")
kick = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/kick.wav")

instruments = {
    "hat": hat,
    "snare": snare,
    "kick": kick
}

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

def markovSampleGen(notes):
    #choose the starting sample!
    noteNow = "kick"
    #allways start on a kick!
    sampleList = [noteNow]
    
    transitionName = [["KK","KS","KH"],["SS","SK","SH"],["HH","HS","HK"]]
    probSample = [[0.2,0.6,0.2],[0.1,0.6,0.3],[0.2,0.7,0.1]]    
    
    i = 0
    # To calculate the probability of the sampleList
    prob = 1

    while i != notes:
        if noteNow == "kick":
            change = np.random.choice(transitionName[0],replace=True,p=probSample[0])
            if change == "KK":
                prob = prob * 0.2
                sampleList.append("kick")
                
            elif change == "KS":
                prob = prob * 0.6
                noteNow = "snare"
                sampleList.append("snare")
                
            else:
                prob = prob * 0.2
                noteNow = "hat"
                sampleList.append("hat")
                
        elif noteNow == "snare":
            change = np.random.choice(transitionName[1],replace=True,p=probSample[1])
            if change == "SS":
                prob = prob * 0.1
                sampleList.append("snare")
                
            # commented this out bc i dont want kick after snare
            elif change == "SK":
                prob = prob * 0.6
                noteNow = "kick"
                sampleList.append("kick")
                
            else:
                prob = prob * 0.3
                noteNow = "hat"
                sampleList.append("hat")
                
        
        elif noteNow == "hat":
            change = np.random.choice(transitionName[2],replace=True,p=probSample[2])
            if change == "HH":
                prob = prob * 0.2
                sampleList.append("hat")
                
            elif change == "HS":
                prob = prob * 0.7
                noteNow = "snare"
                sampleList.append("snare")
                
            else:
                prob = prob * 0.1
                noteNow = "kick"
                sampleList.append("kick")
                
        i += 1  
    return(sampleList)


def noteValueGen():#this function generates a list of notevalues 
    probValue = [0.15,0.3,0.55] #these are the probalilities a notevalue can be chosen
    noteValue = [0.25,0.5,1]#these are the possible note values
    noteVList = np.random.choice(noteValue,replace=True,p=probValue)
    return(noteVList)#returns the list of notevalues


def bpmAdjusted(bpmInput):#this function adjusts the bpm to match the note value 
    bpmAdjust = 60/bpmInput
    return(bpmAdjust)


def tStamps(noteValues):    #converts timeList into time stamps to be played
    list=[]
    i=0
    for ts in noteValues: # it adds up the last note to the next one to create a list 
        list.append(i)
        i = i + ts
    return(list)



noteValuesList=[]

def TimeStampGen(bpmInput):#this function combines the process of all the functions and generates from the samplelist a timestamp list 
    
    for samples in sampleList:#here the List of values is created depending on the number of notes 
        noteValue = noteValueGen()
        noteValuesList.append(noteValue)#its appends it to one list of noteValues
    
    noteList =[]
    for dur in noteValuesList:#here the noteValueList is adjusted with the function depeding on bpnm
        noteList.append(bpmAdjusted(bpmInput) * dur)#appends it to a list for the next function

    for values in noteList: #here the adjusted notevalues are converted to timestamps 
        tStampsArr =tStamps(noteList)
    return(tStampsArr) #the timestamps are returned to the function 


noteListTimes=[]
def createEvent(name,timestamp,noteDuration):#this function creates the events for the given samples and timestamps 
    global intruments
    newEvent = {}
    newEvent['name'] = name    
    newEvent['instrument'] = instruments[name] 
    newEvent['timeS'] = timestamp  
    newEvent['noteDur'] = noteDuration
    noteListTimes.append(newEvent)




def createEvents(tStampsArr):#this function creates the event per timestamp and sample and makes one big event out of it
    i=0
    for samples in sampleList:
        createEvent(samples,tStampsArr[i],noteValuesList[i])
        i += 1

def eventPlay(noteListTimes,i):
    noteListTimes[i]['instrument'].play()
    print(noteListTimes[i]['name'],noteListTimes[i]['timeS'])
    

def Playing():#handles the note palying part  and handles de deg eventPlay
    current = time.time()
    i = 0
   
    while True :
        #choose a int between 0 and 2 to choose random samples
        #samplerand=random.randint(0,2)
        
        now = time.time() - current
        
        #checks if enough time has passed to play next sample
        if(now >= noteListTimes[i]['timeS']):
            eventPlay(noteListTimes,i)
            
            if noteListTimes:
                noteListTimes.pop(0)   

        if(i == len(noteListTimes)):
        
            break   
        #removes sample from list when timeStamp=true
        time.sleep(0.001)  
              
#samples to choose from

    #lets the sample play out
    time.sleep(1)


def midiGen():
    # set the necessary values for MIDI util
    velocity=80
    track = 0
    channel = 9 # corresponds to channel 10 drums
    bpm = bpmInput


    # create the MIDIfile object, to which we can add notes
    mf = MIDIFile(1)
    # set name and tempo
    time_beginning = 0
    mf.addTrackName(track, time_beginning, "Beat Sample Track")
    mf.addTempo(track, time_beginning, bpm)

    # variables necessary for transforming events to midi output
    qnote_dur = 60 / bpmInput
    instr_midi_pitch = {
        "kick": 35,
        "snare": 38,
        "hat": 40
    }


    for event in noteListTimes:
        # transform time (sec) to (qnote)
        qnote_time = event["times"] / qnote_dur
        instr_name = event["instrument"]
        mf.addNote(track, channel, instr_midi_pitch[instr_name], qnote_time,
            event['noteDur'], velocity)

    with open("events_lists.midi",'wb') as outf:
        mf.writeFile(outf)

answerYN = askQuestion('bool','HI today we are making a irregular beat, would you like to hear one?')

if (answerYN): 
    customBpm = askQuestion('bool','OKAY GREAT!, I have A default BPM:120. Or would you like to choose a custom one ?')
    
    if (customBpm):
        bpmInput = askQuestion('int','I see, custom Bpm is much beter anyway then the boring 120.. tell me what would you like to replace it with. ',{'min': 50, 'max': 200})
        print('allright bpm:',bpmInput, 'is a great choise')
    else:
        bpmInput=120
        print('okay default bpm',bpmInput, 'is used')
        
        
    if(bpmInput):
    #noteEvent is generated on requested input
        while not askQuestion('bool','are you ready to play it?'):
            print('Okay ill wait...... type: [yes] if you are ready to play!')
            # notReady = askQuestion('bool','ready?')
        
        print('okay, ready? the sequence will play in:', end=''); pyautogui.countdown(5)
        
        
        sampleList = markovSampleGen(15)
        
        timeStamps = TimeStampGen(bpmInput)
        
        createEvents(timeStamps)
        print(noteListTimes)
        Playing()
        
        storeToMidi=askQuestion('bool','would you like to store this rithm to a midi file?')
        if (storeToMidi):
             midiGen()  
             
        else:
               print('hoi')
        # elif(not askReady):
        #     if (notReady):
            
        #         sampleList = markovSampleGen(15)
    
        #         timeStamps = TimeStampGen(bpmInput)

        #         createEvents(timeStamps)

        #         Playing()

                
else:           
                
    print(':(     okay, next time maybe...bye')