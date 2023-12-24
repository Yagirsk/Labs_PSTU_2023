#include <iostream>  // сделано для латиницы т.к. не разоботает с кириллицей
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int gl, sogl;
	gl = sogl = 0;
	string st;
	cin >> st;
	for (int i = 0; i < st.length(); i++)
	{
		wchar_t b = tolower(st[i]);
		if (b == 'a' || b == 'e' || b == 'y' || b == 'u' || b == 'i' || b == 'o' || b == 'a' || b == 'a')
		{
			gl++;
		}
		else
		{
			sogl++;
		}
	}
	cout << gl << endl;
	cout << sogl << endl;
}
