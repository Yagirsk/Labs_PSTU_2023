# 1) Задание
**Двумерные массивы массивы** 

Заполнить двумерный массив: все элементы, которые выше 
главной диагонали = 0. Элементы главной диагонали и 
ниже главной диагонали, заполняются по возрастанию, 
начиная с 1. При этом каждая диагональ параллельная 
главной  состоит из одинаковых цифр.

# 2) Код программы

```cpp
#include <iostream>
using namespace std;
int main()
{
	const int m = 100;
	int a;
	cin >> a;
	int arr[m][m];
	int pp = 0;
	for (int i = 0; i < a; i++)
	{
		pp = 0;
		for (int j = 0; j < a; j++)
		{

			if (j < i) 
			{ 
				arr[j][i] = 0; 
			}
			if (j >= i) 
			{
				arr[j][i] = 1+pp;
				pp++;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
```

# 3) Блок схема
<image src ="lab2.drawio.png">
  
# 4) Тесты
<image src ="test1_lab2_TDA.png">

<image src ="test2_lab2_TDA.png">
