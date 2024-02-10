#include <iostream>
using namespace std;
void TOH(int n, char A, char B, char C)
{
    if (n == 1) {
        cout << "Перенести диск " << n << " с штыря " << A << " на штырь " << C << endl;
        return;
    }
    TOH(n - 1, A, C, B);
    cout << "Перенести диск " << n << " с штыря " << A << " на штырь " << C << endl;
    TOH(n - 1, B, A, C);
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    cout << "Введите количество колец\n";
    int n;
    cin >> n;
    cout << "Штырь А - штырь на котором находятся кольца вначале\n";
    cout << "Штырь В - промежуточный штырь\n";
    cout << "Штырь С - штырь на который надо перенести кольца\n";
    TOH(n, 'A', 'B', 'C');
    return 0;
}