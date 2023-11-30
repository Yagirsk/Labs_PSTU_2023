#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float a;
	int n;
	float max = -1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a = sin(n + i / n);
		a = round(a * 10) / 10;
		if (a >= max)
		{
			max = a;
		}
	}
	int sh = 0;
	for (int i = 1; i <= n; i++)
	{
		a = sin(n + i / n);
		a = round(a * 10) / 10;
		if (a == max)
		{
			sh += 1;
		}
	}
	cout << sh - 1 << endl;
	return 0;
}