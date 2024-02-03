#include <iostream>
using namespace std;
int main()
{
	int lb = 20, ub = 100;
	int arr[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() % (ub - lb + 1)) + lb;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n/2; i++)
	{
		int a = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1 - i] = a;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
