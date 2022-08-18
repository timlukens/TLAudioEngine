//
//  TLPatchCable.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#ifndef TLPatchCable_hpp
#define TLPatchCable_hpp

#include <stdio.h>

class TLPatchCable {
public:
    TLPatchCable(int bufferSize, void* input, void* output);
    ~TLPatchCable();
    
    void* outputObj;
    void* signal;
    
private:
    int _bufferSize;
    void* _input;
    
};

#endif /* TLPatchCable_hpp */
