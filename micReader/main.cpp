//
//  main.cpp
//  micReader
//
//  Created by Pavel Tyletsky on 5/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "micReader.hpp"
#include "constants.h"
#include <math.h>
#include "wavWriter.hpp"
#include "detector.hpp"
#include "SyncronizedQueue.hpp"
#include <vector>

int main(int argc, const char * argv[]) {
    std::auto_ptr<MicReader> mr(new MicReader());
    std::auto_ptr<wavWriter> ww(new wavWriter());
//    std::auto_ptr<SynchronizedQueue<frame_t*>>
//        que(new SynchronizedQueue<frame_t*>(BUFSIZE));
    SynchronizedQueue<frame_t*> queue(BUFSIZE);
    
//    mr->StartRecording(&queue);
    
//    ww->write("/Users/pashatyl/docs/test.wav", buffer);
    
//    Detector<SynchronizedQueue<frame_t*>> d(queue, NUM_SAMPLES);
//    d.detect();
    return 0;
}





























