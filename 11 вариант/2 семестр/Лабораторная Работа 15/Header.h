#pragma once

#include <list>
#include <cstring>
#include <iostream>
using namespace std;

class HASHTABLE
{
	private:
		static const int HashGroups = 20;
		char str[20];
		list<pair<int, string>> table[HashGroups];
	public:
		bool isEmpty() const;
		int hashFunction(int key);
		void insertItem(int key, string str);
		void removeItemByKey(int key);
		void searchItemByKey(int key);
		/*void searchItemByValue(string str);*/
		void printHashTable();
};	