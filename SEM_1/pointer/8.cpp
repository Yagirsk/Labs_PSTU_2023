#include <iostream>
#include <string>
using namespace std;
int main(){
	string s, a, b;
	cin >> s >> a >> b;
	int small = 0;
	int big = 0;
	int other = 0;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		string sim = s.substr(i, 1);
		if (sim == a)
			big++;
		else if (sim == b)
			small++;
		else
			other++;
	}
	cout << big << endl << small << endl << other << endl << s.length();
	return 0;
}