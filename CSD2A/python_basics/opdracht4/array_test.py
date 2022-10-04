import random 
import simpleaudio as sa

arr =[[0]* 4 for i in range(4)]
print(arr)


hihat = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/hihat.wav")
snare = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/snare.wav")
kick = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/HKU/jaar_2/CSD_22-23/blok2a/assets/kick.wav")

# snare_event = {
#    {' instrument':snare,}
#    {' instrument':kick,}
#    ' instrument3':hihat
# }
# kick_event = {
# }
# hat_event = {
# }

sampleEvent = random.choice(list(snare_event))
print ( sampleEvent)
def eventPlay(eventSum):
    # print(sampleEvent['instrument'])
    sampleRand=random.randint(0,2)
    eventSum[sampleRand].play()
    return(sampleEvent)
