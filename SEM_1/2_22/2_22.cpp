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
		if (a >= max)
		{
			max = a;
		}
	}
	cout << max << endl;
	return 0;
}