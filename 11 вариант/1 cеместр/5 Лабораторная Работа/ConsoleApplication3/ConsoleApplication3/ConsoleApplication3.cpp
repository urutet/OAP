// ConsoleApplication3.cpp : Defines the entry point for the console application.
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
	float a, m = 16, j = 0.1, w, r;
	for (int n = 1; n <= 3; n++) {
		printf("¬ведите a ");
		scanf_s("%f", &a);
	while (j < 0.4)
		{
			w = tan(a / 3) + exp(a / m);
			r = 0.9*sqrt(w + j) + abs(pow(a, 2) - 1);
			cout << "w=" << w << "\t";
			cout << " r=" << r << endl;
			j = j + 0.1;
		}
	}
}