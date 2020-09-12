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


Tree* makeTree(Tree* Root);       //�������� ������
Tree* list(int i, char* s);       //�������� ������ ��������
Tree* insertElem(Tree* Root);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
void view(Tree* t, int level);    //����� ������ 
int count(Tree* t, char letter);  //������� ���������� ����
void delAll(Tree* t);             //������� ������
void osnova11();
void var11(Tree* root, int n, int* num);
void dop5();
void var5(Tree* root, int* nleft);
void dop7();
void var7(Tree* root, int* n);
void dop15();
void var15(Tree* root, int* nRight);
void reverse(Tree* root);