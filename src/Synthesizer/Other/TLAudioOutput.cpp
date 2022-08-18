//
//  TLAudioOutput.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#include "TLAudioOutput.hpp"
#include <memory>

using namespace std;

TLAudioOutput::TLAudioOutput() {
    
}

TLAudioOutput::~TLAudioOutput() {
    
}

int TLAudioOutput::tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData) {
    if(_inputCable->signal) {
        memcpy(outputBuffer, _inputCable->signal, framesPerBuffer * sizeof(float));
    }
    return 0;
}
