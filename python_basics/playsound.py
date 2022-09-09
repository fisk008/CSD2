import simpleaudio as sa
i=1
c=0

afspelen = input("hoe vaak wil je het afspelen?")
c = afspelen
#print("dat is het goede antwoord het wordt nu ",afspelen," afgespeeld!")

while i < 10 :
    
    print("het wordt nu voor de",i,"de keer afgespeeld")
    print(i)
    # wave_obj = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/CSD2/audio_files/test1.wav")
    #play_obj = wave_obj.play()
    #play_obj.wait_done()
    if (i == c):
        break
    i=i+1
    
#print("dat is het goede antwoord het wordt nu ",afspelen," afgespeeld!")
