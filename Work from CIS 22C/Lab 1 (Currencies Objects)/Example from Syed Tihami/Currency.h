#ifndef Currency_h
#define Currency_h

#include <string>
#include <iostream>

using namespace std;

class Currency {
private:
    int wholeValue;
    int fractionalValue;
    static int instances;
    //Private functions:
    void alignWholeFractional();
    int totalValue();
    
protected:
    string wholeName;
    string fractionalName;
    int fractionalInWhole;
    bool initialized;
    
public:
    //virtual void assignNames() = 0;
    Currency();
    Currency(int w, int f);
    Currency(const Currency &obj);
    virtual ~Currency();
    void setWholeValue(int w);
    void setFractionalValue(int f);
    void setValue(int w, int f = 0);
    void addValue (int w, int f = 0);
    void subtractValue(int w, int f = 0);
    static bool noInstances() { return instances == 0; }
    
    //Mutators:
    string getWholeName() { return wholeName; }
    string getFractName() { return fractionalName; }
    int getParts() { return fractionalInWhole; }
    int getWhole() { return wholeValue; }
    int getFractional() { return fractionalValue; }
    
    //Operator Overloads:
    friend Currency operator+(const Currency &a, const Currency &b);
    friend Currency operator-(const Currency &a, const Currency &b);
    friend ostream &operator<<(ostream &out, const Currency &a);
    friend istream &operator>>(istream &in, Currency &a);
    friend Currency operator-(const Currency &a);
    Currency operator-() const;
    Currency &operator+=(const Currency &a);
    Currency &operator-=(const Currency &a);
};

#endif /* Currency_h */
