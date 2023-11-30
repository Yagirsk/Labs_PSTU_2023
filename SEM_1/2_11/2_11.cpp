#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	int n;
	cin >> n;
	bool t = 0;
	bool f = 0;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (a > 0 and t == 0)
		{
			f = 1;
			t = 1;
		}
		if (a < 0 and t == 0)
		{
			f = 0;
			t = 1;
		}
	}
	if (t == 1)
	{
		if (f == 0)
		{
			cout << "отрицательное";
		}
		else
		{
			cout << "положительное";
		}
	}
	else
	{
		cout << "все нули";
	}
	return 0;
}