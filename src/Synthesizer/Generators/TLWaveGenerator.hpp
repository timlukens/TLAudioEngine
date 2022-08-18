//
//  TLWaveGenerator.hpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#ifndef TLWaveGenerator_hpp
#define TLWaveGenerator_hpp

#include <stdio.h>
#include <vector>
#include "TLGenerator.hpp"

using namespace std;

enum TLWaveType {
    TLWaveTypeSine = 0
};

class TLWaveGenerator : public TLGenerator {
public:
    TLWaveGenerator(TLWaveType type);
    ~TLWaveGenerator();
    
    int tick(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, void *userData);
    void SetFrequency(double freq);
    void SetAmplitude(double amp);
    TLPatchNode* freqModNode;
    TLPatchNode* ampModNode;
    
private:
    double _amplitude;
    double _frequency;
    int tableSize = 8192;
    double index = 0;
    double stepSize;
    vector<float> table;
    
    void CreateSineTable();
};

#endif /* TLWaveGenerator_hpp */
