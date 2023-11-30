#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru_RU");
	float n, s, a;
	int i = 1;
	cin >> n >> s;
	bool t = 0;
	while (i <= n and !t)
	{
		a = sin(n + i / n);  
		a = round(a * 10)/10;
		cout << n + i / n << "|" << a << endl;
		if (a == s)
		{
			t = 1;
		}
		else
		{
			i++;
		}
	}
	if (t == 1)
	{
		cout << s << " входит в последовательность  \n";
	}
	else
	{
		cout << s << " не входит в последовательность \n";
	}
	return 0;
}