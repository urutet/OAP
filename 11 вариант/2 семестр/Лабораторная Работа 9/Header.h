#include <iostream>
#include <fstream>

struct Address
{
	int element;
	Address* previous;
	Address* next;
};


Address* setElement();
void input(Address* e, Address** head, Address** tail);
void output(Address** head, Address** tail);
void delet(int num, Address** head, Address** tail);
void find(int num, Address** head);
void changeX(int numOfElem, int num, Address** head);
void circle(Address** head, Address** tail);
Address* setElementI(int i);