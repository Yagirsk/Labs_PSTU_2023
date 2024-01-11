// f(x) = e^x - e^-x - 2
// f'(x) = e^x + e^x
// f''(x) = 2 * e^x
// [0; 1]
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	float x, xpre;
	// f(a) * f''(a) > 0
	// (1-1-2)*(2*1) < 0
	// f(b) * f''(b) > 0
	// (e^2 - 1/e^2 - 2)*(2*e^2) => x0 = b
	x = 1;
	xpre = 0;
	double eps = 0.000001;
	while (abs(x - xpre) > eps) 
	{
		xpre = x;
		x = xpre - (exp(xpre) - exp(-xpre) - 2) / (2 * exp(xpre));
	}
	cout << "Корень: " << x << endl;
	return 0;
}
