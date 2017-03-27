#ifndef Wallet_h
#define Wallet_h

#include <string>
#include "Currency.h"
#include "Dollar.h"
#include "Pound.h"
#include "Euro.h"
#include "PKRupee.h"
#include "Riyal.h"

enum CurrencyNames {CURRENCY_1 = 0, CURRENCY_2, CURRENCY_3, CURRENCY_4, CURRENCY_LAST};

class Wallet {
private:
    int numberOfCurrencies;
    Currency *currencies[CURRENCY_LAST + 1];
public:
    Wallet();
    ~Wallet();
    bool isEmpty() { return Currency::noInstances(); }
    int getNumCurrencies() { return numberOfCurrencies; }
    Currency *operator[](int index) { return currencies[index]; }
    void addByCurrency(Currency temp, int index);
    void subtractByCurrency(Currency temp, int index);
    void emptyWallet();
    int addCurrency(string selection);
    int checkCurrency(string entry);
};

#endif /* Wallet_h */
