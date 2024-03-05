#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Node 
{
    int data;
    Node* next;
};
void push(Node*& head, int data) 
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
void createStack(Node*& head, int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        int data;
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        push(head, data);
    }
}
void printStack(Node* head) 
{
    if (head == nullptr) 
    {
        cout << "Stack is empty." << std::endl;
        return;
    }
    Node* p = head;
    cout << "Stack: ";
    while (p != nullptr) 
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void deleteNth(Node* &head, int del, int n) 
{
    if (del > n)
    {
        cout << "erroe" << endl;
        return;
    }
    Node* p = head;
    if (p == nullptr)
    {
        cout << "Stack is empty. Cannot delete element." << std::endl;
        return;
    }
    if (del == n)
    {
        head = head->next;
        return;
    }
    while (n > del+1)
    {
        p = p->next;
        n--;
    }
    Node* tmp = p;
    Node* temp = p->next;
    tmp->next = temp->next;
    tmp = temp;
    delete temp, tmp;
}
void newEl(Node* head)
{
    Node* tmp = head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    Node* newElem = new Node;
    cin >> newElem->data;
    tmp->next = newElem;
    newElem->next = nullptr;
}
void saver(Node* head)
{
    ofstream file("F.txt");
    while (head != nullptr)
    {
        file << head->data << endl;
        head = head->next;
    }
    file.close();
}
void recover(Node* &head)
{
    vector <int> save;
    ifstream file("F.txt");
    string tmp;
    while (getline(file, tmp))
    {
        int numb = stoi(tmp);
        save.push_back(numb);
    }
    for (int i = save.size() - 1; i >= 0; i--)
    {
        push(head, save[i]);
    }
    file.close();
}
void cleaner(Node* &head)
{
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
int main() 
{
    Node* head = nullptr;
    int n;
    cout << "Enter the number of elements in the stack: ";
    cin >> n;
    createStack(head, n);
    printStack(head);
    int del;
    cin >> del;
    deleteNth(head, del, n);
    printStack(head);
    newEl(head);
    printStack(head);
    saver(head);
    cleaner(head);
    recover(head);
    printStack(head);
    return 0;
}
