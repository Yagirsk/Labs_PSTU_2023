# 1) Задание
**Динамические массивы** 

Лабораторная работа №10, вариант 6
Сформировать двумерный массив. Удалить из него строку с
заданным номером.

# 2) Код программы

```cpp
#include <iostream>
using namespace std;
int main()
{
	const int n = 100;
	int a[n];
	int d, k;
	cin >> d;
	bool t = 0;
	for (int i = 0; i < d; i++)
	{
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	cin >> k;
	for (int i = k - 1; i < d - 1; i++)
	{
		a[i] = a[i + 1];
	}
	d--;
	int j = 0;
	while (t == 0)
	{
		if (a[j] % 2 == 0)
		{
			for (int i = d; i > j+1; i--)
			{
				a[i] = a[i-1];
			}
			t = 1;
			a[j+1] = a[j] + 2;
		}
		j++;
	}
	d++;
	for (int i = 0; i < d; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
```

# 3) Блок схема

<image src ="lab10.drawio.png">

# 4) Тесты

<image src ="test1_lab10.png">

<image src ="test2_lab10.png">
