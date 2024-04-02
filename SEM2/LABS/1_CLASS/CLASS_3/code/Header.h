#pragma once
#include <iostream>
using namespace std;
class money
{
private:
	long rub;
	int kop;
public:
	money() { rub = 0, kop = 0; }
	money(long r, int k) { rub = r, kop = k; }
	money(const money& t) { rub = t.rub, kop = t.kop; }
	~money() {}
	long get_rub() { return rub; }
	int get_kop() { return kop; }
	void set_rub(long n_rub) { rub = n_rub; }
	void set_rub(int n_kop) { kop = n_kop; }
	money& operator=(const money&);
	money operator*(float m);
	float operator/(const money&);
	money operator/(float m);
	friend istream& operator>>(istream& in, money& t);
	friend ostream& operator<<(ostream& out, const money& t);
};
