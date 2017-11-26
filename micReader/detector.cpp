//
//  detector.cpp
//  micReader
//
//  Created by Pavel Tyletsky on 17/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#include "detector.hpp"

template <class T>
Detector<T>::Detector(std::auto_ptr<T> &queue, size_t size){
    this->queue = queue;
    this->bufSize = size;
    buffer = new frame_t[bufSize];
}

template <class T>
void Detector<T>::detect(){
    while(true){
        buffer = queue->pop();
        for(int i = 0; i < bufSize; ++i){
            if (buffer[i] > sizeof(frame_t) * 8 * BORDER){
                printf("Bordered!\n");
                break;
            }
        }
    }
}

template <class T>
Detector<T>::~Detector(){
    delete[] buffer;
}
