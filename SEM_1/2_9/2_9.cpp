#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n/2; i++) // этот и седующий цикл отрисовывают верхнее горизонтольное заднее ребро куба
	{
		cout << "  ";
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "* ";
	} 
	cout << endl;
	for (int i = 1; i <= n/2-1; i++) // цикл отрисовывает между верхней задней и передней горизнтольными ребрами 
	{
		for (int j = n/2 -1; j >= i ; j--)
		{
			cout << "  ";
		}
		cout << "* ";
		for (int j = 1; j <= n - 2; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		for (int j=i; j>1; j--)
		{
			cout << "  ";
		}
		cout << "* \n";
	}
	for (int i = 1; i <= n; i++) // отрисовывает верхнее переднее горизонтальное ребро куба
	{
		cout << "* ";
	}
	for (int i = 1; i <= (n / 2) - 1; i++)
	{
		cout << "  ";
	}
	cout << "*  \n";
	for (int i = 1; i <= (n-1)/2; i++)
	{
		cout << "* ";
		for (int j = 1; j<=n-2; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		for (int j = 1; j<=n/2-1; j++)
		{
			cout << "  ";
		}
		cout << "* \n";
	}
	for (int i = 1; i<n/2; i++)
	{
		cout << "* ";
		for (int j = 1; j<=n-2; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		for (int j = i; j <n/2-1; j++)
		{
			cout << "  ";
		}
		cout << "* \n";
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "* ";
	}
	return 0;
}