CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++20
LDFLAGS= -ljack
SOURCE= main.o callback.o audioToFile.o oscillator.o sine.o saw.o square.o 
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
