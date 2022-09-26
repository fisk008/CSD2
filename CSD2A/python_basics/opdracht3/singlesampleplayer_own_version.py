#my version of the assignment 

#input of floats for the time segments in quart notes
ritm = int(input('Enter space-separated floats : ').split())


bpm = 120
bpmInput= input('hi...default bpm:120 would you like too keep it? type: yes or no \n')

if(bpmInput == "no"):
    print('what bpm would you like?:')
    customBpm = int(input())
    bpm = customBpm
    print('okay bpm is now:',bpm)

if(bpmInput == "yes"):
    print("okay default bpm:",bpm, "is used ")

bpmInputvar = 60.0 / bpm

timelist = []

for duration in ritm :
    timelist.append(duration * ritm)

print(timelist)