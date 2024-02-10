#include <iostream>
using namespace std;
int main()
{
	const int m = 100;
	int a;
	cin >> a;
	int arr[m][m];
	int pp = 0;
	for (int i = 0; i < a; i++)
	{
		pp = 0;
		for (int j = 0; j < a; j++)
		{

			if (j < i) 
			{ 
				arr[j][i] = 0; 
			}
			if (j >= i) 
			{
				arr[j][i] = 1+pp;
				pp++;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
