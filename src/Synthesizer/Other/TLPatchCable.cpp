//
//  TLPatchCable.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#include "TLPatchCable.hpp"
#include "TLRealTimeAudioObject.hpp"

TLPatchCable::TLPatchCable(int bufferSize, void* input, void* output) {
    _bufferSize = bufferSize;
    _input = input;
    outputObj = output;
    
    TLRealTimeAudioObject* o = (TLRealTimeAudioObject*)output;
    
    o->setInputCable(this);
}

TLPatchCable::~TLPatchCable() {
    
}

