#include <list>
#include <cstring>
#include <iostream>
#include "Header.h"
using namespace std;

void main()
{
	HASHTABLE h;
	int k, key;
	string str;

	do
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1 - Check HashTable (isEmpty)" << endl;
		cout << "2 - Enter Information" << endl;
		cout << "3 - Remove Item By Key" << endl;
		cout << "4 - Print Table" << endl;
		cout << "5 - Search By Key" << endl;
		cout << "0 - Exit" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter k" << endl;
		cin >> k;
		switch (k)
		{
		case 1: h.isEmpty(); break;
		case 2:  cout << "Enter key: "; cin >> key; cout << endl; cout << "Enter string: "; cin >> str; cout << endl; h.insertItem(key, str); break;
		case 3: cout << "Enter key: "; cin >> key; h.removeItemByKey(key); break;
		case 4: h.printHashTable(); break;
		case 5: cout << "Enter key: "; cin >> key; h.searchItemByKey(key); break;
		}
	} while (k != 0);
}