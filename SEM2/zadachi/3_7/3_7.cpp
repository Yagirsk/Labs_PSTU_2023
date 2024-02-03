#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	const int d = 100;
	int a[d];
	int n, max, min;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;
	max = min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	cout << "Максимальный элемент: " << max << endl;
	cout << "Минимальный элемент: " << min << endl;
	return 0;
}
