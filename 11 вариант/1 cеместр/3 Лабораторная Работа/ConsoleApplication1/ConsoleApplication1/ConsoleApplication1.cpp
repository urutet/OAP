// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <iostream>
#include <iomanip>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int i;
	char s, probel;
	probel = ' ';
	cout << "Введите символ ";
	cin >> s;
	for (i = 1; i <= 20; i++)
	{
		cout << setw(20) << setfill(probel) << probel;
		cout << setw(40) << setfill(s) << s << endl;
	}


}