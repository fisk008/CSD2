#my version of the assignment 

bpm = 120

print("default bpm;",bpm,"would you like too keep it? type: yes or no ")
bpmInput=input(int())
if(bpmInput == "yes"):
    bpmInput=input(int())
    bpmInput=bpm


if(bpmInput == "no"):
    print("okay default bpm",bpm, "is used ")

