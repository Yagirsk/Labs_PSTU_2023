#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            int j = i;
            sum += j;
        }
        else
        {
            int j = -i;
            sum += j;
        }
    }
    cout << sum << endl;
    return 0;
}
