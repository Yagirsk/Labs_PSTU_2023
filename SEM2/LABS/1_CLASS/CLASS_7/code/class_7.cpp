#include <iostream>
#include "Setn.h"
#include "Money.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	/*Setn<int> a(5, 0);
	cin >> a;
	cout << "a:" << a << endl;

	Setn<int> b(10, 0);
	cout << "b:" << b << endl;
	b = a;
	cout << "b:" << b << endl;

	cout << "Элемент 2: " << a[2];
	cout << "\nsize = " << b() << endl;
	Setn<int> s(5, 0); 
	cin >> b;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	s = a * b;
	cout << "s:" << s << endl;*/

	Money mon;
	cin >> mon;
	cout << mon << endl;
	Money mon1;
	cin >> mon1;
	cout << mon1 << endl;
	Money mon2;
	mon2 = mon * mon1;
	cout << mon2 << endl;

	Money t;
	cin >> t;
	cout << t << endl;
	Setn<Money>Ar(5, t);
	cin >> Ar;
	cout << Ar << endl;

	Setn<Money>B(10, t);
	cout << B << endl;
	B = Ar;
	cout << B << endl;
	cout << Ar[2] << endl;
	cout << "A size = " << Ar() << endl;

}