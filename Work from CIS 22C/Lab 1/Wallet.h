/////////////////////////////////////////////////////////////////////////////////////////////
//Name: Steve Tu
//Date: 1/23/17
//Class: CIS 22C
//Teacher: Goel
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef WALLET_H
#define WALLET_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Wallet
{
public:
	Wallet(); ///////////default constructor setting everything to default values when this object is created.
	virtual ~Wallet(); //destructor to be used by both base and derived classes.
	bool CheckCurrencyExists(vector <Wallet *> w, string name); //check if currency exists. Returns the TRUE OR FALSE BOOL if it exists or not.
	void removeCurrency(vector <Wallet *> myWallet, int i);    //Removes a specified currency from the wallet.
	//////////////////////////////////////////////////Examples of Polymorphism below for the derived class of Currencies to use for each individual currency in the wallet.
	virtual void setwholeName(string wName) = 0; /////All are pure virtual functions for the derived Currencies objects..
	virtual void setpartName(string pName) = 0;
	virtual void setwholeValue(int wValue) = 0;
	virtual void setpartValue(int pValue) = 0;
	virtual void setpos(int number) = 0;
	virtual string getwholeName() = 0;
	virtual string getpartName() = 0;
	virtual int getwholeValue() = 0;
	virtual int getpartValue() = 0;
	virtual void Checkfor100() = 0; 
	virtual void CheckforNegative() = 0; 
};

#endif