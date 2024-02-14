# 1) Задание
**Строковый ввод-вывод** 

Лабораторная работа №9, вариант 6
1. Создать текстовый файл F1 не менее, чем из 10 строк и
записать в него информацию
2. Скопировать из файла F1 в файл F2 строки, начиная с N
до K.
3. Подсчитать количество согласных букв в файле F2.


# 2) Код программы

```cpp
﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char SOGLalphabet[20] = { 'q', 'w', 'r', 't', 'p', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
int chekSog(string str) 
{
    int sogSTR = 0;
    for (int i = 0; i < str.length(); i++) 
    {
        char tmps = tolower(str[i]);
        for (int i = 0; i < 20; i++)
        {
            if (tmps == SOGLalphabet[i])
            {
                sogSTR++;
            }
        }
    }
    return sogSTR;
}
int main() 
{
    setlocale(LC_ALL, "ru_RU");
    ifstream f1("F1.txt");
    ofstream f2("F2.txt");
    if (!f1.is_open() || !f2.is_open())
    {
        cout << "Ошибка при открытии одного из файлов" << endl;
    }
    int N, K;
    cout << "Введите N и K: ";
    cin >> N >> K;

    string tmp;
    int tmpNum = 1;
    while (getline(f1, tmp))
    {
        if (tmpNum >= N && tmpNum <= K) 
        {
            f2 << tmp << endl;
        }
        tmpNum++;
    }
    f1.close();
    f2.close();

    ifstream f3("F2.txt");
    if (!f3.is_open()) 
    {
        cout << "Ошибка при открытии файла F2" << endl;
    }
    string tmp2;
    int sogKolv = 0;
    while (getline(f3, tmp2)) 
    {
        sogKolv += chekSog(tmp2);
    }
    f3.close();

    cout << "Количество согласных в файле F2 " << sogKolv << endl;
    return 0;
}
```

# 3) Блок схемы
функция main

<image src ="lab9_main.drawio.png">

Функция chekSog

<image src ="lab9_chek.drawio.png">

# 4) Тесты
<image src ="test1_lab5.png">
