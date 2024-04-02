#pragma once
#include "Object.h"
#include <iostream>
using namespace std;
class Vector
{
public:
	Vector(void);
	Vector(int);
	~Vector();
	void add(Object*);
	friend ostream& operator <<(ostream& out, const Vector&);
private:
	Object** beg;
	int size;
	int cur;
};

