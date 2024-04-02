#include <iostream>
#include "Pair.h"
#include "rational.h"
using namespace std;
int main()
{
	Pair a;
	cin >> a;
	cout << a;
	Pair b(1, 3);
	cout << b;

	Pair d;
	Pair c;
	c = a * b;
	cout << "c = a * b = " << c;
	d = b - a;
	cout << "d = b - a = " << d;

	rational ab;
	cin >> ab;
	cout << "ab =\n" << ab;

	rational abc(2, 5);
	cout << "abc =\n" << abc;

	rational abcd = ab + abc;
	cout << "abcd = ab + abc =\n" << abcd;

	ab = abcd * abc;
	cout << "ab = abcd * abc =\n" << ab;
}