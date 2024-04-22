# Лабораторная работа №7 "Шаблоны классов."

## Постановка задачи

1. Определить шаблон класса-контейнера (см. лабораторную работу №6).
2. Реализовать конструкторы, деструктор, операции ввода-вывода, операцию присваивания.
3. Перегрузить операции, указанные в варианте.
4. Инстанцировать шаблон для стандартных типов данных (int, float, double).
5. Написать тестирующую программу, иллюстрирующую выполнение операций для контейнера, содержащего элементы стандартных типов данных.
6. Реализовать пользовательский класс (см. лабораторную работу №3).
7. Перегрузить для пользовательского класса операции ввода-вывода.
8. Перегрузить операции необходимые для выполнения операций контейнерного класса.
9. Инстанцировать шаблон для пользовательского класса.
10. Написать тестирующую программу, иллюстрирующую выполнение операций для контейнера, содержащего элементы пользовательского класса.

### 7 Вариант:

Класс- контейнер МНОЖЕСТВО с элементами типа int.
Реализовать операции:
- [] – доступа по индексу;
- () – определение размера вектора;
- *  – пересечение множеств;
Пользовательский класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек.
Дробная часть числа при выводе на экран должна быть отделена от целой части запятой.

## UML-диаграмма

![](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_7/images/class_7.drawio.png)

## Код программы

`setn.cpp`
```cpp

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
		cout << "Ýëåìåíò " << i << " =\n"; in >> s.data[i];
	}
	return in;
}

```

`money.h`
```cpp
#pragma once
#include <iostream>
using namespace std;
class Money
{
public:
	Money(void);
	Money(long, int);
	Money(const Money& a);
	Money& operator=(const Money&);
	friend ostream& operator<< (ostream&out, const Money&);
	friend istream& operator>> (istream&in, Money&);
	Money operator*(const Money& m);
	virtual ~Money(void) {};
private:
	long rub;
	int kop;
};
```

`money.cpp`
```cpp
#include "Money.h"
using namespace std;
Money::Money(void)
{
	rub = kop = 0;
}
Money::Money(long a, int b)
{
	rub = a;
	kop = b;
}
Money::Money(const Money& r)
{
	rub = r.rub;
	kop = r.kop;
}
Money& Money::operator=(const Money& r)
{
	rub = r.rub;
	kop = r.kop;
	return *this;
}
ostream& operator<< (ostream&out, const Money&r)
{
	out << r.rub << ",";
	if (r.kop < 10) out << 0;
	out << r.kop;
	return out;
}
istream& operator>> (istream&in, Money&r)
{
	cout << "rub: "; in >> r.rub;
	cout << "kop: "; in >> r.kop;
	return in;
}
Money Money::operator*(const Money& m)
{
	Money r;
	if (rub == m.rub) r.rub = rub;
	if (kop == m.kop) r.kop = kop;
	return r;
}
```

`class_7.cpp`
```cpp
﻿#include <iostream>
#include "Setn.h"
#include "Money.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	/*Setn<int> a(5, 0);
	cin >> a;
	cout << "a:" << a << endl;

	Setn<int> b(10, 0);
	cout << "b:" << b << endl;
	b = a;
	cout << "b:" << b << endl;

	cout << "Элемент 2: " << a[2];
	cout << "\nsize = " << b() << endl;
	Setn<int> s(5, 0); 
	cin >> b;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	s = a * b;
	cout << "s:" << s << endl;*/

	Money mon;
	cin >> mon;
	cout << mon << endl;
	Money mon1;
	cin >> mon1;
	cout << mon1 << endl;
	Money mon2;
	mon2 = mon * mon1;
	cout << mon2 << endl;

	Money t;
	cin >> t;
	cout << t << endl;
	Setn<Money>Ar(5, t);
	cin >> Ar;
	cout << Ar << endl;

	Setn<Money>B(10, t);
	cout << B << endl;
	B = Ar;
	cout << B << endl;
	cout << Ar[2] << endl;
	cout << "A size = " << Ar() << endl;

}
```

## Тесты скриншоты

![Скриншот номер 1](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_7/images/изображение_2024-04-22_164848679.png)

## Ответы на вопросы

**1. В чем смысл использования шаблонов?**

`Шаблоны в программировании используются для повышения переиспользования кода, снижения его сложности и увеличения гибкости.`

**2. Каковы синтаксис/семантика шаблонов функций?**

`Синтаксис шаблонов функций начинается с ключевого слова template, за которым следуют угловые скобки с параметрами шаблона. Семантика заключается в создании функций, не зависящих от конкретных типов.`

**3. Каковы синтаксис/семантика шаблонов классов?**

`Шаблоны классов позволяют определить классы с объектами неизвестного типа на этапе написания кода. Синтаксис включает ключевое слово template и параметры шаблона в угловых скобках.`

**4. Что такое параметры шаблона функции?**

`Параметры шаблона функции - это формальные имена, вынесенные в шаблон, которые заменяются на конкретные типы при инстанцировании шаблона.`

**5. Перечислите основные свойства параметров шаблона функции.**

`Основные свойства параметров шаблона функции включают: уникальность имен, неопускание идентификаторов в прототипе, возможность пустого списка параметров, и требование одного типа для всех экземпляров аргумента шаблона.`

**6. Как записывать параметр шаблона?**

`Параметр шаблона записывается в угловых скобках после ключевого слова template, и каждому параметру должно предшествовать слово class или typename.`

**7. Можно ли перегружать параметризованные функции?**

`Да, можно перегружать параметризованные функции, но они должны отличаться списком входных параметров.`

**8. Перечислите основные свойства параметризованных классов.**

`Параметризованные классы описывают семейство классов с одним или более неопределенным формальным параметром, и каждый класс отличается значениями этих параметров.`

**9. Все ли компонентные функции параметризованного класса являются параметризованными?**

`Не все компонентные функции параметризованного класса обязательно являются параметризованными.`

**10. Являются ли дружественные функции, описанные в параметризованном классе, параметризованными?**

`Дружественные функции, описанные в параметризованном классе, не обязательно являются параметризованными.`

**11. Могут ли шаблоны классов содержать виртуальные компонентные функции?**

`Да, шаблоны классов могут содержать виртуальные компонентные функции.`

**12. Как определяются компонентные функции параметризованных классов вне определения шаблона класса?**

`Компонентные функции параметризованных классов определяются вне определения шаблона класса с указанием списка параметров шаблона после имени класса.`

**13. Что такое инстанцирование шаблона?**

`Инстанцирование шаблона - это процесс создания конкретного экземпляра из шаблона путем замены параметров шаблона на конкретные типы или значения.`

**14. На каком этапе происходит генерирование определения класса по шаблону?**

`Генерирование определения класса по шаблону происходит на этапе компиляции, когда компилятор заменяет параметры шаблона на фактические типы.`
