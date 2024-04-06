#include <iostream>
#include "Mnoz.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	Mnoz mnozvo(5);
	cout << mnozvo << endl;
	cin >> mnozvo;
	cout << mnozvo << endl;
	mnozvo[1] = 333;
	cout << mnozvo << endl;

	Mnoz mnozo(10);
	cout << mnozo << endl;
	mnozo = mnozvo;
	cout << mnozo << endl;
	cin >> mnozo;
	Mnoz tmp = mnozvo * mnozo;
	cout << tmp << endl;
	cout << "Длинна множества mnozvo " << mnozvo();

	cout << *(mnozvo.first()) << endl;
	Iterator i = mnozvo.first();
	++i;
	cout << *i << endl;
	for (i = mnozvo.first(); i != mnozvo.last(); ++i)
	{
		cout << *i << " ";
	}

}