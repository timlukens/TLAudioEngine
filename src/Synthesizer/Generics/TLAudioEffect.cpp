//
//  TLAudioEffect.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#include "TLAudioEffect.hpp"

TLAudioEffect::TLAudioEffect() {
    CreateOutputNode();
}

TLAudioEffect::~TLAudioEffect() {
    
}

TLPatchNode* TLAudioEffect::GetNextInputNode() {
    TLPatchNode* node = new TLPatchNode(this);
    inputNodes.push_back(node);
    return node;
}
