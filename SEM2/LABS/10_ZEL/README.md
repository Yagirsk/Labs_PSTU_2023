# 1) Задание
**Динамические массивы** 

Лабораторная работа №10, вариант 6
Сформировать двумерный массив. Удалить из него строку с
заданным номером.

# 2) Код программы

```cpp
﻿#include <iostream>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "ru_RU");
    int strok, stolb;
    cout << "Введите количество строк и столбцов соответственно: ";
    cin >> strok >> stolb;
    int** matrix = new int*[strok];
    for (int i = 0; i < strok; i++)
    {
        matrix[i] = new int[stolb];
        for (int j = 0; j < stolb; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < strok; i++) 
    {
        for (int j = 0; j < stolb; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int del;
    cout << "Введите номер строки для удаления: ";
    cin >> del;
    for (int i = del - 1; i < strok - 1; i++)
    {
        for (int j = 0; j < stolb; j++)
        {
            matrix[i][j] = matrix[i + 1][j];
        }
    }
    delete[] matrix[strok - 1];
    strok--;
    cout << "Итоговый массив:" << endl;
    for (int i = 0; i < strok; i++)
    {
        for (int j = 0; j < stolb; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < strok; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
```

# 3) Блок схема

<image src ="lab10.drawio.png">

# 4) Тесты

<image src ="test1_lab10.png">

<image src ="test2_lab10.png">
