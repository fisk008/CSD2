#include "circ_buffer.h"



CircBuffer::CircBuffer (uint size) : buffer (new float[currentSize]) , currentSize (size) {

}
CircBuffer::~CircBuffer() {
    deleteBuffer();
}


void CircBuffer::input (float value) {
    buffer[writeHead]= value;
}


float CircBuffer::output() {
    std::cout<<buffer[readHead]<<std::endl;
    return buffer[readHead];
}



void CircBuffer::setDistance (uint distance) {

}

void CircBuffer::incrementHeads() {
    incrementWrite();
    incrementRead();

    wrapHeader(writeHead);
    wrapHeader(readHead);
}



inline void CircBuffer::wrapHeader (uint& head) {
    if(head >= currentSize){
        head -= currentSize;
    }
}


inline void CircBuffer::incrementWrite() {
    writeHead++;
}


inline void CircBuffer::incrementRead() {
    readHead++;
    std::cout<<buffer[readHead]<<std::endl;
}


void CircBuffer::deleteBuffer() {
    delete[] buffer;
}