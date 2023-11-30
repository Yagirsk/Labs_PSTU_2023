#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	bool t = 0;
	bool p = 1;
	int w, b;
	cin >> b;
	w = b;
	while (t != 1)
	{
		int a;
		cin >> a;
		if (a == 0)
		{
			t = 1;
		}
		else if (a < w)
		{
			p = 0;
		}
		w = a;
	}
	if (p == 1)
	{
		cout << "числа в возрастающей последовательности";
	}
	else
	{
		cout << "числа в не возрастающей последовательности";
	}
	return 0;
}