CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++17
LDFLAGS= -ljack
SOURCE=oscillator.o sine.o main.o 
TARGET=synthebak

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
