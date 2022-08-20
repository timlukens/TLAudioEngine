//
//  TLMixer.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#include "TLMixer.hpp"
#include "TLAudioEngine.hpp"
#include <iostream>

TLMixer::TLMixer() {
    _numInputsTicked = 0;
    memset(_buffer, 0, MAX_BUFFER_SIZE);
}

TLMixer::~TLMixer() {
    
}

int TLMixer::tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData) {
    _numInputsTicked++;
    
    for(TLPatchNode* n : inputNodes) {
        float* sig = (float*)n->nodeBuffer;
        for(unsigned int i = 0; i < framesPerBuffer; i++) {
            _buffer[i] += sig[i];
        }
    }

    if (_numInputsTicked < inputNodes.size()) return 0;
    
    for(TLPatchNode* n : outputNodes) {
        n->Tick(inputBuffer, outputBuffer, framesPerBuffer, userData, _buffer);
    }
    
    _numInputsTicked = 0;
    memset(_buffer, 0, framesPerBuffer * sizeof(float));
    
    return 0;
}
