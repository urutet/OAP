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

Tree* makeTree(Tree* Root);       //�������� ������
Tree* list(int i, char* s, int number, int plan);       //�������� ������ ��������
Tree* insertElem(Tree* Root);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
void view(Tree* t, int level);    //����� ������ 
int count(Tree* t, char letter);  //������� ���������� ����
void delAll(Tree* t);             //������� ������
void numSearch(Tree* root, int number);
void reverse(Tree* root);
void planComparison();
Tree2* makeTree2(Tree2* root, int key);
Tree2* insertElem(Tree2* t);
void view(Tree2* t, int level);
Tree2* list(int key);

