//
//  TLRealTimeAudioObject.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#ifndef TLRealTimeAudioObject_hpp
#define TLRealTimeAudioObject_hpp

#include <stdio.h>
#include <vector>
#include "TLPatchCable.hpp"

using namespace std;

class TLRealTimeAudioObject {
public:
    TLRealTimeAudioObject();
    ~TLRealTimeAudioObject();
    
    virtual int tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData);
    void AddOutputTo(TLRealTimeAudioObject* inObj);
    void setInputCable(TLPatchCable* cable);
    
protected:
    vector<TLPatchCable*> _outputCables;
    TLPatchCable* _inputCable;
};

#endif /* TLRealTimeAudioObject_hpp */
