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
	float a = -1.4, m = 16, j, w, r;
	for (int n = 1; n <= 4; n++)
	{
		printf("¬ведите j ");
		scanf_s("%f", &j);
		w = tan(a / 3) + exp(a / m);
		r = 0.9*sqrt(w + j) + abs(pow(a, 2) - 1);
		printf("w = %5.2f\t", w);
		printf("r = %5.2f\n", r);
	}
}
