import simpleaudio as sa
i=0

username= input('hoi hoe heet je?')
print("welkom",username," ik ga nu een audio bestand afspelen")
afspelen = input("hoe vaak wil je het horen?")

int_afspelen = int(afspelen)
print("Dat is het goede antwoord het wordt nu ",int_afspelen,"keer afgespeeld!")
int_afspelen + 1

while i < int_afspelen :   
    print("Het loopje wordt nu voor de",i+1,"de keer afgespeeld")
    wave_obj = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/CSD2/audio_files/test1.wav")
    play_obj = wave_obj.play()
    play_obj.wait_done()
    i=i+1
    
print("hij is nu klaar met",int_afspelen,"keer afspelen!")
