

import numpy as np
import random as rm
states = ["kick","snare","hat"]

transitionName = [["KK","KS","KH"],["SS","SK","SH"],["HH","HS","HK"]]

probSample = [[0.2,0.6,0.2],[0.1,0.6,0.3],[0.2,0.7,0.1]]


def noteSeq(notes):
    # Choose the starting state
    noteNow = "kick"
    # Shall store the sequence of states taken. So, this only has the starting state for now.
    sampleList = [noteNow]
    
    
    
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

def noteValueGen():
    probValue = [0.15,0.3,0.55]
    noteValue = [0.25,0.5,1]
    noteVList = np.random.choice(noteValue,replace=True,p=probValue)
    return(noteVList)

def bpmAdjusted(bpmInput):
    bpmAdjust = 60/bpmInput
    return(bpmAdjust)

def tStamps(noteValues):    #converts timeList into time stamps
    list=[]
    i=0
    for ts in noteValues:
        list.append(i)
        i = i + ts
    return(list)


noteListTimes=[]

def createEvent(name,instrument, timestamp):
    newEvent = {}
    newEvent['name'] = name
    newEvent['instrument'] = instrument
    newEvent['timeS'] = timestamp
    noteListTimes.append(newEvent)

def createEvents():
    i=0
    for samples in sampleList:
        createEvent(samples,samples,tStampsArr[i])
        i += 1


sampleList = noteSeq(8)   
print(sampleList)


noteValuesList=[]
for samples in sampleList:
    noteValue = noteValueGen()
    noteValuesList.append(noteValue)
noteList =[]
for dur in noteValuesList:
    noteList.append(bpmAdjusted(140) * dur)

for values in noteList:
    tStampsArr =tStamps(noteList)

createEvents()

print(noteListTimes)

    
# print(noteListTimes)``