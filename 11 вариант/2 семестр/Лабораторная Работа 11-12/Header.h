#include <iostream>

using namespace std;


struct Tree
{
	int key;
	char arr[20];
	Tree* left;
	Tree* right;
};

Tree* list(int key, char* arr);
Tree* insertElem(Tree* tree, int key, char* arr);
Tree* makeTree(Tree* root);
Tree* delet(Tree* root, int key);
Tree* search(Tree* n, int key);
int count(Tree* t, char letter);
void view(Tree* t, int level);
void delAll(Tree* t);