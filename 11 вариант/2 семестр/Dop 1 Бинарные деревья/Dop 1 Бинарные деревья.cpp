#include <iostream>
#include "Dop1.h"
using namespace std;





int c = 0;
Tree* Root = NULL;
int N1 = 0;
int N;
Tree2* Root2 = NULL;

void main()
{
	int k, key, number;
	char arr[20], letter;
	Tree* ElementFound, * temp;

	do
	{
		cout << "~~~~~~ CHOOSE THE OPTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1 - New Tree " << endl;
		cout << "2 - Insert Element " << endl;
		cout << "3 - Search " << endl;
		cout << "4 - Delete Element " << endl;
		cout << "5 - Show Tree " << endl;
		cout << "6 - Count " << endl;
		cout << "7 - Clear Tree " << endl;
		cout << "8 - Show reversed" << endl;
		cout << "9 - Show the most popular  plan" << endl;
		cout << "~~~~~~ DOP2 OPTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "11 - Make Tree" << endl;
		cout << "12 - Add Elements " << endl;
		cout << "13 - Show Elements " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "99 - Exit" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cin >> k;
		switch (k)
		{
		case 1: Root = makeTree(Root); break;
		case 2: insertElem(Root); break;
		case 3: cout << "Enter the key: "; cin >> key; cout << endl; ElementFound = search(Root, key); cout << "String found: "; cout << ElementFound; cout << endl; break;
		case 4: cout << "Enter the key: "; cin >> key; delet(Root, key); cout << endl; break;
		case 5: temp = Root; view(temp, 0); cout << endl; break;
		case 6: cout << "Enter the letter: "; cin >> letter; cout << endl; count(Root, letter); break;
		case 7: delAll(Root); break;
		case 8: reverse(Root); break;
		case 9: planComparison(); break;
		case 10: cout << "Enter number: "; cin >> number; cout << endl; numSearch(Root, number); break;
		case 11: cout << "Enter N: "; cin >> N; cout << endl; Root2 = makeTree2(Root2, N); break;
		case 12: while (N >= N1) { insertElem(Root2); } break;
		case 13: view(Root2, 0); break;
		}
	} while (k != 99);
}