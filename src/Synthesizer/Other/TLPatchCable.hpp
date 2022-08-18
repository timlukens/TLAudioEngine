//
//  TLPatchCable.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#ifndef TLPatchCable_hpp
#define TLPatchCable_hpp

#include <stdio.h>
#include "TLPatchNode.hpp"

class TLPatchCable {
public:
    TLPatchCable(int bufferSize, int elementSize, TLPatchNode* input, TLPatchNode* output);
    ~TLPatchCable();
    
    TLPatchNode* outputNode;
    TLPatchNode* inputNode;
    void* signal;
    
private:
    int _bufferSize;
    
};

#endif /* TLPatchCable_hpp */
