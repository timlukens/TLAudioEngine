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
    if(_numInputsTicked < inputNodes.size()) return 0;
    
    for(TLPatchNode* n : inputNodes) {
        TLPatchCable* c = (TLPatchCable*)n->connectedCable;
        float* sig = (float*)c->signal;
        for(int i = 0; i < framesPerBuffer; i++) {
            _buffer[i] += sig[i];
        }
    }
    
    for(TLPatchNode* n : outputNodes) {
        TLPatchCable* c = (TLPatchCable*)n->connectedCable;
        memcpy(c->signal, _buffer, framesPerBuffer * sizeof(float));
        TLPatchNode* connectedInputNode = (TLPatchNode*)c->inputNode;
        TLRealTimeAudioObject* o = (TLRealTimeAudioObject*)connectedInputNode->owner;
        o->tick(inputBuffer, outputBuffer, framesPerBuffer, userData);
    }
    
    _numInputsTicked = 0;
    memset(_buffer, 0, framesPerBuffer * sizeof(float));
    
    return 0;
}
