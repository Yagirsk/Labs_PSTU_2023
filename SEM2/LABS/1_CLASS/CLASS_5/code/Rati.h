#pragma once
#include "Pair.h"
using namespace std;
class Rati :
    public Pair
{
public:
    Rati(void);
    ~Rati(void);

    void show();
    Rati(int, int);
    Rati(const Rati&);
    Rati& operator=(const Rati&);
    Rati operator+(const Rati&);
    Rati operator*(const Rati& r);

    friend istream& operator>>(istream& in, Rati& r);
    friend ostream& operator<<(ostream& out, const  Rati& r);
protected:
    int chi;
    int zna;
};

