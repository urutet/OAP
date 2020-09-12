//отдел кадров-2
#include <iostream>
using namespace std;

# define str_len 30                            
# define size 30  

char varArray[str_len];

using namespace std;
void enter_new();
void del();
void out();
void search();
void dateOfEnter();

struct date
{
	int year : 7;
	int month : 5;
	int day : 5;
};

struct Employees
{
	char employeeName[str_len];
	union
	{
		char longName[str_len];
		char shortName[10];
	} listOfFaculties[size];
	char university[10];
	char department[10];
	char position[10];
	struct date dateOfEnter;
	bool isShort;
};
struct Employees employeesList[size];
struct Employees bad;
int current_size = 0; int choice;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска по владельцам " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  out();	break;
		case 4: search(); break;
		}
	} while (choice != 5);
}


void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Имя работника " << endl;
		cin >> employeesList[current_size].employeeName;
		cout << "Образование " << endl;
		cin >> varArray;
		if (strlen(varArray) <= 10)
		{
			employeesList[current_size].isShort = true;
			strcpy_s(employeesList[current_size].listOfFaculties->shortName, varArray);
		}
		else
		{
			employeesList[current_size].isShort = false;
			strcpy_s(employeesList[current_size].listOfFaculties->longName, varArray);
		}
		cout << "Специальность " << endl;
		cin >> employeesList[current_size].department;
		cout << "Должность " << endl;
		cin >> employeesList[current_size].position;
		cout << "Дата вступления в должность " << endl;
		dateOfEnter();
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска по владельцам " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
}


void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			employeesList[de1] = employeesList[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			employeesList[i] = bad;
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска по владельцам " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
}


void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << endl << "Имя работника " << endl;
		cout << employeesList[n].employeeName << endl;
		cout << "Образование " << endl;
		if (employeesList[n].isShort == true)
		{
			cout << employeesList[n].listOfFaculties->shortName << endl;
		}
		else
		{
			cout << employeesList[n].listOfFaculties->longName << endl;
		}
		cout << "Специальность " << endl;
		cout << employeesList[n].department << endl;
		cout << "Должнось " << endl;
		cout << employeesList[n].position << endl;
		cout << "Дата вступления в должность " << endl;
		cout << employeesList[n].dateOfEnter.day << '.' << employeesList[n].dateOfEnter.month << '.' << employeesList[n].dateOfEnter.year << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Имя работника " << endl;
			cout << employeesList[i].employeeName << endl;
			cout << "Образование " << endl;
			if (employeesList[i].isShort == true)
			{
				cout << employeesList[i].listOfFaculties->shortName << endl;
			}
			else
			{
				cout << employeesList[i].listOfFaculties->longName << endl;
			}
			cout << "Специальность " << endl;
			cout << employeesList[i].department << endl;
			cout << "Должность " << endl;
			cout << employeesList[i].position << endl;
			cout << "Дата вступления в должность " << endl;
			cout << employeesList[i].dateOfEnter.day << '.' << employeesList[i].dateOfEnter.month << '.' << employeesList[i].dateOfEnter.year << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска по владельцам " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
}

void dateOfEnter()
{
	int var;
	cout << "Введите год вступления в должность 20(__) " << endl;
	cin >> var;
	employeesList[current_size].dateOfEnter.year = var;
	cout << "Введите месяц вступления " << endl;
	cin >> var;
	employeesList[current_size].dateOfEnter.month = var;
	cout << "Введите день вступления " << endl;
	cin >> var;
	employeesList[current_size].dateOfEnter.day = var;
}


void search()
{
	char varArray[str_len];
	cout << "Введите должность " << endl;
	cin >> varArray;
	for (int i = 0; i < current_size; i++)
		if (_stricmp(employeesList[i].position, varArray) == 0)
		{
			cout << endl << "Имя работника " << endl;
			cout << employeesList[i].employeeName << endl;
			cout << "Образование " << endl;
			if (employeesList[i].isShort == true)
			{
				cout << employeesList[i].listOfFaculties->shortName << endl;
			}
			else
			{
				cout << employeesList[i].listOfFaculties->longName << endl;
			}
			cout << "Специальность " << endl;
			cout << employeesList[i].department << endl;
			cout << "Должность " << endl;
			cout << employeesList[i].position << endl;
			cout << "Дата вступления в должность " << endl;
			cout << employeesList[i].dateOfEnter.day << '.' << employeesList[i].dateOfEnter.month << '.' << employeesList[i].dateOfEnter.year << endl;
		}
	cout << "Что дальше?" << endl;
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска по владельцам " << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
}