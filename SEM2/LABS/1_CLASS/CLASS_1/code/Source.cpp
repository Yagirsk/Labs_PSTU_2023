#include <iostream>
#include <string>
#include <sstream>
#include "Header.h"
using namespace std;
setlocale(LC_ALL, "ru_RU");
void linear_ur::init()
{
	y = 0;
	x = 0;
	B = 0;
	A = 0;
	r = 1;
}
void linear_ur::read()
{
	//r = 1;
	string A_r, B_r;
	cout << "Ââåäèòå êîýôôèöåíòû A è B ñîîòâåòñòâåííî: ";
	cin >> A_r;
	cin >> B_r;
	if (isFloat(A_r))
	{
		A = stof(A_r);
	}
	else { r = 0; }

	if (isFloat(B_r))
	{
		B = stof(B_r);
	}
	else { r = 0; }
}
bool linear_ur::isFloat(const string& input)
{
	istringstream ss(input);
	float value;
	ss >> noskipws >> value;
	return ss.eof() && !ss.fail();
}
void linear_ur::show()
{
	if (B > 0)
	{
		cout << "y = " << A << "x" << " + " << B << endl;
	}
	else if (B == 0)
	{
		cout << "y = " << A << "x" << endl;
	}
	else
	{
		cout << "y = " << A << "x" << " - " << abs(B) << endl;
	}
}
void linear_ur::function(float x_X)
{
	x = x_X;
	y = A * x + B;
	cout << "y = " << y << endl;
	
}
