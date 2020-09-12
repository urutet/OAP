#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;
Address* head = NULL;
Address* tail = NULL;





void main()
{
	int k, num, i;
	Address* temp;
	do
	{
		cout << "Choose an option" << endl;
		cout << "1 - Input" << endl;
		cout << "2 - Output" << endl;
		cout << "3 - Delete" << endl;
		cout << "4 - Find" << endl;
		cout << "5 - ChangeX" << endl;
		cout << "6 - 3rd dop" << endl;
		cout << "99 - Exit" << endl;
		cin >> k;
		switch (k)
		{
		case 1: temp = setElement(); input(temp, &head, &tail); break;
		case 2: output(&head, &tail); break;
		case 3: cout << "Enter Int" << endl; cin >> num; delet(num, &head, &tail); break;
		case 4: cout << "Enter Int" << endl; cin >> num; find(num, &head); break;
		case 5: cout << "Enter num of symbol to change" << endl; cin >> i; cout << "Enter Int" << endl; cin >> num; changeX(i, num, &head); break;
		case 6: circle(&head, &tail); break;
		}
	} while (k != 99);
}