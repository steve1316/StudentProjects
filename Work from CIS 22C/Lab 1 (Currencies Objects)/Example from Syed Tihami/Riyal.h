#ifndef SaudiRiyaal_h
#define SaudiRiyaal_h
#include "Currency.h"
#include <string>

class Riyal : public Currency {
public:
    Riyal() {
        assignNames();
    }
    
    Riyal(int w, int f) : Currency (w, f) {
        assignNames();
        initialized = true;
    }
    
    void assignNames() {
        wholeName = "Saudi Riyal";
        fractionalName = "Halala";
        fractionalInWhole = 100;
    }
};
#endif
