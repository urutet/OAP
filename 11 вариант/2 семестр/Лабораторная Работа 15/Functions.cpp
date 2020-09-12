#include <list>
#include <cstring>
#include <iostream>
#include "Header.h"
using namespace std;

bool HASHTABLE::isEmpty() const
{
	int sum = 0;
	for (int i = 0; i < HashGroups; i++)
	{
		sum += table[i].size();
	}
	if (sum == 0)
	{
		cout << "Table is empty" << endl;
		return true;
	}
	else
	{
		cout << "Table isn't empty" << endl;
		return false;
	}
}

int HASHTABLE::hashFunction(int key)
{
	return key * 742543 % HashGroups;
}

void HASHTABLE::insertItem(int key, string str)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto iter = begin(cell);
	bool keyExists = false;
	for (iter; iter != end(cell); iter++)
	{
		if (iter->first == key)
		{
			cell.emplace_back(key, str);
			keyExists = true;
			break;
		}
	}
	if (!keyExists)
	{
		cell.emplace_back(key, str);
	}

}

void HASHTABLE::removeItemByKey(int key)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto iter = begin(cell);
	bool keyExists = false;
	for (iter; iter != end(cell); iter++)
	{
		if (iter->first == key)
		{
			keyExists = true;
			iter = cell.erase(iter);
			cout << "Cell was erased" << endl;
			break;
		}
	}
	if (!keyExists)
	{
		cout << "Threre's no item with this key " << endl;
	}
}

void HASHTABLE::printHashTable()
{
	for (int i = 0; i < HashGroups; i++)
	{
		/*if (table[i].size == 0)
		{
			continue;
		}
		else
		{*/
			auto iter = table[i].begin();
				for (iter; iter != table[i].end(); iter++)
				{
					cout << "Key: " << iter->first << ", value: " << iter->second << endl;
				}
		/*}*/

	}
}

void HASHTABLE::searchItemByKey(int key)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto iter = begin(cell);
	bool keyExists = false;
	for (iter; iter != end(cell); iter++)
	{
		if (iter->first == key)
		{
			keyExists = true;
			cout << "Item found" << endl;
			cout << "Key: " << iter->first << ", value: " << iter->second << endl;

		}
	}
	if (!keyExists)
	{
		cout << "Threre's no item with this key " << endl;
	}
}

//void HASHTABLE::searchItemByValue(string str)
//{
//	int hashValue = hashFunction();
//	auto& cell = table[hashValue];
//	auto iter = begin(cell);
//	bool keyExists = false;
//	for (iter; iter != end(cell); iter++)
//	{
//		if (iter->second == str)
//		{
//			cout << "Item found" << endl;
//			cout << "Key: " << iter->first << ", value: " << iter->second << endl;
//
//		}
//	}
//	if (!keyExists)
//	{
//		cout << "Threre's no item with this key " << endl;
//	}
//}