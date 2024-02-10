#include <iostream>
using namespace std;
int foo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return foo(n - 1) + foo(n - 2);
}
int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a = foo(i);
        cout << a << " ";
    }
    return 0;
}