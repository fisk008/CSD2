#include <iostream>


#include "circ_buffer.h"

int main(){
    CircBuffer buf(8);
    int i =0;
    buf.setDistance(2);
    while(i<8){
    buf.input(i);

    buf.output();
    buf.incrementHeads();
    }
}