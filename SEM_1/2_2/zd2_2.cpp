#include <iostream>
using namespace std;
int main()
{
	int n;
	int f = 1;
	cin >> n;
	if (n <= 0)
	{
		cout << "Невозможно посчитать произведение натуральных чисел при n <= 0" << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			f *= i;
		}
	}
	cout << f << endl;
	return 0;
}