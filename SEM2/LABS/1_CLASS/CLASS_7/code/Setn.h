#pragma once
#include <iostream>
using namespace std;
template <class T>
class Setn
{
public:
	Setn(int s, T k);
	Setn(const Setn<T>& s);
	~Setn();
	Setn& operator=(const Setn<T>& s);
	T& operator[](int idx);
	Setn operator*(const Setn<T>& s);
	int operator()();

	friend ostream& operator<< <>(ostream&out, const Setn<int>&);
	friend istream& operator>> <>(istream&in, Setn<int>&);
public:
	int size;
	T* data;
};




template <class T>
Setn<T>::Setn(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++) data[i] = k;
}
template <class T>
Setn<T>::Setn(const Setn<T>& s)
{
	size = s.size;
	data = new T[size];
	for (int i = 0; i < size; i++) data[i] = s.data[i];
}
template <class T>
Setn<T>::~Setn()
{
	delete[] data;
	data = 0;
}
template <class T>
Setn<T>& Setn<T>::operator=(const Setn<T>& s)
{
	if (this == &s) { return *this; }
	size = s.size;
	data = new T[size];
	for (int i = 0; i < size; i++) data[i] = s.data[i];
	return *this;
}
template <class T>
T& Setn<T>::operator[](int idx)
{
	if (idx < size) { return data[idx]; }
	else cout << "Erroe\n";
}
template <class T>
Setn<T> Setn<T>::operator*(const Setn<T>& m)
{
	int* tmp_a = new T[0];
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < m.size; j++)
		{
			if (data[i] == m.data[j])
			{
				bool t = 1;
				for (int k = 0; k < s; k++)
				{
					if (tmp_a[k] == data[i]) { t = 0; }
				}
				if (t)
					tmp_a[s++] = data[i];
			}
		}
	}
	Setn mn(s, 0);
	for (int i = 0; i < s; i++)
	{
		mn.data[i] = tmp_a[i];
	}
	return mn;
}
template <class T>
int Setn<T>::operator()()
{
	return size;
}
template <class T>
ostream& operator << (ostream& out, const Setn<T>& s)
{
	for (int i = 0; i < s.size; i++)
	{
		out << s.data[i] << " ";
	}
	return out;
}
template <class T>
istream& operator >> (istream& in, Setn<T>& s)
{
	for (int i = 0; i < s.size; i++)
	{
		cout << "Ёлемент " << i << " =\n"; in >> s.data[i];
	}
	return in;
}