//
//  TLModularRack.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#ifndef TLModularRack_hpp
#define TLModularRack_hpp

#include <stdio.h>
#include <vector>
#include "TLRealTimeAudioObject.hpp"
#include "TLGenerator.hpp"

class TLModularRack : public TLRealTimeAudioObject {
public:
    TLModularRack();
    ~TLModularRack();
    
    int tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData);
    
    void addGenerator(TLGenerator* obj);
    
private:
    std::vector<TLGenerator*> _generators;
};

#endif /* TLModularRack_hpp */
