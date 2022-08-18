//
//  TLPatchCable.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#include "TLPatchCable.hpp"
#include "TLRealTimeAudioObject.hpp"

TLPatchCable::TLPatchCable(int bufferSize, int elementSize, TLPatchNode* input, TLPatchNode* output) {
    _bufferSize = bufferSize;
    inputNode = input;
    outputNode = output;
    
    signal = malloc(elementSize * bufferSize);
}

TLPatchCable::~TLPatchCable() {
    
}

