#include <iostream>
#include <fstream>
using namespace std;

int k;


struct list
{
	char symbol;
	list* next;
};

void insert(list*& p, char ch); //Добавление символа в начало списка
void printList(list* p);       //Вывод списка 
void toFile(list*& p);         //Запись в файл
void fromFile(list*& p);       //Считывание из файла
void symbolSearch(list* p, char ch);
void del(list*& p, char ch);
void symbolSearchNext(list* p, char ch);

void main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	char ch;
	cout << "Выберите " << endl;
	cout << "1-Добавление символа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Поиск символа введенного и предшествующего " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Поиск символа введенного и последующего " << endl;
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
		case 5: {cout << "Введите символ" << endl; cin >> ch; symbolSearch(first, ch); break; };
		case 6: {cout << "Введите символ" << endl; cin >> ch; del(first, ch); break; };
		case 7: {cout << "Введите символ" << endl; cin >> ch; symbolSearchNext(first, ch); break; }
		}
	} while (k != 8);
}

void insert(list*& p, char ch)
{
	list* newP = new list;
	if (newP != NULL)
	{
		newP->symbol = ch;
		newP->next = p;
		p = newP;
	}
	else
	{
		cout << "Запись невозможна" << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление символа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Поиск символа введенного и предшествующего " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Поиск символа введенного и последующего " << endl;
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
			cout << p->symbol << endl;;
			p = p->next;
		}
		cout << "Конец списка " << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление символа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Поиск символа введенного и предшествующего " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Поиск символа введенного и последующего " << endl;
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
		list* tmp = p;
		list buf;
		while (tmp)
		{
			buf = *tmp;
			pfile.write((char*)&buf, sizeof(list));
			tmp = tmp->next;	
		}
		pfile.close();
		cout << "Список записан в файл FILE1.txt " << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление символа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Поиск символа введенного и предшествующего " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Поиск символа введенного и последующего " << endl;
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
		pfile >> (char*)&buf;
		while (!pfile.eof())
		{
			insert(funcFirst, buf.symbol);

			pfile.read((char*)&buf, sizeof(list));

		}
		pfile.close();
		p = funcFirst;
		cout << "Файл считан " << endl;
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление символа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Поиск символа введенного и следующего за ним " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Поиск символа введенного и последующего " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}

void symbolSearch(list* p, char ch)
{
	list* previous;
	previous = new list;
	if (p == NULL)
	{
		cout << "Список пуст" << endl;
	}
	else
	{

			while (p != NULL)
			{
				if (previous->symbol == ch)
				{
					cout << "Символ " << previous->symbol << endl;
					cout << "Предыдущий символ " << p->symbol << endl;
				}
				previous = p;
				p = p->next;
		}
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление символа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Поиск символа введенного и предшествующего " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Поиск символа введенного и последующего " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}

void symbolSearchNext(list* p, char ch)
{
	list* previous;
	previous = new list;
	if (p == NULL)
	{
		cout << "Список пуст" << endl;
	}
	else
	{

		while (p != NULL)
		{
			if (p->symbol == ch)
			{
				cout << "Символ " << p->symbol << endl;
				cout << "Следующий символ " << previous->symbol << endl;
			}
			previous = p;
			p = p->next;
		}
	}
	cout << "Выберите " << endl;
	cout << "1-Добавление символа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Поиск символа введенного и предшествующего " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Поиск символа введенного и последующего " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}

void del(list*& p, char ch)  // Удаление числа 
{
	list* previous, * current, * temp;
	if (ch == p->symbol)
	{
		temp = p;
		p = p->next;    // отсоединить узел 
		delete temp;      //освободить отсоединенный узел
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->symbol != ch)
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
	cout << "1-Добавление символа в список " << endl;
	cout << "2-Вывод списка в консоль " << endl;
	cout << "3-Вывод списка в файл " << endl;
	cout << "4-Считывание списка из файла " << endl;
	cout << "5-Поиск символа введенного и предшествующего " << endl;
	cout << "6-Отчистка списка " << endl;
	cout << "7-Поиск символа введенного и последующего " << endl;
	cout << "8-Выход " << endl;
	cin >> k;
}
