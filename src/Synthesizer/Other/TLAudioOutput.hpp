//
//  TLAudioOutput.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#ifndef TLAudioOutput_hpp
#define TLAudioOutput_hpp

#include <stdio.h>
#include "TLRealTimeAudioObject.hpp"

class TLAudioOutput : public TLRealTimeAudioObject {
public:
    TLAudioOutput();
    ~TLAudioOutput();
    int tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData);
};

#endif /* TLAudioOutput_hpp */
