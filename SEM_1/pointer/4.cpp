#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	int n, tmp, * ptr = &tmp, max, min;
	cout << "введите длинну последовательности ";
	cin >> n;
	cout << "введите первое число ";
	cin>> *ptr;
	max = *ptr;
	min = *ptr;
	for (int i = 2; i <= n; i++)
	{
		cin >> *ptr;
		if (*ptr > max) { max = *ptr; }
		else if (*ptr < min) { min = *ptr; }
	}
	cout << "максимальный элемент " << max << endl;
	cout << "минимальный элемент " << min << endl;
	return 0;
}