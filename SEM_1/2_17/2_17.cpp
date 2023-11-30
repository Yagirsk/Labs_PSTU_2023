#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, x;
	float z = 1;
	cin >> n >> x;
	float sum = 1+x;
	for (int i = 2; i <= n; i++)
	{
		z *= i;
		sum += (pow(x, i) / z);
	}
	cout << sum << endl;
	return 0;
}