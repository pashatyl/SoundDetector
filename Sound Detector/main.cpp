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
#include <thread>

int main(int argc, const char * argv[]) {
    std::shared_ptr<MicReader> mr(new MicReader());
    std::shared_ptr<wavWriter> ww(new wavWriter());
    std::shared_ptr<SynchronizedQueue<frame_t>>
        que(new SynchronizedQueue<frame_t>(BUFSIZE));
//    SynchronizedQueue<frame_t*> que(BUFSIZE);
//
    std::thread tr( [mr, que] { mr->StartRecording(que); } );
    tr.detach();
    std::this_thread::sleep_for(std::chrono::seconds(10));

//
////    ww->write("/Users/pashatyl/docs/test.wav", buffer);
//    
    Detector<SynchronizedQueue<frame_t>> d(que, NUM_SAMPLES);
    d.detect();
    return 0;
}





























