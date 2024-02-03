#include <iostream>
using namespace std;
int main()
{
	const int n = 100;
	int a[n];
	int d;
	cin >> d;
	for (int i = 0; i < d; i++)
	{
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < d; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = d; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = -1;
			d++;
			i++;
		}
	}
	for (int i = 0; i < d; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}