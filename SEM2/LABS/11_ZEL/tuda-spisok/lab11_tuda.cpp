#include <iostream>
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