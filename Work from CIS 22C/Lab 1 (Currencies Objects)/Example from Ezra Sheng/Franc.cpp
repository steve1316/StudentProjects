/** @file Franc.cpp */
#include "Franc.h"
#include <iostream>

using namespace std;

Franc::Franc()
{
	setName("franc");
	setWhole(0);
	setFract(0);
	setFractName("centime");
	setCode("CHF");
}

Franc::Franc(double amount)
{
	setWhole(static_cast<int>(amount));
	setFract(static_cast<int>(amount * 100) % 100);
	setFractName("centime");
	setCode("CHF");
	setName("franc");
}

Franc::Franc(int w, int f)
{
	setWhole(w);
	setFract(f);
	setFractName("centime");
	setCode("CHF");
	setName("franc");
}

Franc::~Franc()
{
}

Franc operator+(const Franc &g1, const Franc &g2)
{
	int f = g1.getFract() + g2.getFract();
	int w = g1.getWhole() + g2.getWhole();
	if (f >= 100)
	{
		w++;
		f = f % 100;
	}
	return Franc(f, w);
}

Franc operator-(const Franc &g1, const Franc &g2)
{
	int f = g1.getFract() - g2.getFract();
	int w = g1.getWhole() - g2.getWhole();
	if (f < 0)
	{
		w--;
		f += 100;
	}
	return Franc(f, w);
}

ostream& operator<< (ostream &out, Franc &g)
{
	cout << g.getCode() << " " << g.getTotal() << " " << g.getName() << 's' << endl;
	return out;
}

istream& operator>> (istream &in, Franc &g)
{
	double a;
	cin >> a;
	g.setWhole(static_cast<int>(a));
	g.setFract(static_cast<int>(a * 100) % 100);
	return in;
}