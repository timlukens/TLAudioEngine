//
//  TLAudioEngine.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#ifndef TLAudioEngine_hpp
#define TLAudioEngine_hpp

#define SAMPLE_RATE 44100.0
#define MAX_BUFFER_SIZE 4096

#include <stdio.h>
#include <vector>
#include <memory>
#include "PortAudio/portaudio.h"
#include "Generics\TLRealTimeAudioObject.hpp"

using namespace std;

struct TLAudioInfo {
    vector<shared_ptr<TLRealTimeAudioObject>> audioObjects;
    int frameSizeInBytes;
};

class TLAudioEngine {
public:
    TLAudioEngine();
    ~TLAudioEngine();
    void StartEngine();
    void AddRealTimeAudioObject(shared_ptr<TLRealTimeAudioObject> obj);
    
private:
    double _sampleRate;
    int _bufferSize;
    int _bitDepth;
    int _inputChannels;
    int _outputChannels;
    
    struct TLAudioInfo* _engineInfo;
    
    PaStream* _paStream;
};

#endif /* TLAudioEngine_hpp */
