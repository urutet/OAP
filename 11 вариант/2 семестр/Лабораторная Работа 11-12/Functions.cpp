#include <iostream>
#include "Header.h"

using namespace std;

int c = 0;


Tree* list(int key, char* arr)
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = key;
	for (int i = 0; i < strlen(arr); i++)
	{
		*((t->arr) + i) = *(arr + i);
	}
	t->left = NULL;
	t->right = NULL;
	return t;
}

Tree* insertElem(Tree* tree, int key, char* arr)
{
	Tree* prev;
	bool find = false;
	while (tree && !find)
	{
		prev = tree;
		if (key = tree->key)
		{
			find = true;
		}
		else
		{
			if (key < tree->key)
			{
				tree = tree->left;
			}
			else if (key > tree->key)
			{
				tree = tree->right;
			}
		}
		if (!find)
		{
			tree = list(key, arr);
			if (key < tree->key)
			{
				prev->left = tree;
			}
			else
			{
				prev->right = tree;
			}
		}
	}
	return tree;
}




Tree* makeTree(Tree* root)
{
	int key;
	char arr[20];
	cout << "Enter any negative number as a key to exit " << endl;
	if (root == NULL)
	{
		while (1)
		{
			cout << "Enter the key "; cin >> key;
			if (key < 0)
			{
				break;
			}
			getchar();
			cout << "Enter a string (not more than 19 symbols): "; cin.getline(arr, 20);
			insertElem(root, key, arr);
		}
	}
	return root;
}


Tree* delet(Tree* root, int key)
{
	Tree* Del, * Prev_Del, * Replace, * Prev_Replace;
	Del = root;
	Prev_Del = NULL;
	while (Del != NULL && key != Del->key)
	{
		Prev_Del = Del;
		if (key < Del->key)
		{
			Del = Del->left;
		}
		else
		{
			Del = Del->right;
		}
	}
	if (Del = NULL)
	{
		cout << "There's no identical key in the tree " << endl;
	}
	if (Del->left = NULL)
	{
		Replace = Del->right;
	}
	if (Del->right = NULL)
	{
		Replace = Del->left;
	}
	else
	{
		Prev_Replace = Del;
		Replace = Del->left;
		while (Replace->right != NULL)
		{
			Prev_Replace = Replace;
			Replace = Replace->right;
		}
		if (Prev_Replace == Del)
			Replace->right = Del->right;
		else
		{
			Replace->right = Del->right;
			Prev_Replace->right = Replace->left;
			Replace->left = Prev_Replace;
		}
	}
	if (Del == root) root = Replace;
	else
		if (Del->key < Prev_Del->key)
			Prev_Del->left = Replace;
		else
			Prev_Del->right = Replace;
	//int temp = Del->key;
	cout << "\nУдален элемент с ключом " << Del->key << endl;
	delete Del;
	return root;
}


Tree* search(Tree* n, int key) 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->left, key);
		else
			if (key > (key, n->key))
				rc = search(n->right, key);
	}
	else
		cout << "There's no element like this\n";
	return rc;
}

int count(Tree* t, char letter) //Подсчет количества слов
{
	if (t)
	{
		count(t->right, letter);
		if (*(t->arr) == letter)
			c++;
		count(t->left, letter);
	}
	return c;
}

void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->arr);
		view(t->left, level + 1);	//вывод левого поддерева
	}
	else
	{
		cout << endl;
	}
}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->left);
		delAll(t->right);
		delete t;
	}
}
