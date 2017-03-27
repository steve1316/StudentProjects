/** @file Ruble.cpp */
#include "Ruble.h"
#include <iostream>

using namespace std;

Ruble::Ruble()
{
	setWhole(0);
	setFract(0);
	setName("ruble");
	setFractName("kopek");
	setCode("RUB");
}

Ruble::Ruble(double amount)
{
	setWhole(static_cast<int>(amount));
	setFract(static_cast<int>(amount * 100) % 100);
	setFractName("kopek");
	setCode("RUB");
	setName("ruble");
}

Ruble::Ruble(int w, int f)
{
	setWhole(w);
	setFract(f);
	setFractName("kopek");
	setCode("RUB");
	setName("ruble");
}

Ruble::~Ruble()
{
}

Ruble operator+(const Ruble &g1, const Ruble &g2)
{
	int f = g1.getFract() + g2.getFract();
	int w = g1.getWhole() + g2.getWhole();
	if (f >= 100)
	{
		w++;
		f = f % 100;
	}
	return Ruble(f, w);
}

Ruble operator-(const Ruble &g1, const Ruble &g2)
{
	int f = g1.getFract() - g2.getFract();
	int w = g1.getWhole() - g2.getWhole();
	if (f < 0)
	{
		w--;
		f += 100;
	}
	return Ruble(f, w);
}

ostream& operator<< (ostream &out, Ruble &g)
{
	cout << g.getCode() << " " << g.getTotal() << " " << g.getName() << 's' << endl;
	return out;
}

istream& operator>> (istream &in, Ruble &g)
{
	double a;
	cin >> a;
	g.setWhole(static_cast<int>(a));
	g.setFract(static_cast<int>(a * 100) % 100);
	return in;
}