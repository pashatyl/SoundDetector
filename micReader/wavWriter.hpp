//
//  wavWriter.hpp
//  micReader
//
//  Created by Pavel Tyletsky on 16/11/17.
//  Copyright © 2017 Pavel Tyletsky. All rights reserved.
//

#ifndef wavWriter_hpp
#define wavWriter_hpp

#include <stdio.h>
#include "constants.h"

#define SUBCHUNC_2_SIZE (NUM_SAMPLES * (NUM_CHANNELS * sizeof(frame_t)))
struct WAVHEADER
{
    // WAV-формат начинается с RIFF-заголовка:
    // Содержит символы "RIFF" в ASCII кодировке
    // (0x52494646 в big-endian представлении)
    char chunkId[4] = {'R', 'I', 'F', 'F'};
    // 36 + subchunk2Size, или более точно:
    // 4 + (8 + subchunk1Size) + (8 + subchunk2Size)
    // Это оставшийся размер цепочки, начиная с этой позиции.
    // Иначе говоря, это размер файла - 8, то есть,
    // исключены поля chunkId и chunkSize.
    int32_t chunkSize = 36 + SUBCHUNC_2_SIZE;
    // Содержит символы "WAVE"
    // (0x57415645 в big-endian представлении)
    char format[4] = {'W', 'A', 'V', 'E'};
    // Формат "WAVE" состоит из двух подцепочек: "fmt " и "data":
    // Подцепочка "fmt " описывает формат звуковых данных:
    // Содержит символы "fmt "
    // (0x666d7420 в big-endian представлении)
    char subchunk1Id[4] = {'f', 'm', 't', ' '};
    // 16 для формата PCM.
    // Это оставшийся размер подцепочки, начиная с этой позиции.
    int32_t subchunk1Size = 16;
    // Аудио формат, полный список можно получить здесь http://audiocoding.ru/wav_formats.txt
    // Для PCM = 1 (то есть, Линейное квантование).
    // Значения, отличающиеся от 1, обозначают некоторый формат сжатия.
    int16_t audioFormat = 1;
    // Количество каналов. Моно = 1, Стерео = 2 и т.д.
    int16_t numChannels = NUM_CHANNELS;
    // Частота дискретизации. 8000 Гц, 44100 Гц и т.д.
    int32_t sampleRate = SAMPLE_RATE;
    // sampleRate * numChannels * bitsPerSample/8
    int32_t byteRate =
    SAMPLE_RATE * NUM_CHANNELS * sizeof(frame_t);
    // numChannels * bitsPerSample/8
    // Количество байт для одного сэмпла, включая все каналы.
    int16_t blockAlign = NUM_CHANNELS * sizeof(frame_t);
    // Так называемая "глубиная" или точность звучания. 8 бит, 16 бит и т.д.
    int16_t bitsPerSample = sizeof(frame_t) * 8;
    // Подцепочка "data" содержит аудио-данные и их размер.
    // Содержит символы "data"
    // (0x64617461 в big-endian представлении)
    char subchunk2Id[4] = {'d', 'a', 't', 'a'};
    // numSamples * numChannels * bitsPerSample/8
    // Количество байт в области данных.
    int32_t subchunk2Size = SUBCHUNC_2_SIZE;
    // Далее следуют непосредственно Wav данные.
};

class wavWriter{
public:
    static int write(const char* filename, frame_t *buffer);
};

#endif /* wavWriter_hpp */
