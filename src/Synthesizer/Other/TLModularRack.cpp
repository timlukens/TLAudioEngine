//
//  TLModularRack.cpp
//  Hmm (macOS)
//
//  Created by Katie Oates on 8/16/22.
//

#include "TLModularRack.hpp"
#include "Generators/TLWaveGenerator.hpp"
#include "TLAudioOutput.hpp"
#include "Effects/TLMixer.hpp"
#include <iostream>

using namespace std;

TLModularRack::TLModularRack() {
    TLRealTimeAudioObject* output = new TLAudioOutput();
    TLMixer* mixer = new TLMixer();
    
    TLWaveGenerator* sine = new TLWaveGenerator(TLWaveTypeSine);
    TLWaveGenerator* sine2 = new TLWaveGenerator(TLWaveTypeSine);
    TLWaveGenerator* sine3 = new TLWaveGenerator(TLWaveTypeSaw);
    TLWaveGenerator* modSine = new TLWaveGenerator(TLWaveTypeSine);
    TLWaveGenerator* ampModSine = new TLWaveGenerator(TLWaveTypeSine);
    
    sine->ConnectNodes(sine->outputNodes[0], mixer->GetNextInputNode());
    sine->SetFrequency(400.0);
    sine->SetAmplitude(0.1);

    sine2->ConnectNodes(sine2->outputNodes[0], mixer->GetNextInputNode());
    sine2->SetFrequency(200.0);
    sine2->SetAmplitude(0.1);

    sine3->ConnectNodes(sine3->outputNodes[0], mixer->GetNextInputNode());
    sine3->SetFrequency(700.0);
    sine3->SetAmplitude(0.1);
    
    modSine->ConnectNodes(modSine->outputNodes[0], sine->freqModNode);
    modSine->SetFrequency(1.0);
    modSine->SetAmplitude(200.0);
    
    //ampModSine->ConnectNodes(ampModSine->outputNodes[0], sine->ampModNode);
    ampModSine->SetFrequency(1.0);
    ampModSine->SetAmplitude(0.0001);
    
    mixer->ConnectNodes(mixer->outputNodes[0], output->inputNodes[0]);
    
    addGenerator(sine);
    addGenerator(sine2);
    addGenerator(sine3);

    //addGenerator(ampModSine);
    
    _allocatedObjects.push_back(mixer);
    _allocatedObjects.push_back(output);
    _allocatedObjects.push_back(sine);
    _allocatedObjects.push_back(modSine);
    _allocatedObjects.push_back(ampModSine);
}

TLModularRack::~TLModularRack() {
    for(void* obj : _allocatedObjects)
        delete(obj);
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

void TLModularRack::NextScoreLine() {
    TLWaveGenerator* sine3 = (TLWaveGenerator*)_generators[2];

    cin.get();
    sine3->SetFrequency(500.0);
    cin.get();
    sine3->SetFrequency(600);
    cin.get();
}
