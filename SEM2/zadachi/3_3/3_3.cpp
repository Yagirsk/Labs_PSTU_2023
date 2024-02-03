#include <iostream>
using namespace std;
int main()
{
	int lb = 0, ub = 200, tmp, sd;
	const int n = 10;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = (rand() % (ub - lb + 1)) + lb;
		cout << a[i] << " ";
	}
	cout << endl;
	cin >> sd;
	for (int i = 0; i < sd; i++)
	{
		tmp = a[0];
		for (int j = 0; j < n; j++)
		{
			a[j] = a[j+1];
		}
		a[n-1] = tmp;
	}
	for (int t = 0; t < n; t++)
	{
		cout << a[t] << " ";
	}
	cout << endl;
	return 0;
}
