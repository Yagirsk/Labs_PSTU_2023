#include <iostream>
#include <string>
using namespace std;
int main() 
{
	setlocale(LC_ALL; "ru_RU");
	string s;
	char  a, b;
	cin >> s >> a >> b;
	int small = 0;
	int big = 0;
	int other = 0;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		char sim = s[i];
		if (sim == a)
			big++;
		else if (sim == b)
			small++;
		else
			other++;
	}
	cout << "Букв совпадающих с введенной прописной: " << big << endl;
	cout << "Букв совпадающих с введенной строчной: " << small << endl;
	cout << "Букв не совпавших ни с одной из введенных: " << other << endl;
	cout << "Длинна введенной строки: " << s.length() << endl;
	return 0;
}