#include <iostream>
#include "Dop1.h"
using namespace std;


extern int c;
extern Tree* Root;
int numOfPlan1 = 0;
int numOfPlan2 = 0;
int numOfPlan3 = 0;
extern int N1;
extern int N;


Tree* list(int key, char* fio, int number, int plan)
{
	Tree* t = new Tree;
	t->key = key;
	for (int i = 0; i < 20; i++)
	{
		*((t->fio) + i) = *(fio + i);
	}
	t->number = number;
	t->plan = plan;
	if (plan == 1)
	{
		numOfPlan1++;
	}
	else if (plan == 2)
	{
		numOfPlan2++;
	}
	else
	{
		numOfPlan3++;
	}
	t->left = t->right = NULL;
	return t;
}

Tree* insertElem(Tree* t)
{
	int key;
	char fio[20];
	bool find = false;
	int number;
	int plan;
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
			cout << "Enter name: ";
			getchar();
			cin.getline(fio, 20);
			cout << endl;
			cout << "Enter number: "; cin >> number;
			cout << endl;
			cout << "Enter a plan (1-Plan1; 2-Plan2; 3-Plan3): "; cin >> plan;
			cout << endl;
			temp = list(key, fio, number, plan);
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
	char fio[20];
	int number;
	int plan;
	cout << "Enter negative number to end " << endl;
	if (root == NULL)
	{
		cout << "Enter the key: "; cin >> key;
		getchar();
		cout << "Enter Name: "; cin.getline(fio, 20);
		cout << "Enter number: "; cin >> number;
		cout << endl;
		cout << "Enter a plan (1-Plan1; 2-Plan2; 3-Plan3): "; cin >> plan;
		cout << endl;
		if (plan == 1)
		{
			numOfPlan1++;
		}
		else if (plan == 2)
		{
			numOfPlan2++;
		}
		else
		{
			numOfPlan3++;
		}
		root = list(key, fio, number, plan);
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
	cout << "\nElement is deleted " << Del->key << endl;
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
		if (*(t->fio) == letter)
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
		int tm = t->key;
		cout << tm << ' ';
		puts(t->fio);
		cout << "Number: " << t->number << ' ';
		cout << "Plan: " << t->plan << ' ';
		cout << endl;
		view(t->left, level + 1);	//вывод левого поддерева
	}
	else
	{
		cout << endl;
	}
}

void numSearch(Tree* root, int number)
{
	if(root != NULL)
	{
		if (number == root->number)
		{
			cout << "Name: " << root->fio << endl;
			cout << "Number: " << root->number << endl;
			cout << "Plan" << root->plan << endl;
		}
		else
		{
			numSearch(root->left, number);
			numSearch(root->right, number);
		}
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
	printf("%d. \"%s\" %d Plan%d \n", root->key, root->fio, root->number, root->plan);
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

void planComparison()
{
	if ((numOfPlan1 > numOfPlan2) && (numOfPlan1 > numOfPlan3))
	{
		cout << "Plan1 has the most number of users " << endl;
	}
	else if ((numOfPlan1 < numOfPlan2) && (numOfPlan2 > numOfPlan3))
	{
		cout << "Plan2 has the most number of users " << endl;
	}
	 else if ((numOfPlan3 > numOfPlan1) && (numOfPlan3 > numOfPlan2))
	{
		cout << "Plan3 has the most number of users " << endl;
	}
}

Tree2* list(int key)
{
	Tree2* t = new Tree2;
	t->key = key;
	t->num = key;
	t->left = t->right = NULL;
	return t;
}


Tree2* makeTree2(Tree2* root, int key)
{
	if (root == NULL)
	{
		root = list(key);
	}
	else
	{
		cout << "Tree already exists" << endl;
	}
	root->left = root->right = NULL;
	return root;
}


Tree2* insertElem(Tree2* t)
{
	int key;
	bool find = false;
	bool lefty = true;
	Tree2* temp = t, * Prev = temp;
	while (1)
	{
		if (lefty == true)
		{
			key = N1;
			lefty = !lefty;
			N1++;
		}
		else
		{
			key = N - 1;
			N = N - 1;
			lefty = !lefty;
		}
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
			temp = list(key);
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


void view(Tree2* t, int level) //Вывод дерева 
{
	if (t)
	{
		cout << endl;
		cout << t->key;
		view(t->right, level + 1);
		view(t->left, level + 1);
		
		
	}
	else
	{
		cout << endl;
	}
}