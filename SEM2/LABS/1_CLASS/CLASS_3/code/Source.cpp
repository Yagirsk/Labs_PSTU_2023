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
	float tmp_1 = rub * 100 + kop;
	float tmp_2 = m.rub * 100 + m.kop;
	float p = tmp_1 / tmp_2;
	return p;
}
money money::operator/(float m)
{
	float tmp_1 = rub * 100 + kop;
	money p;
	tmp_1 /= m;
	int t = tmp_1;
	p.rub = t / 100;
	p.kop = t % 100;
	return p;
}
istream& custom_input(istream& in, money& m, const char* name)
{
	int tmp;
	cout << "Введите рубли для переменной " << name << ": "; in >> m.rub;
	cout << "Введите копейки для переменной " << name << ": "; in >> tmp;
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
