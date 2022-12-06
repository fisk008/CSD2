CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++17
LDFLAGS= -ljack
SOURCE=oscillator.o writeToFile.o sine.o main.o saw.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
