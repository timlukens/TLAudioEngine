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
#include "Generics/TLRealTimeAudioObject.hpp"
#include "Generics/TLGenerator.hpp"

using namespace std;

class TLModularRack : public TLRealTimeAudioObject {
public:
    TLModularRack();
    ~TLModularRack();
    
    int tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData);
    
    void addGenerator(TLGenerator* obj);

    void NextScoreLine();
    
private:
    vector<TLGenerator*> _generators;
    vector<void*> _allocatedObjects;
};

#endif /* TLModularRack_hpp */
