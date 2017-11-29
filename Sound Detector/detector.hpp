//
//  detector.hpp
//  micReader
//
//  Created by Pavel Tyletsky on 17/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#ifndef detector_hpp
#define detector_hpp

#include <stdio.h>
#include "constants.h"

template <class T>
class Detector{
private:
    std::shared_ptr<T> queue;
    size_t bufSize;
    frame_t *buffer;
    
public:
    Detector(std::shared_ptr<T>&, size_t);
    void detect();
    ~Detector();
};

template <class T>
Detector<T>::Detector(std::shared_ptr<T> &queue, size_t size){
    this->queue = queue;
    this->bufSize = size;
    buffer = new frame_t[bufSize];
}

template <class T>
void Detector<T>::detect(){
    frame_t max = maxof(frame_t) * BORDER;
    while(true){
        buffer = queue->pop();
        for(int i = 0; i < bufSize; ++i){
            if (buffer[i] > max){
                printf("Bordered! ");
                std::cout << buffer[i] << " " << max << std::endl;
                break;
            }
        }
    }
}

template <class T>
Detector<T>::~Detector(){
    delete[] buffer;
}

#endif /* detector_hpp */
