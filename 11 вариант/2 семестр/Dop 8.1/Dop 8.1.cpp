#include "List.h"
#include <iostream>

#define str_len 210
using namespace std;

struct Contacts
{
	char name[str_len];
	char address[str_len];
	char placeOfWorkStudy[str_len];
	char position[str_len];
	int yearOfBirth;
	int monthOfBirth;
	int dayOfBirth;
	int phoneNumber;
	Contacts* next;
};

void print(void* b)       //Функция используется при выводе 
{
	
	Contacts* a = (Contacts*)b;
	cout <<"Имя: "<< a->name << "  " << endl;
	cout << "Адрес: " << a->address << "  " << endl;
	cout << "Место работы: " << a->placeOfWorkStudy << "  " << endl;
	cout << "Должность: " << a->position << "  " << endl;
	cout << "Дата рождения: " << a->dayOfBirth << "." << a->monthOfBirth << "." << a->dayOfBirth << endl;
	cout << "Номер телефона: " << a->phoneNumber << "  " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
}

int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Заполнение списка" << endl;
	cout << "2. Вывод списка" << endl;
	cout << "3. Поиск" << endl;
	cout << "4. Удаление эл-та" << endl;
	cout << "5. Удаление списка" << endl;
	cout << "6. Подсчёт элементов списка" << endl;
	cout << "7. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 7);
	return c;
}

int main(void)
{
	int count=0, num;
	setlocale(LC_CTYPE, "Rus");
	Contacts a1 = { "Eli","St1", "Work1", "Director", 1999, 12, 14 };
	Contacts a2 = { "Joseph","St2", "Work2", "Vice", 1910, 11, 12 };
	Contacts a3 = { "Adolph","St3", "Work3", "Vice", 1912, 01, 04};
	bool rc;
	Object L1 = Create();
	int size=0 ;
	while (true)
	{
		switch (menu())
		{
		case 1: {
			  // создание списка с именем L1
			L1.Insert(&a1);
			L1.Insert(&a2);
			L1.Insert(&a3);
		}
			break;
		case 2: 
		{
			cout << "Список:" << endl;
			L1.PrintList(print);
		}
			  break;
		case 3:  
		{
			Element* e = L1.Search(&a1);
			Contacts* aa = (Contacts*)e->Data;
			cout << "Имя: " << aa->name << "  " << endl;
			cout << "Адрес: " << aa->address << "  " << endl;
			cout << "Место работы: " << aa->placeOfWorkStudy << "  " << endl;
			cout << "Должность: " << aa->position << "  " << endl;
			cout << "Дата рождения: " << aa->dayOfBirth << "." << aa->monthOfBirth << "." << aa->dayOfBirth << endl;
			cout << "Номер телефона: " << aa->phoneNumber << "  " << endl;
		}
			break;
		case 4: {
			rc = L1.Delete(&a2);
			if (rc == true) cout << "Удален элемент" << endl;
		}
			  break;
		case 5:
		{
			rc = L1.DeleteList();
			if (rc == true) cout << "Удалено" << endl;
		}
			break;
		case 6:
			size = L1.CountList(size);
			cout << "Кол-во записей в списке: " << size << endl;
			break;
		case 7:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}
