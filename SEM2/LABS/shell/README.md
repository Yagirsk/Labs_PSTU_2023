# 1) Задание 

Отсортировать массив сортировкой Шелла

# 2) Код программы

```cpp
﻿#include <iostream>
using namespace std;
const int Totenkopf = 25;
void yana(int arr[])
{
    for (int i = 0; i < Totenkopf; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void shellSort(int arr[])
{
    for (int h = Totenkopf / 2; h > 0; h /= 2)
    {
        for (int i = h; i < Totenkopf; i++)
        {
            int tmp = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h)
            {
                arr[j] = arr[j - h];
            }
            arr[j] = tmp;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    int rik[Totenkopf];
    for (int i = 0; i < Totenkopf; i++) { rik[i] = rand() % 10; }
    cout << "Исходный массив\n";
    yana(rik);
    shellSort(rik);
    cout << "Отсортированныйй массив\n";
    yana(rik);
}
```

# 3) Блок схема

Функция main

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/shell/images/shell_main.drawio.png">

Функция shellSort

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/shell/images/shell_2sort.drawio.png">

Функция yana

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/shell/images/shell_yana.drawio.png">



# 4) Тесты

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/shell/images/изображение_2024-03-24_033443519.png">

