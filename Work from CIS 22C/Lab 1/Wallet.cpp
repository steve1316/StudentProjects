/////////////////////////////////////////////////////////////////////////////////////////////
//Name: Steve Tu
//Date: 1/23/17
//Class: CIS 22C
//Teacher: Goel
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Wallet.h"

Wallet::Wallet() ////////Default constructor
{
}

Wallet::~Wallet() /////////Virtual destructor for the derived Currencies.
{
}

bool Wallet::CheckCurrencyExists(vector <Wallet *> myWallet, string name)
{
	for (int counter = 0; counter < myWallet.size(); counter++)
	{ ///////Loops through each element and checks if the given names already exists.
		string x = myWallet[counter]->getwholeName();
		string y = myWallet[counter]->getpartName();
		if (x == name) //////////wholeName already exists.
		{
			return true;
		}
		else if (y == name) /////////partName already exists.
		{
			return true;
		}
	}
	return false; /////Doesn't exist.
}

void Wallet::removeCurrency(vector <Wallet *> myWallet, int i)
{
	delete myWallet[i]; ///////////Removes the specified currency in the vector.
}
