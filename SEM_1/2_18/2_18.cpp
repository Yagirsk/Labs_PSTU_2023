#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		int k = n % 10;
		n /= 10;
		cout << k;
	}
	return 0;
}
