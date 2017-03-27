#ifndef PKRupee_h
#define PKRupee_h
#include "Currency.h"
#include <string>

class PKRupee : public Currency {
public:
    PKRupee() {
        assignNames();
    }
    
    PKRupee (int w, int f) : Currency (w, f) {
        assignNames();
        initialized = true;
    }
    
    void assignNames() {
        wholeName = "Pakistani Rupee";
        fractionalName = "Paise";
        fractionalInWhole = 100;
    }
};
#endif
