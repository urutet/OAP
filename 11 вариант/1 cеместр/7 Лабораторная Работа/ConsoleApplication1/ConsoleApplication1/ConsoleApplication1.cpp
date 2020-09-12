// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <stdio.h>
#include <iostream>
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int mult = 1;
//	float q, a = 5.45, y, s;
//	for (int n = 1; n <= 5; n++) {
//		printf("¬ведите y ");
//		scanf_s("%f", &y);
//		q = 4 * y / (n + 1);
//		q = mult*q;
//	}
//	s = 2*a + q*sin(a);
//	printf("s = %f\n", s);
//}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	float q = 0, x, y, mult;
	for (int n = 1; n <= 6; n++){
		printf("¬ведите y ");
		scanf_s("%f", &y);
		printf("¬ведите x ");
		scanf_s("%f", &x);
		mult = x*y;
		q = mult + q;
	}
	printf("q= %f\n", q);
}