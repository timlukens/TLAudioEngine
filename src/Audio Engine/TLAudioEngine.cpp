//
//  TLAudioEngine.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#include "TLAudioEngine.hpp"
#include <iostream>

static int TLAudioCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData );

TLAudioEngine::TLAudioEngine() {
    _sampleRate = SAMPLE_RATE;
    _bufferSize = 256;
    _bitDepth = 16;
    _inputChannels = 0;
    _outputChannels = 1;
    _engineInfo = new TLAudioInfo();
}

TLAudioEngine::~TLAudioEngine() {
    Pa_CloseStream(_paStream);
    Pa_Terminate();
}

void TLAudioEngine::StartEngine() {
    PaError err = Pa_Initialize();
    if(err) {
        printf("TLAudioEngine experienced an error in StartEngine. Could not initialize. %s\n", Pa_GetErrorText(err));
        return;
    }
    
    err = Pa_OpenDefaultStream(&_paStream, _inputChannels, _outputChannels, paFloat32, _sampleRate, (unsigned long)_bufferSize, &TLAudioCallback, _engineInfo);
    if(err) {
        printf("TLAudioEngine experienced an error in StartEngine. Could not open audio stream. %s\n", Pa_GetErrorText(err));
        return;
    }
    
    err = Pa_StartStream(_paStream);
    if(err) {
        printf("TLAudioEngine experienced an error in StartEngine. Could not start audio stream. %s\n", Pa_GetErrorText(err));
        return;
    }
    
    printf("TLAudioEngine running...\n");
}

void TLAudioEngine::AddRealTimeAudioObject(shared_ptr<TLRealTimeAudioObject> obj) {
    _engineInfo->audioObjects.push_back(obj);
}

#pragma mark callback
static int TLAudioCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData )
{
    TLAudioInfo* ai = (TLAudioInfo*)userData;
    memset(outputBuffer, 0, sizeof(float) * framesPerBuffer);
    for(shared_ptr<TLRealTimeAudioObject> o : ai->audioObjects) {
        o->tick(inputBuffer, outputBuffer, framesPerBuffer, ai);
    }

    return 0;
}
