//
//  micReader.hpp
//  micReader
//
//  Created by Pavel Tyletsky on 10/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#ifndef micReader_hpp
#define micReader_hpp

#include <iostream>
#include "portaudio.h"

#define SAMPLE_RATE (44100)
#define NUM_CHANNELS 1
#define PA_SAMPLE_TYPE paInt16
#define FRAMES_PER_BUFFER 1000

class MicReader {
private:
    PaError err;
    __int16_t *sampleBlock;
    PaStreamParameters inputParameters;
    PaStreamParameters outputParameters;
    PaStream *stream;
public:
    MicReader();
    void StartRecording();
    ~MicReader();
};

#endif /* micReader_hpp */
