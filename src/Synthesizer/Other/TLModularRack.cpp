//
//  TLModularRack.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#include "TLModularRack.hpp"

TLModularRack::TLModularRack() {
    
}

TLModularRack::~TLModularRack() {
    
}

int TLModularRack::tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData) {
    for(TLGenerator* gen : _generators) {
        gen->tick(inputBuffer, outputBuffer, framesPerBuffer, userData);
    }
    
    return 0;
}

void TLModularRack::addGenerator(TLGenerator* obj) {
    if(dynamic_cast<TLGenerator*>(obj) != nullptr) {
        _generators.push_back(obj);
    }
}
