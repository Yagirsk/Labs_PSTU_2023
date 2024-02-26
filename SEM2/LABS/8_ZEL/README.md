# 1) Задание

Лабораторная работа №8, вариант 6

Сформировать двоичный файл из элементов, заданной в
варианте структуры, распечатать его содержимое, выполнить
удаление и добавление элементов в соответствии со своим
вариантом, используя для поиска удаляемых или добавляемых
элементов функцию. Формирование, печать, добавление и
удаление элементов оформить в виде функций. Предусмотреть
сообщения об ошибках при открытии файла и выполнении
операций ввода/вывода.

Структура "Школьник":
- фамилия, имя, отчество;
- класс;
- номер телефона;
- оценки по предметам (математика, физика, русский
язык, литература).
Удалить все элементы, у которых есть 2 хотя бы по одному
предмету, добавить элемент в начало файла.

# 2) Код программы

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int num = 1;
vector <string> save;
struct School
{
	string name;
	int classt;
	long long int phone;
	int math;
	int phys;
	int rus;
	int litr;
};
void setS(int n)
{
	ofstream f1("f.txt");
	if (f1.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			School human;
			cout << "Введите ФИО ученика №" << num << endl;
			cin.ignore();
			getline(cin, human.name);
			f1 << human.name << endl;
			cout << "Введите класс ученика" << endl;
			cin >> human.classt;
			f1 << "Класс: " << human.classt << endl;
			cout << "Введите номер телефона ученика" << endl;
			cin >> human.phone;
			f1 << "Номер телефона: " << human.phone << endl;
			cout << "Введите оценку по математике" << endl;
			cin >> human.math;
			f1 << "Оценка по математике: " << human.math << endl;
			cout << "Введите оценку по физике" << endl;
			cin >> human.phys;
			f1 << "Оценка по физике: " << human.phys << endl;
			cout << "Введите оценку по русскому языку" << endl;
			cin >> human.rus;
			f1 << "Оценка по руссному: " << human.rus << endl;
			cout << "Введите оценку по литературе" << endl;
			cin >> human.litr;
			f1 << "Оценка по литературе: " << human.litr << endl;
			num++;
		}
	}
	else
	{
		cout << "Ошибка при открытии файла" << endl;
	}
	f1.close();
}
void show()
{
	ifstream f1("f.txt");
	if (f1.is_open())
	{
		string tmp;
		while (getline(f1, tmp))
		{
			cout << tmp << endl;
		}
		cout << "\n\n";
	}
	else
	{
		cout << "Ошибка при открытии файла" << endl;
	}
	f1.close();
}
void saver()
{
	string tmp;
	ifstream f1("f.txt");
	if (f1.is_open())
	{
		while (getline(f1, tmp))
		{
			save.push_back(tmp);
		}
	}
	else
	{
		cout << "Ошибка при открытии файла" << endl;
	}
	f1.close();
}
void del (int n)
{
	ofstream f3("f.txt");
	if (f3.is_open())
	{
		School human;
		cout << "Введите ФИО нового ученика" << endl;
		cin >> human.name;
		f3 << human.name << endl;
		cout << "Введите класс ученика" << endl;
		cin >> human.classt;
		f3 << "Класс: " << human.classt << endl;
		cout << "Введите номер телефона ученика" << endl;
		cin >> human.phone;
		f3 << "Номер телефона: " << human.phone << endl;
		cout << "Введите оценку по математике" << endl;
		cin >> human.math;
		f3 << "Оценка по математике: " << human.math << endl;
		cout << "Введите оценку по физике" << endl;
		cin >> human.phys;
		f3 << "Оценка по физике: " << human.phys << endl;
		cout << "Введите оценку по русскому языку" << endl;
		cin >> human.rus;
		f3 << "Оценка по руссному: " << human.rus << endl;
		cout << "Введите оценку по литературе" << endl;
		cin >> human.litr;
		f3 << "Оценка по литературе: " << human.litr << endl;
		for (int i = 0; i < n; i++)
		{
			bool extermination = 0;
			for (int j = i * 7 + 3; j < i * 7 + 7; j++)
			{
				string str = save[j];
				for (int k = 0; k < str.length(); k++)
				{
					char b = str[k];
					if (b == '2')
					{
						extermination = 1;
					}
				}
			}
			if (!extermination)
			{
				for (int k = i * 7; k < i * 7 + 7; k++)
				{
					f3 << save[k] << endl;
				}
			}
		}
	}
	else
	{
		cout << "Ошибка при открытии файла" << endl;
	}
	f3.close();
}
int main()
{
	setlocale(LC_ALL, "ru_RU");
	int n;
	cout << "Введите количество учеников" << endl;
	cin >> n;
	setS(n);
	show();
	saver();
	del(n);
	show();
	return 0;
}
```

# 3) Блок схемы
функция main

<image src ="lab8_main.drawio.png">

Функция saver

<image src ="lab8_saver.drawio.png">

Функция del

<image src ="lab8_delT.drawio.png">

Функция setS

<image src ="lab8_set.drawio.png">

Функция show

<image src ="lab8_show.drawio.png">

Структура School

<image src ="lab8_struct.drawio.png">


# 4) Тест

Первоначальный вводв в файл

<image src ="1st_enter.png">

Вывод из файла

<image src ="1st_conclusion.png">

Ввод данных нового ученика

<image src ="newS_enter.png">

Итоговый вывод, с новым учеником вначале, и удаленными учениками с двойкой по любому из предметов

<image src ="final_conclusion.png">

Результат в файле

<image src ="inFILE.png">
