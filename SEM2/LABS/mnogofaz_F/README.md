# Лабораторная работа № 15.2 "Многофазная сортировка слиянием на три файла"

## Без варианта.

### Задание

Отсортировать массив произвольного размера с произвольным заполнением с использованием многофазной сортировки  на три файла.

## Блок-схема

![Блок схема функций](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_F/images/15.2_mergeSortedArrays.jpg)

![Блок схема функций](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_F/images/15.2_sliv.jpg)

![Блок схема функций](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_F/images/15.2_ultimateSliv.jpg)

![Блок схема main](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_F/images/15.2_main.jpg)

## Программа

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) // сливает два массива в третий
{
    vector<int> result;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            result.push_back(arr1[i]);
            ++i;
        }
        else
        {
            result.push_back(arr2[j]);
            ++j;
        }
    }
    while (i < arr1.size())
    {
        result.push_back(arr1[i]);
        ++i;
    }
    while (j < arr2.size())
    {
        result.push_back(arr2[j]);
        ++j;
    }
    return result;
}

void sliv(ifstream& f1, ifstream& f2, ofstream& f3, int stringKolVo) // сливает количество колво серий из первого и второго файла в третий, при том f2 маленький, строк там kolVo, f3 пустой, или запоненный ненужными числами
{
    string buf;
    for (int i = 0; i < stringKolVo; i++)
    {
        getline(f1, buf);
        vector<int> result = { 0 };
        bool negative = false;
        for (int i = 0; i < (int)buf.size() - 1; ++i)
        {
            if ((buf[i] == ' ') && negative)
            {
                result.back() *= -1;
                negative = false;
                result.push_back(0);
            }
            else if (buf[i] == ' ')
            {
                result.push_back(0);
            }
            else if (buf[i] == '-')
            {
                negative = true;
            }
            else
            {
                result.back() *= 10;
                result.back() += buf[i] - '0';
            }
        }
        if (negative) result.back() *= -1;

        negative = false;
        getline(f2, buf);
        if (buf.size() <= 1)
        {
            for (int i = 0; i < result.size(); i++)
            {
                f3 << result[i] << " ";
            }
        }
        else
        {
            vector<int> result2 = { 0 };
            for (int i = 0; i < (int)buf.size() - 1; ++i)
            {
                if ((buf[i] == ' ') && negative)
                {
                    result2.back() *= -1;
                    negative = false;
                    result2.push_back(0);
                }
                else if (buf[i] == ' ')
                {
                    result2.push_back(0);
                }
                else if (buf[i] == '-')
                {
                    negative = true;
                }
                else
                {
                    result2.back() *= 10;
                    result2.back() += buf[i] - '0';
                }
            }
            if (negative) result2.back() *= -1; // если последний элемент отрицательный и он уже не дождется пробела
            negative = false;
            vector<int> slito = mergeSortedArrays(result, result2);
            for (int i = 0; i < slito.size(); i++)
            {
                f3 << slito[i] << " ";
            }
        }

        if (!(i == stringKolVo - 1)) f3 << endl;
    }
}

void ultimateSliv(int kolVo) // сливает все в файл f3 в одну отсортированную строку
{
    ofstream f1, f2, f3; // для записи
    ifstream f11, f22, f33; // для чтения
    string buf;
    f11.open("file1.txt");
    f33.open("file3.txt");
    f2.open("file2.txt");
    sliv(f11, f33, f2, kolVo);
    f33.close();
    f3.open("file3.txt");
    if (getline(f11, buf))
    {
        f3 << buf;
    }
    while (getline(f11, buf))
    {
        f3 << endl << buf;
    }
    f11.close();
    f3.close();
    f2.close();

    f22.open("file2.txt");
    f1.open("file1.txt");
    if (getline(f22, buf))
    {
        f1 << buf;
    }
    while (getline(f22, buf))
    {
        f1 << endl << buf;
    }
    f22.close();
    f1.close();
}

int main()
{
    system("chcp 1251 > null");
    srand(time(NULL));
    ofstream f1, f2, f3; // для записи
    ifstream f11, f22, f33; // для чтения
    f1.open("file1.txt");
    int N, start, end;

    cout << "Введите размер массива: ";
    cin >> N;
    while (N < 1)
    {
        cout << "Да что ты вообще вводишь?" << endl << "Введите размер массива: ";
        cin >> N;
    }
    cout << "Введите границы случайных чисел в виде: a b -> ";
    cin >> start >> end;
    while (end < start)
    {
        cout << "Да что ты вообще вводишь?" << endl << "Введите границы случайных чисел в виде: a b -> ";
        cin >> start >> end;
    }

    for (int i = 0; i < N; i++) // заполняем файл
    {
        int tmp;
        tmp = rand() % (end - start + 1) + start;
        f1 << tmp << " ";
        cout << tmp << " ";
    }
    f1.close();

    f11.open("file1.txt");
    f2.open("file2.txt");
    int tmp, tmp2;
    f11 >> tmp;
    f2 << tmp << " ";
    for (int i = 0; i < N - 1; i++) // разбиваем на строки, в которых числа упорядочены
    {
        f11 >> tmp2;
        if (tmp <= tmp2)
        {
            f2 << tmp2 << " ";
        }
        else
        {
            f2 << endl << tmp2 << " ";
        }
        tmp = tmp2;
    }
    f11.close();
    f2.close();
    f22.open("file2.txt");

    string buf;
    int count = 0;
    while (getline(f22, buf)) count++;
    f22.clear();
    f22.seekg(0);

    int phib1 = 0, phib2 = 1;
    while (phib1 + phib2 < count) // ищем ближайшую к числу строк пару чисел фибоначчи с округлением в большую сторону, ведь все строки должны влезть
    {
        int phiBuf = phib1 + phib2;
        phib1 = phib2;
        phib2 = phiBuf;
    }

    f1.open("file1.txt");
    f3.open("file3.txt");
    if (getline(f22, buf))
    {
        f1 << buf;
    }
    for (int i = 0; i < phib2 - 1; i++) // разбиваем по файлам, используя пару чисел фибоначчи
    {
        string serie;
        if (getline(f22, serie))
        {
            f1 << endl << serie;
        }
    }

    if (getline(f22, buf))
    {
        f3 << buf;
    }
    for (int i = 0; i < phib1 - 1; i++) // продолжаем разбивать, фиктивными сериями будут пустые строки
    {
        string serie;
        if (getline(f22, serie))
        {
            f3 << endl << serie;
        }
        else
        {
            f3 << endl;
        }
    }
    f1.close();
    f3.close();
    f22.close();

    while (phib2 - phib1 >= 0) // идем по числам фибоначчи в обратную строну, сливая все в одну строку
    {
        int phibber;
        ultimateSliv(phib1);
        phibber = phib2 - phib1;
        phib2 = phib1;
        phib1 = phibber;
    }
    cout << endl << "Отсортированный массив находится в file3.txt" << endl; // в остальных файлах если что, пусто
    f33.open("file3.txt");
    getline(f33, buf);
    cout << buf; // для удобства выводим отсортированный массив
    f33.close();
    return 0;
}
```

## Тесты скриншоты

![Первый тест](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_F/images/1.png)
![Второй тест](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_F/images/2.png)
![Третий тест](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/mnogofaz_F/images/3.png)
