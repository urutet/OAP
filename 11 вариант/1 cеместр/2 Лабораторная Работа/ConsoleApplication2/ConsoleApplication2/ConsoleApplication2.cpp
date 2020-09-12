// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <iostream>
void main()
{
	double y, r, a = 1.75, b = 4.5 * pow(10, -4);
	y = a * exp(-2*b) - sqrt(1 + a);
	r = log(1 + 20 * b) / (1 + a);
	std::cout << "r = " << r;
}