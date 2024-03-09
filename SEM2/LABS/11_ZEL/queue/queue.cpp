#include <iostream>
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
