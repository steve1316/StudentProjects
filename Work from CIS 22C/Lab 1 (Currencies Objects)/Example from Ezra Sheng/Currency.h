/** @file Currency.h */
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

using namespace std;

// Declaration for the class Currency
class Currency
{
private:
	//Attributes
	string name;
	int whole;
	int fract;
	string fractname;
	string code;

protected:

	void setName(string n);
	void setFractName(string fn);
	void setCode(string c);

public:
	//Constructor and destructor
	Currency();
	virtual ~Currency();

	//Getters
	string getName() const;
	int getWhole() const;
	int getFract() const;
	string getFractName() const;
	double getTotal() const;

	//Method to return the ISO 4217 code
	string getCode() const;

	//Setters
	void setWhole(int w);
	void setFract(int f);
	void setTotal(double a);

	void addAmount(double a);
};
#endif