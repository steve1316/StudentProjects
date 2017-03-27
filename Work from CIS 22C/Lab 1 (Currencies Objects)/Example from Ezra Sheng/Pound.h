/** @file Pound.h */
#ifndef POUND_H
#define POUND_H

#include <iostream>
#include <string>
#include "Currency.h"

using namespace std;

// Declaration for the class Pound
class Pound : public Currency
{
public:
	//Constructors and destructor
	Pound();
	Pound(double amount);
	Pound(int w, int f);
	~Pound();

	//Overloaded operators
	friend Pound operator+(const Pound &g1, const Pound &g2);
	friend Pound operator-(const Pound &g1, const Pound &g2);
	friend ostream& operator<< (ostream &out, Pound &g);
	friend istream& operator>> (istream &in, Pound &g);
};
#endif