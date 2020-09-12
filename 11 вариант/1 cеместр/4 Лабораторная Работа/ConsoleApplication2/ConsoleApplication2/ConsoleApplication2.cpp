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
	setlocale(LC_CTYPE, "Russian");
	float a, b, c, d;
	printf_s("¬ведите a "); scanf_s("%f", &a);
	printf_s("¬ведите b "); scanf_s("%f", &b);
	printf_s("¬ведите c "); scanf_s("%f", &c);
	if (a > b && a > c) {
		d = a;
	}
	else if (a > b && a < c) {
		d = c;
	}
	else if (a < b && b > c) {
		d = b;
	}
	else if (a < b && b < c) {
		d = c;
	}
	printf_s("d = %f", d);
}