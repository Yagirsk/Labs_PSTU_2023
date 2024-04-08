#pragma once
#include <iostream>
#include <string>
class PC
{
private:
	std::string CPU;
	int RAM;
	int HDD;
public:
	PC();
	PC(std::string name, int RAM, int HDD);
	PC(const PC&);
	~PC();
	std::string get_CPU();
	void set_CPU(std::string name_n);
	int get_RAM();
	void set_RAM(int RAM_n);
	int get_HDD();
	void set_HDD(int HDD_n);
	void show();
};
