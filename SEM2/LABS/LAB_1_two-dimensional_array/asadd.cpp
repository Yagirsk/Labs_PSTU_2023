#include <iostream>
using namespace std;
int main()
{
	const int m = 100, n = 100;
	int a, b;
	cin >> a >> b;
	int arr[m][n];
	int pp = 1;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if ((i + j) % 2 == 1)
			{
				arr[i][j] = 0;
			}
			if ((i + j) % 2 == 0)
			{
				arr[i][j] = pp;
				pp++;
			}
			if (pp == 10)
			{
				pp = 1;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}