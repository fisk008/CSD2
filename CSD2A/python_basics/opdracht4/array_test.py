import random 
import simpleaudio as sa
noteV=[0.25,0.5,1]
rithms=[]

arr =[random.choice(noteV) for i in range(16)]
arr1 =[random.choice(noteV) for i in range(16)]
arr2=[random.choice(noteV) for i in range(16)]

print(arr)
print(arr1)
print(arr2)




hihat = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/hihat.wav")
snare = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/snare.wav")
kick = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/kick.wav")


playEvents = []

def createEvent(instrument, timestamp):
    newEvent = {}
    newEvent['instrument'] = instrument
    newEvent['timeS'] = timestamp
    playEvents.append(newEvent)

for ts in arr:
    createEvent(hihat, ts)
for ts in arr2:
    createEvent(kick, ts)

# print(playEvents)



exit()
# playEvents = [
# {'name': 'snare','instrument':snare,'timeS':timestampS},
# {'name': 'kick','instrument':kick,'timeS':timestampK} ,
# {'name': 'hihat','instrument':hihat,'timeS':timestampH}]




def handleEvent(event):
    print(event['timeS'],event['name'])
    event['instrument'].play()
    return(event)


handleEvent(playEvents[0])
handleEvent(playEvents[1])
handleEvent(playEvents[2])