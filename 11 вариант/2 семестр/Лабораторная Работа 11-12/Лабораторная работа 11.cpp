#include <iostream>
#include "Lab11.h"
using namespace std;





int c = 0;
Tree* Root = NULL;

void main()
{
	int k, key;
	char arr[20], letter;
	Tree* ElementFound, *temp;

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
		cout << "8 - Main 11" << endl;
		cout << "9 - Dop 5" << endl;
		cout << "10 - Dop 7" << endl;
		cout << "11 - Dop 15" << endl;
		cout << "12 - Show reversed" << endl;
		
		cout << "99 - Exit" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
		case 8: osnova11(); break;
		case 9: dop5(); break;
		case 10: dop7(); break;
		case 11: dop15(); break;
		case 12: reverse(Root); break;
		}
	} while (k != 99);
}





//#include <iostream>
//using namespace std;
//
//struct Tree
//{
//	int key;
//	char* arr;
//	Tree* left;
//	Tree* right;
//};
//
//Tree* setRoot(char* arr, int key)
//{
//	Tree* root = new Tree;
//	root->arr = arr;
//	root->key = key;
//	root->left = NULL;
//	root->right = NULL;
//	return root;
//}
//
//
//
//
//Tree* insert(Tree* root, char* arr, int key)
//{	
//	if (root == NULL)
//	{
//		root = setRoot(arr, key);
//		return root;
//	}
//	else if (key <= root->key)
//	{
//		root->left = insert(root->left, arr, key);
//		return root;
//	}
//	else
//	{
//		root->right = insert(root->right, arr, key);
//		return root;
//	}
//}
//
//void printTree(Tree* root)
//{
//	if (root != NULL)
//	{
//		printTree(root->left);
//		cout << root->arr << endl;
//		printTree(root->right);
//	}
//}
//
//Tree* Root = NULL;
//
//void main()
//{
//	int k, key;
//	char arr[20], letter;
//	Tree* ElementFound, * temp;
//
//	do
//	{
//		cout << "~~~~~~ CHOOSE THE OPTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//		cout << "1 - Set Root " << endl;
//		cout << "2 - Insert" << endl;
//		cout << "3 - Show Tree " << endl;
//
//		cout << "99 - Exit" << endl;
//		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//		cin >> k;
//		switch (k)
//		{
//		case 1: cout << "Enter the key: "; cin >> key; cout << endl; cout << "Enter a string "; cin >> arr; Root = setRoot(arr, key); break;
//		case 2: cout << "Enter the key: "; cin >> key; cout << endl; cout << "Enter a string "; cin >> arr; insert(Root, arr, key); break;
//		case 3: printTree(Root); break;
//		}
//	} while (k != 99);
//}