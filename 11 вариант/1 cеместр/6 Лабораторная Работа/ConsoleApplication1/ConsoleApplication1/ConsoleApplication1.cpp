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
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	float a = 1.33*pow(10, -3), b, d, x;
	int k = 6;
	for (int n = 1; n <= 4; n++) {
		printf("Введите x ");
		scanf_s("%f", &x);
		d = exp(-x) + (x - a) / log(x);
		if (d >= k + sqrt(a)) {
			b = 6*d*x;
		}
		else {
			b = sin(x / a);
		}
		printf("b = %f \n", b);
		printf("x = %f \n", x);
	}
}

//#include <iostream>
//void main()
//{
//	int f, i, s = 0;
//	using namespace std;
//	setlocale(LC_CTYPE, "Russian");
//	printf("Введите число ");
//	scanf_s("%d", &f);
//	for (i = 10; i <= 99; i++)
//	{
//		if (f == (int(i / 10) + i % 10))
//		s = s + 1;
//		
//	}
//	printf("Количество двузначных чисел %d\n ", s);
//}