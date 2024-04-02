#pragma once
#include <iostream>
using namespace std;
class Pair
{

public:
	Pair(void);

	virtual ~Pair(void);
	Pair(int, int);
	Pair(const Pair&);

	int get_f() { return fir; }
	int get_s() { return sec; }
	void set_f(int);
	void set_s(int);

	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);

	Pair operator*(const Pair&);
	Pair operator-(const Pair&);
	bool operator==(const Pair&);

protected:
	int fir;
	int sec;
};

