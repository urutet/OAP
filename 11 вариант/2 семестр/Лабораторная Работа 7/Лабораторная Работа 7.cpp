// proectStack.cpp: определяет точку входа для консольного приложения.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyStack.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Удаление элементов кратных 3" << endl;
		cout << "5 - Отчистка стека" << endl;
		cout << "6 - Запись стека в файл" << endl;
		cout << "7 - Вывод из файла в стек" << endl;
		cout << "8 - Стек из длин строк в файле и нахождение самой короткой строки" << endl;
		cout << "9 - Массивы в обратном порядке" << endl;
		cout << "10 - Повторяющиеся числа в стеке" << endl;
		cout << "11 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4: kr3(myStk); break;
		case 5: clear(myStk); break;
		case 6: toFile(myStk); break;
		case 7: fromFile(myStk); break;
		case 8: string_length(myStk); break;
		case 9: halves(); break;
		case 10: repeated(myStk); break;
		case 11: return 0;
			break;
		}
	}
	return 0;
}
