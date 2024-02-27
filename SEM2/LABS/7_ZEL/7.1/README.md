# 1) Задание
**Перегрузка функций** 

Лабораторная работа №7.1, вариант 6

Написать перегруженные функции и основную программу,
которая их вызывает.

1) для вычитания вещественных чисел;
2) для вычитания комплексных чисел.

# 2) Код программы

```cpp
﻿#include <iostream>
using namespace std;
struct Complex 
{
    double real;
    double komp;
};
Complex subtract(Complex knum1, Complex knum2) 
{
    Complex result;
    result.real = knum1.real - knum2.real;
    result.komp = knum1.komp - knum2.komp;
    return result;
}
double subtract(double rnum1, double rnum2)
{
    double result;
    result = rnum1 - rnum2;
    return result;
}
int main() 
{
    setlocale(LC_ALL, "ru_RU");
    int rnum1, rnum2, rresult;
    Complex knum1, knum2, kresult;

    cin >> rnum1;
    cin >> rnum2;
    rresult = subtract(rnum1, rnum2);
    cout << "Результат: " << rresult << endl;

    cin >> knum1.real >> knum1.komp;
    cin >> knum2.real >> knum2.komp;
    kresult = subtract(knum1, knum2);
    cout << "Результат: " << kresult.real << " + " << kresult.komp << "i" << endl;
    return 0;
}
```

# 3) Блок схемы
функция main

<image src ="lab7.1_main.drawio.png">

Функция subtact (complex)

<image src ="lab7.1_subtr2.drawio.png">

Функция subtact (double)

<image src ="lab7.1_subtr1.drawio.png">

Структура Complex

<image src ="lab7.1_struct.drawio.png">

# 4) Тесты
<image src ="pereg_test1.png">

<image src ="pereg_test2.png">
