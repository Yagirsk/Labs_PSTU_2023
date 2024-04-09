# Лабораторная работа №4 "Простое наследование. Принцип подстановки."

## Постановка задачи

1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами,
копирования.
3. Определить в классе деструктор.4. Определить в классе компоненты-функции для просмотра и установки полей
данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Определить производный класс.
8. Написать программу, в которой продемонстрировать создание объектов и работу
всех перегруженных операций.
9. Реализовать функции, получающие и возвращающие объект базового класса.
Продемонстрировать принцип подстановки.

### 7 Вариант:

Базовый класс:
ПАРА_ЧИСЕЛ (PAIR)
Первое_число (first) - int
Второе_число (second) – int
 - Определить методы проверки на равенство и операцию перемножения полей.
 - Реализовать операцию вычитания пар по формуле (a,b)-(c,d)=(a-b,c-d)
 - Создать производный класс ПРОСТАЯ_ДРОБЬ(RATIONAL), с полями Числитель и Знаменатель. Переопределить операцию вычитания и определить операции сложения и умножения простых дробей.

## UML-диаграмма

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_4/images/class_4.drawio.png">

## Код программы

~~~
﻿#include <iostream>
#include "Pair.h"
#include "rational.h"
using namespace std;
int main()
{
	Pair a;
	cin >> a;
	cout << a;
	Pair b(1, 3);
	cout << b;

	Pair d;
	Pair c;
	c = a * b;
	cout << "c = a * b = " << c;
	d = b - a;
	cout << "d = b - a = " << d;

	rational ab;
	cin >> ab;
	cout << "ab =\n" << ab;

	rational abc(2, 5);
	cout << "abc =\n" << abc;

	rational abcd = ab + abc;
	cout << "abcd = ab + abc =\n" << abcd;

	ab = abcd * abc;
	cout << "ab = abcd * abc =\n" << ab;
}
~~~

~~~
#pragma once
#include <iostream>
using namespace std;
class Pair
{

public:
	Pair(void);

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
#pragma once
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

~~~

~~~
#pragma once
#include "Pair.h"
using namespace std;
class rational :
    public Pair
{
public:
    rational(void);
    ~rational(void);

    rational(int, int);
    rational(const rational&);
    rational& operator=(const rational&);
    rational operator+(const rational&);
    rational operator*(const rational& r);

    friend istream& operator>>(istream& in, rational& r);
    friend ostream& operator<<(ostream& out, const  rational& r);
protected:
    int chi;
    int zna;
};

~~~

~~~
#include "rational.h"
rational::rational(void) :Pair()
{
	chi = fir;
	zna = sec;
}
rational::~rational(void) {}
rational::rational(int a, int b) :Pair(a, b)
{
	chi = a;
	zna = b;
}
rational::rational(const rational& l)
{
	zna = l.zna;
	chi = l.chi;
}
rational& rational::operator=(const rational& l)
{
	if (&l == this)
		return *this;
	chi = l.chi;
	zna = l.zna;
	return *this;
}
istream& operator>>(istream& in, rational& r)
{
	cout << "chislitel: "; in >> r.chi;
	cout << "znamenatel: "; in >> r.zna;
	return in;
}
ostream& operator<<(ostream& out, const  rational& r)
{
	out << "drob': " << r.chi << " / " << r.zna << endl;
	return out;
}
rational rational::operator+(const rational& r)
{
	rational tmp;
	tmp.zna = zna * r.zna;
	tmp.chi = chi * r.zna + r.chi * zna;
	return tmp;
}
rational rational::operator*(const rational& r)
{
	rational tmp;
	tmp.zna = zna * r.zna;
	tmp.chi = chi * r.chi;
	return tmp;
}
~~~

## Тесты скриншоты

<image src ="https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_4/images/изображение_2024-04-09_121634251.png">

## Ответы на вопросы

**1. Для чего используется механизм наследования?**

`Механизм наследования используется для создания новых классов на основе существующих. Он позволяет классам наследовать свойства и методы других классов, что способствует повторному использованию кода.`

**2. Каким образом наследуются компоненты класса, описанные со спецификатором public?**

`Компоненты класса, описанные со спецификатором public, наследуются также с модификатором public в производном классе. Это означает, что они остаются доступными извне.`

**3. Каким образом наследуются компоненты класса, описанные со спецификатором private?**

`Компоненты класса, описанные со спецификатором private, не наследуются в производном классе. Они остаются закрытыми и недоступными извне.`

**4. Каким образом наследуются компоненты класса, описанные со спецификатором protected?**

`Компоненты класса, описанные со спецификатором protected, наследуются с модификатором protected в производном классе. Они доступны внутри производного класса и его потомков.`

**5. Каким образом описывается производный класс?**

`Производный класс описывается путем создания нового класса, который наследует свойства и методы от базового класса. Синтаксис: class Derived : public Base { ... }.`

**6. Наследуются ли конструкторы?**

`Конструкторы наследуются, но они не вызываются автоматически. В производном классе можно явно вызвать конструктор базового класса.`

**7. Наследуются ли деструкторы?**

`Деструкторы также наследуются, но также не вызываются автоматически. Важно убедиться, что деструктор базового класса объявлен как виртуальный.`

**8. В каком порядке конструируются объекты производных классов?**

`Объекты производных классов конструируются в следующем порядке:`

`1. Вызывается конструктор базового класса.`

`2. Выполняются инициализации производного класса.`

`3. Вызывается конструктор производного класса.`

**9. В каком порядке уничтожаются объекты производных классов?**

`1. Вызывается деструктор производного класса.`

`2. Выполняются действия деструктора базового класса.`

**10. Что представляют собой виртуальные функции и механизм позднего связывания?**

`Виртуальные функции позволяют проводить динамическое связывание. Они определяются в базовом классе и могут быть переопределены в производных классах. Механизм позднего связывания обеспечивает вызов правильной функции во время выполнения.`

**11. Могут ли быть виртуальными конструкторы? Деструкторы?**

`Конструкторы не могут быть виртуальными, но деструкторы могут. Виртуальные деструкторы обеспечивают корректное удаление объектов при использовании указателей на базовый класс.`

**12. Наследуется ли спецификатор virtual?**

`Спецификатор virtual не наследуется, но его использование в производном классе позволяет переопределить функцию как виртуальную.`

**13. Какое отношение устанавливает между классами открытое наследование?**

`Открытое наследование устанавливает отношение “является” между базовым и производным классами.`

**14. Какое отношение устанавливает между классами закрытое наследование?**

`Закрытое наследование устанавливает отношение “реализует” между базовым и производным классами.`

**15. В чем заключается принцип подстановки?**

`Принцип подстановки заключается в том, что объект производного класса может использоваться везде, где используется объект базового класса.`

**16. Имеется иерархия классов:**
```cpp
class Student
{
	int age;
public:
	string name;
	...
};
class Employee : public Student
{
protected:
	string post;
	...
};
class Teacher : public Employee
{
	protected: int stage;
	...
};

Teacher x;
```
**Какие компонентные данные будет иметь объект х?**

`Объект x принадлежит классу Teacher, который наследует свойства от класса Employee, а тот, в свою очередь, наследует свойства от класса Student.`

`Поэтому объект x будет иметь следующие компонентные данные:`

`public     name (наследовано от класса Student).`

`protected  post (наследовано от класса Employee).`

`protected  stage (собственное свойство класса Teacher).`

**17. Для классов Student, Employee и Teacher написать конструкторы без параметров.**

```cpp
class Student
{
public:
    Student()
	{
		age = 0;
		name = " ";
	}
};
class Employee : public Student
{
public:
    Employee() : Student()
	{
		post = " ";
	}
};
class Teacher : public Employee
{
public:
    Teacher() : Employee()
	{
		stage = 0;
	}
};
```

**18. Для классов Student, Employee и Teacher написать конструкторы с параметрами.**

```cpp
class Student
{
public:
    Student(int a, string n)
	{
		age = a;
		name = n;
	}
};
class Employee : public Student
{
public:
    Employee(string n, string p) : Student(a, n)
	{
		post = p;
	}
};
class Teacher : public Employee
{
public:
    Teacher(string n, string p, int s) : Employee(n, p)
	{
		stage = s;
	}
};
```

**19. Для классов Student, Employee и Teacher написать конструкторы копирования.**

```cpp
class Student
{
public:
    Student(const Student& S)
	{
		age = S.age;
		name = S.name;
	}
};
class Employee : public Student
{
public:
    Employee(const Employee& E)
	{
		name = E.name;
		post = E.post;
	}
};
class Teacher : public Employee
{
public:
    Teacher(const Teacher& T)
	{
		name = T.name;
		post = T.post;
		stage = T.stage;
	}
};
```

**20. Для классов Student, Employee и Teacher определить операцию присваивания.**

```cpp
Student operator=(const Student& S)
{
	if (&S==this) return *this;
	age = S.age;
	name = S.name;
	return *this;
}
Employee operator=(const Employee& E)
{
	if (&S==this) return *this;
	name = E.name;
	post = E.post;
	return *this;
}
Teacher operator=(const Teacher& T)
{
	if (&S==this) return *this;
	name = T.name;
	post = T.post;
	stage = T.stage;
	return *this;
}
```
