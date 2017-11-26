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
    T *buffer;
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
    void push(T const &val);
    T pop();
    ~SynchronizedQueue();
};

#endif /* SyncronizedQueue_hpp */
