//
//  TLMixer.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/17/22.
//

#ifndef TLMixer_hpp
#define TLMixer_hpp

#include <stdio.h>
#include <vector>
#include "Generics/TLRealTimeAudioObject.hpp"
#include "Other/TLPatchCable.hpp"
#include "Generics/TLAudioEffect.hpp"

using namespace std;

class TLMixer : public TLAudioEffect {
public:
    TLMixer();
    ~TLMixer();
    
    int tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData);
    
private:
    int _numInputsTicked;
};

#endif /* TLMixer_hpp */
