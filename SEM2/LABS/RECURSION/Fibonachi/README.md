# 1) Задание
**Рекурсия** 

Посчитать числа Фибонначи до n-ого элемента.

# 2) Код программы

```cpp
﻿#include <iostream>
using namespace std;
int foo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return foo(n - 1) + foo(n - 2);
}
int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a = foo(i);
        cout << a << " ";
    }
    return 0;
}
```

# 3) Блок схема
<image src ="">

<image src ="test1_fib.png">

  
# 4) Тесты
<image src ="test1_fib.png">

<image src ="test2_fib.png">
