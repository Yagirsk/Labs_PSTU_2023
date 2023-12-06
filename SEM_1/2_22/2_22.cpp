#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float a;
	int n, num = 1;
	float max = -1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a = sin(n + i / n);
		if (a >= max)
		{
			max = a;
			num = i;
		}
	}
	cout << max << endl << num << endl;
	return 0;
}
