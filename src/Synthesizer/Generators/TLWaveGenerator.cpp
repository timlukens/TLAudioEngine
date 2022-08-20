//
//  TLWaveGenerator.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#define _USE_MATH_DEFINES

#include "TLWaveGenerator.hpp"
#include "TLAudioEngine.hpp"
#include "Other/TLPatchNode.hpp"
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
            for (int i = 0; i < tableSize; i++) {
                table.push_back(sin(M_PI * 2 * ((double)i / (double)tableSize)));
            }
            break;
        case TLWaveTypeSaw:
            for (int i = 0; i < tableSize; i++) {
                table.push_back((double)i / (double)tableSize);
            }
            break;
        default:
            cout << "TLWaveGenerator attempting to create invalid wave type.\n";
    }

    stepSize = _frequency * (double)tableSize / SAMPLE_RATE;
}

TLWaveGenerator::~TLWaveGenerator() {
    delete(freqModNode);
    delete(ampModNode);
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
        freqModSig = (float*)freqModNode->nodeBuffer;
        /*for (int i = 0; i < framesPerBuffer; i++) {
            cout << freqModSig[i] << "\n";
        }*/
    }
    
    if(ampModNode->connectedCable != nullptr) {
        ampModSig = (float*)ampModNode->nodeBuffer;
    }
    
    for(int i = 0; i < framesPerBuffer; i++) {
        if(freqModNode->connectedCable != nullptr)
            stepSize = abs((_frequency + freqModSig[i]) * (double)tableSize / SAMPLE_RATE);
        
       if(ampModSig != nullptr)
            useAmp += ampModSig[i];
        
        _buffer[i] = table[index] * useAmp;
        index += stepSize;
        if(index > tableSize) index -= tableSize;
    }
    
    for(TLPatchNode* n : outputNodes) {
        n->Tick(inputBuffer, outputBuffer, framesPerBuffer, userData, _buffer);
    }
    
    memset(_buffer, 0, sizeof(float) * framesPerBuffer);
    
    return 0;
}
