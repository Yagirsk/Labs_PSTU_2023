#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
PC::PC()
{
	CPU = "";
	RAM = 0;
	HDD = 0;
	cout << "Конструктор без параметров для объекта " << this << endl;
}
PC::PC(string s, int a, int b)
{
	CPU = s;
	RAM = a;
	HDD = b;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}
PC::PC(const PC& t)
{
	CPU = t.CPU;
	RAM = t.RAM;
	HDD = t.HDD;
	cout << "Конструктор копирования для объекта " << this << endl;
}
PC::~PC()
{
	cout << "Деструктор для объекта " << this << endl;
}
string PC::get_CPU()
{
	return CPU;
}
void PC::set_CPU(std::string CPU_n)
{
	CPU = CPU_n;
}
int PC::get_RAM()
{
	return RAM;
}
void PC::set_RAM(int RAM_n)
{
	RAM = RAM_n;
}
int PC::get_HDD()
{
	return HDD;
}
void PC::set_HDD(int HDD_n)
{
	HDD = HDD_n;
}
void PC::show()
{
	cout << "Название ЦП: " << CPU << "\nRAM: " << RAM << "\nHDD: " << HDD << endl;
}
