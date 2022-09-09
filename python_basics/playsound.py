import simpleaudio as sa

wave_obj = sa.WaveObject.from_wave_file("/Users/rubenbos/Documents/CSD2/audio_files/test1.wav")
play_obj = wave_obj.play()
play_obj.wait_done()