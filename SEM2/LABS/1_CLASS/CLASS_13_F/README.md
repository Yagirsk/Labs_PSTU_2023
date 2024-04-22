
# Лабораторная работа №13 "Стандартные обобщенные алгоритмы библиотеки STL."

## Постановка задачи

### Задача 1.

1. Создать последовательный контейнер.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
3. Удалить элементы в соответствии с заданием (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
4. Отсортировать контейнер по убыванию и по возрастанию ключевого поля (использовать алгоритм sort()).
5. Найти в контейнере заданный элемент (использовать алгоритмы find(), find_if(), count(), count_if()).
6. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()).
7. Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.

### Задача 2.

1. Создать адаптер контейнера.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
3. Удалить элементы в соответствии с заданием (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
4. Отсортировать контейнер по убыванию и по возрастанию ключевого поля (использовать алгоритм sort()).
5. Найти в контейнере элемент с заданным ключевым полем (использовать алгоритмы find(), find_if(), count(), count_if()).
6. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()).
7. Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.

### Задача 3

1. Создать ассоциативный контейнер.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
3. Удалить элементы в соответствии с заданием (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
4. Отсортировать контейнер по убыванию и по возрастанию ключевого поля (использовать алгоритм sort()).
5. Найти в контейнере элемент с заданным ключевым полем (использовать алгоритмы find(), find_if(), count(), count_if()).
6. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()).
7. Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.

### 7 Вариант:

```txt
		Задача 1
1. Контейнер - вектор
2. Тип элементов Money (см. лабораторную работу №3).
		Задача 2
Адаптер контейнера - очередь.
		Задача 3
Ассоциативный контейнер - словарь.

		Задание 3                      
Найти минимальный элемент и добавить его в конец контейнера.
		Задание 4
Найти элемент с заданным ключом и удалить его из контейнера.
		Задание 5
К каждому элементу добавить сумму минимального и максимального элементов контейнера.
```

## UML-диаграмма

![uml](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/uml%20(1).png)

## Код программы

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
	bool operator<(const Money&);
	bool operator<=(const Money&);
	bool operator>(const Money&);
	bool operator>=(const Money&);
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
bool Money::operator<(const Money& m)
{
	long long int allKopecks1 = rubles * 100 + kopecks;
	long long int allKopecks2 = m.rubles * 100 + m.kopecks;
	if (allKopecks1 < allKopecks2) return true;
	else return false;
}
bool Money::operator<=(const Money& m)
{
	long long int allKopecks1 = rubles * 100 + kopecks;
	long long int allKopecks2 = m.rubles * 100 + m.kopecks;
	if (allKopecks1 <= allKopecks2) return true;
	else return false;
}
bool Money::operator>(const Money& m)
{
	long long int allKopecks1 = rubles * 100 + kopecks;
	long long int allKopecks2 = m.rubles * 100 + m.kopecks;
	if (allKopecks1 > allKopecks2) return true;
	else return false;
}
bool Money::operator>=(const Money& m)
{
	long long int allKopecks1 = rubles * 100 + kopecks;
	long long int allKopecks2 = m.rubles * 100 + m.kopecks;
	if (allKopecks1 >= allKopecks2) return true;
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
	long long int buf;
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

`main.cpp`
```cpp
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
#include "money.h"
using namespace std;

Money s;
Money sumMinMax(0, 0); // для обработки каждого

struct Equal_s // для поиска
{
	bool operator()(Money t)
	{
		return t == s;
	}
};

struct Comp_less // для сортировки по убыванию
{
	bool operator()(Money t1, Money t2)
	{
		if (t1 > t2) return true;
		else return false;
	}
};

void sumAdd(Money& t) // для обработки каждого
{
	t = t + sumMinMax;
}

vector<Money> makeVector(int n) // создание и наполнение вектора
{
	Money a;
	vector<Money> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

void printVector(vector<Money> v) // печать вектора
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
	cout << endl;
}

queue<Money> makeQueue(int n) // создание и наполнение очереди
{
	Money a;
	queue<Money> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push(a);
	}
	return v;
}

void printQueue(queue<Money> v) // печать очереди
{
	Money tmp;
	for (int i = 0; i < v.size(); i++)
	{
		tmp = v.front();
		v.pop();
		cout << tmp << endl;
		v.push(tmp);
	}
	cout << endl;
}

vector<Money> copyQueueToVector(queue<Money> q)
{
	vector<Money> result;
	Money tmp;
	for (int i = 0; i < q.size(); i++)
	{
		tmp = q.front();
		q.pop();
		result.push_back(tmp);
		q.push(tmp);
	}
	return result;
}

queue<Money> copyVectorToQueue(vector<Money> v)
{
	queue<Money> result;
	Money tmp;
	for (int i = 0; i < v.size(); i++)
	{
		result.push(v[i]);
	}
	return result;
}

void sortQueue_o0O(queue<Money>& q)
{
	vector<Money> v(copyQueueToVector(q));
	sort(v.begin(), v.end());
	q = copyVectorToQueue(v);
}

void sortQueue_O0o(queue<Money>& q)
{
	vector<Money> v(copyQueueToVector(q));
	sort(v.begin(), v.end(), Comp_less());
	q = copyVectorToQueue(v);
}

Money queueMin(queue<Money> q)
{
	vector<Money> v(copyQueueToVector(q));
	auto i = min_element(v.begin(), v.end());
	return (*i);
}

Money queueMax(queue<Money> q)
{
	vector<Money> v(copyQueueToVector(q));
	auto i = max_element(v.begin(), v.end());
	return (*i);
}

Money queueFindS(queue<Money> q, Money s)
{
	vector<Money> v(copyQueueToVector(q));
	Money result(INT64_MAX, INT32_MAX);
	auto i = find_if(v.begin(), v.end(), Equal_s());
	if (i != v.end())
	{
		cout << "Элемент найден: " << *i << endl;
		result = (*i);
		return result;
	}
	else cout << "Нет такого элемента!" << endl;
	return result;
}

void queueRemoveS(queue<Money>& q, Money s)
{
	vector<Money> v(copyQueueToVector(q));
	auto i = remove_if(v.begin(), v.end(), Equal_s());
	v.erase(i, v.end());
	q = copyVectorToQueue(v);
}

void queueMinMaxAdder(queue<Money>& q)
{
	vector<Money> v(copyQueueToVector(q));
	sumMinMax = sumMinMax + queueMin(q);
	sumMinMax = sumMinMax + queueMax(q);
	for_each(v.begin(), v.end(), sumAdd);
	q = copyVectorToQueue(v);
}

map<int, Money> makeMap(int n)
{
	map<int, Money> m;
	Money a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void printMap(map<int, Money> m)
{
	for (int i = 0; i < m.size(); i++) cout << i << " - " << m[i] << endl;
}

int mapMaxElemKey(map<int, Money> v)
{
	auto i = v.begin(); 
	int nom = 0, k = 0;
	Money m = (*i).second;
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}
	return nom;
}

int mapMinElemKey(map<int, Money> v)
{
	auto i = v.begin();
	int nom = 0, k = 0;
	Money m = (*i).second;
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}
	return nom;
}

void delOneElemMap(map<int, Money>& mmm, int key)
{
	if (key >= mmm.size()) return;
	vector<Money> v;
	Money a;
	for (int i = 0; i < key; i++)
	{
		v.push_back(mmm[i]);
	}
	for (int i = key+1; i < mmm.size(); i++)
	{
		v.push_back(mmm[i]);
	}
	map<int, Money> m;
	for (int i = 0; i < v.size(); i++)
	{
		m.insert(make_pair(i, v[i]));
	}
	mmm = m;
}

void sortMap_o0O(map<int, Money>& mmm)
{
	vector<Money> v;
	Money a;
	for (int i = 0; i < mmm.size(); i++)
	{
		v.push_back(mmm[i]);
	}
	sort(v.begin(), v.end());
	map<int, Money> m;
	for (int i = 0; i < v.size(); i++)
	{
		m.insert(make_pair(i, v[i]));
	}
	mmm = m;
}

void sortMap_O0o(map<int, Money>& mmm)
{
	vector<Money> v;
	Money a;
	for (int i = 0; i < mmm.size(); i++)
	{
		v.push_back(mmm[i]);
	}
	sort(v.begin(), v.end(), Comp_less());
	map<int, Money> m;
	for (int i = 0; i < v.size(); i++)
	{
		m.insert(make_pair(i, v[i]));
	}
	mmm = m;
}

void minMaxAddToMap(map<int, Money>& mmm)
{
	vector<Money> v;
	Money a;
	for (int i = 0; i < mmm.size(); i++)
	{
		v.push_back(mmm[i]);
	}
	for_each(v.begin(), v.end(), sumAdd);
	map<int, Money> m;
	for (int i = 0; i < v.size(); i++)
	{
		m.insert(make_pair(i, v[i]));
	}
	mmm = m;
}

int main()
{
	system("chcp 1251 > null");
	int n;
	cout << "ЗАДАЧА 1. ВЕКТОР." << endl;
	cout << "Введите количество элементов в векторе: ";	cin >> n;
	vector<Money> v;
	v = makeVector(n);
	printVector(v);

	auto i = min_element(v.begin(), v.end());
	cout << "Минимальный элемент = " << *i << endl;
	v.push_back(*i);
	cout << "Пушим минимальный элемент в конец вектора:" << endl;
	printVector(v);

	cout << "Введите ключ, по которому будет найден элемент:\n";
	cin >> s;
	i = find_if(v.begin(), v.end(), Equal_s());
	if (i != v.end()) cout << "Элемент найден: " << *(i) << endl;
	else cout << "Нет такого элемента!" << endl;
	cout << "Удаление всех элементов с таким ключом:\n";
	i = remove_if(v.begin(), v.end(), Equal_s());
	v.erase(i, v.end());
	printVector(v);

	cout << "Сортировка по убыванию:" << endl;
	sort(v.begin(), v.end(), Comp_less());
	printVector(v);
	cout << "Сортировка по возрастанию:" << endl;
	sort(v.begin(), v.end());
	printVector(v);

	cout << "Ко всем элементам добавили сумму макс. и мин. элементов:" << endl;
	i = min_element(v.begin(), v.end());
	sumMinMax = sumMinMax + (*i);
	i = max_element(v.begin(), v.end());
	sumMinMax = sumMinMax + (*i);
	for_each(v.begin(), v.end(), sumAdd);
	printVector(v);
	sumMinMax.setKopecks(0); sumMinMax.setRubles(0);

	cout << "ЗАДАЧА 2. ОЧЕРЕДЬ." << endl;
	cout << "Введите количество элементов в очереди: ";	cin >> n;
	queue<Money> q;
	q = makeQueue(n);
	printQueue(q);

	Money qElem = queueMin(q);
	cout << "Минимальный элемент = " << qElem << endl;
	q.push(qElem);
	cout << "Пушим минимальный элемент в конец очереди:" << endl;
	printQueue(q);

	cout << "Введите ключ, по которому будет найден элемент:\n";
	cin >> s;
	queueFindS(q, s);
	cout << "Удаление всех элементов с таким ключом:\n";
	queueRemoveS(q, s);
	printQueue(q);

	cout << "Сортировка по убыванию:" << endl;
	sortQueue_O0o(q);
	printQueue(q);
	cout << "Сортировка по возрастанию:" << endl;
	sortQueue_o0O(q);
	printQueue(q);

	cout << "Ко всем элементам добавили сумму макс. и мин. элементов:" << endl;
	queueMinMaxAdder(q);
	printQueue(q);
	sumMinMax.setKopecks(0); sumMinMax.setRubles(0);

	cout << "ЗАДАЧА 3. СЛОВАРЬ." << endl;
	cout << "Введите количество элементов в словаре: ";	cin >> n;
	map<int, Money> m;
	m = makeMap(n);
	printMap(m);

	n = mapMinElemKey(m);
	cout << "Минимальный элемент = " << m[n] << endl;
	m.insert(make_pair(m.size(), m[n]));
	cout << "Пушим минимальный элемент в конец словаря:" << endl;
	printMap(m);

	cout << "Введите ключ, по которому будет найден элемент (в этом словаре ключ совпадает с индексом):\n";
	cin >> n;
	if ((n < m.size())&&(n >= 0)) cout << "Элемент найден: " << m[n] << endl;
	else cout << "Нет такого элемента!" << endl;
	cout << "Удаление элемента с таким ключом:\n";
	delOneElemMap(m, n);
	printMap(m);

	cout << "Сортировка по убыванию второго поля:" << endl;
	sortMap_O0o(m);
	printMap(m);
	cout << "Сортировка по возрастанию второго поля:" << endl;
	sortMap_o0O(m);
	printMap(m);

	cout << "Ко всем элементам добавили сумму макс. и мин. элементов:" << endl;
	n = mapMinElemKey(m);
	sumMinMax = sumMinMax + m[n];
	n = mapMaxElemKey(m);
	sumMinMax = sumMinMax + m[n];
	minMaxAddToMap(m);
	printMap(m);
	sumMinMax.setKopecks(0); sumMinMax.setRubles(0);
	return 0;
}
```

## Тесты скриншоты

![Скриншот номер 1](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/1.png)

![Скриншот номер 2](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/2.png)

![Скриншот номер 3](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/3.png)

![Скриншот номер 4](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/4.png)

![Скриншот номер 5](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/5.png)

![Скриншот номер 6](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/6.png)

![Скриншот номер 7](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/7.png)

![Скриншот номер 8](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/8.png)

![Скриншот номер 9](https://github.com/Yagirsk/Labs_PSTU_2023/blob/main/SEM2/LABS/1_CLASS/CLASS_13_F/images/9.png)

## Ответы на вопросы

`Так как в 13-й лабораторной работе нет вопросов, здесь будут ответы на вопросы из пропущенных 11-й и 12-й лабораторных работ.`

### 11

**1. Из каких частей состоит библиотека STL?**

`1. Контейнеры (Containers): Классы для хранения коллекций объектов.`
`2. Алгоритмы (Algorithms): Функции для обработки последовательностей данных.`
`3. Итераторы (Iterators): Объекты, предоставляющие доступ к элементам контейнеров.`
`4. Функторы (Functors): Функциональные объекты.`

**2. Какие типы контейнеров существуют в STL?**

`1. Последовательные контейнеры: vector, deque, list, forward_list, array, basic_string.`
`2. Ассоциативные контейнеры: set, multiset, map, multimap.`
`3. Неупорядоченные ассоциативные контейнеры: unordered_set, unordered_multiset, unordered_map, unordered_multimap.`
`4. Адаптеры контейнеров: stack, queue, priority_queue.`

**3. Что нужно сделать для использования контейнера STL в своей программе?**

`Подключить необходимый заголовочный файл контейнера, например, #include <vector>. Использовать пространство имен std, либо указывать его перед каждым типом или функцией STL.`

**4. Что представляет собой итератор?**

`Итератор представляет собой объект, который используется для перебора элементов контейнера.`

**5. Какие операции можно выполнять над итераторами?**

`*iter: разыменование итератора для доступа к значению элемента, ++iter и --iter: перемещение итератора вперёд или назад, iter + n и iter - n: сдвиг итератора на n позиций вперёд или назад (только для итераторов произвольного доступа).`

**6. Каким образом можно организовать цикл для перебора контейнера с использованием итератора?**

```cpp
for (auto it = container.begin(); it != container.end(); ++it)
{
    // Действия с *it
}
```

**7. Какие типы итераторов существуют?**

`Итераторы ввода и вывода, Однонаправленные итераторы, Двунаправленные итераторы, Итераторы произвольного доступа, Реверсивные итераторы.`

**8. Перечислить операции и методы общие для всех контейнеров.**

`begin() и end(): возвращают итераторы на начало и конец контейнера.`
`size(): возвращает количество элементов в контейнере.`
`empty(): проверяет, пуст ли контейнер.`
`clear(): удаляет все элементы из контейнера.`

**9. Какие операции являются эффективными для контейнера vector? Почему?**

`Эффективные операции для контейнера vector включают добавление и удаление элементов в конце контейнера и работу с элементами по индексу, так как vector представляет собой динамический массив, и эти операции не требуют перемещения остальных элементов или перебора элементов.`

**10. Какие операции являются эффективными для контейнера list? Почему?**

`Эффективные операции для контейнера list включают вставку и удаление элементов в любом месте списка, так как list является двусвязным списком, и эти операции не требуют перемещения других элементов. Самым эффективным является добавление в конец или начало, так как оно не требует перемещения по указателям до нужного места.`

**11. Какие операции являются эффективными для контейнера deque? Почему?**

`Эффективными операциями для контейнера deque в C++ являются добавление (push_front, push_back) и удаление (pop_front, pop_back) элементов как с начала, так и с конца контейнера. Это связано с тем, что deque (двусторонняя очередь) разработана таким образом, чтобы обеспечивать быструю вставку и удаление элементов на обоих концах.`

**12. Перечислить методы, которые поддерживает последовательный контейнер vector.**

`push_back - добавление элемента в конец`
`pop_back - удаление последнего элемента`
`at - доступ к элементу по индексу с проверкой границ`
`front - доступ к первому элементу`
`back - доступ к последнему элементу`
`begin, end - итераторы для начала и конца`
`rbegin, rend - обратные итераторы`
`empty - проверка на пустоту`
`size - получение размера`
`clear - очистка содержимого`
`insert - вставка элементов`
`erase - удаление элементов`
`resize - изменение размера`
`shrink_to_fit - уменьшает ёмкость до размера`

**13. Перечислить методы, которые поддерживает последовательный контейнер list.**

`push_front, push_back - добавление элементов в начало/конец`
`pop_front, pop_back - удаление элементов из начала/конца`
`front, back - доступ к первому/последнему элементу`
`begin, end - итераторы для начала и конца`
`rbegin, rend - обратные итераторы`
`empty - проверка на пустоту`
`size - получение размера`
`clear - очистка содержимого`
`insert - вставка элементов`
`erase - удаление элементов`
`resize - изменение размера`

**14. Перечислить методы, которые поддерживает последовательный контейнер deque.**

`push_front, push_back - добавление элементов в начало/конец`
`pop_front, pop_back - удаление элементов из начала/конца`
`at, operator[] - доступ к элементам`
`front, back - доступ к первому/последнему элементу`
`begin, end - итераторы для начала и конца`
`rbegin, rend - обратные итераторы`
`empty - проверка на пустоту`
`size - получение размера`
`clear - очистка содержимого`
`insert - вставка элементов`
`erase - удаление элементов`
`resize - изменение размера`
`shrink_to_fit - уменьшает ёмкость до размера`

**15. Задан контейнер vector. Как удалить из него элементы со 2 по 5?**

```cpp
std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
v.erase(v.begin() + 1, v.begin() + 4); // Удаляются числа 2, 3, 4, 5
```

**16. Задан контейнер vector. Как удалить из него последний элемент?**

```cpp
std::vector<int> v = {1, 2, 3, 4, 5, 6};
v.pop_back(); // Удаляется число 6
```

**17. Задан контейнер list. Как удалить из него элементы со 2 по 5?**

```cpp
std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8};
auto it1 = std::next(l.begin(), 1);
auto it2 = std::next(l.begin(), 5);
l.erase(it1, it2); // Удаляются числа 2, 3, 4, 5
```

**18. Задан контейнер list. Как удалить из него последний элемент?**

```cpp
std::list<int> l = {1, 2, 3, 4, 5, 6};
l.pop_back(); // Удаляется число 6
```

**19. Задан контейнер deque. Как удалить из него элементы со 2 по 5?**

```cpp
std::deque<int> d = {1, 2, 3, 4, 5, 6, 7, 8};
d.erase(d.begin() + 1, d.begin() + 5); // Удаляются числа 2, 3, 4, 5
```

**20. Задан контейнер deque. Как удалить из него последний элемент?**

```cpp
std::deque<int> d = {1, 2, 3, 4, 5, 6};
d.pop_back(); // Удаляется число 6
```
`Важно помнить, что метод erase принимает итераторы, указывающие на начало и конец диапазона удаления, и удаляет элементы в полуоткрытом интервале [начало, конец), включая элемент, на который указывает начальный итератор, но исключая элемент, на который указывает конечный итератор.`

**21. Написать функцию для печати последовательного контейнера с использованием итератора.**

```cpp
template <typename T>
void printContainer(const T& container)
{
    for (auto it = container.begin(); it != container.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
```

**22. Что представляют собой адаптеры контейнеров?**

`Адаптеры контейнеров в C++ не являются самостоятельными контейнерами. Они используют другие контейнеры (например, deque или vector) для хранения элементов, но предоставляют свой интерфейс для работы с этими элементами. В стандартной библиотеке есть адаптеры std::stack, std::queue и std::priority_queue.`

**23. Чем отличаются друг от друга объявления stack<int> s и stack<int, list<int> > s?**

`stack<int> s и stack<int, list<int>> s заключаются в использовании разных типов контейнеров для внутреннего хранения элементов. По умолчанию stack<int> использует deque<int>, а stack<int, list<int>> использует list<int>.`

**24. Перечислить методы, которые поддерживает контейнер stack.**

`push() - добавляет элемент в стек`
`pop() - удаляет верхний элемент из стека`
`top() - возвращает верхний элемент стека`
`empty() - проверяет, пуст ли стек`
`size() - возвращает количество элементов в стеке`

**25. Перечислить методы, которые поддерживает контейнер queue.**

`push() - добавляет элемент в конец очереди`
`pop() - удаляет первый элемент из очереди`
`front() - возвращает первый элемент очереди`
`back() - возвращает последний элемент очереди`
`empty() - проверяет, пуста ли очередь`
`size() - возвращает количество элементов в очереди4.`

**26. Чем отличаются друг от друга контейнеры queue и priority_queue?**

`queue работает по принципу FIFO (First In, First Out), где элементы обрабатываются в порядке их добавления.`
`priority_queue упорядочивает элементы по приоритету (например, большие int имеют более высокий приоритет, чем меньшие), обеспечивая быстрый доступ к элементу с наивысшим приоритетом, который не обязательно является первым добавленным.`

**27. Задан контейнер stack. Как удалить из него элемент с заданным номером?**

```cpp
void removeAt(std::stack<int>& st, int index)
{
    std::vector<int> temp;
    int currentIndex = 0;
    while (!st.empty())
	{
        if (currentIndex++ != index)
		{
            temp.push_back(st.top());
        }
        st.pop(); // выкидываем элемент, который нужно удалить
    }
    for (auto it = temp.rbegin(); it != temp.rend(); ++it)
	{
        st.push(*it); // возвращаем все обратно в стек
    }
}
```

**28. Задан контейнер queue. Как удалить из него элемент с заданным номером?**

```cpp
void removeAt(std::queue<int>& q, int index)
{
    std::queue<int> temp;
    int currentIndex = 0;
    while (!q.empty())
	{
        if (currentIndex++ != index)
		{
            temp.push(q.front());
        }
        q.pop(); // выкидываем элемент, который нужно удалить
    }
    q = temp; // присваиваем исходной очереди обработанную
}
```

**29. Написать функцию для печати контейнера stack с использованием итератора.**

```cpp
// В стандартной библиотеке C++ стек не предоставляет итераторов.
// Но, если сильно хочется, можно переделать стек в вектор и произвести эти махинации с ним, после чего переделать vector обратно в стек
void printVector(std::vector<int>& v)
{
    for (auto it = v.rbegin(); it != v.rend(); ++it)
	{
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
// здесь приведена функция вывода вектора через итератор, функции преобразования стека в вектор и обратно есть в 11 методичке, если это кому-то нужно
```

**30. Написать функцию для печати контейнера queue с использованием итератора.**

`С очередью ситуация та же, что и со стеком, функции преобразования очреди в вектор и вектора в очередь можно найти в этом отчёте.`

### 12

**1. Что представляет собой ассоциативный контейнер?**

`Ассоциативный контейнер в C++ — это контейнер, который хранит элементы в виде пар “ключ-значение”. Каждый элемент ассоциирован с уникальным ключом, который используется для доступа к соответствующему значению.`

**2. Перечислить ассоциативные контейнеры библиотеки STL.**

`Ассоциативные контейнеры библиотеки STL включают set, map, multiset, multimap, а также их неупорядоченные версии: unordered_set, unordered_map, unordered_multiset, unordered_multimap.`

**3. Каким образом можно получить доступ к элементам ассоциативного контейнера?**

`Доступ к элементам ассоциативного контейнера можно получить с помощью ключа через оператор [] или метод find(). Также можно использовать итераторы для обхода элементов.`

**4. Привести примеры методов, используемых в ассоциативных контейнерах.**

`insert() — вставка элемента`
`erase() — удаление элемента по ключу`
`find() — поиск элемента по ключу`
`size() — получение количества элементов`
`empty() — проверка на пустоту контейнера`

**5. Каким образом можно создать контейнер map? Привести примеры.**

```cpp
std::map<int, std::string> m;
m.insert(std::make_pair(1, "One"));
m.insert(std::make_pair(2, "Two"));
```
или
```cpp
std::map<int, std::string> m = {{1, "One"}, {2, "Two"}};
```

**6. Каким образом упорядочены элементы в контейнере map по умолчанию? Как изменить порядок на обратный?**

`Элементы в контейнере map упорядочены по ключу в порядке возрастания. Чтобы изменить порядок на обратный, можно использовать специальный компаратор:`
```cpp
std::map<int, std::string, std::greater<int>> m;
```

**7. Какие операции определены для контейнера map?**

`insert() — вставка элемента.`
`erase() — удаление элемента.`
`find() — поиск элемента.`
`size() — размер контейнера.`
`clear() — очистка контейнера.`
`count() — количество элементов с определенным ключом.`

**8. Написать функцию для добавления элементов в контейнер map с помощью функции make_pair().**

```cpp
void addWithMakePair(std::map<int, std::string>& m, int key, const std::string& value)
{
    m.insert(std::make_pair(key, value));
}
```
`В зависимости от конкретной задачи могут изменяться типы данных в словаре и его ключевом поле и, соответственно, в функции.`

**9. Написать функцию для добавления элементов в контейнер map с помощью функции операции прямого доступа [].**

```cpp
void addWithOperator(std::map<int, std::string>& m, int key, const std::string& value)
{
    m[key] = value;
}
```
`Ситуация та же, что и в предыдущем вопросе.`

**10. Написать функцию для печати контейнера map с помощью итератора.**

```cpp
template<typename K, typename V> // тут то я вспомнил про шаблоны...
void printMapWithIterator(const std::map<K, V>& m)
{
    for (auto it = m.begin(); it != m.end(); ++it)
	{
        std::cout << it->first << ": " << it->second << std::endl;
    }
}
```

**11. Написать функцию для печати контейнера map с помощью функции операции прямого доступа [].**

```cpp
template<typename K, typename V>
void printMapWithAccessOperator(const std::map<K, V>& m)
{
    for (const auto& key : m) // этот страшный цикл означает то, что будут перебраны все элементы
	{
        std::cout << key.first << ": " << m.at(key.first) << std::endl;
    }
}
```

**12. Чем отличаются контейнеры map и multimap?**

`map хранит уникальные ключи, тогда как multimap может иметь несколько элементов с одинаковыми ключами.`
`В map каждый ключ связан с одним значением, в multimap один ключ может быть связан с несколькими значениями.`
`Сортировка по ключу в них работает немного по разному.`

**13. Что представляет собой контейнер set?**

`set - это ассоциативный контейнер, содержащий уникальный набор отсортированных элементов.`

**14. Чем отличаются контейнеры map и set?**

`map хранит пары ключ-значение, set хранит только уникальные ключи.`
`В map доступ к элементам осуществляется по ключу, в set - по значению.`

**15. Каким образом можно создать контейнер set? Привести примеры.**

```cpp
int main()
{
    std::set<int> exampleSet; // Пустой set
    exampleSet.insert(1); // Добавление элемента
    exampleSet.insert(2);
    return 0;
}
```

**16. Каким образом упорядочены элементы в контейнере set по умолчанию? Как изменить порядок на обратный?**

`Элементы в set упорядочены по возрастанию по умолчанию.`
`Чтобы изменить порядок на обратный, можно использовать std::greater в качестве компаратора, как это было показано с map.`

**17. Какие операции определены для контейнера set?**

`insert, erase, find, count, clear, size, empty`

**18. Написать функцию для добавления элементов в контейнер set.**

```cpp
void addElement(std::set<int>& s, int element) // ...и тут я снова забыл про шаблоны ...
{
    s.insert(element);
}
```

**19. Написать функцию для печати контейнера set.**

```cpp
template<typename T> // ... но быстро о них вспомнил
void printSet(const std::set<T>& s)
{
    for (const auto& element : s) // мой НЕ любимый цикл
	{
        std::cout << element << std::endl;
    }
}
```

**20. Чем отличаются контейнеры set и multiset?**

`set хранит только уникальные элементы, multiset может содержать дубликаты элементов.`

