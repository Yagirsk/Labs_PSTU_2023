# 1) Задание
**Строки** 

Лабораторная работа №6, вариант 6
Преобразовать строку таким образом, чтобы сначала в ней
были напечатаны только буквы, а потом только цифры, не
меняя порядка следования символов в строке.

# 2) Код программы

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, str, tmp;
	int k = 0;
	getline(cin, s);
	int d = s.length();
	for (int i = 0; i < d; i++)
	{
		if (s[i] == '0' or s[i] == '1' or s[i] == '2' or s[i] == '3' or s[i] == '4' or s[i] == '5' or s[i] == '6' or s[i] == '7' or s[i] == '8' or s[i] == '9')
		{
			str += s[i];
			for (int j = i; j < d - 1; j++)
			{
				s[j] = s[j + 1];
			}
			i--;
			d--;
		}
	}
	string st = s.substr(0, d);
	st += str;
	cout << st;
	return 0;
}
```

# 3) Блок схема
<image src ="lab6s.drawio.png">

# 4) Тесты
<image src ="lab6_test1.png">

<image src ="lab6_test2.png">

<image src ="lab6_test3.png">
