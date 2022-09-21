#my version of the assignment 

bpm = 120
bpmInput= input('hi...default bpm:120 would you like too keep it? type: yes or no \n')

if(bpmInput == "no"):
    print('what bpm would you like?:')
    customBpm = int(input())
    bpm = customBpm
    print('okay bpm is now:',bpm)

if(bpmInput == "yes"):
    print("okay default bpm:",bpm, "is used ")

