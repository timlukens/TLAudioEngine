//
//  TLAudioGenerator.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#include "TLGenerator.hpp"
#include "TLAudioEngine.hpp"
#include <math.h>

TLGenerator::TLGenerator() {
    CreateOutputNode();
}

TLGenerator::~TLGenerator() {
    
}

int TLGenerator::tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData) {
    return 0;
}
