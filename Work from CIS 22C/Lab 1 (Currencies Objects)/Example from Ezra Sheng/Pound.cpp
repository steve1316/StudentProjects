//** @file Pound.cpp */
#include "Pound.h"
#include <iostream>

using namespace std;

Pound::Pound()
{
	setName("pound");
	setWhole(0);
	setFract(0);
	setFractName("pence");
	setCode("GBP");
}

Pound::Pound(double amount)
{
	setWhole(static_cast<int>(amount));
	setFract(static_cast<int>(amount * 100) % 100);
	setFractName("pence");
	setCode("GBP");
	setName("pound");
}

Pound::Pound(int w, int f)
{
	setWhole(w);
	setFract(f);
	setFractName("pence");
	setCode("GBP");
	setName("pound");
}

Pound::~Pound()
{
}

Pound operator+(const Pound &g1, const Pound &g2)
{
	int f = g1.getFract() + g2.getFract();
	int w = g1.getWhole() + g2.getWhole();
	if (f >= 100)
	{
		w++;
		f = f % 100;
	}
	return Pound(f, w);
}

Pound operator-(const Pound &g1, const Pound &g2)
{
	int f = g1.getFract() - g2.getFract();
	int w = g1.getWhole() - g2.getWhole();
	if (f < 0)
	{
		w--;
		f += 100;
	}
	return Pound(f, w);
}

ostream& operator<< (ostream &out, Pound &g)
{
	cout << g.getCode() << " " << g.getTotal() << " " << g.getName() << 's' << endl;
	return out;
}

istream& operator>> (istream &in, Pound &g)
{
	double a;
	cin >> a;
	g.setWhole(static_cast<int>(a));
	g.setFract(static_cast<int>(a * 100) % 100);
	return in;
}