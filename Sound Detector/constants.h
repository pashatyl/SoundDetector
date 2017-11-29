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
#define BORDER 0.3
#define BUFSIZE 100000

#define NUM_SAMPLES 480000 //should be FRAMES_PER_BUFFER * n

#define issigned(t) (((t)(-1)) < ((t) 0))

#define umaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
(0xFULL << ((sizeof(t) * 8ULL) - 4ULL)))

#define smaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
(0x7ULL << ((sizeof(t) * 8ULL) - 4ULL)))

#define maxof(t) ((unsigned long long) (issigned(t) ? smaxof(t) : umaxof(t)))

#endif /* constants_h */
