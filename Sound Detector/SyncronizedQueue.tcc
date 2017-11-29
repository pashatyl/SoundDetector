//
//  SyncronizedQueue.cpp
//  micReader
//
//  Created by Pavel Tyletsky on 25/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

template <class T>
void SynchronizedQueue<T>::push(T const &val)
{
    lock l(mutex_); // prevents multiple pushes corrupting queue_
    bool wake = empty(); // we may need to wake consumer
    std::memcpy(val, buffer[correct(head++)], BUFSIZE);
    if (wake) condvar_.notify_one();
}

template <class T>
T SynchronizedQueue<T>::pop()
{
    ulock u(mutex_);
    while (empty())
        condvar_.wait(u);
    return buffer[correct(tail++)];
}

template <class T>
SynchronizedQueue<T>::SynchronizedQueue(size_t size){
    buffer = new T[size];
    this->size = size;
}

template <class T>
SynchronizedQueue<T>::~SynchronizedQueue(){
    mutex_.~mutex();
    condvar_.~condition_variable();
    delete[] buffer;
}
