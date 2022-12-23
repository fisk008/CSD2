CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -g -std=c++20
LDFLAGS= -ljack
SOURCE= main.o oscillator.o sine.o saw.o square.o synth.o add_synth.o melody.o synth_am.o user_input.o callback.o audioToFile.o
TARGET=synth output.csv



$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o

