//
//  TLPatchNode.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#include "TLPatchNode.hpp"
#include "TLPatchCable.hpp"
#include "Generics/TLRealTimeAudioObject.hpp"
#include "TLAudioEngine.hpp"

#include <iostream>

using namespace std;

TLPatchNode::TLPatchNode(void* nodeOwner) {
    owner = nodeOwner;
    connectedCable = nullptr;
    nodeBuffer = calloc(MAX_BUFFER_SIZE, sizeof(float));
}

TLPatchNode::~TLPatchNode() {
    free(nodeBuffer);
}

void TLPatchNode::Tick(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, void* userData, void* buffer) {
    float* sig = (float*)buffer;
    memcpy(nodeBuffer, buffer, sizeof(float) * framesPerBuffer);
    if (connectedCable != nullptr) {
        TLPatchCable* c = (TLPatchCable*)connectedCable;
        if (c->inputNode != nullptr) {
            memcpy(c->inputNode->nodeBuffer, buffer, sizeof(float) * framesPerBuffer);
            if (c->inputNode->owner != nullptr) {
                TLRealTimeAudioObject* o = (TLRealTimeAudioObject*)c->inputNode->owner;
                if (o != nullptr) {
                    o->tick(inputBuffer, outputBuffer, framesPerBuffer, userData);
                }
            }
        }
    }
}
