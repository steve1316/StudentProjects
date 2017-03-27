#ifndef Dollar_h
#define Dollar_h
#include "Currency.h"
#include <string>

class Dollar : public Currency {
public:
    Dollar() {
        assignNames();
    }
    
    Dollar(int w, int f) : Currency (w, f) {
        assignNames();
        initialized = true;
    }
    
    void assignNames() {
        wholeName = "Dollar";
        fractionalName = "Cent";
        fractionalInWhole = 100;
    }
};
#endif
