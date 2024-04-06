#pragma once
#include <iostream>
using namespace std;
class Iterator
{
	friend class Mnoz;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }
	bool operator ==(const Iterator& it) { return elem == it.elem; }
	bool operator !=(const Iterator& it) { return elem != it.elem; }
	void operator++() { elem++; };
	void operator--() { elem--; };
	int& operator*() const { return*elem; }
private:
	int* elem;
};
class Mnoz
{
public:
	Mnoz(int s, int k = 0);
	Mnoz(const Mnoz&m);
	~Mnoz();
	Mnoz& operator=(const Mnoz&m);
	int& operator[](int idx);
	Mnoz operator*(const Mnoz& m);
	int operator()();

	friend ostream& operator<<(ostream& out, const Mnoz& m);
	friend istream& operator>>(istream& in, Mnoz& m);

	Iterator first() { return beg; }
	Iterator last() { return end; }
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};

