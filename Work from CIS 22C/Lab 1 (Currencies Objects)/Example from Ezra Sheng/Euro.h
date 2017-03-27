/** @file Euro.h */
#ifndef EURO_H
#define EURO_H

#include <iostream>
#include <string>
#include "Currency.h"

using namespace std;

// Declaration for the class Euro
class Euro : public Currency
{
public:
	//Constructors and destructor
	Euro();
	Euro(double amount);
	Euro(int w, int f);
	~Euro();

	//Overloaded operators
	friend Euro operator+(const Euro &g1, const Euro &g2);
	friend Euro operator-(const Euro &g1, const Euro &g2);
	friend ostream& operator<< (ostream &out, Euro &g);
	friend istream& operator>> (istream &in, Euro &g);
};
#endif