#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, str, tmp;
	int k = 0;
	getline(cin, s);
	int d = s.length();
	for (int i = 0; i < d; i++)
	{
		if (s[i] == '0' or s[i] == '1' or s[i] == '2' or s[i] == '3' or s[i] == '4' or s[i] == '5' or s[i] == '6' or s[i] == '7' or s[i] == '8' or s[i] == '9')
		{
			str += s[i];
			for (int j = i; j < d - 1; j++)
			{
				s[j] = s[j + 1];
			}
			i--;
			d--;
		}
	}
	string st = s.substr(0, d);
	st += str;
	cout << st;
	return 0;
}
