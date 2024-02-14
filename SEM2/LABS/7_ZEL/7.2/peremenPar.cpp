#include <iostream>
using namespace std;
int min(int k, ...)
{
	int* s = &k+2;
	int mini = *s;
	for(int i = 0; i < k; i++)
	{
		if (*(s + 2 * i) < mini)
		{
			mini = *s;
		}
	}
	return mini;
}
int main()
{
	cout << min(5, 1, 4, 5, 7, 4) << endl;
	cout << min(10, 2, 3, 5, 8, 11, 22, 312, 1, 23, 43) << endl;
	cout << min(12, 101, 314, 512, 724, 122, 233, 345, 543, 678, 122, 344, 987) << endl;
	return 0;
}