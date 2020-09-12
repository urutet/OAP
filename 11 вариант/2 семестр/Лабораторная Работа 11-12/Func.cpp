#include <iostream>
#include "Lab11.h"
using namespace std;


extern int c;
extern Tree* Root;


Tree* list(int key, char* arr)
{
	Tree* t = new Tree;
	t->key = key;
	for (int i = 0; i < 20; i++)
	{
		*((t->arr) + i) = *(arr + i);
	}
	t->left = t->right = NULL;
	return t;
}

Tree* insertElem(Tree* t)
{
	int key;
	char arr[20];
	bool find = false;
	while (1)
	{
		Tree* temp = t, * Prev = temp;
		cout << "Enter the key: "; cin >> key; cout << endl;
		if (key < 0)
		{
			break;
		}
		while (temp && !find)
		{
			Prev = temp;
			if (key == temp->key)
			{
				find = true;
			}
			else if (key < temp->key)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		if (!find)
		{
			cout << "Enter a string: ";
			getchar();
			cin.getline(arr, 20);
			cout << endl;
			temp = list(key, arr);
			if (key < Prev->key)
			{
				Prev->left = temp;
			}
			else
			{
				Prev->right = temp;
			}
		}
	}
	return t;
}


Tree* makeTree(Tree* root)
{
	int key;
	char arr[20];
	cout << "Enter negative number to end " << endl;
	if (root == NULL)
	{
		cout << "Enter the key: "; cin >> key;
		getchar();
		cout << "Enter a string: "; cin.getline(arr, 20);
		root = list(key, arr);
	}
	else
	{
		cout << "The tree already exists. Choose the ""Insert Element"" option" << endl;
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
	if (Del == NULL)
	{
		cout << "There's no identical key in the tree " << endl;
	}
	if (Del->left == NULL)
	{
		Replace = Del->right;
	}
	if (Del->right == NULL)
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


void reverse(Tree* root)
{
	//если дерево пусто, не выполнять никаких действий – обход дерева завершается
	if (!root)
		return;
	//обход левого поддерева
	reverse(root->left);
	//вывод информации
	printf("%d. \"%s\"\n", root->key, root->arr);
	//обход правого поддерева
	reverse(root->right);
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

void osnova11()
{
	int n, num = 0;
	Tree* temp = Root;
	cout << "Enter n: "; cin >> n; cout << endl;
	var11(temp, n, &num);
}

void var11(Tree* root, int n, int* num)
{
	if (root != NULL)
	{
		if (*num != n)
		{
			*num += 1;
			var11(root->right, n, num);
			var11(root->left, n, num);
		}
		else
		{
			cout << root->arr << endl;
		}
	}
}

void dop5()
{
	int nLeft = 0;
	Tree* temp = Root;
	var5(temp, &nLeft);
	cout << nLeft - 1 << endl;
}

void var5(Tree* root, int* nleft)
{
	if (root != NULL)
	{
		*nleft += 1;
		var5(root->left, nleft);
	}
}

void dop7()
{
	int n = 0;
	Tree* temp = Root;
	var5(temp, &n);
	cout << n - 1 << endl;
}

void var7(Tree* root, int* n)
{
	if (root != NULL)
	{
		*n += 1;
		var5(root->left, n);
		var5(root->right, n);
	}
}

void dop15()
{
	int nRight = 0;
	Tree* temp = Root;
	var5(temp, &nRight);
	cout << nRight - 1 << endl;
}

void var15(Tree* root, int* nRight)
{
	if (root != NULL)
	{
		*nRight += 1;
		var5(root->right, nRight);
	}
}