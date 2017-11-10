//
//  main.cpp
//  micReader
//
//  Created by Pavel Tyletsky on 5/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#include <iostream>
#include "micReader.hpp"
#include "constants.h"

int main(int argc, const char * argv[]) {
    std::auto_ptr<MicReader> mr(new MicReader());
    frame_t *buffer = mr->GetOneSampleBlock();
    for(int i = 0; i < FRAMES_PER_BUFFER; ++i){
        std::cout << buffer[i];
    }
    std::cout << std::endl;
    return 0;
}


































