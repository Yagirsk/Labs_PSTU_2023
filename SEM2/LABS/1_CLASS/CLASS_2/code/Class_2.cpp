#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
void print_PC(PC s_pc)
{
	s_pc.show();
}
PC make_PC()
{
	string CPU;
	int RAM, HDD;
	cout << "Введите название ЦП компьютера: ";
	cin >> CPU;
	cout << "Введите объем ОЗУ компьютера: ";
	cin >> RAM;
	cout << "Введите объем жесткого диска компьютера: ";
	cin >> HDD;
	PC pc_n(CPU, RAM, HDD);
	return pc_n;
}
int main()
{
	setlocale(LC_ALL, "ru_RU");
	PC PC_1;
	PC_1.show();
	cout << endl;

	PC PC_2("Intel core i5", 16, 1024);
	PC_2.show();
	cout << endl;

	PC PC_3 = PC_2;
	PC_3.set_CPU("Эльбрус");
	PC_3.set_RAM(64);
	PC_3.set_HDD(2048);
	print_PC(PC_3);
	cout << endl;

	PC_1 = make_PC();
	PC_1.show();
}