//
//  TLPatchNode.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#include "TLPatchNode.hpp"

TLPatchNode::TLPatchNode(void* nodeOwner) {
    owner = nodeOwner;
    connectedCable = nullptr;
}

TLPatchNode::~TLPatchNode() {
    
}

void TLPatchNode::Tick(unsigned long framesPerBuffer, void *userData) {
    
}
