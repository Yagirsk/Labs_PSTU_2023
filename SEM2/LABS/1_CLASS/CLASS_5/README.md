# Лабораторная работа №5 "Наследование. Виртуальные функции. Полиморфизм."

## Постановка задачи

1. Определить абстрактный класс.
2. Определить иерархию классов, в основе которой будет находиться абстрактный
класс (см. лабораторную работу №4).
3. Определить класс Вектор, элементами которого будут указатели на объекты
иерархии классов.
4. Перегрузить для класса Вектор операцию вывода объектов с помощью потоков.
5. В основной функции продемонстрировать перегруженные операции и
полиморфизм Вектора.

### 7 Вариант:

Базовый класс:
ПАРА_ЧИСЕЛ (PAIR)
Первое_число (first) - int
Второе_число (second) – int
 - Определить методы проверки на равенство и операцию перемножения полей.
 - Реализовать операцию вычитания пар по формуле (a,b)-(c,d)=(a-b,c-d)
 - Создать производный класс ПРОСТАЯ_ДРОБЬ(RATIONAL), с полями Числитель и Знаменатель. Переопределить операцию вычитания и определить операции сложения и умножения простых дробей.

## UML-диаграмма

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_5/images/class_5.drawio.png">

## Код программы

~~~
﻿#include <iostream>
#include "Pair.h"
#include "Object.h"
#include "Rati.h"
#include "Vector.h"
using namespace std;
int main()
{
	Pair a;
	cin >> a;
	cout <<"a = " << a << endl;
	Pair b(1, 3);
	cout << "b = " << b << endl;

	cout << "a = ";
	Object* p = &a;
	p->show();
	cout << endl;

	Pair d;
	Pair c;
	c = a * b;
	cout << "c = a * b = " << c << "\n";
	d = b - a;
	cout << "d = b - a = " << d << endl;

	Rati r;
	cin >> r;
	cout << r << endl;
	p = &r;
	p->show();
	cout << "\n\n";

	Vector v(5);
	Pair e;
	cin >> e;
	Rati R;
	cin >> R;
	Object* eo = &e;
	v.add(eo);
	eo = &R;
	v.add(eo);
	cout << "Vector: \n" << v;
}
~~~

~~~
#pragma once
class Object
{
public:
	Object(void);
public:
	~Object(void);
	virtual void show() = 0;
};
~~~

~~~
#include "Object.h"
Object::Object(void){}
Object::~Object(void) {}
~~~

~~~
#pragma once
#include <iostream>
#include "Object.h"
using namespace std;
class Pair :
    public Object
{
public:
	Pair(void);
	void show();

	virtual ~Pair(void);
	Pair(int, int);
	Pair(const Pair&);

	int get_f() { return fir; }
	int get_s() { return sec; }
	void set_f(int);
	void set_s(int);

	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);

	Pair operator*(const Pair&);
	Pair operator-(const Pair&);
	bool operator==(const Pair&);

protected:
	int fir;
	int sec;

};

~~~

~~~
#include "Pair.h"
Pair::Pair(void)
{
	fir = sec = 0;
}
Pair::~Pair(void) {}
Pair::Pair(int a, int b)
{
	fir = a;
	sec = b;
}
Pair::Pair(const Pair& pair)
{
	fir = pair.fir;
	sec = pair.sec;
}
void Pair::set_f(int a)
{
	fir = a;
}
void Pair::set_s(int b)
{
	fir = b;
}
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)
		return *this;
	fir = p.fir;
	sec = p.sec;
	return *this;
}
istream& operator>>(istream& in, Pair& p)
{
	cout << "first: "; in >> p.fir;
	cout << "second: "; in >> p.sec;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p)
{
	out << "\nfirst = " << p.fir;
	out << "\nsecond = " << p.sec;
	out << "\n";
	return out;
}
Pair Pair::operator*(const Pair& p)
{
	Pair tmp;
	tmp.fir = fir * p.fir;
	tmp.sec = sec * p.sec;
	return tmp;
}
Pair Pair::operator-(const Pair& p)
{
	Pair tmp;
	tmp.fir = fir - sec;
	tmp.sec = p.fir - p.sec;
	return tmp;
}
bool Pair::operator==(const Pair& p)
{
	bool tmp = 1;
	if (fir != p.fir) { tmp = 0; }
	if (sec != p.sec) { tmp = 0; }
	return tmp;
}

void Pair::show()
{
	cout << "\nfirst = " << fir;
	cout << "\nsecond = " << sec;
	cout << "\n";
}
~~~

~~~
#pragma once
#include "Pair.h"
using namespace std;
class Rati :
    public Pair
{
public:
    Rati(void);
    ~Rati(void);

    void show();
    Rati(int, int);
    Rati(const Rati&);
    Rati& operator=(const Rati&);
    Rati operator+(const Rati&);
    Rati operator*(const Rati& r);

    friend istream& operator>>(istream& in, Rati& r);
    friend ostream& operator<<(ostream& out, const  Rati& r);
protected:
    int chi;
    int zna;
};

~~~

~~~
#include "Rati.h"
Rati::Rati(void) :Pair()
{
	chi = fir;
	zna = sec;
}
Rati::~Rati(void) {}
Rati::Rati(int a, int b) :Pair(a, b)
{
	chi = a;
	zna = b;
}
Rati::Rati(const Rati& l)
{
	zna = l.zna;
	chi = l.chi;
}
Rati& Rati::operator=(const Rati& l)
{
	if (&l == this)
		return *this;
	chi = l.chi;
	zna = l.zna;
	return *this;
}
istream& operator>>(istream& in, Rati& r)
{
	cout << "chislitel: "; in >> r.chi;
	cout << "znamenatel: "; in >> r.zna;
	return in;
}
ostream& operator<<(ostream& out, const  Rati& r)
{
	out << "drob': " << r.chi << " / " << r.zna << endl;
	return out;
}
Rati Rati::operator+(const Rati& r)
{
	Rati tmp;
	tmp.zna = zna * r.zna;
	tmp.chi = chi * r.zna + r.chi * zna;
	return tmp;
}
Rati Rati::operator*(const Rati& r)
{
	Rati tmp;
	tmp.zna = zna * r.zna;
	tmp.chi = chi * r.chi;
	return tmp;
}
void Rati::show()
{
	cout << "\nchislitel = " << chi;
	cout << "\nznamenatel = " << zna;
	cout << "\n";
}
~~~

~~~
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
~~~

~~~
#include "Vector.h"
Vector::Vector(void)
{
	beg = 0;
	size = 0;
	cur = 0;
}
Vector::~Vector(void)
{
	if (beg != 0) { delete[] beg; }
	beg = 0;
}
Vector::Vector(int n)
{
	beg = new Object*[n];
	cur = 0;
	size = n;
}
void Vector::add(Object* o)
{
	if (cur < size)
	{
		beg[cur] = o;
		cur++;
	}
}
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) { out << "Empty" << endl; }
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->show();
		p++;
	}
	return out;
}
~~~

## Тесты скриншоты

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_5/images/class_5.drawio.png">

## Ответы на вопросы

**1. Какой метод называется чисто виртуальным? Чем он отличается от виртуального метода?**

`1. Чисто виртуальный метод (или абстрактный метод) — это метод, который объявлен в базовом классе, но не имеет реализации в этом классе. Он служит только для определения интерфейса, и его реализация ожидается в производных классах. Виртуальные методы, с другой стороны, имеют реализацию в базовом классе, но могут быть переопределены в производных классах.`

**2. Какой класс называется абстрактным?**

`Абстрактный класс — это класс, который содержит хотя бы один чисто виртуальный метод. Это означает, что он не может быть инстанциирован напрямую, а его цель — служить базой для других классов.`

**3. Для чего предназначены абстрактные классы?**

`Абстрактные классы предназначены для следующих целей:`

`1. Определения общего интерфейса для группы связанных классов.`

`2. Предоставления базовой реализации для методов, которые должны быть переопределены в производных классах.`

`3. Запрета инстанцирования самого абстрактного класса.`

**4. Что такое полиморфные функции?**

`Полиморфные функции — это функции, которые могут принимать аргументы разных типов и вести себя по-разному в зависимости от типа аргументов. Это позволяет обращаться к одной и той же функции с разными типами данных.`

**5. Чем полиморфизм отличается от принципа подстановки?**

`Полиморфизм — это более широкий принцип, который означает способность объектов разных классов обрабатывать одинаковые операции. Принцип подстановки — это часть полиморфизма и утверждает, что объекты производных классов могут безопасно использоваться вместо объектов базовых классов.`

**6. Привести примеры иерархий с использованием абстрактных классов.**

`Геометрические фигуры: базовый абстрактный класс “Фигура” с методами для вычисления площади и периметра, от которого наследуются конкретные фигуры (круг, прямоугольник, треугольник).`

`Транспортные средства: базовый абстрактный класс “Транспорт” с методами для движения и остановки, от которого наследуются автомобили, велосипеды и другие виды транспорта.`

**7. Привести примеры полиморфных функций.**

`Функция “вывести информацию” может принимать разные типы объектов (например, фигуры или транспортные средства) и выводить их характеристики.`

`Метод “подсчитать площадь” может работать с разными типами геометрических фигур (кругами, прямоугольниками и т. д.) и возвращать соответствующие значения.`

**8. В каких случаях используется механизм позднего связывания?**

`Механизм позднего связывания используется, когда вызов метода происходит во время выполнения программы, а не на этапе компиляции. Это позволяет выбирать правильную реализацию метода в зависимости от типа объекта, на котором он вызывается. Позднее связывание обеспечивает гибкость и расширяемость кода.`
