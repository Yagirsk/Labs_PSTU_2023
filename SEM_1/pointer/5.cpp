#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	long long int n, f = 1;
	long long int* fp = &f;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		*fp *= i;
	}
	cout << "факториал " << n << " равен " << f << endl;
	return 0;
}