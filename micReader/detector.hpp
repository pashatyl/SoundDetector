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

class Detector{
private:
    frame_t *buffer;
    unsigned int bufSize;
    
public:
    Detector(frame_t*, unsigned int);
    void detect();
};

#endif /* detector_hpp */
