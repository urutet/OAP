#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Header.h"
using namespace std;

Address* setElement() //Cоздание элемента и возврат его адреса
{
	int num;
	Address* temp = new Address;
	printf("Enter Int\n");
	cin >> temp->element;
	temp->next = NULL;
	temp->previous = NULL;
	return temp;
}

void input(Address* e, Address** head, Address** tail) //Ввод символа из setElement (temp)
{
	Address *temp = *tail;
	if (*head == NULL)
	{
		*head = e;
		*tail = *head;
	}
	else
	{
		temp->next = e;
		e->next = NULL;
		e->previous = temp;
		*tail = e;
	}
}

void output(Address** head, Address** tail)
{
	Address* t = *head;
	while (t != NULL)
	{
		cout << t->element << " ";
		t = t->next;
	}
	cout << endl;
}

void delet(int num, Address** head, Address** tail)  // Удаление имени 
{
	Address* t = *head;
	while (t)
	{
		if (num != t->element)  break;
		t = t->next;
	}
	if (!t)
		printf("This element doesn't exist in this list");
	else
	{
		if (*head == t)
		{
			*head = t->next;
			if (*head)
				(*head)->previous = NULL;
			else
				*head = NULL;
		}
		else
		{
			t->previous->next = t->next;
			if (t != *tail)
				t->next->previous = t->previous;
			else
				*tail = t->previous;
		}
		delete t;
		printf("Element deleted");
	}
}

void find(int num, Address** head)
{
	Address* t = *head;
	while (t)
	{
		if (num != t->element) break;
		t = t->next;
	}
	if (!t)
		printf("Int doesn't exist");
	else
		printf("%d", t->element);
}

void changeX(int numOfElem, int num, Address** head)
{
	Address* prev = new Address;
	Address* nex = new Address;
	Address* newElem;
	Address* temp = new Address;

	Address* t = *head;
	for (int i = 1; i<numOfElem; i++)
	{
		//if (num != t->element)
		//{
		//	t = t->next;
		//}
		//else
		//{
		//	t = temp;
		//}
		t = t->next;
	}
	/*prev = t->previous;
	nex = t->next;
	newElem = setElement();
	newElem->next = nex;
	newElem->previous = prev;
	t = newElem;*/
	t->element = num;
}

Address* setElementI(int i)
{
	Address* temp = new Address;
	temp->element = i;
	temp->next = NULL;
	temp->previous = NULL;
	return temp;
}

void circle(Address** head, Address** tail)
{
	Address* temp = new Address;
	Address* t = *head;
	int k, amount, num = 0, num1 = 1;
	cout << "Enter the amount of people" << endl;
	cin >> amount;
	cout << "Enter k" << endl;
	cin >> k;
	for (int i = 1; i <=amount; i++)
	{
		temp = setElementI(i);
		input(temp, head, tail);
	}
	(*head)->previous = *tail;
	(*tail)->next = *head;
	Address* temp1 = *head;
	Address* delElement = new Address;
	while (amount != 0)
	{
		num++;
		if (num == k)
		{
			cout << num1++ << ")" << temp1->element << endl;
			delElement = temp1;
			temp1->next->previous = temp1->previous;
			temp1->previous->next = temp1->next;
			temp1 = temp1->next;
			delete delElement;
			num = 0;
			amount--;
		}
		else
		{
			temp1 = temp1->next;
		}
	}
	*head = temp1;
}