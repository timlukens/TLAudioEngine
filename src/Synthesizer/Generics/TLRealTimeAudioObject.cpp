//
//  TLRealTimeAudioObject.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#include "TLRealTimeAudioObject.hpp"
#include "TLAudioEngine.hpp"
#include <iostream>

using namespace std;

TLRealTimeAudioObject::TLRealTimeAudioObject() {
    _buffer = (float*)malloc(sizeof(float) * MAX_BUFFER_SIZE);
}

TLRealTimeAudioObject::~TLRealTimeAudioObject() {
    free(_buffer);
    _buffer = nullptr;
    
    for(TLPatchNode* n : inputNodes)
        free(n);
    
    for(TLPatchNode* n : outputNodes)
        free(n);
}

void TLRealTimeAudioObject::CreateOutputNode() {
    outputNodes.push_back(new TLPatchNode(this));
}

void TLRealTimeAudioObject::CreateInputNode() {
    inputNodes.push_back(new TLPatchNode(this));
}

void TLRealTimeAudioObject::ConnectNodes(TLPatchNode* outputNode, TLPatchNode* inputNode) {
    TLPatchCable* cable = new TLPatchCable(MAX_BUFFER_SIZE, sizeof(float), inputNode, outputNode);
    outputNode->connectedCable = cable;
    inputNode->connectedCable = cable;
}

int TLRealTimeAudioObject::tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData) {
    return 0;
}
