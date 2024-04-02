#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	money m_1;
	money m_2;
	money m_3;
	money m_4;
	cin >> m_1;
	cin >> m_2;
	cin >> m_3;
	cin >> m_4;
	cout << "m_1 = " << m_1 << endl;
	cout << "m_2 = " << m_2 << endl;
	cout << "m_3 = " << m_3 << endl;
	cout << "m_4 = " << m_4 << endl;

	cout << "m_1 / m_2 = " << m_1 / m_2 << endl;

	float m;
	cout << "Введите число на которое будет умножено m_3: ";
	cin >> m;
	m_3 = m_3 * m;
	cout << "m_3 = " << m_3 << endl << endl;

	cout << "Введите число на которое будет поделено m_4: ";
	cin >> m;
	m_4 = m_4 / m;
	cout << "m_4 = " << m_4 << endl << endl;
}
