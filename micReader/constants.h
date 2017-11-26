//
//  constants.h
//  micReader
//
//  Created by Pavel Tyletsky on 10/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#ifndef constants_h
#define constants_h
#include <machine/types.h>
#include <memory>

#define frame_t int32_t        // must be the same types?
#define PA_SAMPLE_TYPE paInt32 //
#define FRAMES_PER_BUFFER 100
#define SAMPLE_RATE (48000)
#define NUM_CHANNELS 1
#define BORDER 0.9
#define BUFSIZE 100000

#define NUM_SAMPLES 480000 //should be FRAMES_PER_BUFFER * n

#endif /* constants_h */
