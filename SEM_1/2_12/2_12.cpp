#include <iostream>
using namespace std;
int main()
{
	int n, max, min, b;
	cin >> n;
	cin >> b;
	max = b;
	min = b;
	for (int i = 1; i <= n-1; i++)
	{
		int a;
		cin >> a;
		if (a > max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
	}
	int k = max + min;
	cout << k;
	return 0;
}