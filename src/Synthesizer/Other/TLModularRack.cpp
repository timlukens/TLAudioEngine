//
//  TLModularRack.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#include "TLModularRack.hpp"
#include "TLWaveGenerator.hpp"
#include "TLAudioOutput.hpp"
#include "TLMixer.hpp"

TLModularRack::TLModularRack() {
    TLRealTimeAudioObject* output = new TLAudioOutput();
    TLMixer* mixer = new TLMixer();
    
    TLWaveGenerator* sine = new TLWaveGenerator(TLWaveTypeSine);
    TLWaveGenerator* modSine = new TLWaveGenerator(TLWaveTypeSine);
    TLWaveGenerator* ampModSine = new TLWaveGenerator(TLWaveTypeSine);
    
    sine->ConnectNodes(sine->outputNodes[0], mixer->GetNextInputNode());
    sine->SetFrequency(400.0);
    sine->SetAmplitude(0.5);
    
    modSine->ConnectNodes(modSine->outputNodes[0], sine->freqModNode);
    modSine->SetFrequency(1.0);
    modSine->SetAmplitude(200.0);
    
    ampModSine->ConnectNodes(ampModSine->outputNodes[0], modSine->ampModNode);
    ampModSine->SetFrequency(0.1);
    ampModSine->SetAmplitude(20);
    
    mixer->ConnectNodes(mixer->outputNodes[0], output->inputNodes[0]);
    
    addGenerator(sine);
    addGenerator(modSine);
    addGenerator(ampModSine);
    
    _allocatedObjects.push_back(mixer);
    _allocatedObjects.push_back(output);
    _allocatedObjects.push_back(sine);
    _allocatedObjects.push_back(modSine);
    _allocatedObjects.push_back(ampModSine);
}

TLModularRack::~TLModularRack() {
    for(void* obj : _allocatedObjects)
        free(obj);
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
