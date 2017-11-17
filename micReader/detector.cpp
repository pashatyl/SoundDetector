//
//  detector.cpp
//  micReader
//
//  Created by Pavel Tyletsky on 17/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#include "detector.hpp"

Detector::Detector(frame_t *buffer, unsigned int size){
    this->buffer = buffer;
    this->bufSize = size;
}

void Detector::detect(){
    for(int i = 0; i < bufSize; ++i){
        if (buffer[i] > sizeof(frame_t) * 8 * BORDER){
            printf("Bordered!\n");
        }
    }
}
