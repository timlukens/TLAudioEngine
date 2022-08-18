//
//  TLAudioOutput.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#include "TLAudioOutput.hpp"
#include "TLPatchNode.hpp"
#include <memory>
#include <iostream>

using namespace std;

TLAudioOutput::TLAudioOutput() {
    CreateInputNode();
}

TLAudioOutput::~TLAudioOutput() {
    
}

int TLAudioOutput::tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData) {
    for(TLPatchNode* n : inputNodes) {
        TLPatchCable* c = (TLPatchCable*)n->connectedCable;
        if(c->signal) {
            memcpy(outputBuffer, c->signal, framesPerBuffer * sizeof(float));
        }
    }
    return 0;
}
