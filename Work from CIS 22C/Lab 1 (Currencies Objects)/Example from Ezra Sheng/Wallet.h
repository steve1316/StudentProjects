/** @file Wallet.h */
#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <string>
#include "Currency.h"

using namespace std;

// Declaration for the class Wallet
class Wallet
{

private:
	//Attributes
	Currency* cList[5];
	int cNumber;

public:
	//Constructors
	Wallet();
	Wallet(Currency* a, Currency* b, Currency* c, Currency* d, Currency* e);

	//Functions

	//Method to get the amount of types of currency
	int getCurrencyNumber();

	//Method to remove all currency
	void removeAll();

	//Method to remove a specific currency
	void removeCurrency(const int nIndex);

	//Method to add a currency
	void addCurrency(int index, Currency* c);

	//Method to print the total value
	void printTotal();

	//Method to determine whether the wallet is empty
	bool isEmpty();

	//Method to see if the wallet contents that type of currency
	bool containsCurrency(Currency c);

	//Overloaded operator
	Currency* operator[] (const int nIndex);
};
#endif