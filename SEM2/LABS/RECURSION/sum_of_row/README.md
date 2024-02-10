# 1) Задание
**Рекурсия** 

Лабораторная работа. Вариант 6
Посчитать cумму элементов ряда.

<image src ="var6.png">

# 2) Код программы

```cpp
#include <iostream>
#define _USE_MATH_DEFINES
using namespace std;
double pi = atan(1) * 4;
int tp = 1;
double factorial(int a)
{
	int k = 1;
	for (int i = 1; i <= a; i++)
	{
		k *= i;
	}
	return k;
}
double foo(int a, int n, int x)
{
	if (a == n+1)
	{
		return 0;
	}
	double el = (cos(a * ( pi / 4)) / factorial(a)) * pow(x, a) + foo(a+1, n, x);
	return el;
}
int main()
{
	int a = 0;
	int n, x;
	cin >> n >> x;
	cout << foo(a, n, x) << endl;
	return 0;
}
```

# 3) Блок схема
coming soon
  
# 4) Тесты
<image src ="test1_SoR.png">

<image src ="test2_SoR.png">
