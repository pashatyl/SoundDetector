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
    std::auto_ptr<T> queue;
    size_t bufSize;
    frame_t *buffer;
    
public:
    Detector(std::auto_ptr<T>&, size_t);
    void detect();
    ~Detector();
};

#endif /* detector_hpp */
