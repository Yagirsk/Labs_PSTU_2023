# 1) Задание
**Функции и массивы** 

Элемент матрицы является седловой точкой, если он
является наименьшим в своей строке и наибольшим в своем
столбце (или наоборот: наибольшим в своей строке и
наименьшим в своем столбце).Для заданной матрицы
определить все седловые точки.

# 2) Код программы

```cpp
#include <iostream>
using namespace std;
void chek(int array[100][100], int af, int bf)
{
	for (int i = 0; i < af; i++)
	{
		int imax = array[i][0];
		int imin = array[i][0];
		int pmin = 0, pmax = 0;
		for (int j2 = 0; j2 < bf; j2++)
		{
			if (array[i][j2] > imax) { imax = array[i][j2]; pmax = j2; }
			if (array[i][j2] < imin) { imin = array[i][j2]; pmin = j2; }
		}
		bool flmax = 1, flmin = 1;
		for (int k = 0; k < af; k++)
		{
			if (k != i)
			{
				if (array[k][pmax] < array[i][pmax]) { flmax = 0; }
				if (array[k][pmin] > array[i][pmin]) { flmin = 0; }
			}
		}
		if (flmax == 1) { cout << "Седловая точка: " << array[i][pmax] << " На координатах " << i + 1 << ";" << pmax + 1 << endl; }
		if (flmin == 1) { cout << "Седловая точка: " << array[i][pmin] << " На координатах " << i + 1 << ";" << pmin + 1 << endl; }
	}
}

int main()
{
	setlocale(LC_ALL, "ru_RU");
	const int m = 100, n = 100;
	int a, b;
	cin >> a >> b;
	int arr[m][n];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr[i][j]=rand()%10;
		}
	}
	cout << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	chek(arr, a, b);
	return 0;
}
```

# 3) Блок схемы
функция main

<image src ="lab5p2.drawio.png">

Функция chek

<image src ="lab5p1.drawio.png">

# 4) Тесты
<image src ="test1_lab5.png">

<image src ="test2_lab5.png">

<image src ="test3_lab5.png">

