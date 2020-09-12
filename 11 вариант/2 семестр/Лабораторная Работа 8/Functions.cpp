#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Lab8.h"
#include <fstream>
using namespace std;

float MAX = 0;
queue* headUpper = NULL;
queue* tailUpper = NULL;
queue* headLower = NULL;
queue* tailLower = NULL;
pqueue* head = nullptr;
pqueue* tail = nullptr;
queue* dophead = NULL;
queue* doptail = NULL;

void input(queue*& head, queue*& tail,  char ch)
{
	queue* temp = new queue;
	if (head == NULL)
	{
		head = temp;
		head->symbol = ch;
		tail = head;
	}
	else
	{
		temp->next = NULL;
		temp->symbol = ch;
		tail->next = temp;
		tail = temp;
	}
}

void output(queue*& head)
{
	queue* temp = head;
	if (head == NULL)
	{
		cout << "Очередь пуста " << endl;
	}
	else
	{
		while (temp != NULL)
		{
			cout << temp->symbol << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void symbolDelete(queue*& head)
{
	queue* temp = head;
	if (head == NULL)
	{
		cout << "Очередь пуста " << endl;
	}
	else
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

void symbolSplit(queue*& head)
{
	
	if (head == NULL)
	{
		cout << "Стек пуст " << endl;
	}
	else
	{
		while (head != NULL)
		{
			if (head->symbol == toupper(head->symbol))
			{
				input(headUpper, tailUpper, head->symbol);
				
			}
			if (head->symbol == tolower(head->symbol))
			{
				input(headLower, tailLower, head->symbol);			
			}
			head = head->next;
		}
		cout << "queueUpper " << endl;
		output(headUpper);
		cout << "queueLower " << endl;
		output(headLower);
	}
}


void input(floatqueue*& head, floatqueue*& tail, float number)
{
	floatqueue* temp = new floatqueue;
	if (head == NULL)
	{
		head = temp;
		head->number = number;
		tail = head;
	}
	else
	{
		temp->next = NULL;
		temp->number = number;
		tail->next = temp;
		tail = temp;
	}
}


void sdvigBashkiDoMax(floatqueue*& head, floatqueue*& tail)
{
	float headFloat;
	floatqueue* temp = head;
	if (head == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->number > MAX)
			{
				MAX = temp->number;
			}
			temp = temp->next;
		}
		while (head->number != MAX)
		{
			floatqueue* newTemp = new floatqueue;
			temp = head;
			headFloat = head->number;
			head = head->next;
			delete temp;
			newTemp->next = NULL;
			newTemp->number = headFloat;
			tail->next = newTemp;
			tail = newTemp;
		}
		temp = head;
		cout << "New queue " << endl;
		while (temp != NULL)
		{
			cout << temp->number << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}



void pInput(int num, char x)
{
	pqueue* p = new pqueue;
	p->number = num;
	p->ch = x;
	p->next = nullptr;
	bool flag = false;

	if (!head) // Включение в пустую очередь
	{
		head = tail = p;
	}
	else
	{
		pqueue* phead = head;
		pqueue* ptail = tail;
		if (p->number < head->number)
		{
			p->next = head;
			head = p;
		}
		else
		{
			if (phead == tail)
			{
				flag = true;
			}
			else
			{
				while (1)
				{
					if (phead == tail)
					{
						flag = true;
						break;
					}
					if (p->number < phead->next->number)
					{
						break;
					}
					phead = phead->next;
				}
			}
			if (flag)
			{
				tail->next = p;
				tail = p;
			}
			else
			{
				pqueue* ptemp = phead->next;
				phead->next = p;
				p->next = ptemp;
			}

		}

	}
}

void poutput()
{
	pqueue* temp = head;
	if (head == NULL)
	{
		cout << "Очередь пуста " << endl;
	}
	else
	{
		while (temp != NULL)
		{
			cout << temp->ch << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void fileRead()
{
	char buf[50];
	ifstream pFile("FILE1.txt");
	ofstream pFile2("FILE2.txt");
	while (!pFile.eof())
	{
		pFile.getline(buf, 50);
		for (int i = 0; i < strlen(buf); i++)
		{
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				continue;
			}
			else
			{
				input(dophead, doptail, buf[i]);
			}
		}
		for (int i = 0; i < strlen(buf); i++)
		{
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				input(dophead, doptail, buf[i]);
			}
			else
			{
				continue;
			}
		}
	}
	
	queue* temp = dophead;
	if (dophead == NULL)
	{
		cout << "Очередь пуста " << endl;
	}
	else
	{
		while (temp != NULL)
		{
			pFile2 << temp->symbol << " ";
			temp = temp->next;
		}
	}
}