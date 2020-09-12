// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <iostream>
#include <stdio.h>
//void main()  //trapecija
//
//{
//	int a, b, n = 200;
//	float h, s = 0, x, func, func1;
//	printf ("Vvedite a \n");
//	scanf_s("%d", &a);
//	x = a;
//	printf("Vvedite b \n");
//	scanf_s("%d", &b);
//	h = (float) (b - a) / n;
//	
//	for (x; x < (b - h); x = x + h){
//		s = s + h*(sin(x) + 1 + sin(x + h) + 1) / 2;
//	}
//	printf("%f", s);
//}
//
//void main() //parabola
//{
//		int a, b, n = 200, i = 1;
//		float z, h, s1 = 0, s2 = 0, x;
//		printf ("Vvedite a \n");
//		scanf_s("%d", &a);
//		printf("Vvedite b \n");
//		scanf_s("%d", &b);
//		h = (b - a)/(2.0*n);
//		x = a + 2*h;
//		do {
//			s2 = s2 + sin(x) + 1;
//			x = x + h;
//			s1 = s1 + sin(x) + 1;
//			x = x + h;
//			i = i + 1;
//		}
//		while (i < n);
//		z = h/3*(sin(a) + 1 + 4 * sin(a + h) + 1 + 4 * s1 + 2 * s2 + sin(b) + 1);
//		printf("%f", z);
//}
//
//void main() //kasatelnaya
//{
//	int a, b, n = 200, i = 1;
//	float z, h, s1 = 0, s2 = 0, x = 0, e = 0.0001, x1;
//	printf ("Vvedite a\n");
//	scanf_s("%d", &a);
//	printf("Vvedite b\n");
//	scanf_s("%d", &b);
//	printf("Vvedite e\n");
//	scanf_s("%f", &e);
//	if ((sin(a) + pow(a, 3)*(-sin(a) + 6 * a)) > 0){
//		x1 = a;
//	}
//	if ((sin(b) + pow(b, 3)*(-sin(b) + 6 * b)) > 0) {
//		x1 = b;
//	}
//	do {
//		x = x1;
//		x1 = x - (sin(x) + pow(x, 3)) / (cos(x) + 3 * pow(x, 2));
//		}
//		while (abs(x1 - x) > e);
//		printf("x1 = %f", x1);
//	}

//void main() //dihtomiya
//{
//	int a, b;
//	float x, e;
//	printf("Vvedite a\n");
//	scanf_s("%d", &a);
//	printf("Vvedite b\n");
//	scanf_s("%d", &b);
//	printf("Vvedite e\n");
//	scanf_s("%f", &e);
//	do {
//		x = (a + b) / 2.0;
//		if (((sin(x) + pow(x, 3))*(sin(a) + pow(a, 3))) <= 0){
//		b = x;
//		}
//		else {
//		a = x;
//		}
//	} while (abs(a - b) > (2 * e));
//	printf("x = %f", x);
//}

//void main()  //trapecija
//
//{
//	int a, b, n = 200;
//	float h, s = 0, x, func, func1;
//	printf ("Vvedite a \n");
//	scanf_s("%d", &a);
//	x = a;
//	printf("Vvedite b \n");
//	scanf_s("%d", &b);
//	h = (float) (b - a) / n;
//	
//	for (x; x < (b - h); x = x + h){
//		s = s + h*(pow(x,3)-3 + pow(x+h)-3) / 2;
//	}
//	printf("%f", s);
//}
//
//void main() //parabola
//{
//		int a, b, n = 200, i = 1;
//		float z, h, s1 = 0, s2 = 0, x;
//		printf ("Vvedite a \n");
//		scanf_s("%d", &a);
//		printf("Vvedite b \n");
//		scanf_s("%d", &b);
//		h = (b - a)/(2.0*n);
//		x = a + 2*h;
//		do {
//			s2 = s2 + pow(x,3)-3;
//			x = x + h;
//			s1 = s1 + pow(x,3)-3;
//			x = x + h;
//			i = i + 1;
//		}
//		while (i < n);
//		z = h/3*(pow(a,3) -3 + 4 * (pow(a + h,3) -3) + 4 * s1 + 2 * s2 + pow(x,3)-3;
//		printf("%f", z);
//}
//
void main() //kasatelnaya
{
	int a, b, n = 200, i = 1;
	float z, h, s1 = 0, s2 = 0, x = 0, e = 0.0001, x1;
	printf("Vvedite a\n");
	scanf_s("%d", &a);
	printf("Vvedite b\n");
	scanf_s("%d", &b);
	printf("Vvedite e\n");
	scanf_s("%f", &e);
	if ((pow(a, 3) + a - 3 )*(6*a) > 0){
		x1 = a;
	}
	if ((pow(b, 3) + a - 3)*(6 * a) > 0) {
		x1 = b;
	}
	do {
		x = x1;
		x1 = x - ((pow(x,3)+x-3) / (3*pow(x,2)+1));
	} while (abs(x1 - x) > e);
	printf("x1 = %f", x1);
}

//void main() //dihtomiya
//{
//	int a, b;
//	float x, e;
//	printf("Vvedite a\n");
//	scanf_s("%d", &a);
//	printf("Vvedite b\n");
//	scanf_s("%d", &b);
//	printf("Vvedite e\n");
//	scanf_s("%f", &e);
//	do {
//		x = (a + b) / 2.0;
//		if (((sin(x) + pow(x, 3))*(sin(a) + pow(a, 3))) <= 0){
//		b = x;
//		}
//		else {
//		a = x;
//		}
//	} while (abs(a - b) > (2 * e));
//	printf("x = %f", x);
//}

//void main()  //trapecija
//
//{
//	int a, b, n = 200;
//	float h, s = 0, x, func, func1;
//	printf ("Vvedite a \n");
//	scanf_s("%d", &a);
//	x = a;
//	printf("Vvedite b \n");
//	scanf_s("%d", &b);
//	h = (float) (b - a) / n;
//	
//	for (x; x < (b - h); x = x + h){
//		s = s + h*(sin(x) + 1 + sin(x + h) + 1) / 2;
//	}
//	printf("%f", s);
//}
//
//void main() //parabola
//{
//		int a, b, n = 200, i = 1;
//		float z, h, s1 = 0, s2 = 0, x;
//		printf ("Vvedite a \n");
//		scanf_s("%d", &a);
//		printf("Vvedite b \n");
//		scanf_s("%d", &b);
//		h = (b - a)/(2.0*n);
//		x = a + 2*h;
//		do {
//			s2 = s2 + sin(x) + 1;
//			x = x + h;
//			s1 = s1 + sin(x) + 1;
//			x = x + h;
//			i = i + 1;
//		}
//		while (i < n);
//		z = h/3*(sin(a) + 1 + 4 * sin(a + h) + 1 + 4 * s1 + 2 * s2 + sin(b) + 1);
//		printf("%f", z);
//}
//
void main() //kasatelnaya
{
	int a, b, n = 200, i = 1;
	float z, h, s1 = 0, s2 = 0, x = 0, e = 0.0001, x1;
	printf("Vvedite a\n");
	scanf_s("%d", &a);
	printf("Vvedite b\n");
	scanf_s("%d", &b);
	printf("Vvedite e\n");
	scanf_s("%f", &e);
	if ((sin(a) + pow(a, 3)*(-sin(a) + 6 * a)) > 0){
		x1 = a;
	}
	if ((sin(b) + pow(b, 3)*(-sin(b) + 6 * b)) > 0) {
		x1 = b;
	}
	do {
		x = x1;
		x1 = x - (sin(x) + pow(x, 3)) / (cos(x) + 3 * pow(x, 2));
	} while (abs(x1 - x) > e);
	printf("x1 = %f", x1);
}

//void main() //dihtomiya
//{
//	int a, b;
//	float x, e;
//	printf("Vvedite a\n");
//	scanf_s("%d", &a);
//	printf("Vvedite b\n");
//	scanf_s("%d", &b);
//	printf("Vvedite e\n");
//	scanf_s("%f", &e);
//	do {
//		x = (a + b) / 2.0;
//		if (((sin(x) + pow(x, 3))*(sin(a) + pow(a, 3))) <= 0){
//		b = x;
//		}
//		else {
//		a = x;
//		}
//	} while (abs(a - b) > (2 * e));
//	printf("x = %f", x);
//}

//void main()  //trapecija
//
//{
//	int a, b, n = 200;
//	float h, s = 0, x, func, func1;
//	printf ("Vvedite a \n");
//	scanf_s("%d", &a);
//	x = a;
//	printf("Vvedite b \n");
//	scanf_s("%d", &b);
//	h = (float) (b - a) / n;
//	
//	for (x; x < (b - h); x = x + h){
//		s = s + h*(sin(x) + 1 + sin(x + h) + 1) / 2;
//	}
//	printf("%f", s);
//}
//
//void main() //parabola
//{
//		int a, b, n = 200, i = 1;
//		float z, h, s1 = 0, s2 = 0, x;
//		printf ("Vvedite a \n");
//		scanf_s("%d", &a);
//		printf("Vvedite b \n");
//		scanf_s("%d", &b);
//		h = (b - a)/(2.0*n);
//		x = a + 2*h;
//		do {
//			s2 = s2 + sin(x) + 1;
//			x = x + h;
//			s1 = s1 + sin(x) + 1;
//			x = x + h;
//			i = i + 1;
//		}
//		while (i < n);
//		z = h/3*(sin(a) + 1 + 4 * sin(a + h) + 1 + 4 * s1 + 2 * s2 + sin(b) + 1);
//		printf("%f", z);
//}
//
void main() //kasatelnaya
{
	int a, b, n = 200, i = 1;
	float z, h, s1 = 0, s2 = 0, x = 0, e = 0.0001, x1;
	printf("Vvedite a\n");
	scanf_s("%d", &a);
	printf("Vvedite b\n");
	scanf_s("%d", &b);
	printf("Vvedite e\n");
	scanf_s("%f", &e);
	if ((sin(a) + pow(a, 3)*(-sin(a) + 6 * a)) > 0){
		x1 = a;
	}
	if ((sin(b) + pow(b, 3)*(-sin(b) + 6 * b)) > 0) {
		x1 = b;
	}
	do {
		x = x1;
		x1 = x - (sin(x) + pow(x, 3)) / (cos(x) + 3 * pow(x, 2));
	} while (abs(x1 - x) > e);
	printf("x1 = %f", x1);
}

//void main() //dihtomiya
//{
//	int a, b;
//	float x, e;
//	printf("Vvedite a\n");
//	scanf_s("%d", &a);
//	printf("Vvedite b\n");
//	scanf_s("%d", &b);
//	printf("Vvedite e\n");
//	scanf_s("%f", &e);
//	do {
//		x = (a + b) / 2.0;
//		if (((sin(x) + pow(x, 3))*(sin(a) + pow(a, 3))) <= 0){
//		b = x;
//		}
//		else {
//		a = x;
//		}
//	} while (abs(a - b) > (2 * e));
//	printf("x = %f", x);
//}