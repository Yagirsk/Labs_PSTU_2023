#include "Pair.h"
#pragma once
Pair::Pair(void)
{
	fir = sec = 0;
}
Pair::~Pair(void) {}
Pair::Pair(int a, int b)
{
	fir = a;
	sec = b;
}
Pair::Pair(const Pair& pair)
{
	fir = pair.fir;
	sec = pair.sec;
}
void Pair::set_f(int a)
{
	fir = a;
}
void Pair::set_s(int b)
{
	fir = b;
}
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)
		return *this;
	fir = p.fir;
	sec = p.sec;
	return *this;
}
istream& operator>>(istream& in, Pair& p)
{
	cout << "first: "; in >> p.fir;
	cout << "second: "; in >> p.sec;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p)
{
	out << "\nfirst = " << p.fir;
	out << "\nsecond = " << p.sec;
	out << "\n";
	return out;
}
Pair Pair::operator*(const Pair& p)
{
	Pair tmp;
	tmp.fir = fir * p.fir;
	tmp.sec = sec * p.sec;
	return tmp;
}
Pair Pair::operator-(const Pair& p)
{
	Pair tmp;
	tmp.fir = fir - sec;
	tmp.sec = p.fir - p.sec;
	return tmp;
}
bool Pair::operator==(const Pair& p)
{
	bool tmp = 1;
	if (fir != p.fir) { tmp = 0; }
	if (sec != p.sec) { tmp = 0; }
	return tmp;
}