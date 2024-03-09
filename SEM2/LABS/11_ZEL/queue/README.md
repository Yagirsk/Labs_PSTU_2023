# 1) Задание 

Лабораторная работа №11, вариант 6

Записи в очереди содержат ключевое поле типа
int.
1. Написать функцию для создания очереди. Функция может
создавать пустую очередь, а затем добавлять в неё
элементы.
2. Написать функцию для печати очереди. Функция должна
предусматривать вывод сообщения, если очередь пустая.
3.  Сформировать очередь. Удалить из неё элемент с заданным номером, добавить элемент в
начало очереди.
4. Выполнить изменения в очереди и печать стека после
каждого изменения.
5. Написать функцию для записи очереди в файл.
6. Написать функцию для уничтожения очереди.
7. Записать очередь в файл, уничтожить её.
8. Написать функцию для восстановления очереди из файла.
9. Восстановить очередь и распечатать его.
10. Уничтожить очередь.

# 2) Код программы

```cpp
﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct QueueElem
{
    int data;
    QueueElem* next;
};
struct Queue
{
    QueueElem* front;
    QueueElem* back;
    int size;
    void init()
    {
        front = nullptr;
        back = front;
        size = 0;
    }
    void push(int data)
    {
        QueueElem* tmp = new QueueElem;
        tmp->data = data;
        tmp->next = nullptr;
        if (size == 0)
        {
            front = tmp;
            back = tmp;
        }
        else
        {
            back->next = tmp;
            back = tmp;
        }
        size++;
    }
    int pop()
    {
        int value = front->data;
        QueueElem* tmp = front;
        if (size == 1) { back = nullptr; }
        front = front->next;
        size--;
        delete tmp;
        return value;
    }
    QueueElem* frontEl() { return front; }
    QueueElem* backEl() { return back; }

};
Queue create_queue(int size)
{
    Queue queue{ };
    queue.init();
    int data, counter = 1;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите элемент №" << counter++ << " ";
        cin >> data;
        queue.push(data);
    }
    return queue;
}
void show_queue(Queue& queue)
{
    if (queue.front == nullptr and queue.back == nullptr)
    {
        cout << "Пустая очередь\n";
        return;
    }
    cout << "Очередь: ";
    for (int i = 0; i < queue.size; i++)
    {
        int data = queue.pop();
        cout << data << " ";
        queue.push(data);
    }
    cout << endl;
}
void delQueue(Queue& queue)
{
    while (queue.frontEl() != nullptr)
    {
        QueueElem* tmp = queue.frontEl();
        queue.front = queue.front->next;
        delete tmp;
        queue.size--;
    }
    queue.back = nullptr;
    cout << "Очередь удалена\n";
}
void delElem(Queue& queue, int del)
{
    if (del > queue.size or del <= 0)
    {
        cout << "Ошибка\n";
        return;
    }
    int sizes = queue.size;
    Queue tmpQ{};
    tmpQ.init();
    for (int i = 1; i < del; i++)
    {
        int data = queue.pop();
        tmpQ.push(data);
    }
    int deld = queue.pop();
    while (tmpQ.front != nullptr)
    {
        int data = tmpQ.pop();
        queue.push(data);
    }
    for (int i = 0; i < sizes-del; i++)
    {
        int data = queue.pop();
        queue.push(data);
    }
}
void tolko_sprosit(Queue& queue)
{
    int num;
    cout << "Введите элмент который встанет на первую позицию в очереди: ";
    cin >> num;
    int scheisse = queue.size;
    queue.push(num);
    for (int i = 0; i < scheisse; i++)
    {
        int data = queue.pop();
        queue.push(data);
    }
}
void saver(Queue& queue)
{
    ofstream file("F.txt");
    while (queue.front != nullptr)
    {
        int data = queue.pop();
        file << data << endl;
    }
    file.close();
    cout << "Очередь сохранена\n";
}
void resurrection(Queue& queue)
{
    ifstream file("F.txt");
    string tmp;
    while (getline(file, tmp))
    {
        int data = stoi(tmp);
        queue.push(data);
    }
    file.close();
    cout << "Очередь восстановлена\n";
}
int main()
{
	setlocale(LC_ALL, "ru_RU");
    int size;
    cout << "Введите количество элементов в очереди: ";
    cin >> size;
    Queue ququ = create_queue(size);
    show_queue(ququ);
    if (ququ.frontEl() != nullptr)
    {
        int del;
        cout << "Введите номер элемента который будет удален: ";
        cin >> del;
        delElem(ququ, del);
        show_queue(ququ);
        tolko_sprosit(ququ);
        show_queue(ququ);
        saver(ququ);
        delQueue(ququ); //необязательно т.к. после saver очередь уже пустая, но пусть будет
        resurrection(ququ);
        show_queue(ququ);
    }
	return 0;
}
```

# 3) Блок схема

Функция main

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_main_v2.drawio.png">

Функция create_stack

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/ts_create.drawio.png">
    
Функция showStack

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_show.drawio.png">

Функция StackExtermination

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_exterm.drawio.png">

Функция DelElem

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_delEl.drawio.png">

Функция RetuneStackToTheTrueGlory

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_trueGlory.drawio.png">

Функция saver

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_svaer.drawio.png">

Функция addElem

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_add.drawio.png">

Структура StackElem

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_stackEl.drawio.png">

Структура Stack

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_structStek.drawio.png">

Метод init

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_met_init.drawio.png">

Метод push

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_met_push.drawio.png">

Метод pop

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_met_pop.drawio.png">

Метод topElem

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/st_met_topEl.drawio.png">


# 4) Тесты

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/test1.png">

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/11_ZEL/stek/images/test2.png">
