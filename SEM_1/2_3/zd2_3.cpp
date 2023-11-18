#include <iostream>
using namespace std;
int main()
{
	int n, in;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		in = 1;
		for (int j = i; j <= 2 * i; j++)
		{
			in *= j;
		}
		sum += in;
	}
	cout << sum << endl;
	return 0;
}