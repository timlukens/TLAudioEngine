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
#include "Other/TLPatchCable.hpp"
#include "Other/TLPatchNode.hpp"

using namespace std;

class TLRealTimeAudioObject {
public:
    TLRealTimeAudioObject();
    ~TLRealTimeAudioObject();
    
    virtual int tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData);
    void ConnectNodes(TLPatchNode* outputNode, TLPatchNode* inputNode);
    void CreateInputNode();
    void CreateOutputNode();
    
    vector<TLPatchNode*> outputNodes;
    vector<TLPatchNode*> inputNodes;
    
protected:
    float* _buffer;
};

#endif /* TLRealTimeAudioObject_hpp */
