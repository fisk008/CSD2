#include "circ_buffer.h"

CircBuffer::CircBuffer(){

}

CircBuffer::CircBuffer (uint size) : buffer (new float[size]) , currentSize (size) {
    std::cout<<"buffersize"<<currentSize<<std::endl;
}
CircBuffer::~CircBuffer() {
    deleteBuffer();
}


void CircBuffer::input (float value) {
    buffer[writeHead]= value;
}


float CircBuffer::output() {
    return buffer[readHead];
}

void CircBuffer::setBufferSize(float size){
    currentSize = size;
}

void CircBuffer::setDistance (uint distance) {
    this->distance=distance;
    readHead = (writeHead - distance + currentSize) % currentSize;
  
}


void CircBuffer::incrementHeads() {
    incrementWrite();
    incrementRead();
    
    wrapHeader(writeHead);
    wrapHeader(readHead);

    // std::cout<<"incrementing heads"<<std::endl;
}



inline void CircBuffer::wrapHeader (uint& head) {

    if(head >= currentSize){
        std::cout<<"wrapped:"<<head<<std::endl;
        head -= currentSize;
    }


}


inline void CircBuffer::incrementWrite() {
    writeHead++;
    // std::cout<<"writehead pos:"<<writeHead<<std::endl;
}


inline void CircBuffer::incrementRead() {
    readHead++;
    // std::cout<<"readHead pos:"<<readHead<<std::endl;
}


void CircBuffer::deleteBuffer() {
    delete[] buffer;
}