#include <iostream>
#include "Pair.h"
#include "Object.h"
#include "Rati.h"
#include "Vector.h"
using namespace std;
int main()
{
	Pair a;
	cin >> a;
	cout <<"a = " << a << endl;
	Pair b(1, 3);
	cout << "b = " << b << endl;

	cout << "a = ";
	Object* p = &a;
	p->show();
	cout << endl;

	Pair d;
	Pair c;
	c = a * b;
	cout << "c = a * b = " << c << "\n";
	d = b - a;
	cout << "d = b - a = " << d << endl;

	Rati r;
	cin >> r;
	cout << r << endl;
	p = &r;
	p->show();
	cout << "\n\n";

	Vector v(5);
	Pair e;
	cin >> e;
	Rati R;
	cin >> R;
	Object* eo = &e;
	v.add(eo);
	eo = &R;
	v.add(eo);
	cout << "Vector: \n" << v;
}