// f(x) = e^x - e^-x - 2
// f'(x) = e^x + e^x
// [0; 1]
// ф(x) = x + l(e^x - e^-x - 2)
// r = max(|f'(a)|, |f'(b)|)
// r = max(|e^0 - e^0-2|, |e^2-1/e^2 - 2|) = max(2, 5.254...) = 5.254
// f'(x) > 0 => -1/r < l < 0
// l = -1/20 = -0.05
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	float x, xpre;
	double lamb = -0.05;
	x = 1;
	xpre = 0;
	double eps = 0.000001;
	while (abs(x - xpre) > eps)
	{
		xpre = x;
		x = xpre + lamb * (exp(xpre) - exp(-xpre) - 2);
	}
	cout << "Корень: " << x << endl;
	return 0;
}
