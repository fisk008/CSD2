#include "circ_buffer.h"



CircBuffer::CircBuffer (uint size) : buffer (new float[currentSize]) , currentSize (size) {
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



void CircBuffer::setDistance (uint distance) {
    this->distance=distance;
    distance *= -1;
    readHead = distance + currentSize;
  
}


void CircBuffer::incrementHeads() {
    incrementWrite();
    incrementRead();
    
    wrapHeader(writeHead);
    wrapHeader(readHead);
    // std::cout<<"writehead:"<<writeHead<<std::endl<<"readHead:"<<readHead<<std::endl;
    std::cout<<"incrementing heads"<<std::endl;
}



inline void CircBuffer::wrapHeader (uint& head) {
    // this->currentSize = currentSize;
    // std::cout<<"headTime"<<head<<std::endl;
    if(head >= currentSize){
        std::cout<<"wrapped:"<<head<<std::endl;
        head -= currentSize;
    }

    // std::cout<<"wrapped"<<std::endl;
}


inline void CircBuffer::incrementWrite() {
    writeHead++;
    std::cout<<"writehead pos:"<<writeHead<<std::endl;
}


inline void CircBuffer::incrementRead() {
    readHead++;
    std::cout<<"readHead pos:"<<readHead<<std::endl;
}


void CircBuffer::deleteBuffer() {
    delete[] buffer;
}