/** @file Currency.cpp */
#include "Currency.h"
#include <iostream>

using namespace std;

Currency::Currency()
{
	name = "Currency";
	whole = 0;
	fract = 0;
	fractname = "Currency";
	code = "CUR";
}

Currency::~Currency()
{
}

string Currency::getName() const
{
	return name;
}

int Currency::getWhole() const
{
	return whole;
}

int Currency::getFract() const
{
	return fract;
}

string Currency::getFractName() const
{
	return fractname;
}

double Currency::getTotal() const
{
	return whole + fract / 100.0;
}

string Currency::getCode() const
{
	return code;
}

void Currency::addAmount(double amount)
{
	whole += static_cast<int>(amount);
	fract += static_cast<int>(amount * 100) % 100;
	if (fract >= 100)
	{
		whole++;
		fract = fract % 100;
	}

	if (fract < 0)
	{
		whole--;
		fract += 100;
	}
}


void Currency::setName(string n)
{
	name = n;
}

void Currency::setWhole(int w)
{
	whole = w;
}

void Currency::setFract(int f)
{
	fract = f;
}

void Currency::setFractName(string fn)
{
	fractname = fn;
}

void Currency::setTotal(double a)
{
	whole = static_cast<int>(a);
	fract = static_cast<int>(a * 100) % 100;
}

void Currency::setCode(string c)
{
	code = c;
}