#include <iostream>
#include "Header.h"
#include <Windows.h>
using namespace std;





void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k;
	do
	{
		cout << "1 - First prog" << endl;
		cout << "2 - Second prog" << endl;
		cout << "3 - Dop3" << endl;
		cout << "99 - Exit" << endl;
		cout << "Enter the number of a program" << endl;
		cin >> k;
		switch (k)
		{
		case 1: prog1(); break;
		case 2: prog2(); break;
		case 3: dop3(); break;
		}
	} while (k != 99);
}

