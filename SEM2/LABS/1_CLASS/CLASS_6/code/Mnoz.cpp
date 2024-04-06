#include "Mnoz.h"
Mnoz::Mnoz(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++) { data[i] = k; }
	beg.elem = &data[0];
	end.elem = &data[size];
}
Mnoz::Mnoz(const Mnoz& m)
{
	size = m.size;
	data = new int[size];
	for (int i = 0; i < size; i++) { data[i] = m.data[i]; }
	beg = m.beg;
	end = m.end;
}
Mnoz::~Mnoz()
{
	delete[] data;
	data = 0;
}
Mnoz& Mnoz::operator=(const Mnoz&m)
{
	if (this == &m) { return*this; }
	size = m.size;
	if (data != 0) { delete[] data; }
	data = new int[size];
	for (int i = 0; i < size; i++) { data[i] = m.data[i]; }
	beg = m.beg;
	end = m.end;
	return *this;
}
int& Mnoz::operator[](int idx)
{
	if (idx < size) { return data[idx]; }
	else
	{
		cout << "Error, index > size \n";
	}
}
Mnoz Mnoz::operator*(const Mnoz& m)
{
	int* tmp_a = new int[0];
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
				if(t)
					tmp_a[s++] = data[i];
			}
		}
	}
	Mnoz mn(s);
	for (int i = 0; i < s; i++)
	{
		mn.data[i] = tmp_a[i];
	}
	return mn;
}
int Mnoz::operator()()
{
	return size;
}
ostream& operator<<(ostream& out, const Mnoz& m)
{
	for (int i = 0; i < m.size; i++)
		out << m.data[i] << " ";
	return out;
}
istream& operator>>(istream& in, Mnoz& m)
{
	for (int i = 0; i < m.size; i++)
	{
		cout << "Ёлемент " << i << " = ";
		in >> m.data[i];
	}
	return in;
}