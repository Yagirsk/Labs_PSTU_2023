#include <iostream>
#include "Header.h"
#define GET_VARIABLE_NAME(Variable) #Variable
using namespace std;
money& money::operator=(const money& t)
{
	if (&t == this) { return *this; }
	rub = t.rub;
	kop = t.kop;
	return *this;
}
money money::operator*(float m)
{
	int tmp_1 = rub * 100 + kop;
	tmp_1 *= m;
	money p;
	p.rub = tmp_1 / 100;
	p.kop = tmp_1 % 100;
	return p;
}
float money::operator/(const money& m)
{
	int tmp_1 = rub * 100 + kop;
	int tmp_2 = m.rub * 100 + m.kop;
	float p = tmp_1 / tmp_2;
	return p;
}
money money::operator/(float m)
{
	int tmp_1 = rub * 100 + kop;
	money p;
	tmp_1 / m;
	p.rub = tmp_1 / 100;
	p.kop = tmp_1 % 100;
	return p;
}
istream& operator >>(istream& in, money& m)
{
	int tmp;
	cout << "Ââåäèòå ðóáëè äëÿ ïåðåìåííîé " << varName << ": "; in >> m.rub;
	cout << "Ââåäèòå êîïåéêè äëÿ ïåðåìåííîé " << varName << ": "; in >> tmp;
	if (tmp >= 100)
	{
		m.kop = tmp % 100;
		m.rub += tmp / 100;
	}
	else
	{
		m.kop = tmp;
	}
	return in;
}
ostream& operator <<(ostream& out, const money& m)
{
	if (m.kop<10){ return (out << m.rub << ",0" << m.kop); }
	return (out << m.rub << "," << m.kop);
}
