#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int r = sqrt(n);
	if (r*r == n)
	{
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= r; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	else
	{
		setlocale(LC_ALL, "Russian");
		cout << "число не соответсвует требованиям" << endl;
	}
	return 0;
}
