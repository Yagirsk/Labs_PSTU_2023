#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	const int d = 100;
	bool t = 1;
	int a[d];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
	cout << endl;
	for (int i = 0; i < d-1; i++)
	{
		if (a[i] >= a[i + 1])
		{
			t = 0;
		}
	}
	if (t==1)
	{
		cout << "Массив упорядочен по возрастанию" << endl;
	}
	else
	{
		cout << "Массив не упорядочен по возрастанию" << endl;
	}
	return 0;
}