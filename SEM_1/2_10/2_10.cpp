#include <iostream>
using namespace std;
int main()
{
	int n, a;
	cin >> n;
	cin >> a;
	int max = a;
	for (int i = 2; i <= n; i++)
	{
		int b;
		cin >> b;
		if (b > max)
		{
			max = b;
		}
	}
	cout << max;
	return 0;
}
