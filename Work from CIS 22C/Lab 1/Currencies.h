/////////////////////////////////////////////////////////////////////////////////////////////
//Name: Steve Tu
//Date: 1/23/17
//Class: CIS 22C
//Teacher: Goel
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CURRENCIES_H
#define CURRENCIES_H
#include <iostream>
#include <string>
#include <sstream>
#include "Wallet.h"

using namespace std;

class Currencies : public Wallet
{
protected:
	string wholeName;
	string partName;
	int wholeValue;
	int partValue;
	int pos;
public:
	Currencies(); ////////////////////////default constructor setting everything to default values when a currency is created.
	Currencies(const Currencies &c); ////copy constructor
	~Currencies(); //////////////////////destructor
	void setwholeName(string wName);
	void setpartName(string pName);
	void setwholeValue(int wValue);
	void setpartValue(int pValue);
	void setpos(int number);
	string getwholeName(); 
	string getpartName();
	int getwholeValue();
	int getpartValue(); 
	void Checkfor100();   /////////Checks if the partValue is over 100 and changes it and the wholeValue.
	void CheckforNegative(); //////////Checks if you remove an amount greater than the wholeValue and/or the partValue and adjusts them.
	friend Currencies operator +(Currencies &currency, int number); /////////////operator overloading for +, -, =, <<, and >>
	friend Currencies operator -(Currencies &currency, int number);
	Currencies operator =(const Currencies &currency);
	friend ostream &operator <<(ostream &result, vector <Wallet *> myWallet);
	friend istream &operator >>(istream &input, vector <Wallet *> myWallet);
};

inline ostream &operator <<(ostream &result, vector <Wallet *> myWallet) //I will get LNK2005 error if I leave the ostream and istream here in .h... I fixed it by adding inline next to their names or moving the definitions to the cpp file.
{
	cout << "-----------------------------------------------------\n";
	cout << "\t\tStatus of Wallet\n";
	cout << "-----------------------------------------------------\n";
	for (int i = 0; i < myWallet.size(); i++) ////////////////loop to print out all the individual currencies.
	{
		result << "\n" << i + 1 << ". " << myWallet[i]->getwholeName() << " and " << myWallet[i]->getpartName() << ": ";
		result << myWallet[i]->getwholeValue() << "." << myWallet[i]->getpartValue();
	}
	cout << "\n";
	return result;
}

inline istream &operator >>(istream &input, vector <Wallet *> myWallet)
{
	string number = "";
	input >> number; //whatever number is inputted is to be initialized as a string to parse out the whole value and the part value.
	size_t pos = number.find(".");
	string sub = number.substr(0, pos);
	string sub2 = number.substr(pos + 1);
	int whole = 0;
	unsigned int part = 0;
	stringstream convert(sub);
	convert >> whole;
	stringstream convert2(sub2);
	convert2 >> part;
	int x = myWallet[pos]->getwholeValue() + whole;
	int y = myWallet[pos]->getpartValue() + part;
	myWallet[pos]->setwholeValue(x);
	myWallet[pos]->setpartValue(y);
	myWallet[pos]->Checkfor100();
	return input;
}

#endif