// f(x) = e^x - e^-x - 2
// [0; 1]
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	float a, b, c;
	float fa, fb, fc;
	double eps = 0.000001;
	a = 0;
	b = 1;
	while (b - a > eps)
	{
		c = (a + b) / 2;
		fa = exp(a) - exp(-a) - 2;
		fb = exp(b) - exp(-b) - 2;
		fc = exp(c) - exp(-c) - 2;
		if (fa * fc < 0) { b = c; }
		else if (fb * fc < 0) { a = c; }
		else cout << "Что - то не так \n";
	}
	cout << "Корни: " << a << "; " << b << endl;
	return 0;
}