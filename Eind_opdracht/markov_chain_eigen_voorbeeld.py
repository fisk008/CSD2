
import numpy as np
import random as rm
states = ["kick","snare","hat"]

transitionName = [["KK","KS","KH"],["SS","SK","SH"],["HH","HS","HK"]]
transitionMatrix = [[0.2,0.6,0.2],[0.1,0.6,0.3],[0.2,0.7,0.1]]

def noteSeq(notes):
    # Choose the starting state
    noteNow = "kick"

    # Shall store the sequence of states taken. So, this only has the starting state for now.
    noteList = [noteNow]
    i = 0
    # To calculate the probability of the noteList
    prob = 1

    while i != notes:
        if noteNow == "kick":
            change = np.random.choice(transitionName[0],replace=True,p=transitionMatrix[0])
            if change == "KK":
                prob = prob * 0.2
                noteList.append("kick")
            elif change == "KS":
                prob = prob * 0.6
                noteNow = "snare"
                noteList.append("snare")
            else:
                prob = prob * 0.2
                noteNow = "hat"
                noteList.append("hat")
        elif noteNow == "snare":
            change = np.random.choice(transitionName[1],replace=True,p=transitionMatrix[1])
            if change == "SS":
                prob = prob * 0.5
                noteList.append("snare")
            elif change == "SK":
                prob = prob * 0.2
                noteNow = "kick"
                noteList.append("kick")
            else:
                prob = prob * 0.3
                noteNow = "hat"
                noteList.append("hat")
        
        elif noteNow == "hat":
            change = np.random.choice(transitionName[2],replace=True,p=transitionMatrix[2])
            if change == "HH":
                prob = prob * 0.1
                noteList.append("Hat")
            elif change == "HS":
                prob = prob * 0.2
                noteNow = "snare"
                noteList.append("snare")
            else:
                prob = prob * 0.7
                noteNow = "kick"
                noteList.append("kick")
        i += 1  
    print(noteList)    

noteSeq(5)        

