#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "myStack.h"
#include <fstream>
#include <stdio.h>
using namespace std;
void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}
int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void kr3(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		exit(-1); //если стек пуст - возврат -1
	}
	else
	{
		Stack* previous, * current, * temp;
		current = myStk->head->next;
		previous = myStk->head;
		while (current)
		{
			if (current->data % 3 == 0)
			{
				temp = current;
				previous->next = current->next;
				delete temp;
			}
			else
			{
				current = current->next;
			}
		}
	}
}


void clear(Stack* myStk)
{
	Stack* temp = myStk->head;
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
	}
	else
	{
		while (myStk->head != NULL)
		{
			temp = myStk->head;
			myStk->head = myStk->head->next;
			delete temp;
		}
	}
}

void toFile(Stack* myStk)
{
	ofstream pFile("FILE1.txt");
	if (pFile.fail())
	{
		cout << "Невозможно открыть файл " << endl;
		exit(-1);
	}
	else
	{
		while (myStk->head != NULL)
		{
			pFile << myStk->head->data << " ";
			myStk->head = myStk->head->next;
		}
	}
}

void fromFile(Stack* myStk)
{
	int buf;
	ifstream pFile("FILE1.txt");
	if (pFile.fail())
	{
		cout << "Невозможно открыть файл " << endl;
		exit(-1);
	}
	else
	{
		while (!pFile.eof())
		{
			pFile >> buf;
			push(buf, myStk);
		}
	}
}


void string_length(Stack* myStk)
{
	ifstream pFile("FILE2.txt");
	if (pFile.fail())
	{
		cout << "Невозможно открыть файл " << endl;
		exit(-1);
	}
	else
	{
		char buf[50];
		int buflength, minlength = 99, minlengthNum = 0, minlengthStrNum = 0;
		while (!pFile.eof())
		{
			minlengthNum++;
			pFile.getline(buf, 50);
			buflength = strlen(buf);
			if (buflength < minlength)
			{
				minlength = buflength;
				minlengthStrNum = minlengthNum;
			}
			push(buflength, myStk);
		}
		cout << "Номер самой короткой строки " << minlengthStrNum << endl;
		cout << "Количество символов в самой короткой строке " << minlength << endl;
	}
}

void halves()
{
	char word[20], wordhalf1[10], wordhalf2[10];
	cout << "Введите слово " << endl;
	cin >> word;
	for (int i = 0; i < (strlen(word) / 2); i++)
	{
		wordhalf1[i] = word[i];
		wordhalf1[i + 1] = '\0';
		wordhalf2[i] = word[i + (strlen(word) / 2)];
		wordhalf2[i + 1] = '\0';
	}
	strcat(_strrev(wordhalf1), _strrev(wordhalf2));
	cout << wordhalf1 << endl;
}

int repeated(Stack* myStk)
{
	int counter = 0;
	if (myStk->head == NULL)
	{
		cout << "Стек пуст" << endl;
	}
	else
	{
		Stack* add_2 = myStk->head;
		while (add_2 != NULL)
		{
			bool wasLater = false;
			Stack* add_1 = add_2->next;
			while (add_1 != NULL)
			{
				if ((add_1->data == add_2->data) && (!wasLater))
				{
					counter++;
					wasLater = !wasLater;
				}
				add_1 = add_1->next;
			}
			add_2 = add_2->next;
		}
	}
	return counter;
}