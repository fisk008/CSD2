CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -g -std=c++20
LDFLAGS= -ljack
SOURCE= main.o writeToFile.o oscillator.o sine.o saw.o square.o synth.o add_synth.o melody.o jack_module.o synth_fm.o
TARGET=example


$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o

