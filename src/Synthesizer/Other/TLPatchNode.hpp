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
    
    void Tick(unsigned long framesPerBuffer, void *userData);
    
    void* connectedCable;
    void* owner;
};

#endif /* TLPatchNode_hpp */
