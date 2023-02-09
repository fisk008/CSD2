#include "circ_buffer.h"





    CircBuffer::CircBuffer (uint size) : currentSize (size), buffer (new float[currentSize]) {

    }
    CircBuffer::~CircBuffer() {
        deleteBuffer();
    }


    void CircBuffer::input (float value) {

    }
    

    float CircBuffer::output() {

    }

    void CircBuffer::setDistance (uint distance) {

    }

    void CircBuffer::incrementHeads() {

    }



    inline void CircBuffer::wrapHeader (uint& head) {

    }


    inline void CircBuffer::incrementWrite() {

    }


    inline void CircBuffer::incrementRead() {

    }


    void CircBuffer::deleteBuffer() {

    }