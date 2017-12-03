//
//  wavWriter.cpp
//  micReader
//
//  Created by Pavel Tyletsky on 16/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#include "wavWriter.hpp"

int wavWriter::write(const char* filename, frame_t *buffer, size_t samplesCount){
    FILE *file;
    file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("Failed open file");
        return 1;
    }
    
    WAVHEADER header;
    header.chunkSize = CHUNC_SIZE(samplesCount);
    header.subchunk2Size = SUBCHUNC_2_SIZE(samplesCount);
    fwrite(&header, sizeof(header), 1, file);
    fwrite(buffer, sizeof(frame_t), samplesCount, file);
    fclose(file);
    return 0;
}
