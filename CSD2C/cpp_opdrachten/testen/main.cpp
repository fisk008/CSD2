#include <iostream>


#include "circ_buffer.h"

int main(){
    std::cout<<"hoi"<<std::endl;
    //int bufferSize = 8;//buffersize initialise
    CircBuffer buf(8);

    buf.input(0.5);
    buf.output();
    buf.incrementHeads();

}