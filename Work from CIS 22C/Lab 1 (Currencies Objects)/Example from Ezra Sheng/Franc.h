/** @file Franc.h */
#ifndef FRANC_H
#define FRANC_H

#include <iostream>
#include <string>
#include "Currency.h"

using namespace std;

// Declaration for the class Franc
class Franc : public Currency
{
public:
	//Constructors and destructor
	Franc();
	Franc(double amount);
	Franc(int w, int f);
	~Franc();

	//Overloaded operators
	friend Franc operator+(const Franc &g1, const Franc &g2);
	friend Franc operator-(const Franc &g1, const Franc &g2);
	friend ostream& operator<< (ostream &out, Franc &g);
	friend istream& operator>> (istream &in, Franc &g);
};
#endif