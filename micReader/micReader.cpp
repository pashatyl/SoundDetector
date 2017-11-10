//
//  micReader.cpp
//  micReader
//
//  Created by Pavel Tyletsky on 10/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#include "micReader.hpp"

void HandleError(PaError err){
    if( err != paNoError ){
        std::cout << Pa_GetErrorText(err); //TODO: Log errors
    }
}

MicReader::MicReader(){
    sampleBlock = new frame_t(FRAMES_PER_BUFFER);
    
    err = Pa_Initialize();
    HandleError(err);
    
    /* -- setup input and output -- */
    inputParameters.device = Pa_GetDefaultInputDevice();    inputParameters.channelCount = NUM_CHANNELS;
    inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    inputParameters.suggestedLatency =
    Pa_GetDeviceInfo( inputParameters.device )->defaultHighInputLatency ;
    inputParameters.hostApiSpecificStreamInfo = NULL;
    outputParameters.device = Pa_GetDefaultOutputDevice();    outputParameters.channelCount = NUM_CHANNELS;
    outputParameters.sampleFormat = PA_SAMPLE_TYPE;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultHighOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;
    
    err = Pa_OpenStream(
                        &stream,
                        &inputParameters,
                        &outputParameters,
                        SAMPLE_RATE,
                        FRAMES_PER_BUFFER,
                        paClipOff,      /* we won't output out of range samples so don't bother clipping them */
                        NULL, /* no callback, use blocking API */
                        NULL ); /* no callback, so no callback userData */
    HandleError(err);
    err = Pa_StartStream( stream );
    HandleError(err);
}

void MicReader::StartRecording(){
    for(int i=0; i<(10*SAMPLE_RATE)/FRAMES_PER_BUFFER; ++i )
    {
        err = Pa_WriteStream( stream, sampleBlock, FRAMES_PER_BUFFER );
        HandleError(err);
//        for(int i = 0; i < FRAMES_PER_BUFFER; i+=2){
//            std::cout << sampleBlock[i];
//        }
//        std::cout << std::endl;
        err = Pa_ReadStream( stream, sampleBlock, FRAMES_PER_BUFFER );
        HandleError(err);
    }
}

frame_t* MicReader::GetOneSampleBlock(){
    frame_t *buffer = new frame_t(FRAMES_PER_BUFFER);
    Pa_WriteStream(stream, buffer, FRAMES_PER_BUFFER);
//    for(int i = 0; i < FRAMES_PER_BUFFER; ++i){
//        std::cout << buffer[i];
//    }
//    std::cout << std::endl;
    return buffer;
}

MicReader::~MicReader(){
    delete[] sampleBlock;
    err = Pa_StopStream( stream );
    HandleError(err);
    err = Pa_CloseStream( stream );
    HandleError(err);
}

