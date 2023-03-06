
// #include "circ_buffer.h"

// struct InterpolatedBuffer : CircBuffer {
  
//     float *buffer;
//     uint currentSize;
//     uint writeHead;
//     uint readHead;
//     uint distance;

//     InterpolatedCircBuffer();
//     InterpolatedCircBuffer(uint size);
//     ~CircBuffer();

//     void input(float value);
//     float output();
//     void setBufferSize(float size);
//     void setDistance(uint distance);
//     void incrementHeads();

//     inline void wrapHeader(uint &head);
//     inline void incrementWrite();
//     inline void incrementRead();
//     void deleteBuffer();

//     float* buffer;
//     uint currentSize { 0 };
//     uint writeHead { 0 }, readHead { 0 };
//     int distance = {0};
// };