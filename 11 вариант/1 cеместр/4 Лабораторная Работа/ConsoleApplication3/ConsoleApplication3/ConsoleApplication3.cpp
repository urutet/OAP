// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int d;
	puts("Как дела? (1-Отлично, 2-Не очень)");
	cin >> d;
	switch (d)
	{
	case 1: { puts("Чего такой радостный? (1 - Нашел работу, 2 - Купил авто, 3 - Получил стипендию");
		cin >> d;
		switch (d)
		{
		case 1: puts("Молодец!"); break;
		case 2: puts("Отлчино! Подвези меня до дома"); break;
		case 3: puts("Отлично! Идем в магазин за твой счет");
			break;
		}
		break;
	}
	case 2: puts("Что случилось?");
		cin >> d;
		switch (d)
		{
		case 1: puts("Разбил машину"); break;
		case 2: puts("Уволили с работы"); break;
		case 3: puts("Потратил стипендию за один день"); break;
		}
		break;
	default: puts("Выберите рдин из предложенных вариантов"); break;
	}
	return 0;
}
