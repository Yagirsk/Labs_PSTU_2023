#include <iostream>
using namespace std;
int main()
{
	int lb = 1, ub = 100;
	const int n = 100;
	int d;
	cin >> d;
	int a[n];
	for (int i = 0; i < d; i++)
	{
		a[i] = (rand() % (ub - lb + 1) + lb);
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < d; i++)
	{
		if (a[i] % 2 == 1)
		{
			for (int j = i; j < d-1; j++)
			{
				a[j] = a[j + 1];
			}
			d--;
			i--;
		}
	}
	for (int i = 0; i < d; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
