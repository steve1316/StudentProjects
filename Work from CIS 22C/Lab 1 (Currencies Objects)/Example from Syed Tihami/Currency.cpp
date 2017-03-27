#include "Currency.h"
#include <string>

using namespace std;

//**************************************************************
//Currency Class Default Consctructor                          *
//This constructor increments the instances                    *
//static variable and initializes some of its member variables *
//**************************************************************
Currency::Currency() : wholeValue(0), fractionalValue(0), wholeName(""), fractionalName(""), fractionalInWhole(1), initialized(false) {
    instances = instances + 1;
}

//*****************************************************
//Currency Class Overloaded Constructor               *
//This constructor sets up the Currency object        *
//*****************************************************
Currency::Currency(int w, int f) : wholeValue(0), fractionalValue(0), wholeName(""), fractionalName(""), fractionalInWhole(1), initialized(false) {
    instances = instances + 1;
    setValue(w, f);
}

//***********************************************************
//Currency Class Destructor                                 *
//The destructor decremenets the instances static variable  *
//***********************************************************
Currency::~Currency() {
    instances = instances - 1;
}

//***************************************
//Copy Constructor for Currency Class   *
//***************************************
Currency::Currency(const Currency &obj) {
    instances = instances + 1;
    wholeValue = obj.wholeValue;
    fractionalValue = obj.fractionalValue;
    wholeName = obj.wholeName;
    fractionalName = obj.fractionalName;
    fractionalInWhole = obj.fractionalInWhole;
    initialized = obj.initialized;
}

//*********************************************************
//Definition of function alignWholeFractional             *
//This function rolls over excess fractional quantities   *
//to whole quantities                                     *
//*********************************************************
void Currency::alignWholeFractional() {
    wholeValue += fractionalValue / fractionalInWhole;
    fractionalValue = fractionalValue % fractionalInWhole;
}

//********************************************************************************************
//Definition of function setWholeValue                                                       *
//This function validates and sets the value of the whole component of the Currency object   *
//********************************************************************************************
void Currency::setWholeValue(int w) {
    if (w > 0)
        wholeValue = w;
}

//*************************************************************************************************
//Definition of function setFractionalValue                                                       *
//This function validates and sets the value of the fractional component of the Currency object   *
//*************************************************************************************************
void Currency::setFractionalValue(int f) {
    if (f > 0)
        fractionalValue = f;
}

//********************************************************************************************
//Definition of function setValue                                                            *
//This function sets and aligns the values of the Currency object                            *
//********************************************************************************************
void Currency::setValue(int w, int f) {
    setWholeValue(w);
    setFractionalValue(f);
    alignWholeFractional();
}

//********************************************************************************************
//Definition of function addValue                                                            *
//This function allows the user to increase the value of the Currency object                 *
//********************************************************************************************
void Currency::addValue (int w, int f) {
    *this += Currency(w, f);
    alignWholeFractional();
}

//********************************************************************************************
//Definition of function subtractValue                                                       *
//This function allows the user to decrease the value of the Currency object                 *
//********************************************************************************************
void Currency::subtractValue(int w, int f) {
    *this -= Currency(w, f);
    alignWholeFractional();
}

//************************************************************************
//Definition of function totalValue                                      *
//This function is used by other member functions to ensure that the     *
//Currency object does not hold a negative value                         *
//************************************************************************
int Currency::totalValue() {
    return  wholeValue * fractionalInWhole + fractionalValue;
}

//*************************************************************************
//Overloading += operator  for use with two Currency objects              *
//*************************************************************************
Currency &Currency::operator+=(const Currency &a) {
    *this = *this + a;
    return *this;
}

//**************************************************************************
//Overloading -= operator for use with two Currency objects                *
//**************************************************************************
Currency &Currency::operator-=(const Currency &a) {
    *this = *this - a;
    return *this;
}

//***************************************************************************
//Overloading - (unary) operator for use with two Currency objects          *
//***************************************************************************
Currency Currency::operator-() const {
    Currency temp = *this;
    temp.wholeValue = -temp.wholeValue;
    temp.fractionalValue = -temp.fractionalValue;
    return temp;
}

//********************************************************************************************
//Overloading + operator for use with two Currency objects                                   *
//It adds the whole and fractional components of the given Currency objects,                 *
//then it calls the align method to fix whole/fractional parts                               *
//********************************************************************************************
Currency operator+(const Currency &a, const Currency &b) {
    if (a.wholeName != "" && b.wholeName !="" && a.wholeName != b.wholeName) throw "ERROR: Cannot add values of two different currencies";
    Currency temp = a;
    temp.wholeValue += b.wholeValue;
    temp.fractionalValue += b.fractionalValue;
    temp.alignWholeFractional();
    if (temp.totalValue() < 0) throw "ERROR: You have overdrawn the money in this currency";
    return temp;
}

//********************************************************************************************
//Overloading - (binary) operator for use with two Currency objects                          *
//It subtractss the whole and fractional components of the given Currency objects,           *
//then it calls the align method to fix whole/fractional parts                               *
//********************************************************************************************
Currency operator-(const Currency &a, const Currency &b) {
    if (a.wholeName != "" && b.wholeName !="" && a.wholeName != b.wholeName) throw "ERROR: Cannot add values of two different currencies";
    Currency temp = a;
    temp.wholeValue -= b.wholeValue;
    temp.fractionalValue -= b.fractionalValue;
    temp.alignWholeFractional();
    if (temp.totalValue() < 0) throw "ERROR: You have overdrawn the money in this currency";
    return temp;
}

//*********************************************************************************
//Overloading << operator for use with two Currency objects                       *
//*********************************************************************************
ostream &operator<<(ostream &out, const Currency &a) {
    out << a.wholeValue << ' ' << a.wholeName << "s and " << a.fractionalValue << ' ' << a.fractionalName << "s";
    return out;
}

//*********************************************************************************
//Overloading >> operator for use with two Currency objects                       *
//**********************************************************************************
istream &operator>>(istream &in, Currency &a) {
    in >> a.wholeValue >> a.fractionalValue;
    return in;
}
