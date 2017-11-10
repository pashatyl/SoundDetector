//
//  main.cpp
//  micReader
//
//  Created by Pavel Tyletsky on 5/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#include <iostream>
#include "micReader.hpp"

int main(int argc, const char * argv[]) {
    std::auto_ptr<MicReader> mr(new MicReader());
    mr->StartRecording();
}


































