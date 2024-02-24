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
			cin >> human.name;
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
