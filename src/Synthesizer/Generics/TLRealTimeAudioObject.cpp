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
    cout << "TLRealTimeAudioObject alloc\n";
}

TLRealTimeAudioObject::~TLRealTimeAudioObject() {
    cout << "TLRealTimeAudioObject dealloc\n";
}

void TLRealTimeAudioObject::AddOutputTo(TLRealTimeAudioObject* inObj) {
    TLPatchCable* c = new TLPatchCable(MAX_BUFFER_SIZE, this, inObj);
    _outputCables.push_back(c);
}

void TLRealTimeAudioObject::setInputCable(TLPatchCable* cable) {
    _inputCable = cable;
}

int TLRealTimeAudioObject::tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData) {
    return 0;
}
