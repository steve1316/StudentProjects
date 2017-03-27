#ifndef Pound_h
#define Pound_h
#include "Currency.h"
#include <string>

class Pound : public Currency {
public:
    Pound() {
        assignNames();
    }
    
    Pound (int w, int f) : Currency (w, f) {
        assignNames();
        initialized = true;
    }
    
    void assignNames() {
        wholeName = "British Pound";
        fractionalName = "Pence";
        fractionalInWhole = 100;
    }
};
#endif
