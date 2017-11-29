//
//  SyncronizedQueue.hpp
//  micReader
//
//  Created by Pavel Tyletsky on 25/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#ifndef SyncronizedQueue_hpp
#define SyncronizedQueue_hpp

#include <stdio.h>
#include <queue>
#include <mutex>
#include "constants.h"

template <class T>
class SynchronizedQueue
{
    std::mutex mutex_;
    std::condition_variable condvar_;
    unsigned int head;
    unsigned int tail;
    T **buffer;
    size_t size;
    
    typedef std::lock_guard<std::mutex> lock;
    typedef std::unique_lock<std::mutex> ulock;
    
    unsigned int correct(const unsigned int n) const {
        return n % size;
    }
    
    bool empty() const {
        return head == tail;
    }
    
public:
    SynchronizedQueue(size_t size);
    void push(T const *val);
    T* pop();
    ~SynchronizedQueue();
};

template <class T>
void SynchronizedQueue<T>::push(T const *val)
{
    lock l(mutex_); // prevents multiple pushes corrupting queue_
    bool wake = empty(); // we may need to wake consumer
    std::memcpy(buffer[correct(head++)], val, FRAMES_PER_BUFFER);
    if (wake) condvar_.notify_one();
}

template <class T>
T* SynchronizedQueue<T>::pop()
{
    ulock u(mutex_);
    while (empty())
        condvar_.wait(u);
    return buffer[correct(tail++)];
}

template <class T>
SynchronizedQueue<T>::SynchronizedQueue(size_t size){
    head = 0;
    tail = 0;
    this->size = size;
    buffer = new T*[size];
    for(int i = 0; i < size; i++){
        buffer[i] = new T[FRAMES_PER_BUFFER];
    }
}

template <class T>
SynchronizedQueue<T>::~SynchronizedQueue(){
    mutex_.~mutex();
    condvar_.~condition_variable();
    delete[] buffer;
}

#endif /* SyncronizedQueue_hpp */
