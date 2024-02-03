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
	int p, q;
	cin >> p >> q;
	while (p < q)
	{
		int a = arr[p-1];
		arr[p-1] = arr[q-1];
		arr[q-1] = a;
		p++;
		q--;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}