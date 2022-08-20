//
//  TLPatchNode.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#ifndef TLPatchNode_hpp
#define TLPatchNode_hpp

#include <stdio.h>
//#include "TLPatchCable.hpp"

class TLPatchNode {
public:
    TLPatchNode(void* nodeOwner);
    ~TLPatchNode();
    
    void Tick(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, void* userData, void* buffer);
    
    void* connectedCable;
    void* owner;
    void* nodeBuffer;
};

#endif /* TLPatchNode_hpp */
