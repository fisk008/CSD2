CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -g -std=c++20
LDFLAGS= -ljack
SOURCE= circ_buffer.o main.o
TARGET= app



$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o

