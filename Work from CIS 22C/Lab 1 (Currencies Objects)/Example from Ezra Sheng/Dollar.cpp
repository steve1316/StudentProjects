/** @file Dollar.cpp */
#include "Dollar.h"
#include <iostream>

using namespace std;

Dollar::Dollar()
{
	setName("dollar");
	setWhole(0);
	setFract(0);
	setFractName("cent");
	setCode("USD");
}

Dollar::Dollar(double amount)
{
	setWhole(static_cast<int>(amount));
	setFract(static_cast<int>(amount * 100) % 100);
	setName("dollar");
	setFractName("cent");
	setCode("USD");
}

Dollar::Dollar(int w, int f)
{
	setWhole(w);
	setFract(f);
	setName("dollar");
	setFractName("cent");
	setCode("USD");
}

Dollar::~Dollar()
{
}

Dollar operator+(const Dollar &g1, const Dollar &g2)
{
	int f = g1.getFract() + g2.getFract();
	int w = g1.getWhole() + g2.getWhole();
	if (f >= 100)
	{
		w++;
		f = f % 100;
	}
	return Dollar(f, w);
}

Dollar operator-(const Dollar &g1, const Dollar &g2)
{
	int f = g1.getFract() - g2.getFract();
	int w = g1.getWhole() - g2.getWhole();
	if (f < 0)
	{
		w--;
		f += 100;
	}
	return Dollar(f, w);
}

ostream& operator<< (ostream &out, Dollar &g)
{
	cout << g.getCode() << " " << g.getTotal() << " " << g.getName() << 's' << endl;
	return out;
}

istream& operator>> (istream &in, Dollar &g)
{
	double a;
	cin >> a;
	g.setWhole(static_cast<int>(a));
	g.setFract(static_cast<int>(a * 100) % 100);
	return in;
}