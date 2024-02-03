#include <iostream>
using namespace std;
int main()
{
	const int d = 100;
	int a[d];
	int n, max;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	cout << max << endl;
	return 0;
}
