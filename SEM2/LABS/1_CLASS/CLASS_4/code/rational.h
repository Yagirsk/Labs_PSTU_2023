#pragma once
#include "Pair.h"
using namespace std;
class rational :
    public Pair
{
public:
    rational(void);
    ~rational(void);

    rational(int, int);
    rational(const rational&);
    rational& operator=(const rational&);
    rational operator+(const rational&);
    rational operator*(const rational& r);

    friend istream& operator>>(istream& in, rational& r);
    friend ostream& operator<<(ostream& out, const  rational& r);
protected:
    int chi;
    int zna;
};

