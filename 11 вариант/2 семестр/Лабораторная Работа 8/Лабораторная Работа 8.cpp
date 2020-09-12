#include <iostream>
#include "Lab8.h"
using namespace std;

queue* head = NULL;
queue* tail = NULL;
floatqueue* floatHead = NULL;
floatqueue* floatTail = NULL;

int main()
{
	int k, num;
	char ch;
	float number;
	for (;;)
	{
		cout << "1 - Input Symbol" << endl;
		cout << "2 - Output" << endl;
		cout << "3 - Delete" << endl;
		cout << "4 - Symbol Split" << endl;
		cout << "5 - Input Number" << endl;
		cout << "6 - Number Shift to Max" << endl;
		cout << "7 - pInput" << endl;
		cout << "8 - pOutput" << endl;
		cout << "9 - File Read" << endl;
		cout << "99 - Exit" << endl;
		cin >> k;
		switch (k)
		{
		case 1: cout << "Input a symbol" << endl; cin >> ch; input(head, tail, ch); break;
		case 2: output(head); break;
		case 3: symbolDelete(head); break;
		case 4: symbolSplit(head); break;
		case 5: cout << "Input a number" << endl; cin >> number;  input(floatHead, floatTail, number); break;
		case 6: sdvigBashkiDoMax(floatHead, floatTail); break;
		case 7: cout << "Input int" << endl; cin >> num; cout << "Input a char" << endl; cin >> ch; pInput(num, ch); break;
		case 8: poutput(); break;
		case 9: fileRead(); break;
		case 99: return 0; break;
		}
	}
	return 0;
}