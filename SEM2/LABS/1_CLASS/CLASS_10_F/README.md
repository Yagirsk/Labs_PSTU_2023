# Лабораторная работа №10 "Сохранение данных в файле с использованием потоков."

## Постановка задачи

1. Создать пользовательский класс с минимальной функциональностью.
2. Написать функцию для создания объектов пользовательского класса (ввод исходной информации с клавиатуры) и сохранения их в потоке (файле).
3. Написать функцию для чтения и просмотра объектов из потока.
4. Написать функцию для удаления объектов из потока в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
5. Написать функцию для добавления объектов в поток в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
6. Написать функцию для изменения объектов в потоке в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
7. Для вызова функций в основной программе предусмотреть меню.

### 7 Вариант:

```txt
Создать класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
- деление сумм,
- умножение суммы на дробное число.
	Задание:
- Удалить все записи не равные заданному значению.
- Уменьшить все записи с заданным значением в два раза.
- Добавить K записей в начало файла.
```

## UML-диаграмма

![uml](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/uml.png)

## Код программы

`multilineComment.txt`
```txt
	Постановка задачи:
1. Создать пользовательский класс с минимальной функциональностью.
2. Написать функцию для создания объектов пользовательского класса (ввод исходной информации с клавиатуры) и сохранения их в потоке (файле).
3. Написать функцию для чтения и просмотра объектов из потока.
4. Написать функцию для удаления объектов из потока в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
5. Написать функцию для добавления объектов в поток в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
6. Написать функцию для изменения объектов в потоке в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
7. Для вызова функций в основной программе предусмотреть меню.

	Вариант 7.
Создать класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
	- деление сумм,
	- умножение суммы на дробное число.
Задание:
	- Удалить все записи не равные заданному значению.
	- Уменьшить все записи с заданным значением в два раза.
	- Добавить K записей в начало файла.
```

`money.h`
```cpp
#pragma once
#include <iostream>
using namespace std;
class Money
{
	long long int rubles;
	int kopecks;
public:
	Money()
	{
		rubles = 0;
		kopecks = 0;
	}
	Money(long long int r, int k)
	{
		rubles = r;
		kopecks = k;
	}
	Money(const Money& t)
	{
		rubles = t.rubles;
		kopecks = t.kopecks;
	}
	~Money() {};
	long long int getRubles()
	{
		return rubles;
	}
	int getKopecks()
	{
		return kopecks;
	}
	void setRubles(long long int r)
	{
		rubles = r;
	}
	void setKopecks(int k)
	{
		kopecks = k;
	}
	Money& operator=(const Money&);
	bool operator==(const Money&);
	Money& operator++(); // префиксная
	Money& operator--(); // префиксная
	Money operator++(int); //постфиксная
	Money operator--(int); //постфиксная
	Money operator+(const Money&);
	Money operator-(const Money&);
	Money operator*(const Money&);
	Money operator/(const Money&);
	Money operator*(const double&);
	Money operator/(const double&);
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
	friend fstream& operator>>(fstream& fin, Money& t);
	friend fstream& operator<<(fstream& fout, const Money& t);
};
```

`money.cpp`
```cpp
#pragma once
#include "money.h"
#include <iostream>
#include <fstream>
using namespace std;
Money& Money::operator=(const Money& t)
{
	if (&t == this) return *this;
	rubles = t.rubles;
	kopecks = t.kopecks;
	return *this;
}
bool Money::operator==(const Money& t)
{
	if ((kopecks == t.kopecks) && (rubles == t.rubles)) return true;
	else return false;
}
Money& Money::operator++() // префиксная операция
{
	rubles++;
	return *this;
}
Money& Money::operator--() // префиксная операция
{
	rubles--;
	return *this;
}
Money Money::operator ++(int) // постфиксная операция
{
	long long int temp = rubles;
	temp++;
	Money t(temp, kopecks);
	return t;
}
Money Money::operator--(int) // постфиксная операция
{
	Money tmp = *this;
	tmp.rubles--;
	return tmp;
}
Money Money::operator+(const Money& t)
{
	long long int rub = rubles;
	long long int rub2 = t.rubles;
	int  kop = kopecks;
	int kop2 = t.kopecks;
	int buf;
	Money summa;
	summa.rubles = rub + rub2;
	summa.kopecks = (kop + kop2) % 100;
	buf = (kop + kop2) / 100;
	summa.rubles += buf;
	return summa;
}
Money Money::operator-(const Money& t)
{
	long long int rub = rubles;
	long long int rub2 = t.rubles;
	int kop = kopecks;
	int kop2 = t.kopecks;
	long long int allKopecks1 = rub * 100 + kop;
	long long int allKopecks2 = rub2 * 100 + kop2;
	Money sub;
	sub.kopecks = (allKopecks1 - allKopecks2) % 100;
	sub.rubles = (allKopecks1 - allKopecks2) / 100;
	return sub;
}
Money Money::operator*(const Money& t)
{
	long long int rub = rubles;
	long long int rub2 = t.rubles;
	int  kop = kopecks;
	int kop2 = t.kopecks;
	int buf;
	long long int allKopecks1 = rub * 100 + kop;
	long long int allKopecks2 = rub2 * 100 + kop2;
	buf = allKopecks1 * allKopecks2;
	Money product;
	product.rubles = 0;
	product.kopecks = buf % 10000 / 100;
	product.rubles += buf/10000;
	return product;
}
Money Money::operator/(const Money& t)
{
	long long int rub = rubles;
	long long int rub2 = t.rubles;
	int  kop = kopecks;
	int kop2 = t.kopecks;
	double buf;
	long double allKopecks1 = rub * 100 + kop;
	long double allKopecks2 = rub2 * 100 + kop2;
	buf = allKopecks1 / allKopecks2;
	Money divided;
	divided.rubles = buf;
	buf -= abs(divided.rubles);
	buf *= 100;
	divided.kopecks = buf;
	return divided;
}
Money Money::operator*(const double& t)
{
	long long int rub = rubles;
	int kop = kopecks;
	long long int buf;
	long long int allKopecks = rub * 100 + kop;
	buf = allKopecks * t;
	Money divided;
	divided.rubles = 0;
	divided.kopecks = buf % 100;
	divided.rubles += buf / 100;
	return divided;
}
Money Money::operator/(const double& t)
{
	long long int rub = rubles;
	int kop = kopecks;
	long long int buf;
	long long int allKopecks = rub * 100 + kop;
	buf = allKopecks / t;
	Money divided;
	divided.rubles = 0;
	divided.kopecks = buf % 100;
	divided.rubles += buf / 100;
	return divided;
}
istream& operator>>(istream& in, Money& t)
{
	cout << "Введите рубли без копеек (если вы вводите отрицательное число, вводите и рубли и копейки со знаком минус): ";
	in >> t.rubles;
	cout << "Введите копейки без рублей: "; in >> t.kopecks;
	if (abs(t.kopecks) >= 100)
	{
		int buf = t.kopecks / 100;
		t.rubles += buf;
		t.kopecks = t.kopecks % 100;
	}
	return in;
}
ostream& operator<<(ostream& out, const Money& t)
{
	int boof = t.kopecks;
	if (t.kopecks < 0)
	{
		boof = -t.kopecks;
	}
	if ((t.rubles == 0) && (t.kopecks < 0))
	{
		if (boof >= 10)
		{
			return (out << "-" << t.rubles << "," << boof);
		}
		else
		{
			return (out << "-" << t.rubles << "," << 0 << boof);
		}
	}
	else if (boof >= 10)
	{
		return (out << t.rubles << "," << boof);
	}
	else
	{
		return (out << t.rubles << "," << 0 << boof);
	}
}
fstream& operator>>(fstream& fin, Money& t)
{
	char buf1, buf2;
	fin >> buf1 >> t.rubles >> buf2 >> t.kopecks;
	if (buf1 == '-')
	{
		t.rubles *= -1;
		t.kopecks *= -1;
	}
	return fin;
}
fstream& operator<<(fstream& fout, const Money& t)
{
	fout << (t.rubles >= 0 ? '+' : '-') << (t.rubles >= 0 ? t.rubles : -t.rubles) << ',' << (t.kopecks >= 0 ? t.kopecks : -t.kopecks) << endl;
	return fout;
}
```

`file_work.h`
```cpp
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "money.h"
using namespace std;
int makeFile(const char* f_name) // создать файл
{
	fstream stream(f_name, ios::out | ios::trunc); //открыть для записи
	if (!stream) return -1; //ошибка открытия файла
	int n;
	Money p;
	cout << "Введите число записей: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p; //ввод атрибутов объекта из стандартного потока
		stream << p << "\n"; //запись объекта в файловый поток
	}
	stream.close(); //закрыть поток
	return n; //вернуть количество записанных объектов
}
int printFile(const char* f_name) // распечатать содержимое файла
{
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream) return -1;//ошибка открытия файла
	Money p; int i = 0;
	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}
int delFile(const char* f_name, int k) // удалить по номеру k
{
	fstream temp("temp", ios::out); //открыть для записи
	fstream stream(f_name, ios::in); //открыть для чтения
	if (!stream) return -1; //ошибка открытия файла
	int i = 0; Money p;
	while (stream >> p) //пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
		if (stream.eof()) break;
		i++;
		//если номер объекта не равен k, то записываем его во вспомогательный файл
		if (i != k) temp << p;
	}
	//закрыть файлы
	stream.close(); temp.close();
	remove(f_name); //удалить старый файл
	rename("temp", f_name); // переименовать temp
	return i; //количество прочитанных
}
int addFile(const char* f_name, int k, Money pp) // добавить элемент на позицию k в файле
{
	fstream temp("temp", ios::out); //открыть для записи
	fstream stream(f_name, ios::in); //открыть для чтения
	if (!stream)return -1; //ошибка открытия файла
	Money p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (i == k)
		{
			temp << pp; //записать в temp новую запись
			l++;
		}
		temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l; //количество добавленных
}
int addEnd(const char* f_name, Money pp) // запись элемента в конец файла
{
	fstream stream(f_name, ios::app); //открыть для добавления
	if (!stream) return -1; //ошибка открытия файла
	stream << pp; //записать новую запись
	return 1;
}
int changeFile(const char* f_name, int k, Money pp) // изменить элемент с номером k на указанный
{
	fstream temp("temp", ios::out); //открыть для записи
	fstream stream(f_name, ios::in); //открыть для чтения
	if (!stream) return -1; //ошибка открытия файла
	Money p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (i == k)
		{
			temp << pp;
			l++;
		}
		else temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l; //количество измененных элементов
}
int delAllExceptPPFile(const char* f_name, Money pp) // удалить всё, что не равно pp
{
	fstream temp("temp", ios::out); //открыть для записи
	fstream stream(f_name, ios::in); //открыть для чтения
	if (!stream) return -1; //ошибка открытия файла
	Money p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (p == pp)
		{
			temp << p;
			l++;
		}
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l; //количество оставшихся элементов
}
int decreaseAllPPFile(const char* f_name, Money pp) // уменьшить всё, что равно pp
{
	fstream temp("temp", ios::out); //открыть для записи
	fstream stream(f_name, ios::in); //открыть для чтения
	if (!stream) return -1; //ошибка открытия файла
	Money p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (p == pp)
		{
			temp << (p/2);
			l++;
		}
		else temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l; //количество измененных элементов
}
int addKRecsToBegOfFile(const char* f_name, int K) // добавить K элементов в начало файла
{
	fstream temp("temp", ios::out); //открыть для записи
	fstream stream(f_name, ios::in); //открыть для чтения
	if (!stream) return -1; //ошибка открытия файла
	Money p;
	for (int i = 0; i < K; i++)
	{
		cin >> p;
		temp << p;
	}
	while (stream >> p)
	{
		if (stream.eof()) break;
		temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return K;
}
```

`main.cpp`
```cpp
#include <iostream>
#include "money.h"
#include "file_work.h"
int main()
{
	system("chcp 1251 > null");
	Money p, p1, p2;
	int k, c;
	char file_name[30];
	do
	{
		cout << "\n1. Создать (пересоздать) файл.";
		cout << "\n2. Распечатать файл.";
		cout << "\n3. Удалить одну запись из файла.";
		cout << "\n4. Добавить одну запись в файл.";
		cout << "\n5. Изменить одну запись в файле.";
		cout << "\n6. Удалить все записи, не равные данной.";
		cout << "\n7. Уменьшить все записи, равные данной в два раза.";
		cout << "\n8. Добавить К записей в начало файла.";
		cout << "\n0. Выйти из программы.\n";
		cin >> c;
		switch (c)
		{
		case 1:
		{
			cout << "Введите название файла, не более 30 символов и без пробелов: "; cin >> file_name;
			k = makeFile(file_name);
			if (k < 0) cout << "Не удалось создать файл.";
			break;
		}
		case 2:
		{
			cout << "Введите название существующего файла, не более 30 символов и без пробелов: "; cin >> file_name;
			k = printFile(file_name);
			if (k == 0) cout << "Файл пуст.\n";
			if (k < 0) cout << "Невозможно прочитать файл!\n";
			break;
		}
		case 3:
		{
			cout << "Введите название существующего файла, не более 30 символов и без пробелов: "; cin >> file_name;
			int nom; cout << "Введите номер элемента, который необходимо удалить: "; cin >> nom;
			k = delFile(file_name, nom);
			if (k < 0)cout << "Невозможно прочитать файл!";
			break;
		}
		case 4:
		{
			cout << "Введите название существующего файла, не более 30 символов и без пробелов: ";
			cin >> file_name;
			int nom;  cout << "Введите номер, на который нужно разместить элемент: "; cin >> nom;
			cout << "Новая сумма денег: ";
			cin >> p1;
			k = addFile(file_name, nom, p1);
			if (k < 0) cout << "Невозможно прочитать файл!";
			if (k == 0) k = addEnd(file_name, p1);
			break;
		}
		case 5:
		{
			cout << "Введите название существующего файла, не более 30 символов и без пробелов: "; cin >> file_name;
			int nom; cout << "Введите номер элемента, который нужно изменить: "; cin >> nom;
			cout << "Новая сумма денег: ";
			cin >> p2;
			k = changeFile(file_name, nom, p2);
			if (k < 0) cout << "\nНевозможно прочитать файл!";
			if (k == 0) cout << "\nНет записи под таким номером!";
			break;
		}
		case 6:
		{
			cout << "Введите название существующего файла, не более 30 символов и без пробелов: "; cin >> file_name;
			cout << "Введите сумму, всё, что ей не равно будет стерто из файла: ";
			cin >> p2;
			k = delAllExceptPPFile(file_name, p2);
			if (k < 0) cout << "\nНевозможно прочитать файл!";
			if (k == 0) cout << "\nЗаписей в файле не осталось!";
			break;
		}
		case 7:
		{
			cout << "Введите название существующего файла, не более 30 символов и без пробелов: "; cin >> file_name;
			cout << "Введите сумму, всё, что ей равно будет поделено на 2: ";
			cin >> p2;
			k = decreaseAllPPFile(file_name, p2);
			if (k < 0) cout << "\nНевозможно прочитать файл!";
			if (k == 0) cout << "\nВ файле нет такой записи!";
			break;
		}
		case 8:
		{
			cout << "Введите название существующего файла, не более 30 символов и без пробелов: "; cin >> file_name;
			int k;  cout << "Введите количество записей, которое нужно вставить в начало файла: "; cin >> k;
			k = addKRecsToBegOfFile(file_name, k);
			if (k < 0) cout << "\nНевозможно прочитать файл!";
			if (k == 0) cout << "\nВы сказали вставить 0 записей, ну вот ничего и не вставили!";
			break;
		}
		}
	}
	while (c != 0);
	return 0;
}
```


## Тесты скриншоты

![Скриншот номер 1](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/1.png)

![Скриншот номер 2](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/2.png)

![Скриншот номер 3](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/3.png)

![Скриншот номер 4](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/4.png)

![Скриншот номер 5](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/5.png)

Как видим, числа в файлах хранятся в непонятном человеку виде, например, +2,2 - это 2 рубля 2 копейки, то есть 2,02 а не 2,20 как можно было подумать.

![Скриншот номер 6](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/6.png)

![Скриншот номер 7](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/7.png)

![Скриншот номер 8](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/8.png)

![Скриншот номер 9](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/9.png)

![Скриншот номер 10](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_10_F/images/10.png)

## Ответы на вопросы

**1. Что такое поток?**

`Поток в C++ — это абстракция, которая представляет последовательность байтов или символов. Это может быть поток данных, который поступает из устройства ввода, такого как клавиатура, или поток данных, который направляется в устройство вывода, например, на экран или в файл.`

**2. Какие типы потоков существуют?**

`Существуют три основных типа потоков: ввода (istream), вывода (ostream) и двунаправленные потоки (iostream), которые поддерживают как ввод, так и вывод.`

**3. Какую библиотеку надо подключить при использовании стандартных потоков?**

`Для использования стандартных потоков ввода/вывода необходимо подключить библиотеку <iostream>.`

**4. Какую библиотеку надо подключить при использовании файловых потоков?**

`Для работы с файловыми потоками нужно подключить библиотеку <fstream>.`

**5. Какую библиотеку надо подключить при использовании строковых потоков?**

`Для использования строковых потоков необходимо подключить библиотеку <sstream>.`

**6. Какая операция используется при выводе в форматированный поток?**

`Для вывода в форматированный поток используется операция вставки <<.`

**7. Какая операция используется при вводе из форматированных потоков?**

`Для ввода из форматированных потоков используется операция извлечения >>.`

**8. Какие методы используются при выводе в форматированный поток?**

`Методы put(), write(), и перегруженный оператор <<, используются для вывода в форматированный поток.`

**9. Какие методы используется при вводе из форматированного потока?**

`Методы get(), read(), getline(), и перегруженный оператор >>, используются для ввода из форматированного потока.`

**10. Какие режимы для открытия файловых потоков существуют?**

`Режимы открытия файловых потоков: ios::in (чтение), ios::out (запись), ios::app (добавление в конец файла), ios::ate (перемещение указателя в конец файла при открытии), ios::trunc (обрезание файла при открытии), и ios::binary (бинарный режим).`

**11. Какой режим используется для добавления записей в файл?**

`Для добавления записей в файл используется режим ios::app.`

**12. Какой режим (комбинация режимов) используется в конструкторе ifstream file("f.txt")?**

`В конструкторе ifstream file("f.txt") используется режим ios::in.`

**13. Какой режим (комбинация режимов) используется в конструкторе fstream file("f.txt")?**

`В конструкторе fstream file("f.txt") используются режимы ios::in | ios::out.`

**14. Какой режим (комбинация режимов) используется в конструкторе ofstream file("f.txt")?**

`В конструкторе ofstream file("f.txt") используется режим ios::out.`

**15. Каким образом открывается поток в режиме ios::out|ios::app?**

`Поток открывается с использованием конструктора или метода open() с указанием режимов ios::out | ios::app, что позволяет записывать данные в конец файла, не удаляя его текущее содержимое.`

**16. Каким образом открывается поток в режиме ios::out |ios::trunc?**

`Поток открывается с использованием конструктора или метода open() с указанием режимов ios::out | ios::trunc, что приводит к обрезанию файла и записи данных с начала файла.`

**17. Каким образом открывается поток в режиме ios::out |ios::in|ios::trunc?**

`Поток открывается с использованием конструктора или метода open() с указанием режимов ios::out | ios::in | ios::trunc, что позволяет читать и писать в файл, при этом файл обрезается при открытии.`

**18. Каким образом можно открыть файл для чтения?**

`Файл для чтения можно открыть, используя конструктор ifstream или метод open() объекта ifstream с указанием пути к файлу.`

**19. Каким образом можно открыть файл для записи?**

`Файл для записи можно открыть, используя конструктор ofstream или метод open() объекта ofstream с указанием пути к файлу.`

**20. Привести примеры открытия файловых потоков в различных режимах.**

```cpp
std::ofstream out("file.txt"); // Открытие для записи, режим ios::out
std::ifstream in("file.txt"); // Открытие для чтения, режим ios::in
std::fstream fs("file.txt", std::ios::in | std::ios::out); // Открытие для чтения и записи
std::ofstream out_app("file.txt", std::ios::app); // Открытие для добавления в конец файла
```
`Также можно создать множество других комбинаций режимов, добавлять к ним ios::trunc, соединять вместе, применять к разным объектам, открывать через open() и т.д.`

**21. Привести примеры чтения объектов из потока.**

```cpp
int number;
std::ifstream in("file.txt");
in >> number; // Чтение числа из файла
```
`Перегружая >>, мы можем читать из файла и объекты класса, так же, как и в примере с числом, но только при учете того, что объекты классов перед этим были занесены в файл определенным образом, например, через перегруженный <<.`

**22. Привести примеры записи объектов в поток.**

```cpp
int number = 42;
std::ofstream out("file.txt");
out << number; // Запись числа в файл
```
`Перегружая <<, мы можем писать в файл и объекты класса, так же, как и в примере с числом, важно также перегрузить >>, чтобы в будущем правильно считать объекты классов из файла.`

**23. Сформулировать алгоритм удаления записей из файла.**

```txt
1. Создать временный файл для записи.
2. Открыть исходный файл для чтения.
3. Проверить, удалось ли открыть исходный файл. Если нет, вернуть -1 как признак ошибки.
4. Инициализировать счетчик прочитанных записей.
5. Читать записи из исходного файла до тех пор, пока не достигнут конец файла.
	- Если достигнут конец файла, прервать чтение.
	- Увеличить счетчик прочитанных записей.
	- Если номер текущей записи не равен заданному номеру k, записать её во временный файл.
6. Закрыть исходный и временный файлы.
7. Удалить исходный файл.
8. Переименовать временный файл в исходный.
9. Вернуть количество прочитанных записей.

Данная функция принимает название файла (полный путь), номер элемента который нужно удалить.
```

**24. Сформулировать алгоритм добавления записей в файл.**

```txt
1. Создать временный файл для записи.
2. Открыть исходный файл для чтения.
3. Проверить, удалось ли открыть исходный файл. Если нет, вернуть -1 как признак ошибки.
4. Инициализировать счетчики прочитанных и добавленных записей.
5. Читать записи из исходного файла до тех пор, пока не достигнут конец файла.
	- Если достигнут конец файла, прервать чтение.
	- Увеличить счетчик прочитанных записей.
	- Если номер текущей записи равен заданному номеру k, записать новую запись во временный файл и увеличить счетчик добавленных записей, иначе - записать текущую запись во временный файл.
6. Закрыть исходный и временный файлы.
7. Удалить исходный файл.
8. Переименовать временный файл в исходный.
9. Вернуть количество добавленных записей.

Данная функция принимает название файла (полный путь), номер элемента, куда нужно вставить запись и запись, которую нужно вставить.
```

**25. Сформулировать алгоритм изменения записей в файле.**

```txt
1. Создать временный файл для записи.
2. Открыть исходный файл для чтения.
3. Проверить, удалось ли открыть исходный файл. Если нет, вернуть -1 как признак ошибки.
4. Инициализировать счетчики прочитанных и измененных записей.
5. Читать записи из исходного файла до тех пор, пока не достигнут конец файла.
	- Если достигнут конец файла, прервать чтение.
	- Увеличить счетчик прочитанных записей.
	- Если номер текущей записи равен заданному номеру k, записать измененную запись во временный файл и увеличить счетчик измененных записей, иначе - записать текущую запись во временный файл.
6. Закрыть исходный и временный файлы.
7. Удалить исходный файл.
8. Переименовать временный файл в исходный.
9. Вернуть количество измененных записей.

Данная функция принимает название файла (полный путь), номер элемента, который нужно изменить и запись, на которую нужно изменить запись с указанным номером.
```
