
#include <iostream>
#include "TLAudioEngine.hpp"
#include "Other\TLModularRack.hpp"


using namespace std;

int main() {
    TLAudioEngine* engine = new TLAudioEngine();
    shared_ptr<TLModularRack> rack = make_shared<TLModularRack>();

    engine->AddRealTimeAudioObject(rack);
    engine->StartEngine();
    
    rack->NextScoreLine();
    
    delete(engine);
    
    return 0;
}
