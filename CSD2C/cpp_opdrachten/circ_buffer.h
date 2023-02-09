#include <iostream>
#pragma once



class CircBuffer {
    using uint = unsigned int;

public:
    CircBuffer (uint size) : currentSize (size), buffer (new float[currentSize]){};

    ~CircBuffer();
    
    void input (float value);
    float output();

    void setDistance (uint distance) {

    }

    void incrementHeads() {

    }

private:

    inline void wrapHeader (uint& head) {

    }


    inline void incrementWrite() {

    }


    inline void incrementRead() {

    }


    void deleteBuffer() {

    }

    float* buffer;
    uint currentSize { 0 };
    uint writeHead { 0 }, readHead { 0 };
};