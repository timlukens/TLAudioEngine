//
//  TLWaveGenerator.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#include "TLWaveGenerator.hpp"
#include "TLAudioEngine.hpp"
#include "TLPatchNode.hpp"
#include <math.h>
#include <iostream>

using namespace std;

TLWaveGenerator::TLWaveGenerator(TLWaveType type) {
    _frequency = 440.0;
    _amplitude = 1.0;
    
    freqModNode = new TLPatchNode(nullptr);
    ampModNode = new TLPatchNode(nullptr);
    
    switch(type) {
        case TLWaveTypeSine:
            CreateSineTable();
            break;
        default:
            cout << "TLWaveGenerator attempting to create invalid wave type.\n";
    }
}

TLWaveGenerator::~TLWaveGenerator() {
    free(freqModNode);
    free(ampModNode);
}

void TLWaveGenerator::CreateSineTable() {
    for(int i = 0; i < tableSize; i++) {
        table.push_back(sin(M_PI * 2 * ((double)i / (double)tableSize)));
    }
    
    stepSize = _frequency * (double)tableSize / SAMPLE_RATE;
}

void TLWaveGenerator::SetFrequency(double freq) {
    _frequency = freq;
    stepSize = _frequency * (double)tableSize / SAMPLE_RATE;
}

void TLWaveGenerator::SetAmplitude(double amp) {
    _amplitude = amp;
}

int TLWaveGenerator::tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData) {
    float* freqModSig = nullptr;
    float* ampModSig = nullptr;
    double useAmp = _amplitude;
    
    if(freqModNode->connectedCable != nullptr) {
        TLPatchCable* freqModCable = (TLPatchCable*)freqModNode->connectedCable;
        freqModSig = (float*)freqModCable->signal;
    }
    
    if(ampModNode->connectedCable != nullptr) {
        TLPatchCable* ampModCable = (TLPatchCable*)ampModNode->connectedCable;
        ampModSig = (float*)ampModCable->signal;
    }
    
    for(int i = 0; i < framesPerBuffer; i++) {
        if(freqModNode->connectedCable != nullptr)
            stepSize = (_frequency + freqModSig[i]) * (double)tableSize / SAMPLE_RATE;
        
        if(ampModNode->connectedCable != nullptr)
            useAmp += ampModSig[i];
        
        _buffer[i] = table[index] * useAmp;
        index += stepSize;
        if(index > tableSize) index -= tableSize;
    }
    
    for(TLPatchNode* n : outputNodes) {
        TLPatchCable* c = (TLPatchCable*)n->connectedCable;
        memcpy(c->signal, _buffer, sizeof(float) * framesPerBuffer);
        TLPatchNode* connectedInputNode = c->inputNode;
        
        if(connectedInputNode->owner != nullptr) {
            TLRealTimeAudioObject* o = (TLRealTimeAudioObject*)connectedInputNode->owner;
            o->tick(inputBuffer, outputBuffer, framesPerBuffer, userData);
        }
    }
    
    memset(_buffer, 0, sizeof(float) * framesPerBuffer);
    
    return 0;
}
