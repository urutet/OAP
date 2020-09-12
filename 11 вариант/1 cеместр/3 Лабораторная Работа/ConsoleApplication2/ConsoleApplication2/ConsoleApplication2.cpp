// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double s, d;
	cout << "¬ведите длину диагонали ";
	cin >> d;
	s = pow(d, 2) / 2;
	cout << "s= " << s;
}