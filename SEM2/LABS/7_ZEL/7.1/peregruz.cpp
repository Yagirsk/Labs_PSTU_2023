#include <iostream>
using namespace std;
struct Complex 
{
    double real;
    double komp;
};
Complex subtract(Complex knum1, Complex knum2) 
{
    Complex result;
    result.real = knum1.real - knum2.real;
    result.komp = knum1.komp - knum2.komp;
    return result;
}
double subtract(double rnum1, double rnum2)
{
    double result;
    result = rnum1 - rnum2;
    return result;
}
int main() 
{
    setlocale(LC_ALL, "ru_RU");
    int rnum1, rnum2, rresult;
    Complex knum1, knum2, kresult;

    cin >> rnum1;
    cin >> rnum2;
    rresult = subtract(rnum1, rnum2);
    cout << "Результат: " << rresult << endl;

    cin >> knum1.real >> knum1.komp;
    cin >> knum2.real >> knum2.komp;
    kresult = subtract(knum1, knum2);
    cout << "Результат: " << kresult.real << " + " << kresult.komp << "i" << endl;
    return 0;
}
