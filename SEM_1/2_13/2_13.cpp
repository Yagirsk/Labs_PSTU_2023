#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	float a, b, c;
	cout << "квадратное уравнение имее вид ax^2 + bx + c = 0. введите коэфиценты a, b, c соответственно \n";
	cin >> a >> b >> c;
	float D = pow(b,2) - 4 * a * c;
	if (D < 0)
	{
		cout << "нет корней\n";
	}
	else if (D == 0)
	{
		float x = -b / (2 * a);
		cout << x << " корень уравнения\n";
	}
	else 
	{
		float x1 = (-b + sqrt(D)) / (2 * a);
		float x2 = (-b - sqrt(D)) / (2 * a);
		cout << x1 << " первый корень уравнения\n";
		cout << x2 << " второй корень уравнения\n";
	}
	return 0;
}
