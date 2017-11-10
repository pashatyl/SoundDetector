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
#include "constants.h"

class MicReader {
private:
    PaError err;
    frame_t *sampleBlock;
    PaStreamParameters inputParameters;
    PaStreamParameters outputParameters;
    PaStream *stream;
public:
    MicReader();
    void StartRecording();
    frame_t* GetOneSampleBlock();
    ~MicReader();
};

#endif /* micReader_hpp */
