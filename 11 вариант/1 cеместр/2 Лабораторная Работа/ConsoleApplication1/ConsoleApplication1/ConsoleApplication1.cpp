// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

///////////////////////LABA2///////////////////////////////////////

/*#include <iostream>
using namespace std;
void main()
{
float w, d, a = 1.5, x = -1.8;
long double z = 15 * pow(10, -9);
w = tan(1)*(1 + x) + z - exp(a);
d = 9 * sqrt(2 - 3 * x) + abs(a + 1);
cout << "w= " << w;
cout << "d= " << d;
}*/

#include <iostream>
using namespace std;
void main()
{
	float s, w, v, a = 1.5, b = -8.1;
	int j = 4;
	long double t = 4 * pow(10, -8);
	s = sqrt(t * a / t + 1) + 4 * exp(2 * b);
	w = s * a / (1 + 0.1 * a);
	v = s + j * sqrt(pow(a, 2) + pow(b, 2));
	cout << "s= " << s;
	cout << "w= " << w;
	cout << "v= " << v;
}