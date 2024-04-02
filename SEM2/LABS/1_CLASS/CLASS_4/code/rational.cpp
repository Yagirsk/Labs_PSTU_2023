#include "rational.h"
rational::rational(void) :Pair()
{
	chi = fir;
	zna = sec;
}
rational::~rational(void) {}
rational::rational(int a, int b) :Pair(a, b)
{
	chi = a;
	zna = b;
}
rational::rational(const rational& l)
{
	zna = l.zna;
	chi = l.chi;
}
rational& rational::operator=(const rational& l)
{
	if (&l == this)
		return *this;
	chi = l.chi;
	zna = l.zna;
	return *this;
}
istream& operator>>(istream& in, rational& r)
{
	cout << "chislitel: "; in >> r.chi;
	cout << "znamenatel: "; in >> r.zna;
	return in;
}
ostream& operator<<(ostream& out, const  rational& r)
{
	out << "drob': " << r.chi << " / " << r.zna << endl;
	return out;
}
rational rational::operator+(const rational& r)
{
	rational tmp;
	tmp.zna = zna * r.zna;
	tmp.chi = chi * r.zna + r.chi * zna;
	return tmp;
}
rational rational::operator*(const rational& r)
{
	rational tmp;
	tmp.zna = zna * r.zna;
	tmp.chi = chi * r.chi;
	return tmp;
}