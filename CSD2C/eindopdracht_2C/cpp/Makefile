CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -g -std=c++20
LDFLAGS= -ljack
SOURCE= circ_buffer.o delay.o flanger.o  main.o
TARGET= galgje



$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o

