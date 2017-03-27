/** @file Wallet.cpp */
#include "Wallet.h"
#include <iostream>

using namespace std;

Wallet::Wallet()
{
	cNumber = 0;
	for (int x = 0; x < 5; x++)
	{
		cList[x] = nullptr;
	}
}

Wallet::Wallet(Currency* a, Currency* b, Currency* c, Currency* d, Currency* e)
{
	cList[0] = a;
	cList[1] = b;
	cList[3] = c;
	cList[4] = d;
	cList[5] = e;
}

int Wallet::getCurrencyNumber()
{
	return cNumber;
}

void Wallet::removeAll()
{
	cout << "Removed ";
	printTotal();
	for (int x = 0; x < 5; x++)
		cList[x] = nullptr;
	cNumber = 0;
}
void Wallet::removeCurrency(const int nIndex)
{
	if (cList[nIndex] != nullptr)
		cNumber--;;
	cList[nIndex] = nullptr;
}

void Wallet::addCurrency(int index, Currency* c)
{
	if (cList[index] == nullptr)
	{
		cNumber++;
		cList[index] = c;
	}
	else
		cout << "There is already a currency here" << endl;
}

void Wallet::printTotal()
{
	cout << "Total Value:" << endl;
	for (int x = 0; x < 5; x++)
	{
		if (cList[x] != nullptr)
			cout << cList[x]->getCode() << " " << cList[x]->getTotal() << " " << cList[x]->getName() << 's' << endl;
	}
}

bool Wallet::isEmpty()
{
	bool allnull = true;
	for (int x = 0; x < 5; x++)
	{
		if (cList[x] != nullptr)
			allnull = false;
	}
	return allnull;
}

bool Wallet::containsCurrency(Currency c)
{
	bool contains = false;
	for (int x = 0; x < 5; x++)
	{
		if (cList[x] != nullptr && c.getCode() == cList[x]->getCode())
			contains = true;
	}
	return contains;
}

Currency* Wallet::operator[] (const int nIndex)
{
	return cList[nIndex];
}