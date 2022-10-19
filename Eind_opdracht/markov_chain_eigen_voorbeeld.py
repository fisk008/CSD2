

import numpy as np
import random as rm




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
                prob = prob * 0.33
                sampleList.append("kick")
                
            elif change == "KS":
                prob = prob * 0.33
                noteNow = "snare"
                sampleList.append("snare")
                
            else:
                prob = prob * 0.33
                noteNow = "hat"
                sampleList.append("hat")
                
        elif noteNow == "snare":
            change = np.random.choice(transitionName[1],replace=True,p=probSample[1])
            if change == "SS":
                prob = prob * 0.5
                sampleList.append("snare")
                
            # commented this out bc i dont want kick after snare
            elif change == "SK":
                prob = prob * 0.2
                noteNow = "kick"
                sampleList.append("kick")
                
            else:
                prob = prob * 0.5
                noteNow = "hat"
                sampleList.append("hat")
                
        
        elif noteNow == "hat":
            change = np.random.choice(transitionName[2],replace=True,p=probSample[2])
            if change == "HH":
                prob = prob * 0.33
                sampleList.append("Hat")
                
            elif change == "HS":
                prob = prob * 0.33
                noteNow = "snare"
                sampleList.append("snare")
                
            else:
                prob = prob * 0.33
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


noteListTimes=[]

def TimeStampGen(bpmInput):#this function combines the process of all the functions 
    noteValuesList=[]
    
    for samples in sampleList:#here the List of values is created depending on the number of notes 
        noteValue = noteValueGen()
        noteValuesList.append(noteValue)#its appends it to one list of noteValues
    noteList =[]
    for dur in noteValuesList:#here the noteValueList is adjusted with the function depeding on bpnm
        noteList.append(bpmAdjusted(bpmInput) * dur)#appends it to a list for the next function

    for values in noteList:#here the adjusted notevalues are converted to timestamps 
        tStampsArr =tStamps(noteList)
    return(tStampsArr) #the timestamps are returned to the function 

def createEvent(name,instrument, timestamp):#this function creates the events 
    newEvent = {}
    newEvent['name'] = name
    newEvent['instrument'] = instrument
    newEvent['timeS'] = timestamp
    noteListTimes.append(newEvent)

def createEvents(tStampsArr):#this function creates the event per timestamp and sample and makes one big event out of it
    i=0
    for samples in sampleList:
        createEvent(samples,samples,tStampsArr[i])
        i += 1





sampleList = markovSampleGen(8)
   
timeStamps = TimeStampGen(140)

createEvents(timeStamps)
print(noteListTimes)

noteListTimes[1]['instrument'].play()

    
