#include "Money.h"
using namespace std;
Money::Money(void)
{
	rub = kop = 0;
}
Money::Money(long a, int b)
{
	rub = a;
	kop = b;
}
Money::Money(const Money& r)
{
	rub = r.rub;
	kop = r.kop;
}
Money& Money::operator=(const Money& r)
{
	rub = r.rub;
	kop = r.kop;
	return *this;
}
ostream& operator<< (ostream&out, const Money&r)
{
	out << r.rub << ",";
	if (r.kop < 10) out << 0;
	out << r.kop;
	return out;
}
istream& operator>> (istream&in, Money&r)
{
	cout << "rub: "; in >> r.rub;
	cout << "kop: "; in >> r.kop;
	return in;
}
Money Money::operator*(const Money& m)
{
	Money r;
	if (rub == m.rub) r.rub = rub;
	if (kop == m.kop) r.kop = kop;
	return r;
}