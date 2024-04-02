#include "Rati.h"
Rati::Rati(void) :Pair()
{
	chi = fir;
	zna = sec;
}
Rati::~Rati(void) {}
Rati::Rati(int a, int b) :Pair(a, b)
{
	chi = a;
	zna = b;
}
Rati::Rati(const Rati& l)
{
	zna = l.zna;
	chi = l.chi;
}
Rati& Rati::operator=(const Rati& l)
{
	if (&l == this)
		return *this;
	chi = l.chi;
	zna = l.zna;
	return *this;
}
istream& operator>>(istream& in, Rati& r)
{
	cout << "chislitel: "; in >> r.chi;
	cout << "znamenatel: "; in >> r.zna;
	return in;
}
ostream& operator<<(ostream& out, const  Rati& r)
{
	out << "drob': " << r.chi << " / " << r.zna << endl;
	return out;
}
Rati Rati::operator+(const Rati& r)
{
	Rati tmp;
	tmp.zna = zna * r.zna;
	tmp.chi = chi * r.zna + r.chi * zna;
	return tmp;
}
Rati Rati::operator*(const Rati& r)
{
	Rati tmp;
	tmp.zna = zna * r.zna;
	tmp.chi = chi * r.chi;
	return tmp;
}
void Rati::show()
{
	cout << "\nchislitel = " << chi;
	cout << "\nznamenatel = " << zna;
	cout << "\n";
}