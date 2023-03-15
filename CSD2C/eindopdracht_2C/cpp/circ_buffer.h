#include <iostream>
#pragma once

class CircBuffer {
    using uint = unsigned int;

public:
    CircBuffer();
    CircBuffer (uint size);
    ~CircBuffer();
    void setBufferSize(float size);
    void input (float value);
    float output();
    //distance between the write and readhead
    void setDistance (uint distance);
    //increments the write and readhead
    void incrementHeads();

private:
    //makes the buffer round and circular
    inline void wrapHeader (uint& head);
    //makes that the writehead moves position
    inline void incrementWrite();
    //makes the readhead moves position
    inline void incrementRead();
    //deletes the buffer at the end of the program
    void deleteBuffer();
    

    float* buffer;
    uint currentSize { 0 };
    uint writeHead { 0 }, readHead { 0 };
    int distance = {0};
};