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

// Структура, описывающая заголовок WAV файла.

int main(int argc, const char * argv[]) {
    std::auto_ptr<MicReader> mr(new MicReader());
    std::auto_ptr<wavWriter> ww(new wavWriter());
    frame_t *buffer = mr->GetOneSampleBlock();
    
    ww->write("/Users/pashatyl/docs/test.wav", buffer);
    
    Detector *d = new Detector(buffer, NUM_SAMPLES);
    d->detect();
    return 0;
}





























