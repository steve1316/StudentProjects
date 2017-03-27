/** @file Ruble.h */
#ifndef RUBLE_H
#define RUBLE_H

#include <iostream>
#include <string>
#include "Currency.h"

using namespace std;

// Declaration for the class Ruble
class Ruble : public Currency
{
public:
	//Constructors and destructor
	Ruble();
	Ruble(double amount);
	Ruble(int w, int f);
	~Ruble();

	//Overloaded operators
	friend Ruble operator+(const Ruble &g1, const Ruble &g2);
	friend Ruble operator-(const Ruble &g1, const Ruble &g2);
	friend ostream& operator<< (ostream &out, Ruble &g);
	friend istream& operator>> (istream &in, Ruble &g);
};
#endif