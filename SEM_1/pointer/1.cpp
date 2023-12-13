#include <iostream>
using namespace std;
int main()
{
	int a, b, tmp;
	int* aptr;
	int* bptr;
	cin >> a;
	aptr = &a;
	tmp = *aptr;
	cin >> b;
	bptr = &b;
	*aptr = *bptr;
	*bptr = tmp;
	cout << *aptr << endl << *bptr << endl;
	return 0;
}