
#include <iostream>
#include "TLAudioEngine.hpp"
#include "TLModularRack.hpp"


using namespace std;

int main() {
    TLAudioEngine* engine = new TLAudioEngine();
    shared_ptr<TLModularRack> rack = make_shared<TLModularRack>();

    engine->AddRealTimeAudioObject(rack);
    engine->StartEngine();
    
    cin.get();
    
    free(engine);
    
    return 0;
}
