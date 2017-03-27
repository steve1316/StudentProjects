/** @file Dollar.h */
#ifndef DOLLAR_H
#define DOLLAR_H

#include <iostream>
#include <string>
#include "Currency.h"

using namespace std;

// Declaration for the class Dollar
class Dollar: public Currency
{
public:
	//Constructors and destructor
	Dollar();
	Dollar(double amount);
	Dollar(int w, int f);
	~Dollar();

	//Overloaded operators
	friend Dollar operator+(const Dollar &g1, const Dollar &g2);
	friend Dollar operator-(const Dollar &g1, const Dollar &g2);
	friend ostream& operator<< (ostream &out, Dollar &g);
	friend istream& operator>> (istream &in, Dollar &g);
};
#endif