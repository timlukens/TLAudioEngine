//
//  TLWaveGenerator.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#include "TLWaveGenerator.hpp"
#include "TLAudioEngine.hpp"
#include <math.h>
#include <iostream>

using namespace std;

TLWaveGenerator::TLWaveGenerator(TLWaveType type) {
    switch(type) {
        case TLWaveTypeSine:
            CreateSineTable();
            break;
        default:
            cout << "TLWaveGenerator attempting to create invalid wave type.\n";
    }
}

TLWaveGenerator::~TLWaveGenerator() {
    
}

void TLWaveGenerator::CreateSineTable() {
    for(int i = 0; i < tableSize; i++) {
        table.push_back(sin((M_2_PI * (double)i) / (double)tableSize));
    }
    
    stepSize = 220.0 * (double)tableSize / SAMPLE_RATE;
}

int TLWaveGenerator::tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData) {
    for(int i = 0; i < framesPerBuffer; i++) {
        _buffer[i] = table.at(index);
        index += stepSize;
        if(index > tableSize) index -= tableSize;
    }
    
    for(TLPatchCable* c : _outputCables) {
        c->signal = _buffer;
        TLRealTimeAudioObject* o = (TLRealTimeAudioObject*)c->outputObj;
        o->tick(inputBuffer, outputBuffer, framesPerBuffer, userData);
    }
    
    return 0;
}
