#include <iostream>
#include <string>
#include "Header.h"
#include <sstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	string end_if;
	cout << "Введите 'Panzerselbstfahrlafette' если хотите прекратить выполнение работы программы: ";
	cin >> end_if;
	if (end_if == "Panzerselbstfahrlafette")
	{
		return 0;
	}


	linear_ur urav;
	urav.init();
	urav.read();
	if (urav.r == 1)
	{
		urav.show();

		cout << "Введите x: ";
		string x_r;
		cin >> x_r;
		if (urav.isFloat(x_r))
		{
			float x_x = stof(x_r);
			urav.function(x_x);
		}
		else { cout << "Некорректное значение x\n"; }

	}
	else { cout << "Некорректное значение одной или обеих переменных\n"; }


	system("pause");
	main();
}