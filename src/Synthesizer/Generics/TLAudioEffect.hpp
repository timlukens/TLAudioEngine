//
//  TLAudioEffect.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#ifndef TLAudioEffect_hpp
#define TLAudioEffect_hpp

#include <stdio.h>
#include "TLRealTimeAudioObject.hpp"
#include "Other\TLPatchNode.hpp"

class TLAudioEffect : public TLRealTimeAudioObject {
public:
    TLAudioEffect();
    ~TLAudioEffect();
    
    TLPatchNode* GetNextInputNode();
};

#endif /* TLAudioEffect_hpp */
