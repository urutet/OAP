// ConsoleApplication1.cpp : Defines the entry point for the console application.
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
	float x, y, z, Max, Min;
	printf_s("¬ведите x "); scanf_s("%f", &x);
	printf_s("¬ведите y "); scanf_s("%f", &y);
	printf_s("¬ведите z "); scanf_s("%f", &z);
	if (x > y && x > z) {
		Max = x;
	}
	else if (x > y && x < z) {
		Max = z;
	}
	else if (x < y && y > z) {
		Max = y;
	}
	else if (x < y && y < z) {
		Max = z;
	}
	if (x*y < x*z && x*y < y*z){
		Min = x*y;
	}
	else if (x*y < x*z && x*y > y*z){
		Min = y*z;
	}
	else if (x*y > x*z && y*z < x*z){
		Min = y*z;
	}
	else if (x*y > x*z && y*z > x*z){
		Min = x*z;
	}
	printf("Max*min %.2f", Max*Min);
}
