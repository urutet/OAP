#include <iostream>
//#include <stdio.h>
//#include <cstring>
//#include <cstdlib>

#define _crt_secure_no_warnings
#include <string>
using namespace std;





float trapecja();

float parabola();

float dihtomiya();

float kasatelnaya();

void maxword1();

float main(float)
{
	setlocale(LC_CTYPE, "Russian");
	int c;
	float (*operation)(), result;
	do
	{
		cout << endl;
		cout << "Введите" << endl;
		cout << "1-Трапеция" << endl;
		cout << "2-Парабола" << endl;
		cout << "3-Дихтомия" << endl;
		cout << "4-Касательная" << endl;
		cout << "5-Наибольшее слово" << endl;
		cout << "6-Выход" << endl;
		cin >> c;
		switch (c)
		{
		case 1: operation = trapecja; result = operation(); cout << result << endl;  break;
		case 2: operation = parabola; result = operation(); cout << result << endl; break;
		case 3: operation = dihtomiya; result = operation(); cout << result << endl; break;
		case 4: operation = kasatelnaya; result = operation(); cout << result << endl; break;
		case 5: maxword1();
		case 6: break;
		}
	} while (c != 5);

}



float trapecja()
{
	int a, b, n = 200, i = 1;
	float h, s = 0, x = 0, func, func1, z, s1 = 0, s2 = 0, e = 0.0001, x1;
	printf("Vvedite a \n");
	scanf_s("%d", &a);
	x = a;
	printf("Vvedite b \n");
	scanf_s("%d", &b);
	h = (float)(b - a) / n;

	for (x; x < (b - h); x = x + h) {
		s = s + h * (sin(x) + 1 + sin(x + h) + 1) / 2;
	}
	return s;
}
float parabola()
{
	int a, b, n = 200, i = 1;
	float h, s = 0, x = 0, func, func1, z, s1 = 0, s2 = 0, e = 0.0001, x1;
	printf("Vvedite a \n");
	scanf_s("%d", &a);
	printf("Vvedite b \n");
	scanf_s("%d", &b);
	h = (b - a) / (2.0 * n);
	x = a + 2 * h;
	do {
		s2 = s2 + sin(x) + 1;
		x = x + h;
		s1 = s1 + sin(x) + 1;
		x = x + h;
		i = i + 1;
	} while (i < n);
	z = h / 3 * (sin(a) + 1 + 4 * sin(a + h) + 1 + 4 * s1 + 2 * s2 + sin(b) + 1);
	return z;
}
float dihtomiya()
{
	int a, b, n = 200, i = 1;
	float h, s = 0, x = 0, func, func1, z, s1 = 0, s2 = 0, e = 0.0001, x1;
	printf("Vvedite a\n");
	scanf_s("%d", &a);
	printf("Vvedite b\n");
	scanf_s("%d", &b);
	printf("Vvedite e\n");
	scanf_s("%f", &e);
	do {
		x = (a + b) / 2.0;
		if (((sin(x) + pow(x, 3)) * (sin(a) + pow(a, 3))) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	} while (abs(a - b) > (2 * e));
	return x;
}
float kasatelnaya()
{
	int a, b, n = 200, i = 1;
	float h, s = 0, x = 0, func, func1, z, s1 = 0, s2 = 0, e = 0.0001, x1;
	printf("Vvedite a\n");
	scanf_s("%d", &a);
	printf("Vvedite b\n");
	scanf_s("%d", &b);
	printf("Vvedite e\n");
	scanf_s("%f", &e);
	if ((sin(a) + pow(a, 3) * (-sin(a) + 6 * a)) > 0) {
		x1 = a;
	}
	if ((sin(b) + pow(b, 3) * (-sin(b) + 6 * b)) > 0) {
		x1 = b;
	}
	do {
		x = x1;
		x1 = x - (sin(x) + pow(x, 3)) / (cos(x) + 3 * pow(x, 2));
	} while (abs(x1 - x) > e);
	return x1;
}
void maxword1()
{
	int length;
	char *str;
	char maxword[20], minword[20];
	int i, mx = 0, mn = 0, buf = 0, k = 0, s = 0, firstcharpos = 0, k1 = 0, g, j = 0, j1 = 99, firstpos1 = 0;
	setlocale(LC_CTYPE, "Russian");
	cout << "Input length ";
	cin >> length;
	str = new char[length + 1];
	/*char str[250];*/
	cout << "Input string:";
	gets_s(str, length);
	for (i = 0; i < (strlen(str) - 1); i++)
		if (str[i] != ' ' && str[i] != '\0')
		{
			k++;
			firstcharpos = i - s;
			s++;
			cout << firstcharpos << endl;
		}
		else
		{
			if (k > k1)
			{
				for (g = firstcharpos; g < (firstcharpos + k); g++)
				{
					maxword[g] = str[g];
				}
				k1 = k;
				firstpos1 = firstcharpos;
				k = 0;
				s = 0;
				cout << "k1 " << k1 << endl;
			}
			cout << maxword << endl;
		}
	cout << maxword << endl;
	for (g = firstpos1; g < (firstpos1 + k1); g++)
	{
		cout << maxword[g];
	}
}