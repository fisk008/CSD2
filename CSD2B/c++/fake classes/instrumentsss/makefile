CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE=main.o instrumentss.o 
TARGET=synthesizer.exc

$(TARGET): $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f $(TARGET) *.o
