# 1) Задание
**Работа с одномерными массивами** 

Лабораторная работа №11, вариант 6

Записи в линейном списке содержат ключевое поле типа
int.
1. Написать функцию для создания списка. Функция может
создавать пустой список, а затем добавлять в него
элементы.
2. Написать функцию для печати списка. Функция должна
предусматривать вывод сообщения, если список пустой.
3.  Сформировать однонаправленный список. Удалить из
него элемент с заданным номером, добавить элемент в
начало списка.
4. Выполнить изменения в списке и печать списка после
каждого изменения.
5. Написать функцию для записи списка в файл.
6. Написать функцию для уничтожения списка.
7. Записать список в файл, уничтожить его и выполнить
печать (при печати должно быть выдано сообщение "Список
пустой").
8. Написать функцию для восстановления списка из файла.
9. Восстановить список и распечатать его.
10. Уничтожить список.

# 2) Код программы

```cpp
﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int counter = 1;
struct ListElem
{
    int data;
    ListElem* next;
};
ListElem* createList(int n)
{
    if (n > 0)
    {
        ListElem* start = nullptr;
        ListElem* p, * r;
        start = new ListElem;
        cout << "Введите элемент №" << counter << " ";
        counter++;
        cin >> start->data;
        start->next = nullptr;
        p = start;
        for (int i = 0; i < n - 1; i++)
        {
            cout << "Введите элемент №" << counter << " ";
            counter++;
            r = new ListElem;
            cin >> r->data;
            r->next = nullptr;
            p->next = r;
            p = r;
        }
        return start;
    }
    return nullptr;
}
void showList(ListElem* start)
{
    if (start != nullptr)
    {
        cout << "Список: ";
        ListElem* p = start;
        while (p != nullptr) 
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Список пуст " << endl;
    }
    return;
}
void delElem(int del, int n, ListElem*& start)
{
    if (n == 0)
    {
        cout << "error";
        return;
    }
    else if (del > n)
    {
        cout << "error";
        return;
    }
    else
    {
        ListElem* p = start;
        if (del == 1)
        {
            start = start->next;
            delete p;
            return;
        }

        for (int i = 1; i < del - 1; i++)
        {
            p = p->next;
        }

        ListElem* temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}
void newFirstElem(ListElem*& start)
{
    int newElem;
    cout << "Введите значения нового элемента который встанет на первую позицию в списке ";
    cin >> newElem;
    ListElem* newElemA = new ListElem;
    newElemA->data = newElem;
    newElemA->next = start;
    start = newElemA;
}
void saver(ListElem* start)
{
    ofstream file("F1.txt");
    if (file.is_open())
    {
        ListElem* p = start;
        while (p != nullptr)
        {
            file << p->data << endl;
            p = p->next;
        }
        cout << "Список сохранен в файл " << endl;
    }
    else
    {
        cout << "error";
    }
    file.close();
}
void cleaner(ListElem*& start)
{
    ListElem* ext = start;
    ListElem* save;
    while (ext != nullptr)
    {
        save = ext->next;
        delete ext;
        ext = save;
    }
    start = nullptr;
    cout << "Список удален " << endl;
}
void recovery(ListElem* start)
{
    ifstream file("F1.txt");
    if (file.is_open())
    {
        ListElem* p, * r;
        start->next = nullptr;
        string tmp;
        getline(file, tmp);
        int numb = stoi(tmp);
        start->data = numb;
        p = start;
        while (getline(file, tmp))
        {
            int num = stoi(tmp);
            r = new ListElem;
            r->data = num;
            r->next = nullptr;
            p->next = r;
            p = r;
        }
        cout << "Список восстановлен " << endl;
    }
    else
    {
        cout << "error";
    }
    file.close();
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    int n;
    cout << "Введите количество элементов списка ";
    cin >> n;
    ListElem* start = createList(n);
    cout << endl;
    showList(start);
    if (start->next != nullptr)
    {
        int del;
        cout << "Введите какой элемент удалить ";
        cin >> del;
        delElem(del, n, start);
        showList(start);
        newFirstElem(start);
        showList(start);
        saver(start);
        cleaner(start);
        start = new ListElem;
        recovery(start);
        showList(start);
    }
    return 0;
}
```

# 3) Блок схема

Функция main

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-spisok/images/t1s-main.drawio.png">

Функция createList

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-spisok/images/t1s-create.drawio.png">
    
Функция cleaner

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-spisok/images/t1s-clean.drawio.png">

Функция delElem

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-spisok/images/t1s-del.drawio.png">

Функция newFistElem

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-spisok/images/t1s-new-elemEl.drawio.png">

Функция recovery

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-spisok/images/t1s-rec.drawio.png">

Функция saver

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-spisok/images/t1s-save-v2.drawio.png">

Структура ListElem

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-spisok/images/t1s_struct-s.drawio.png">


# 4) Тесты

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-syuda-spisok/images/test_1.png">

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/tuda-syuda-spisok/images/test_2.png">

