#pragma once
//Structs, Stacks & Queues
struct queue
{
	char symbol;
	queue* next;
};

struct floatqueue
{
	float number;
	floatqueue* next;
};

struct pqueue
{
	short number;
	char ch;
	pqueue* next;

};

//Functions

void input(queue*& head, queue*& tail, char ch);
void output(queue*& que);
void symbolDelete(queue*& que);
void symbolSplit(queue*& que);

// DOPY PEREGRUZKA
void input(floatqueue*& head, floatqueue*& tail, float number);
void sdvigBashkiDoMax(floatqueue*& head, floatqueue*& tail);

void pInput(int num, char x);
void poutput();
void fileRead();