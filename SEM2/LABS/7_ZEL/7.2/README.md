# 1) Задание
**Работа с одномерными массивами** 

Лабораторная работа №4, вариант 6
1) Сформировать одномерный массив целых чисел,
используя датчик случайных чисел.
2) Распечатать полученный массив.
3) Удалить элемент с заданным номером.
4) Добавить после первого четного элемента массива
элемент со значением M[ I-1 ]+2.
5) Распечатать полученный массив.
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
<image src ="lab4ss.drawio.png">

# 4) Тесты
<image src ="test1_lab4.png">

<image src ="test2_lab4.png">

<image src ="test3_lab4.png">
