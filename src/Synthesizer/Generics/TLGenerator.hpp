//
//  TLAudioGenerator.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#ifndef TLAudioGenerator_hpp
#define TLAudioGenerator_hpp

#include <stdio.h>
#include <vector>
#include "Generics\TLRealTimeAudioObject.hpp"
#include "Other\TLPatchCable.hpp"

using namespace std;

class TLGenerator : public TLRealTimeAudioObject {
public:
    TLGenerator();
    ~TLGenerator();
    
    virtual int tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData);
};

#endif /* TLAudioGenerator_hpp */
