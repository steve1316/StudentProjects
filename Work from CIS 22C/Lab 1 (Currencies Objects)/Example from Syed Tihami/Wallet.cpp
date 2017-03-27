#include "Wallet.h"
#include <string>

using namespace std;

//*******************************************
//Default Constructor for Wallet Class      *
//*******************************************
Wallet::Wallet() : numberOfCurrencies(0) {}

//*************************************************************
//Deconstructor for Wallet Class                              *
//The Deconstructor de-allocates memory used for the wallet   *
//*************************************************************
Wallet::~Wallet() {
    for (int i = 0; i < numberOfCurrencies; i++) {
        delete currencies[i];
        currencies[i] = nullptr;
    }
    numberOfCurrencies = 0;
}

//***************************************************************************************************
//addCurrency Method for the Wallet class                                                           *
//This method analyzes a string and checks if it matches the name of an included currency           *
//If it does, it allocates a new currency object under that currency
//It returns 0 if successfully completed, 1 if the currency is already in use, and 2 if the name is not found
//***************************************************************************************************
int Wallet::addCurrency(string selection) {
    for (int i = 0; i < numberOfCurrencies; i++) {
        if (selection == currencies[i]->getWholeName() || selection == currencies[i]->getFractName()) {
            return 1;
        }
    }
    if (selection == Dollar().getWholeName() || selection == Dollar().getFractName()) {
        currencies[numberOfCurrencies++] = new Dollar(0, 0);
    }
    else if (selection == Pound().getWholeName() || selection == Pound().getFractName()) {
        currencies[numberOfCurrencies++] = new Pound(0, 0);
    }
    else if (selection == Euro().getWholeName() || selection == Euro().getFractName()) {
        currencies[numberOfCurrencies++] = new Euro(0, 0);
    }
    else if (selection == PKRupee().getWholeName() || selection == PKRupee().getFractName()) {
        currencies[numberOfCurrencies++] = new PKRupee(0, 0);
    }
    else if (selection == Riyal().getWholeName() || selection == Riyal().getFractName()) {
        currencies[numberOfCurrencies++] = new Riyal(0, 0);
    }
    else {
        return 2;
    }
    return 0;
}

//******************************************************************************
//Definition of function addByCurrency                                         *
//It takes a Currency object and an index as parameters and adds the Currency  *
//object to the Currency object corresponding to the index                     *
//******************************************************************************
void Wallet::addByCurrency(Currency temp, int index) {
    *(currencies[index]) += temp;
}

//***********************************************************************************
//Definition of function subtractByCurrency                                         *
//It takes a Currency object and an index as parameters and subtracts the Currency  *
//object to the Currency object corresponding to the index                          *
//***********************************************************************************
void Wallet::subtractByCurrency(Currency temp, int index) {
    *(currencies[index]) -= temp;
}

//****************************************************************************
//Definition of function emptyWallet                                         *
//It takes no parameters and empties the wallet                              *
//****************************************************************************
void Wallet::emptyWallet() {
    for (int i = 0; i <  numberOfCurrencies; i++) {
        cout << "Removing " <<  *(currencies[i]) << " from your wallet...\n";
        delete currencies[i];
        currencies[i] = nullptr;
    }
    numberOfCurrencies = 0;
}

//****************************************************************************
//Definition of memeber function checkCurrency                               *
//This function takes in a string argument and checks if a currency          *
//is available in the wallet the name of which matches the entry             *
//****************************************************************************
int Wallet::checkCurrency(string entry) {
    int index = -1;
    for (int i = 0; i < getNumCurrencies() && index == -1; i++) {
        if (currencies[i]->getWholeName() == entry || currencies[i]->getFractName() == entry) {
            index = i;
        }
    }
    return index;
}
