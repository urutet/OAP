#include <iostream>
#include <fstream>
using namespace std;

int k;


struct list
{
	int number;
	list* next;
};

void insert(list*& p, int ch); //Добавление символа в начало списка
void printList(list* p);       //Вывод списка 
void toFile(list*& p);         //Запись в файл
void fromFile(list*& p);       //Считывание из файла
void sumKr5(list* p);
void del(list*& p, int ch);
void sumKr2(list* p);

void main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	int ch;
	cout << "Выберите " << endl;
	cout << "1-Добавление числа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Сумма кратных 5 " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Сумма кратных 2 " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
	do
	{
		switch (k)
		{
		case 1: {cout << "Введите символ" << endl; cin >> ch; insert(first, ch); break; };
		case 2: {printList(first); break; };
		case 3: {toFile(first); break; };
		case 4: {fromFile(first); break; };
		case 5: {sumKr5(first); break; };
		case 6: {cout << "Введите символ" << endl; cin >> ch; del(first, ch); break; };
		case 7: {sumKr2(first); break; }
		}
	} while (k != 8);
}

void insert(list*& p, int ch)
{
	list* newP = new list;
	if (newP != NULL)
	{
		newP->number = ch;
		newP->next = p;
		p = newP;
	}
	else
	{
		cout << "Запись невозможна" << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление числа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Сумма кратных 5 " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Сумма кратных 2 " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}

void printList(list* p)
{
	if (p == NULL)
	{
		cout << "Список пуст " << endl;
	}
	else
	{
		cout << "Список " << endl;
		while (p != NULL)
		{
			cout << p->number << endl;;
			p = p->next;
		}
		cout << "Конец списка " << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление числа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Сумма кратных 5 " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Сумма кратных 2 " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}

void toFile(list*& p)
{
	ofstream pfile("FILE1.txt");
	if (pfile.fail())
	{
		cout << "Невозможно открыть файл " << endl;
		exit(1);
	}
	else
	{
		
		
		while (p != NULL)
		{
			
			pfile << p->number << endl;
			p = p->next;
		}
		pfile.close();
		cout << "Список записан в файл FILE1.txt " << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление числа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Сумма кратных 5 " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Сумма кратных 2 " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}

void fromFile(list*& p)
{
	ifstream pfile("FILE1.txt");
	if (pfile.fail())
	{
		cout << "Невозможно открыть файл " << endl;
		exit(1);
	}
	else
	{
		list* funcFirst = nullptr;
		list buf;
		pfile.read((char*)&buf, sizeof(list));
		while (!pfile.eof())
		{
			insert(funcFirst, buf.number);
			pfile.read((char*)&buf, sizeof(list));

		}
		pfile.close();
		p = funcFirst;
		cout << "Файл считан " << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление числа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Сумма кратных 5 " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Сумма кратных 2 " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}

void sumKr5(list* p)
{
	int sum = 0;
	if (p == NULL)
	{
		cout << "Список пуст" << endl;
	}
	else
	{

		while (p != NULL)
		{
			if (p-> number%5 == 0)
			{
				sum += p->number;
			}
			p = p->next;
		}
		cout << "Сумма чисел кратных 5 " << sum << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление числа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Сумма кратных 5 " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Сумма кратных 2 " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}

void sumKr2(list* p)
{
	int sum = 0;
	if (p == NULL)
	{
		cout << "Список пуст" << endl;
	}
	else
	{

		while (p != NULL)
		{
			if (p->number % 2 == 0)
			{
				sum += p->number;
			}
			p = p->next;
		}
		cout << "Сумма чисел кратных 2 " << sum << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление числа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Сумма кратных 5 " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Сумма кратных 2 " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}

void del(list*& p, int ch)  // Удаление числа 
{
	list* previous, * current, * temp;
	if (ch == p->number)
	{
		temp = p;
		p = p->next;    // отсоединить узел 
		delete temp;      //освободить отсоединенный узел
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != ch)
		{
			previous = current;
			current = current->next; // перейти к следующему 
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			free(temp);
		}
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление числа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Сумма кратных 5 " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Сумма кратных 2 " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}
