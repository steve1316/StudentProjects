/////////////////////////////////////////////////////////////////////////////////////////////
//Name: Steve Tu
//Date: 1/23/17
//Class: CIS 22C
//Teacher: Goel
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Currencies.h"

Currencies::Currencies() //default constructor setting everything to default values when this object is created.
{
	wholeName = "null";
	partName = "null";
	wholeValue = 0;
	partValue = 0;
	pos = 0;
}

Currencies::Currencies(const Currencies &c) //copy constructor
{
	wholeValue = c.wholeValue;
	partName = c.partName;
	wholeValue = c.wholeValue;
	partValue = c.partValue;
	pos = c.pos;
}

Currencies::~Currencies() //destructor
{
}

void Currencies::setwholeName(string wName)
{
	wholeName = wName;
}

void Currencies::setpartName(string pName)
{
	partName = pName;
}

void Currencies::setwholeValue(int wValue)
{
	wholeValue = wValue;
}

void Currencies::setpartValue(int pValue)
{
	partValue = pValue;
}

void Currencies::setpos(int number)
{
	pos = number;
}

string Currencies::getwholeName()
{
	return wholeName;
}
string Currencies::getpartName()
{
	return partName;
}

int Currencies::getwholeValue()
{
	return wholeValue;
}

int Currencies::getpartValue()
{
	return partValue;
}

void Currencies::Checkfor100()
{
	if (partValue == 100) ////if partValue is 100, set it to zero and add one to wholeValue. 100 parts = 1 whole.
	{
		wholeValue += 1;
		partValue = 0;
	}
	else if (partValue > 100) ////if its greater than 100, subtract 100 from it and that will be partValue. wholeValue is incremented by one.
	{
		wholeValue += 1;
		partValue = partValue - 100;
	}
}

void Currencies::CheckforNegative()
{
	if (wholeValue < 0) //////////if wholeValue is negative, set it equal to zero.
	{
		wholeValue = 0;
	}
	else if (partValue < 0) //if partValue is negative....
	{
		wholeValue -= 1; /////... decrement wholeValue by one...
		if (abs(partValue) < 100) ////... and then subtract partValue from 100.
		{
			partValue = 100 - abs(partValue);
		}
		else if (abs(partValue) > 100) ////... or subtract 100 from partValue.
		{
			partValue = abs(partValue) - 100;
		}
	}
}

Currencies operator +(Currencies &currency, int number)
{
	int result = 0;
	int x = currency.getwholeValue();
	result = x + number;
	currency.setwholeValue(result);
	return(currency);
}

Currencies operator -(Currencies &currency, int number)
{
	int result = 0;
	int x = currency.getwholeValue();
	result = x - number;
	currency.setwholeValue(result);
	return(currency);
}

Currencies Currencies::operator =(const Currencies &currency)
{
	wholeValue = currency.wholeValue;
	partName = currency.partName;
	wholeValue = currency.wholeValue;
	partValue = currency.partValue;
	return *this;
}
