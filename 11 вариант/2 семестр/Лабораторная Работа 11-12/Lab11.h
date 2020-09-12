#pragma once
#include <iostream>
using namespace std;



struct Tree
{
	int key;
	char arr[50];
	Tree* left;
	Tree* right;
};


Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i, char* s);       //Создание нового элемента
Tree* insertElem(Tree* Root);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
int count(Tree* t, char letter);  //Подсчет количества слов
void delAll(Tree* t);             //Очистка дерева
void osnova11();
void var11(Tree* root, int n, int* num);
void dop5();
void var5(Tree* root, int* nleft);
void dop7();
void var7(Tree* root, int* n);
void dop15();
void var15(Tree* root, int* nRight);
void reverse(Tree* root);