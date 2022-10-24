
from fileinput import filename
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
noteValuesList=[]
noteListTimes=[]
mf = MIDIFile(1)

hat = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD2/audio_files/hihat.wav")
kick = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD2/audio_files/kick.wav")
snare = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD2/audio_files/snare.wav")
chord = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD2/audio_files/chord.wav")
jit = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD2/audio_files/jit.wav")
perc= sa.WaveObject.from_wave_file('/Users/rubenbos/Documents/HKU/jaar_2/CSD2/audio_files/perc.wav')

instruments = {
    "hat": hat,
    "snare": snare,
    "kick": kick,
    "chord":chord,
    "jit":jit,
    "perc":perc
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
            result = float(result)
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


def markovSampleGen(notes):#here the note generation is generated using a markov chain
    #choose the starting sample!
    noteNow = "kick"
    #allways start on a kick!
    sampleList = [noteNow]
    #possible transition of samples that come after the sample 
    transitionName = [["KK","KS","KH","KC"],["SS","SK","SH","SP"],["HH","HS","HK","HJ",]]
    probSample =     [[0.15,0.4,0.25,0.2],   [0.2,0.3,0.3,0.2],      [0.2,0.6,0.1,0.1]] #chances of the transition happening    
    
    i = 0
    # To calculate the probability of the sampleList
    prob = 1

    while i != notes:
        if noteNow == "kick":
            change = np.random.choice(transitionName[0],replace=True,p=probSample[0])
            if change == "KK":
                prob = prob * 0.15
                sampleList.append("kick")
                
            elif change == "KS":
                prob = prob * 0.6
                noteNow = "snare"
                sampleList.append("snare")
            elif change == "KH":
                prob = prob * 0.15
                noteNow = "hat"
                sampleList.append("hat")
            else :
                prob = prob * 0.1
                noteNow = "chord"  
                sampleList.append("chord") 
                
        elif noteNow == "snare":
            change = np.random.choice(transitionName[1],replace=True,p=probSample[1])
            if change == "SS":
                prob = prob * 0.2
                sampleList.append("snare")
                
           
            elif change == "SK":
                prob = prob * 0.3
                noteNow = "kick"
                sampleList.append("kick")
                
            elif change == "SH":
                prob = prob * 0.4
                noteNow = "hat"
                sampleList.append("hat")
            else:
                prob = prob* 0.1
                noteNow = "perc"
                sampleList.append("perc")   
        
        elif noteNow == "hat":
            change = np.random.choice(transitionName[2],replace=True,p=probSample[2])
            if change == "HH":
                prob = prob * 0.2
                sampleList.append("hat")
                
            elif change == "HS":
                prob = prob * 0.6
                noteNow = "snare"
                sampleList.append("snare")
                
            elif change == "HK":
                prob = prob * 0.10
                noteNow = "kick"
                sampleList.append("kick")
            
            else:
                prob= prob  * 0.10
                noteNow = "jit"
                sampleList.append("jit")
                   
        elif noteNow == "chord":        
                
            noteNow = "kick"
            sampleList.append("kick")
            
        elif noteNow == "perc": 
      
            noteNow = "hat"
            sampleList.append("hat") 
            
        elif noteNow == "jit": 
            
            noteNow = "snare"
            sampleList.append("snare")       
             
        i += 1  
    print("Probability of the possible seqeunce " + str(prob))        
    return(sampleList)


def noteValueGen():#this function generates a list of notevalues 
    probValue = [0.15,0.25,0.1,0.15,0.15,0.2] #these are the probalilities a notevalue can be chosen
    noteValue = [0.25,0.3,0.4,0.5,0.75,1]#these are the possible note values
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


def createEvent(name,timestamp,noteDuration):#this function creates the events for the given samples and timestamps 
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


def eventPlay(noteListTimes,i):# this function makes the note play and also print it when played
    noteListTimes[i]['instrument'].play()
    print(noteListTimes[i]['name'],noteListTimes[i]['timeS'])
   
    
def Playing():#handles the note palying part and handles de def eventPlay
    current = time.time()
    i = 0
   
    while True :
        #choose a int between 0 and 2 to choose random samples
        #samplerand=random.randint(0,2)
        
        now = time.time() - current
        
        #checks if enough time has passed to play next sample
        if(now >= noteListTimes[i]['timeS']):
            eventPlay(noteListTimes,i)
            
            if noteListTimes:# empty's the list 
                noteListTimes.pop(0)   
        
        if(i == len(noteListTimes)):
        
            break   
        #removes sample from list when timeStamp=true
        time.sleep(0.001)  
              
#samples to choose from

    #lets the sample play out
    time.sleep(1.5)


def midiGen():#handles the midi generation if you would like to store
    # set the necessary values for MIDI util
    velocity=80
    track = 0
    channel = 9 # corresponds to channel 10 drums
    bpm = bpmInput
     

    # create the MIDIfile object, to which we can add notes
    
    # set name and tempo
    time_beginning = 0
    mf.addTrackName(track, time_beginning, "Beat Sample Track")
    mf.addTempo(track, time_beginning, bpm)

    # variables necessary for transforming events to midi output
    qnote_dur = 60 / bpmInput
    instr_midi_pitch = {
        "kick": 35,
        "snare": 38,
        "hat": 40,
        "jit": 41,
        "chord": 42,
        "perc": 43
    }


    for event in noteListTimes:
        # transform time (sec) to (qnote)
        qnote_time = event["timeS"] / qnote_dur
        instr_name = event["name"]
        mf.addNote(track, channel, instr_midi_pitch[instr_name], qnote_time,
            event['noteDur'], velocity)
    
        
def saveMidi():#saves it to a files if true
    file_name = askQuestion('string', 'Insert file name: ')
    with open(f'midifiles/{file_name + str(".mid")}','wb') as outf:
        mf.writeFile(outf)


# here the program begins
replay=False

answerYN = askQuestion('bool','HI today we are making a irregular beat using a markov chain, would you like to hear one?')

while not replay:
    if (answerYN): 
        customBpm = askQuestion('bool','OKAY GREAT!, I have A default BPM:120. Or would you like to choose a custom one ?')
        
        if (customBpm):
            bpmInput = askQuestion('int','I see, custom Bpm is much beter anyway then the boring 120.. tell me what would you like to replace it with. ',{'min': 50, 'max': 200})
            print('allright bpm:',bpmInput, 'is a great choise')
        else:
            bpmInput=120
            print('okay default bpm',bpmInput, 'is used')
            
        numberNotes = askQuestion('int','how many notes would you like in the sequence?',{'min':1,'max':128})  
        print('okay',numberNotes,'notes wil be played')  
        if(bpmInput):
        #noteEvent is generated on requested input
            while not askQuestion('bool','are you ready to play it?'):
                print('Okay ill wait...... type: [yes] if you are ready to play!')
                
            
            print('okay, ready? the sequence will play in:', end=''); pyautogui.countdown(3)
        
            sampleList = markovSampleGen(numberNotes-1)
            
            timeStamps = TimeStampGen(bpmInput)
            
            createEvents(timeStamps)
            midiGen()
            
            Playing()#plays the sequence
            
            
            if askQuestion('bool','would you like to store this rithm to a midi file?') :
                saveMidi()           
            
            
            newRithm = askQuestion('bool','would you like to generate a new rithm?')
            
            if not newRithm:
                replay= True 
                print('allright, thank you for listening to this amaazing generator!!') 
    else:           
                    
        print(':(     okay, next time maybe...bye')
        replay = True