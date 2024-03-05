#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct ListElem
{
    int data;
    ListElem* next;
    ListElem* prev;
};
struct helpMe
{
    ListElem* first;
    ListElem* final;
};
helpMe createList(int n)
{
    helpMe ss;
    if (n > 0)
    {
        ListElem* start = nullptr;
        ListElem* p, * r;
        start = new ListElem;
        cin >> start->data;
        start->next = nullptr;
        start->prev = nullptr;
        p = start;
        for (int i = 0; i < n - 1; i++)
        {
            r = new ListElem;
            cin >> r->data;
            r->next = nullptr;
            r->prev = p;
            p->next = r;
            p = r;
        }
        ss.first = start;
        ss.final = p;
        return ss;
    }
}
void showList(ListElem* start)
{
    if (start != nullptr)
    {
        {
            ListElem* p = start;
            while (p != nullptr) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "void list" << endl;
    }
    return;
}
void delElem(int del, int n, ListElem*& start, helpMe och)
{
    if (n == 0)
    {
        cout << "err";
        return;
    }
    else if (del > n)
    {
        cout << "err";
        return;
    }
    else
    {
        ListElem* p = start;
        if (del == 1)
        {
            start = start->next;
            start->prev = nullptr;
            delete p;
            return;
        }
        if (del == n)
        {
            ListElem* p = och.final;
            p = p->prev;
            p->next = nullptr;
            och.final = p;
            return;
        }
        for (int i = 1; i < del - 1; i++)
        {
            p = p->next;
        }

        ListElem* temp = p->next;
        p->next = temp->next;
        if (temp->next != nullptr)
        {
            temp->next->prev = p;
        }
        delete temp;
    }
}
void newFirstElem(ListElem*& start)
{
    int newElem;
    cin >> newElem;
    ListElem* newElemA = new ListElem;
    newElemA->data = newElem;
    newElemA->prev = nullptr;
    newElemA->next = start;
    start->prev = newElemA;
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
    }
    else
    {
        cout << "err";
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
}
void recovery(helpMe och)
{
    ifstream file("F1.txt");
    if (file.is_open())
    {
        ListElem* p, * r;
        och.first->next = nullptr;
        och.first->prev = nullptr;
        string tmp;
        getline(file, tmp);
        int numb = stoi(tmp);
        och.first->data = numb;
        p = och.first;
        while (getline(file, tmp))
        {
            int num = stoi(tmp);
            r = new ListElem;
            r->data = num;
            r->next = nullptr;
            r->prev = p;
            p->next = r;
            p = r;
        }
        och.final = p;
    }
    else
    {
        cout << "err";
    }
    file.close();
}
int main()
{
    int n;
    cin >> n;
    helpMe ss;
    ss = createList(n);
    cout << endl;
    showList(ss.first);
    int del;
    cin >> del;
    delElem(del, n, ss.first, ss);
    showList(ss.first);
    newFirstElem(ss.first);
    showList(ss.first);
    saver(ss.first);
    cleaner(ss.first);
    ss.final = nullptr;
    ss.first = new ListElem;
    recovery(ss);
    showList(ss.first);
    return 0;
}
