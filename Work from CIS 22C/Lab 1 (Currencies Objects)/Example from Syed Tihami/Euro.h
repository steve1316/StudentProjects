#ifndef Euro_h
#define Euro_h
#include "Currency.h"
#include <string>

class Euro : public Currency {
public:
    Euro() {
        assignNames();
    }
    
    Euro (int w, int f) : Currency (w, f) {
        assignNames();
        initialized = true;
    }
    
    void assignNames() {
        wholeName = "Euro";
        fractionalName = "Cent";
        fractionalInWhole = 100;
    }
};
#endif
