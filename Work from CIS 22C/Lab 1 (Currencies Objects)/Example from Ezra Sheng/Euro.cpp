/** @file Euro.cpp */
#include "Euro.h"
#include <iostream>

using namespace std;

Euro::Euro()
{
	setName("euro");
	setWhole(0);
	setFract(0);
	setFractName("cent");
	setCode("EUR");
}

Euro::Euro(double amount)
{
	setWhole(static_cast<int>(amount));
	setFract(static_cast<int>(amount * 100) % 100);
	setName("euro");
	setFractName("cent");
	setCode("EUR");
}

Euro::Euro(int w, int f)
{
	setWhole(w);
	setFract(f);
	setName("euro");
	setFractName("cent");
	setCode("EUR");
}

Euro::~Euro()
{

}

Euro operator+(const Euro &g1, const Euro &g2)
{
	int f = g1.getFract() + g2.getFract();
	int w = g1.getWhole() + g2.getWhole();
	if (f >= 100)
	{
		w++;
		f = f % 100;
	}
	return Euro(f, w);
}

Euro operator-(const Euro &g1, const Euro &g2)
{
	int f = g1.getFract() - g2.getFract();
	int w = g1.getWhole() - g2.getWhole();
	if (f < 0)
	{
		w--;
		f += 100;
	}
	return Euro(f, w);
}

ostream& operator<< (ostream &out, Euro &g)
{
	cout << g.getCode() << " " << g.getTotal() << " " << g.getName() << 's' << endl;
	return out;
}

istream& operator>> (istream &in, Euro &g)
{
	double a;
	cin >> a;
	g.setWhole(static_cast<int>(a));
	g.setFract(static_cast<int>(a * 100) % 100);
	return in;
}