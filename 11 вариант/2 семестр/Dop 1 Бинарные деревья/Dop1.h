#pragma once
struct Tree
{
	int key;
	char fio[50];
	int number;
	int plan;
	Tree* left;
	Tree* right;
};

struct Tree2
{
	int num;
	int key;
	Tree2* left;
	Tree2* right;
};

Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i, char* s, int number, int plan);       //Создание нового элемента
Tree* insertElem(Tree* Root);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
int count(Tree* t, char letter);  //Подсчет количества слов
void delAll(Tree* t);             //Очистка дерева
void numSearch(Tree* root, int number);
void reverse(Tree* root);
void planComparison();
Tree2* makeTree2(Tree2* root, int key);
Tree2* insertElem(Tree2* t);
void view(Tree2* t, int level);
Tree2* list(int key);

