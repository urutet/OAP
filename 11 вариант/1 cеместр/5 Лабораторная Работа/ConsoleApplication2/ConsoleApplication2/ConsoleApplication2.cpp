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
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	float a = -1.4, m = 16, j = 1.8, w, r;
	while (j < 3) 
	{
		w = tan(a / 3) + exp(a / m);
		r = 0.9*sqrt(w + j) + abs(pow(a, 2) - 1);
		cout << "w=" << w << "\t";
		cout << " r=" << r << endl;
		j = j + 0.2;
	}
}