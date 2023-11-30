#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru_RU");
    int n, s;
    bool t = 0;
    cin >> n >> s;
    int N = n;
    int a;
    while (n != 0)
    {
        a = n % 10;
        if (a == s)
        {
            t = 1;
        }
        n /= 10;
    }
    if (t == 1)
    {
        cout << "цифра " << s << " входит в число " << N << endl;
    }
    else
    {
        cout << "цифра " << s << " не входит в число " << N << endl;
    }
    return 0;
}